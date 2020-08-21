# ctime

`ctime` is a C/C++ library to provide functionality similar to Golang's `time` package. It is essentially a threadsafe wrapper around the `ctime` and `strftime` functions, allocating no memory. It reduces the amount of manual overhead that would be required if using the underlying `ctime` and `strftime` functions directly.

# features

* C support (C11)
* C++ support (C++11)
* Threadsafe
* Lightweight (zero allocations)