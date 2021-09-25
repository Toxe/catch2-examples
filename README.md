# Catch2 Examples

A couple of examples on how to structure a CMake project using Catch2.

> Note: All of these are highly contrived examples. The code we are testing is in a small library (`src/libtestee`) and usually the test files would/should be inside the same directory that contains the code itself. But for the purpose of examples the test files are actually outside of that directory tree.

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

- Uses and includes the single header version of Catch2 v2.13.7.
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

### `src/single_header_single_test_file`

- Uses and includes the single header version of Catch2 v2.13.7.
- One test file, containing of multiple sections.

#### Run

```
$ ./build/src/single_header_single_test_file/single_header_single_test_file
Everything seems to be working.

$ ./build/src/single_header_single_test_file/tests
===============================================================================
All tests passed (16 assertions in 1 test case)
```
