# Catch2 Examples

## Build

Default build instructions for CMake.

### Linux + Mac

```
$ mkdir build
$ cd build
$ cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
$ ninja
```

### Windows

```
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
$ cmake --build . --config Debug
```

## Examples

### `src/libtestee`

A small library with some simple functions for testing.

### `src/single_header_multiple_test_files`

- Uses single header version of Catch2 v2.13.7.
- Multiple test files, one for each source file in `libtestee`.

#### Run

```
$ ./build/src/single_header_multiple_test_files/single_header_multiple_test_files
Everything seems to be working.

$ ./build/src/single_header_multiple_test_files/test_add
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/single_header_multiple_test_files/test_mul
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/single_header_multiple_test_files/test_sub
===============================================================================
All tests passed (6 assertions in 1 test case)

```
