# z5206677 - Andrew Wong
# https://featherbear.github.io/UNSW-COMP6441/blog/post/plsdonthaq.me

import re
with open("shuffle.txt", "r") as f:
  lines = f.readlines()
  lines.sort(key=lambda s: int(re.search("(\d+)", s)[0]))
  with open("shuffle_solved.txt", "w") as ff:
    for line in lines:
      ff.write(re.sub("::\d+::","",line))
