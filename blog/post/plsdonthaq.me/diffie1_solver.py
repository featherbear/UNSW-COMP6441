# z5206677 - Andrew Wong
# https://featherbear.github.io/UNSW-COMP6441/blog/post/plsdonthaq.me

import sys

b = int(sys.argv[1]) ## Enter the base here
m = int(sys.argv[2]) ## Enter the modulus here
p = int(sys.argv[3]) ## Enter public data

i = 0
while True:
  if (b ** i) % m == p:
    print("Secret is:", i)
    break
  i += 1
