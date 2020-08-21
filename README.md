# ctime

`ctime` is a C/C++ library to provide functionality similar to Golang's `time` package. It is essentially a threadsafe wrapper around the `ctime` and `strftime` functions, allocating no memory. It reduces the amount of manual overhead that would be required if using the underlying `ctime` and `strftime` functions directly.

# features

* C support (C11)
* C++ support (C++11)
* Threadsafe
* Lightweight (zero allocations)
* Dependency free

# usage


## unix timestamp (seconds)

```C
#include "ctime.h"

int unix_time = ctime_unix();

// 159797839
printf("%d\n", unix_time);
```

## unix tiemstamp (nanoseconds)

```C
#include "ctime.h"

long int unix_time_ns = ctime_unix_nano();

// 1597978391673755711
printf("%li\n", unix_time_ns);
```

## year month date timestamp

```C
#include "ctime.h"

char output[128];
memset(output, 0, 128);
ctime_ymd(output, 128);

// 2020-08-20
printf("%s\n", output);
```

## standard timestamp

```C
#include "ctime.h"

char output[128];
memset(output, 0, 128);
ctime_std(output, 128);

//  Thu Aug 20 19:53:11 2020
printf("%s\n", output);
```