# ctime

Is basically a wrapper around the `ctime` and other time related functions. It is intended to give utility functions similar to the Golang `time` package. It doesn't allocate any memory internally and requires user-supplied buffers for storing formatted data. It is suitable for use in C/C++ projects

# features

* C11 compatible