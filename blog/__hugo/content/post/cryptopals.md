---
title: "Cryptopals"
date: 2019-07-05T23:38:52+10:00

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

So I was trying to find substition cipher challenges online, but found myself at [cryptopals.com](https://cryptopals.com).  
Whoops, but might as well [play around](https://cryptopals.com/sets/1)!

I'll be using Javascript and/or Python for these challenges.  
Also, instead of writing my code more declarative than imperative, so that I can reuse them later

# Set One

## Convert hex to base64
> The string: `49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d`
Should produce: `SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t`

```python
def hexToString(hex):
  return bytearray.fromhex(hex).decode()

def stringToB64(str):
  import base64
  return base64.b64encode(str.encode())

def hexToB64(hex):
  return stringToB64(hexToString(hex))

print(hexToB64("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"))
```

**Output**  
`SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t`

## Fixed XOR

> Write a function that takes two equal-length buffers and produces their XOR combination.  
If your function works properly, then when you feed it the string: `1c0111001f010100061a024b53535009181c` and `686974207468652062756c6c277320657965`  
XORing the hex decoded strings should result in `746865206b696420646f6e277420706c6179`

```python
def hexToBytes(hex):
  import binascii
  return binascii.unhexlify(hex)

def hexStringXOR(hex1, hex2):
  import binascii

  str1 = hexToBytes(hex1)
  str2 = hexToBytes(hex2)
  
  output = ""
  
  for i in range(len(str1)):
    output += chr(str1[i] ^ str2[i])
  
  return binascii.hexlify(output.encode()).decode()

print(hexStringXOR("1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965"))
```

**Output**  
`746865206b696420646f6e277420706c6179`

## Single-byte XOR cipher

> The hex encoded string: `1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736` has been XOR'd against a single character. Find the key, decrypt the message.  
You can do this by hand. But don't: write code to do it for you.  
How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score. 

We'll use the most common English letters (in order E T A O I N S H R D L U). 

```python
def hexToBytes(hex):
  import binascii
  return binascii.unhexlify(hex)

def hexToString(hex):
  return bytearray.fromhex(hex).decode()
  
def stringToHex(str):
  import binascii
  return binascii.hexlify(str.encode())

def hexStringXOR(hex1, hex2):
  import binascii

  str1 = hexToBytes(hex1)
  str2 = hexToBytes(hex2)
  
  output = ""
  
  for i in range(len(str1)):
    output += chr(str1[i] ^ str2[i])
  
  return binascii.hexlify(output.encode()).decode()

inputString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
for c in "ABCDEFGIHJKLMNOPQRSTUVWXYZ":
  XOR_result = hexStringXOR(inputString, stringToHex(c * len(hexToBytes(inputString))))
  print(c, XOR_result, hexToString(XOR_result))
```

**Result**
```
A 5a76767270777e39545a3e6a397570727c39783969766c777d39767f397b787a7677 Zvvrpw~9TZ>j9upr|9x9ivlw}9v9{xzvw
B 5975757173747d3a57593d693a7673717f3a7b3a6a756f747e3a757c3a787b797574 Yuuqst}:WY=i:vsq:{:juot~:u|:x{yut
C 5874747072757c3b56583c683b7772707e3b7a3b6b746e757f3b747d3b797a787475 Xttpru|;VX<h;wrp~;z;ktnu;t};yzxtu
D 5f73737775727b3c515f3b6f3c707577793c7d3c6c736972783c737a3c7e7d7f7372 _sswur{<Q_;o<puwy<}<lsirx<sz<~}sr
E 5e72727674737a3d505e3a6e3d717476783d7c3d6d726873793d727b3d7f7c7e7273 ^rrvtsz=P^:n=qtvx=|=mrhsy=r{=|~rs
F 5d7171757770793e535d396d3e7277757b3e7f3e6e716b707a3e71783e7c7f7d7170 ]qquwpy>S]9m>rwu{>>nqkpz>qx>|}qp
G 5c7070747671783f525c386c3f7376747a3f7e3f6f706a717b3f70793f7d7e7c7071 \pptvqx?R\8l?svtz?~?opjq{?py?}~|pq
I 527e7e7a787f76315c523662317d787a74317031617e647f75317e77317370727e7f R~~zxv1\R6b1}xzt1p1a~du1~w1spr~
H 537f7f7b797e77305d533763307c797b75307130607f657e74307f76307271737f7e S{y~w0]S7c0|y{u0q0`e~t0v0rqs~
J 517d7d797b7c75325f513561327e7b7977327332627d677c76327d74327073717d7c Q}}y{|u2_Q5a2~{yw2s2b}g|v2}t2psq}|
K 507c7c787a7d74335e503460337f7a7876337233637c667d77337c75337172707c7d P||xz}t3^P4`3zxv3r3c|f}w3|u3qrp|}
L 577b7b7f7d7a73345957336734787d7f71347534647b617a70347b72347675777b7a W{{}zs4YW3g4x}q4u4d{azp4{r4vuw{z
M 567a7a7e7c7b72355856326635797c7e70357435657a607b71357a73357774767a7b Vzz~|{r5XV2f5y|~p5t5ez`{q5zs5wtvz{
N 5579797d7f7871365b553165367a7f7d733677366679637872367970367477757978 Uyy}xq6[U1e6z}s6w6fycxr6yp6twuyx
O 5478787c7e7970375a543064377b7e7c723776376778627973377871377576747879 Txx|~yp7ZT0d7{~|r7v7gxbys7xq7uvtxy
P 4b67676361666f28454b2f7b286461636d28692878677d666c28676e286a696b6766 Kggcafo(EK/{(dacm(i(xg}fl(gn(jikgf
Q 4a66666260676e29444a2e7a296560626c29682979667c676d29666f296b686a6667 Jffb`gn)DJ.z)e`bl)h)yf|gm)fo)khjfg
R 4965656163646d2a47492d792a6663616f2a6b2a7a657f646e2a656c2a686b696564 Ieeacdm*GI-y*fcao*k*zedn*el*hkied
S 4864646062656c2b46482c782b6762606e2b6a2b7b647e656f2b646d2b696a686465 Hdd`bel+FH,x+gb`n+j+{d~eo+dm+ijhde
T 4f63636765626b2c414f2b7f2c606567692c6d2c7c637962682c636a2c6e6d6f6362 Occgebk,AO+,`egi,m,|cybh,cj,nmocb
U 4e62626664636a2d404e2a7e2d616466682d6c2d7d627863692d626b2d6f6c6e6263 Nbbfdcj-@N*~-adfh-l-}bxci-bk-olnbc
V 4d6161656760692e434d297d2e6267656b2e6f2e7e617b606a2e61682e6c6f6d6160 Maaeg`i.CM)}.bgek.o.~a{`j.ah.loma`
W 4c6060646661682f424c287c2f6366646a2f6e2f7f607a616b2f60692f6d6e6c6061 L``dfah/BL(|/cfdj/n/`zak/`i/mnl`a
X 436f6f6b696e67204d432773206c696b65206120706f756e64206f66206261636f6e Cooking MC's like a pound of bacon
Y 426e6e6a686f66214c422672216d686a64216021716e746f65216e67216360626e6f Bnnjhof!LB&r!mhjd!`!qntoe!ng!c`bno
Z 416d6d696b6c65224f412571226e6b6967226322726d776c66226d64226063616d6c Ammikle"OA%q"nkig"c"rmwlf"md"`caml
```

Our key was 'X' -> `X 436f6f6b696e67204d432773206c696b65206120706f756e64206f66206261636f6e Cooking MC's like a pound of bacon`

