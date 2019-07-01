---
title: "What's Wrong With the Code - 02"
date: 2019-07-01T16:18:45+10:00

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
char *read_username(int sockfd) {
  char *buffer, *style, userstring[1024];
  int i;
  
  buffer = (char*) malloc(1024);
  
  if (!buffer) {
    error("buffer allocation failed: %m");
    return NULL;
  }

  if (read(sockfd, userstring, sizeof(userstring) - 1) <= 0) {
    free(buffer);
    error("read failure: %m");
    return NULL;
  }

  userstring[sizeof(userstring) - 1] = '\0';
  style = strchr(userstring, ':');
  
  if (style) *style++ = '\0';
  
  sprintf(buffer, "username=%.32s", userstring);
  
  if (style) snprintf(buffer, sizeof(buffer) - strlen(buffer) - 1, ", style=%s\n", style);

  return buffer;
}
```

# What&apos; wrong with the code?

_sizeof_.  

Consider the code
```c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  char *a = malloc(100);
  char b[100];

  printf("sizeof(a) is %d\n", sizeof(a));
  printf("sizeof(b) is %d\n", sizeof(b));
}
```

One might think that we'd get 100 and 100, but in fact...

```
sizeof(a) is 4
sizeof(b) is 100
```

**Note** - A pointer is 4 bytes on a 32-bit machine, but 8 bytes on a 64-bit machine!

With the exception of arrays of a staticly defined size - `sizeof` returns the size of the variable.  
In this case, the variable `a` is a pointer - not an array

So in running the code, these two lines will be problematic:

* Line 23: `sprintf(buffer, "username=%.32s", userstring);`
* Line 25: `if (style) snprintf(buffer, sizeof(buffer) - strlen(buffer) - 1, ", style=%s\n", style);`

