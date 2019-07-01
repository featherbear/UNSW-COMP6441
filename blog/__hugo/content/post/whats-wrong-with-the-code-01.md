---
title: "What's Wrong With the Code - 01"
date: 2019-07-01T16:18:44+10:00

categories: ["Musings", "Extended Security"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---


```c
int read_data(int sockfd) {
  char buf[1024];
  unsigned short max = sizeof(buf);
  short length;
  
  length = get_network_short(sockfd);

  if (length > max) {
    error("bad length: %d\n", length);
    return 1;
  }
    
  if(read(sockfd, buf, length) < 0){
    error("read: %m");
    return 1;
  }

  ... process data ...

  return 0;
}
```

# What&apos;s wrong with the code?

On line 8, we have a comparison `length > max` which will return an error if the length of the data exceeds the buffer size.  
However, we are comparing an `unsigned short` to a `short`.  

If `get_network_short(sockfd)` (line 6) returns a value greater than `65535 / 2`, for example `32768`, then due to `length` being a `signed` variable the value stored will actually be negative.  
Upon comparison, we'll actually be comparing `-32768 > max`, which will always return `false`.  

Hence, the code to raise the bad length error will never be called!


