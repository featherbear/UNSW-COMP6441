---
title: "RSA Crypto"
date: 2019-06-18T18:15:55+10:00

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

> I wrote a little bit about public/private key crypto [here](../something-awesome-research-security)

---

If you consider the [Merkle puzzles](../merkle-puzzles), the key (pun not intended) takeaway is the work effort required.

For initial communication, the second party needs to crack the ID/key pair (let's say it takes a minute).  
After that initial time required, consequential message encryption and decryption will be fast.

To an attacker, however, if there are 10000 ID/key pairs - it will take them a long time (5000 tries on average).  
And at a rate of 1 ID/key pair per minute, that's 5000 minutes. 83 hours. _Three and a half days_.

If the ID/key pair was to change frequently - our poor attacker here is going to have a miserable time :(. Yess, secure!!

> The idea to gain from this is that, it is much more difficult and time consuming to brute force the correct details - especially when the key space is massively large.

---

_Trivia: RSA is short for Rivest-Shamir-Adleman, the trio of cryptographers who had 'invented' the algorithm in 1977._

RSA encryption takes hold of this work ratio notion

With public/private encryption, one key is used to encrypt a plaintext message, and another key is used to recover the plaintext message.  
This works because of fancy maths, which we'll look at now!

# Rationale

The basic principle that RSA uses, is the mathematical congruence  
![m^e^d === m (mod n)](https://wikimedia.org/api/rest_v1/media/math/render/svg/98b7f857d10d5b056d5db624bd3a475d2cb475cd)

That even if some terms are known, it is extremely difficult to determine the other unknown terms, as each change of value in a term may give a solution (albeit incorrect).  
Only by knowing the correct values (ie our private key) does finding the solution to the problem becamse feasible.

# Generating a key

1. Choose two different large prime numbers, `p` and `q` (and keep them safe)
2. Compute the term `n`, which will be used as the modulo value. `n = p x q`
3. Calculate Euler's totient (`ϕ`), which is used in the private key (keep it safe). `ϕ = p-1 x q-1`
4. Choose a prime number `e` smaller than `ϕ` which is co-prime with `ϕ`. (Not divisible by `ϕ`)
5. Chose a value `d` where `e x d mod ϕ = 1`

# Encrypting

- Public key has `e` and `n`
- We convert the message character into its ascii (ie `A = 65`)
- `c = m^e % n`

# Decrypting

- Private key has `d` and `n`
- `m = c^d % n`

---

![](./Snipaste_2019-06-19_01-19-31.png)

Note: This repetition doesn't happen in actual proper implementations (I think?)

---

As I had mentioned [before](../something-awesome-research-security), asymmetric key crypto is more resource intenseful than symmetric key crypto.  
So usually, RSA is used to securely exchange a symmetric key, rather than to actually be used for encrypting messages.

---

Links:

* http://comp6445-curlybracket-letsmakeflagsgreatagain-curlybracket.bid/challenges/rsa/rsa.html
* https://en.wikipedia.org/wiki/Public-key_cryptography
* https://www.nku.edu/~christensen/section%2026%20RSA.pdf
* https://people.csail.mit.edu/rivest/Rsapaper.pdf
* https://web.archive.org/web/20130829080627/http://doctrina.org/Why-RSA-Works-Three-Fundamental-Questions-Answered.html
* https://web.archive.org/web/20170602054430/https://www.cs.virginia.edu/~kam6zx/rsa/a-worked-example/
