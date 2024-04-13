# microbench-cpp

Microbenchmark example in C++

### Dependencies

Requires https://bazel.build/ to be installed.

### Build

`bazel build //main:main -c opt`

### Run

`bazel run //main:main -c opt `

This will generate an output like the following:

```
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
BM_StringConcatV1     519933 ns       518423 ns         1000
BM_StringConcatV2    1717999 ns      1703354 ns          413
```


-----

https://github.com/pin3da https://gitlab.com/pin3da
