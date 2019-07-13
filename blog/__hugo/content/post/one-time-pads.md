---
title: "One Time Pads"
date: 2019-07-13T16:40:11+10:00

categories: ["Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

> From what I understood, one time pads would be used with XOR - but looks like it's actually just a Caesar / ROT(ation) on a per-character basis

# Principles of One Time Pads

* The pad must be truly random (and not pseudo-random)
* The pad must be as long as, or longer than the message
* The pad must never be resued

# Usage

For each character in the message, we shift it by the value at the same position from the pad.

For example

```python
"""
Rotate function. Only for letters
"""
def rotate(message, pad):
  # if len(pad) < len(message):
  #   raise Exception("Pad must be as long as or longer than the message")
  
  print(pad)
  def thisFunctionHereForSimplificationSake():
    import re
    if not re.match("^[a-zA-Z]*$", message):
      raise Exception("Please use only letters in the message")  
    if not re.match("^[a-zA-Z]*$", pad):
      raise Exception("Please use only letters in the pad")


  thisFunctionHereForSimplificationSake()

  output = []

  # Convert both messages to upper case
  # Restore case later
  _message = message.upper()
  _pad = pad.upper()

  _ordA = ord('A')
  
  for i in range(len(message)):
    # Subtract 65 (A) to get a number from 0 to 25
    _m = ord(_message[i])        - _ordA
    _p = ord(_pad[i % len(pad)]) - _ordA # Wrap the pad because we can (for purpose of breaking partial pads)

    # Add character and padding offset, wrapped from 0 to 25
    _o = (_m + _p) % 26

    # Add back the offset
    _o += _ordA

    # Convert back to a letter
    _o = chr(_o)

    # Restore letter case
    if message[i].islower():
      _o = _o.lower()

    output.append(_o)

  return "".join(output)
```

So if our key was "AAAAA", then `rotate("Hello", "XKCDZ") => Eonon`.

To decrypt the pad, for the sake of laziness and space saving - we'll just feed the inverted key into the `rotate` function

```python
def de_rotate(cipher, key):
  key = "".join([chr(ord('A') + (26 - (ord(c) - ord('A')) % 26)) for c in key.upper()])
  return rotate(cipher, key)
```

Performing `de_rotate("Eonon", "XKCDZ") => Hello`

---

# Activity

```
LpaGbbfctNiPvwdbjnPuqolhhtygWhEuafjlirfPxxl

WdafvnbcDymxeeulWOtpoofnilwngLhblUfecvqAxs

UijMltDjeumxUnbiKstvdrVhcoDasUlrvDypegublg

LpaAlrhGmjikgjdmLlcsnnYmIsoPcglaGtKeQcemiu

LpaDohqcOzVbglebjPdTnoTzbyRbuwGftflTliPiqp
```

We've got five strings that have all been encrypted with the same one-time pad (more like many-time pad now).  
Okay so let's start breaking this

The basic principles of breaking ciphers with the same encryption key is that, if we break one of them - we break all of them.


Let's throw a script together to touch each one at the same time.

```python
messages = [
  "LpaGbbfctNiPvwdbjnPuqolhhtygWhEuafjlirfPxxl",
  "WdafvnbcDymxeeulWOtpoofnilwngLhblUfecvqAxs",
  "UijMltDjeumxUnbiKstvdrVhcoDasUlrvDypegublg",
  "LpaAlrhGmjikgjdmLlcsnnYmIsoPcglaGtKeQcemiu",
  "LpaDohqcOzVbglebjPdTnoTzbyRbuwGftflTliPiqp"
]

def attempt(key):
  for i, m in enumerate(messages):
    R = de_rotate(m, key)
    print(i+1, R[:len(key)] + "." + R[len(key):])
  print()

while True:
  attempt(input("Enter attempt: "))
```

We _could_ try brute force it, but that'd be abit...  
Instead, thinking analytically - considering that the message is in English. 

`Lpa` is probably the word `The`.

By entering in `The` as the key - by nature of this symmetric encryption pattern - we're given the key used to **decrypt** the word `The`, as the output.

```
Enter attempt: The
1 Siw.NuxmvpUbLcpzicjWnmvedomunPdLnwmchpkbWqts
2 Dww.mojivZfftlxqsPKaikvyjpesuzHouhByajomHqo
3 Bbf.TepKcabftBgxpDoaozyOdjhZhlQskrKrllzqiec
4 Siw.HenoZiqbgncztEhjljuRiPlkWvcstCaDaXvatbq
5 Siw.KhdxvKgOxneaicLkMjvMvirNinsNypmePsbLpjl
  ^^^
```

```
Enter attempt: Siw
1 The.OtfnuxVaTdohjbrXmuwdlplcoOlMmenbpqjjXpbt
2 Eve.nnrjuHgebmwytOSbhswxrqdavyPptpCxiknuIpw
3 Can.UdxLbicebCffqCwbnhzNlkgHikYtjzLqtmyyjdk
4 The.IdvpYqraoobhuDpkkrvQqQksXuktsKbCiYuiuay
5 The.LglyuShNfodijbTlLrwLdjqVjmaOxxndXtaTqit
  ^^^
```

So from the first three characters, we have the possible trigrams `The`, `Eve` and `Can`.  
Looks like the guess was right!

---

If we keep going, eventually we recover these messages:

* TheSecretToWinningEurovisionIsExcellentHair
* EveryoneDeservesAHippopotamusWhenTheyreSad
* CanYouPleaseHelpOliverFindTheFluxCapacitor
* TheMostImportantPersonInTheWorldIsMeMyself
* ThePriceOfBitcoinIsTooDamnHighGivenTheData

with the key `SiwOxzoyaUuTnjqtwhLazaqzplktOpAxybyaeemIxpu`

---

## Log

For the fun of it, here's a log of everything I did

<details>
```
LpaGbbfctNiPvwdbjnPuqolhhtygWhEuafjlirfPxxl
WdafvnbcDymxeeulWOtpoofnilwngLhblUfecvqAxs
UijMltDjeumxUnbiKstvdrVhcoDasUlrvDypegublg
LpaAlrhGmjikgjdmLlcsnnYmIsoPcglaGtKeQcemiu
LpaDohqcOzVbglebjPdTnoTzbyRbuwGftflTliPiqp
```

```
Enter attempt: The
1 Siw.NuxmvpUbLcpzicjWnmvedomunPdLnwmchpkbWqts
2 Dww.mojivZfftlxqsPKaikvyjpesuzHouhByajomHqo
3 Bbf.TepKcabftBgxpDoaozyOdjhZhlQskrKrllzqiec
4 Siw.HenoZiqbgncztEhjljuRiPlkWvcstCaDaXvatbq
5 Siw.KhdxvKgOxneaicLkMjvMvirNinsNypmePsbLpjl

Enter attempt: Siw
1 The.OtfnuxVaTdohjbrXmuwdlplcoOlMmenbpqjjXpbt
2 Eve.nnrjuHgebmwytOSbhswxrqdavyPptpCxiknuIpw
3 Can.UdxLbicebCffqCwbnhzNlkgHikYtjzLqtmyyjdk
4 The.IdvpYqraoobhuDpkkrvQqQksXuktsKbCiYuiuay
5 The.LglyuShNfodijbTlLrwLdjqVjmaOxxndXtaTqit
```
--> I tried `The`, and reversing `Siw` gives `The`, `Eve` and `Can`

```
Enter attempt: CanYou
1 JpnInh.dcgPuVtwqdvtNudqxnftliInCunhvrgrsRjdj
2 Udnhht.zcQaydcehnIUrpbqrtgljpsRfbyWrkavdCjy
3 SiwOxz.BjrwydSnokWyrvqtHnaoQceAjriFkvcghdxm
4 JpnCxx.fGzluqejqoXrasapKsGsbRomjaTvWkOcroua
5 JpnFan.ocBbHhelrdvVbTaqFfzyEdgcEfghxZjiCkcv

Enter attempt: SiwOxz
1 TheSec.nuxZlQdohnmoXmuaoiplcsZiMmermmqjjBayt
2 Everyo.juHkpymwyxZPbhsaioqdazjMptpGifknuMat
3 CanYou.LbigpyCffuNtbnhdYikgHmvVtjzPbqmyynoh
4 TheMos.pYqvllobhyOmkkrzBnQksBfhtsKfNfYuiylv
5 ThePri.yuSlYcodinmQlLraWajqVnxxOxxroUtaTutq
```
--> I tried adding the word `You` onto `Can` (guess) and it looks like it works with the other messages

```
Enter attempt: Everyone
1 HuwPdnsy.pSeYxiqxfsLdsayddyupYtRqwkfukdsLtch
2 Siwoxzoy.ZdiggqhhSTpyqasjeqswiXuxhZbnehdWtx
3 QnfVnfQf.azigWzoeGxpefdIdytZjuGynrIuygshxhl
4 HuwJnduC.ioetivqiHqybpzLiExkYesywCyGnSoriez
5 HuwMqtdy.KeRkixrxfUzCpaGvxdNkwiTbpkhCnuCemu

Enter attempt: Siwoxzoy
1 TheSecre.bFmByxpdrfTgtpxjplcsZiQwixnxlsrRfpp
2 Everyone.LqqjhfgnEGxbrprpqdazjMtdtMjqfwcCfk
3 CanYouPl.mmqjXonkSkxhgsHjkgHmvVxtdVcbhhgdty
4 TheMostI.ubmwjkpoTdgeqoKoQksBfhxcOlOqTdqoqm
5 ThePrice.WrZnjmqdrHhFqpFbjqVnxxShbxpFojBkyh
```
--> `Eve` probably goes to `Everyone`... yep!

```
Enter attempt: CanYouPlease
1 JpnInhqrpNqL.twqdvtAjmotdftliInPjwfrhgrsRjdw
2 UdnhhtmrZyut.cehnIUeekonjgljpsRsqhUnaavdCjy
3 SiwOxzOyauut.SnokWyekzrDdaoQceAwgrDglcghdxm
4 JpnCxxsVijqg.ejqoXrnhjnGiGsbRomwpCtSaOcroua
5 JpnFanbrKzDx.elrdvVoIjoBvzyEdgcRupftPjiCkcv

Enter attempt: SiwOxzOyauut
1 TheSecretToW.dohnmoBwquroplcsZiQwalpsqjjBayx
2 EveryoneDese.mwyxZPfrouluqdazjMtdlAllknuMat
3 CanYouPlease.CffuNtfxdxBokgHmvVxtvJewmyynoh
4 TheMostImpor.obhyOmountEtQksBfhxcGzQlYuiylv
5 ThePriceOfBi.odinmQpVnuZgjqVnxxShtlrAtaTutq
```
--> `CanYouPlease`

```
Enter attempt: TheMostImportant
1 SiwUnjmuhYuYcwqi.qgLicwszvekpDhRbhyfzuzmHlix
2 DwwthviuRjyglehs.DHpdawmfwwiwnLuisNbsodxSld
3 BbfAxbKbsfygBnop.RlpjpzCzqzPjzUyycWudqobtzr
4 SiwOxzoYauutnjqt.SeygzvFeWdaYjgyhNmGsCklewf
5 SiwRapxuCkHknlri.qIzHzwArpjDkbwTmayhHxqWaea

Enter attempt: SiwOxzoYauutnjqt
1 TheSecretToWinni.rfTgtpxjhzenJyObixnxlsrRxdr
2 EveryoneDeserves.EGxbrprpircutCritMjqfwcCxy
3 CanYouPleaseHelp.SkxhgsHjcuJhfLvydVcbhhgdlm
4 TheMostImportant.TdgeqoKoIyuWpxvhOlOqTdqoia
5 ThePriceOfBitcoi.rHhFqpFbbeXihnQmbxpFojBkqv
```
--> `TheMostImportant`

```
Enter attempt: TheSecretToWinning
1 SiwOxzoyaUuTnjqtwh.WnmwhfqpfnIlWhnxwfpkbXtvu
2 DwwnrlkyKfybwrhdJI.aikwblrhdusPzoyMsyjomItq
3 BbfUhrMflbybMaoaXm.aozzRflkKheYdeiVljlzqjhe
4 SiwIhpqCtquoywqeYf.jljvUkRovWokdnTlXyXvaues
5 SiwLkfzyVgHfyyrtwJ.kMjwPxkuYigaYsgxyNsbLqmn

Enter attempt: SiwOxzoyaUuTnjqtwh
1 TheSecretToWinning.XmuaoitvymCoRlkmneqjjBayx
2 EveryoneDeservesAH.bhsaiounwtmSusvBjxknuMat
3 CanYouPleaseHelpOl.bnhdYioqDgyByifKcimyynoh
4 TheMostImportantPe.kkrzBnUuoVinyrQaOxYuiylv
5 ThePriceOfBitcoinI.lLraWanaRhadTwdmpMtaTutq
```
--> `TheSecretToWinning`

```
Enter attempt: TheMostImportantPeople
1 SiwUnjmuhYuYcwqiujBffk.sadhkoDzSfmoqlvyqLjia
2 DwwthviuRjyglehsHKfadk.mgezivnDvmxDmepcbWjd
3 BbfAxbKbsfygBnopVofgsn.CaycPizMzchMfprnfxxr
4 SiwOxzoYauutnjqtWhodcj.FfEgaXjyzlScReDjpiuf
5 SiwRapxuCkHknlriuLpEck.AsxmDjboUqfosTypAeca

Enter attempt: SiwOxzoYauutnjqtWhodcj
1 TheSecretToWinningBrof.tzlfbhIjEagmwcsyjIjuj
2 EveryoneDeservesAHfmmf.nfmxzosNhhrBsvmcuTjp
3 CanYouPleaseHelpOlfsbi.DzgaGbeWlxbKlgonyuxd
4 TheMostImportantPeople.GeMerQoilgMaXvAjifur
5 ThePriceOfBitcoinIpQlf.BrfkUcgyGlzmyKvpTbcm
```
--> Looks like it wasn't `People`, let's try `Person`

```
Enter attempt: TheMostImportantPerson
1 SiwUnjmuhYuYcwqiujYccb.sadhkoDzSfmoqlvyqLgfx
2 DwwthviuRjyglehsHKcxab.mgezivnDvmxDmepcbWga
3 BbfAxbKbsfygBnopVocdpe.CaycPizMzchMfprnfxuo
4 SiwOxzoYauutnjqtWhlaza.FfEgaXjyzlScReDjpirc
5 SiwRapxuCkHknlriuLmBzb.AsxmDjboUqfosTypAezx

Enter attempt: SiwOxzoYauutnjqtWhlaza
1 TheSecretToWinningEuro.tzlfbhIjEagmwcsyjImxm
2 EveryoneDeservesAHippo.nfmxzosNhhrBsvmcuTms
3 CanYouPleaseHelpOliver.DzgaGbeWlxbKlgonyuag
4 TheMostImportantPerson.GeMerQoilgMaXvAjifxu
5 ThePriceOfBitcoinIsToo.BrfkUcgyGlzmyKvpTbfp
```
--> `Person` worked

```
Enter attempt: TheMostImportantPersonInTheWorld
1 SiwUnjmuhYuYcwqiujYccbduomukIqTr.hyfzuzmHlix
2 DwwthviuRjyglehsHKcxabxapesrsUwy.sNbsodxSld
3 BbfAxbKbsfygBnopVocdpeNujhZeeDao.cWudqobtzr
4 SiwOxzoYauutnjqtWhlazaQzPlkTopax.NmGsCklewf
5 SiwRapxuCkHknlriuLmBzbLmirNfgfVc.ayhHxqWaea

Enter attempt: SiwOxzoYauutnjqtWhlazaQzPlkTopax
1 TheSecretToWinningEurovisionIsEx.ixnxlsrRxdr
2 EveryoneDeservesAHippopotamusWhe.tMjqfwcCxy
3 CanYouPleaseHelpOliverFindTheFlu.dVcbhhgdlm
4 TheMostImportantPersonInTheWorld.OlOqTdqoia
5 ThePriceOfBitcoinIsTooDamnHighGi.bxpFojBkqv
```
--> `TheMostImportantPersonInTheWorld`

```
Enter attempt: EveryoneDeservesAHippopotamusWhen
1 HuwPdnsyqJqLebzjjgHfbawtotmmElXqn.bohrtrCtuh
2 SiwoxzoyAuutnjqtWHlazaqzplktoPaxy.QkalxcNtp
3 QnfVnfQfbqutDsxqKllgodGtjoRgaYeni.Zdlnigohd
4 HuwJnduCjfqgpozuLeudyzJyPscVkkewT.pPaZeqzer
5 HuwMqtdyLvDxpqajjIvEyaEliyFhcaZbg.bqPukBvmm

Enter attempt: SiwoxzoyAuutnjqtWHlazaqzplktoPaxy
1 TheSecretToWinningEurovisionIsExc.nbpuugBzxr
2 EveryoneDeservesAHippopotamusWhen.CxioyrMzs
3 CanYouPleaseHelpOliverFindTheFlux.Lqtqjvnng
4 TheMostImportantPersonInTheWorldI.bCiCffyku
5 ThePriceOfBitcoinIsTooDamnHighGiv.ndXxlQusp
```
--> `EveryoneDeservesAHippopotamusWhen`

```
Enter attempt: TheMostImportantPersonInTheWorldIs
1 SiwUnjmuhYuYcwqiujYccbduomukIqTrsn.qeefrXepz
2 DwwthviuRjyglehsHKcxabxapesrsUwydC.mxyjcIek
3 BbfAxbKbsfygBnopVocdpeNujhZeeDaonL.fiaugjsy
4 SiwOxzoYauutnjqtWhlazaQzPlkTopaxYb.RxMqqupm
5 SiwRapxuCkHknlriuLmBzbLmirNfgfVcln.sMhwBqxh

Enter attempt: SiwOxzoYauutnjqtWhlazaQzPlkTopaxYb
1 TheSecretToWinningEurovisionIsExce.rdmdiQjzl
2 EveryoneDeservesAHippopotamusWhenT.nwghtBju
3 CanYouPleaseHelpOliverFindTheFluxC.ghisxcxi
4 TheMostImportantPersonInTheWorldIs.SwUohnuw
5 ThePriceOfBitcoinIsTooDamnHighGive.tLpuSjcr
```
--> `TheMostImportantPersonInTheWorldIs`

```
Enter attempt: TheSecretToWinningEurovisionIsExcellent
1 SiwOxzoyaUuTnjqtwhLazaqzplktOpAxybyaeem.Wqtt
2 DwwnrlkyKfybwrhdJIpvxakfqdiayTdejQutyix.Hqo
3 BbfUhrMflbybMaoaXmpbmdAzkgPnkChutZneatb.iec
4 SiwIhpqCtquoywqeYfyywzDeQkaCuohdEpZtMpl.tbq
5 SiwLkfzyVgHfyyrtwJzZwaYrjqDomeCirbaIhvW.pjl

Enter attempt: SiwOxzoyaUuTnjqtwhLazaqzplktOpAxybyaeem
1 TheSecretToWinningEurovisionIsExcellent.Xpbx
2 EveryoneDeservesAHippopotamusWhenTheyre.Ipw
3 CanYouPleaseHelpOliverFindTheFluxCapaci.jdk
4 TheMostImportantPersonInTheWorldIsMeMys.uay
5 ThePriceOfBitcoinIsTooDamnHighGivenTheD.qit
```
--> `TheSecretToWinningEurovisionIsExcellent`

```
Enter attempt: TheMostImportantPersonInTheWorldIsMeMyself
1 SiwUnjmuhYuYcwqiujYccbduomukIqTrsnxhwtnLms.s
2 DwwthviuRjyglehsHKcxabxapesrsUwydCtaqxyWmn.
3 BbfAxbKbsfygBnopVocdpeNujhZeeDaonLmlsicxab.
4 SiwOxzoYauutnjqtWhlazaQzPlkTopaxYbYaEemixp.
5 SiwRapxuCkHknlriuLmBzbLmirNfgfVclnzPzkXefk.

Enter attempt: SiwOxzoYauutnjqtWhlazaQzPlkTopaxYbYaEemixp
1 TheSecretToWinningEurovisionIsExcellentHai.t
2 EveryoneDeservesAHippopotamusWhenTheyreSad.
3 CanYouPleaseHelpOliverFindTheFluxCapacitor.
4 TheMostImportantPersonInTheWorldIsMeMyself.
5 ThePriceOfBitcoinIsTooDamnHighGivenTheData.
```
--> `TheMostImportantPersonInTheWorldIsMeMyself`

```
Enter attempt: TheSecretToWinningEurovisionIsExcellentHair
1 SiwOxzoyaUuTnjqtwhLazaqzplktOpAxybyaeemIxpu.
2 DwwnrlkyKfybwrhdJIpvxakfqdiayTdejQutyixTxk.
3 BbfUhrMflbybMaoaXmpbmdAzkgPnkChutZneatbuly.
4 SiwIhpqCtquoywqeYfyywzDeQkaCuohdEpZtMplfim.
5 SiwLkfzyVgHfyyrtwJzZwaYrjqDomeCirbaIhvWbqh.

Enter attempt: SiwOxzoyaUuTnjqtwhLazaqzplktOpAxybyaeemIxpu
1 TheSecretToWinningEurovisionIsExcellentHair.
2 EveryoneDeservesAHippopotamusWhenTheyreSad.
3 CanYouPleaseHelpOliverFindTheFluxCapacitor.
4 TheMostImportantPersonInTheWorldIsMeMyself.
5 ThePriceOfBitcoinIsTooDamnHighGivenTheData.
```
--> And that `t` is probably `r` to spell `Hair`.

</details>

So ultimately, our OTP phrase was `SiwOxzoyaUuTnjqtwhLazaqzplktOpAxybyaeemIxpu`.

We can verify this by trying to encrypt the phrase again.

```python
rotate("TheSecretToWinningEurovisionIsExcellentHair", "SiwOxzoyaUuTnjqtwhLazaqzplktOpAxybyaeemIxpu")
```
=> `LpaGbbfctNiPvwdbjnPuqolhhtygWhEuafjlirfPxxl`

Looks like it worked!


<!-- 
```python
messages = ["LpaGbbfctNiPvwdbjnPuqolhhtygWhEuafjlirfPxxl",
"WdafvnbcDymxeeulWOtpoofnilwngLhblUfecvqAxs",
"UijMltDjeumxUnbiKstvdrVhcoDasUlrvDypegublg",
"LpaAlrhGmjikgjdmLlcsnnYmIsoPcglaGtKeQcemiu",
"LpaDohqcOzVbglebjPdTnoTzbyRbuwGftflTliPiqp"
]

def toBytes(string):
  return [ord(c) for c in list(string)]

def fromBytes(seq):
  return "".join([chr(b) for b in seq])

def doXOR(seq1, seq2):
  length = min(len(seq1), len(seq2))
  XOR = []
  for i in range(length):
    XOR.append(seq1[i] ^ seq2[i])
  return XOR

b_messages = list(map(toBytes, messages))
``` -->
