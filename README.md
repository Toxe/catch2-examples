# Catch2 Examples

A couple of examples for structuring CMake projects using [Catch2](https://github.com/catchorg/Catch2),
either as a single header or as a statically compiled library (Catch2 v3). Compatible with CTest.

> Note: All of these are highly contrived examples. The code we are testing sits in a small library (`src/libtestee`) and usually the test files would/should be inside the same directory that contains the code itself. But for the purpose of these examples the test files are actually outside of that directory tree.

- [Build](#build)
- [`src/libtestee`](#srclibtestee)
- [Single Header Examples](#single-header-examples)
- [Catch2 v3 Examples](#catch2-v3-examples)
- [CTest](#ctest)
- [Build Performance Comparison](#build-performance-comparison)

## Build

Default build instructions for CMake.

#### Linux + Mac

```
$ mkdir build
$ cd build
$ cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
$ ninja
```

#### Windows

```
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
$ cmake --build . --config Debug
```

#### Disable Tests

Tests are enabled by default. To disable building tests set the CMake flag `BUILD_TESTING` to `OFF`:

```
$ cmake [..] -DBUILD_TESTING=OFF
```

#### Sanitizers and Static Analysis

The code can be compiled with sanitizer and static analysis support. Look here for the details: https://github.com/Toxe/cpp-sanitizers.
The test binaries themselves won't be build with sanitizer support.

#### Disable Building Catch2 v2 or v3 Examples

To prevent building Catch2 v2 or v3 examples set the CMake flags `DISABLE_CATCH2v2` or `DISABLE_CATCH2v3` to `ON`:

```
$ cmake [..] -DDISABLE_CATCH2v2=ON
```

## `src/libtestee`

A small library with some simple functions for testing. Just so that we don't repeat the code that we want to test in every example.

> Note: Usually the test files that test these functions would/should be inside this directory. But for the purpose of these examples the test files are outside of that directory tree.

## Single Header Examples

These example projects all include their own single header version of Catch2 v2.13.7.

### `src` `/` `single_header` `/` `multiple_test_files`

- Uses and includes the single header version of Catch2 v2.13.7.
- Multiple test files, one for each source file in `libtestee`.

```
$ ./build/src/single_header/multiple_test_files/multiple_test_files
Everything seems to be working.

$ ./build/src/single_header/multiple_test_files/single_header_test_add
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/single_header/multiple_test_files/single_header_test_mul
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/single_header/multiple_test_files/single_header_test_sub
===============================================================================
All tests passed (6 assertions in 1 test case)
```

### `src` `/` `single_header` `/` `single_test_file_one_source`

- Uses and includes the single header version of Catch2 v2.13.7.
- One big test file, containing multiple sections.

```
$ ./build/src/single_header/single_test_file_one_source/single_test_file_one_source
Everything seems to be working.

$ ./build/src/single_header/single_test_file_one_source/tests
===============================================================================
All tests passed (16 assertions in 1 test case)
```

### `src` `/` `single_header` `/` `single_test_file_multiple_sources`

- Uses and includes the single header version of Catch2 v2.13.7.
- One test file, combining multiple sources into one binary.

```
$ ./build/src/single_header/single_test_file_multiple_sources/single_test_file_multiple_sources
Everything seems to be working.

$ ./build/src/single_header/single_test_file_multiple_sources/tests
===============================================================================
All tests passed (16 assertions in 3 test cases)
```

## Catch2 v3 Examples

These example projects use the newest version of Catch2 v3 (`devel` branch) as a static library, which greatly increases compile time.
It is downloaded automatically from GitHub via CMake [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html).

### `src` `/` `catch2v3` `/` `multiple_test_files`

- Catch2 v3 static library.
- Multiple test files, one for each source file in `libtestee`.

```
$ ./build/src/catch2v3/multiple_test_files/multiple_test_files
Everything seems to be working.

$ ./build/src/catch2v3/multiple_test_files/catch2v3_test_add
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/catch2v3/multiple_test_files/catch2v3_test_mul
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/catch2v3/multiple_test_files/catch2v3_test_sub
===============================================================================
All tests passed (6 assertions in 1 test case)
```

### `src` `/` `catch2v3` `/` `single_test_file_one_source`

- Catch2 v3 static library.
- One big test file, containing multiple sections.

```
$ ./build/src/catch2v3/single_test_file_one_source/single_test_file_one_source
Everything seems to be working.

$ ./build/src/catch2v3/single_test_file_one_source/tests
===============================================================================
All tests passed (16 assertions in 1 test case)
```

### `src` `/` `catch2v3` `/` `single_test_file_multiple_sources`

- Catch2 v3 static library.
- One test file, combining multiple sources into one binary.

```
$ ./build/src/catch2v3/single_test_file_multiple_sources/single_test_file_multiple_sources
Everything seems to be working.

$ ./build/src/catch2v3/single_test_file_multiple_sources/tests
===============================================================================
All tests passed (16 assertions in 3 test cases)
```

## CTest

Either run each test file individually (see above) or with CTest.

```
$ cd build

$ ctest -N
Test project /home/toxe/Programmierung/catch2-examples/build
  Test  #1: single_header_test_add
  Test  #2: single_header_test_mul
  Test  #3: single_header_test_sub
  Test  #4: single_header_single_test_file_multiple_sources_tests
  Test  #5: single_header_single_test_file_one_source_tests
  Test  #6: catch2v3_test_add
  Test  #7: catch2v3_test_mul
  Test  #8: catch2v3_test_sub
  Test  #9: catch2v3_single_test_file_multiple_sources_tests
  Test #10: catch2v3_single_test_file_one_source_tests

Total Tests: 10

$ ctest
Test project /home/toxe/Programmierung/catch2-examples/build
      Start  1: single_header_test_add
 1/10 Test  #1: single_header_test_add ..................................   Passed    0.01 sec
      Start  2: single_header_test_mul
 2/10 Test  #2: single_header_test_mul ..................................   Passed    0.01 sec
      Start  3: single_header_test_sub
 3/10 Test  #3: single_header_test_sub ..................................   Passed    0.01 sec
      Start  4: single_header_single_test_file_multiple_sources_tests
 4/10 Test  #4: single_header_single_test_file_multiple_sources_tests ...   Passed    0.01 sec
      Start  5: single_header_single_test_file_one_source_tests
 5/10 Test  #5: single_header_single_test_file_one_source_tests .........   Passed    0.01 sec
      Start  6: catch2v3_test_add
 6/10 Test  #6: catch2v3_test_add .......................................   Passed    0.01 sec
      Start  7: catch2v3_test_mul
 7/10 Test  #7: catch2v3_test_mul .......................................   Passed    0.01 sec
      Start  8: catch2v3_test_sub
 8/10 Test  #8: catch2v3_test_sub .......................................   Passed    0.01 sec
      Start  9: catch2v3_single_test_file_multiple_sources_tests
 9/10 Test  #9: catch2v3_single_test_file_multiple_sources_tests ........   Passed    0.01 sec
      Start 10: catch2v3_single_test_file_one_source_tests
10/10 Test #10: catch2v3_single_test_file_one_source_tests ..............   Passed    0.01 sec

100% tests passed, 0 tests failed out of 10

Total Test time (real) =   0.09 sec
```

To run the tests in parallel:

```
$ ctest --progress -j8
Test project /home/toxe/Programmierung/catch2-examples/build
10/10 Test  #6: catch2v3_test_add
100% tests passed, 0 tests failed out of 10

Total Test time (real) =   0.02 sec
```

## Build Performance Comparison

Build environment:

- AMD Ryzen 9 3900X (12 cores)
- Ubuntu 21.04 running on WSL2 on Windows 10
- Clang 12 with LibC++
- Debug build

Times are measured either recompiling the whole project (including `libtestee`, the main programs, all the tests and in case of Catch2 v3 the static library)
or just rebuilding the test programs after their code has changed.

#### Catch2 v2 Single Header

Building only Catch2 v2 examples.

|               | ninja -j 1 | ninja -j 8 | ninja -j 26 |
| ------------- | ---------- | ---------- | ----------- |
| clean rebuild | 32.862 s   | 7.350 s    | 7.196 s     |
| only tests    | 30.857 s   | 7.094 s    | 6.816 s     |

#### Catch2 v3 Static Library

Building only Catch2 v3 examples.

|               | ninja -j 1 | ninja -j 8 | ninja -j 26 |
| ------------- | ---------- | ---------- | ----------- |
| clean rebuild | 43.332 s   | 6.839 s    | 3.703 s     |
| only tests    | 5.741 s    | 1.109 s    | 1.022 s     |
