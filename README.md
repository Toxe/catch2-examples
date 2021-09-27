# Catch2 Examples

A couple of examples and tests for structuring CMake projects using [Catch2](https://github.com/catchorg/Catch2). Compatible with CTest.

> Note: All of these are highly contrived examples. The code we are testing is in a small library (`src/libtestee`) and usually the test files would/should be inside the same directory that contains the code itself. But for the purpose of these examples the test files are actually outside of that directory tree.

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

## `src/libtestee`

A small library with some simple functions for testing. Just so that we don't repeat the code that we want to test in every example.

> Note: Usually the test files that test these functions would/should be inside this directory. But for the purpose of these examples the test files are outside of that directory tree.

## Single Header Examples

These example projects all include their own single header version of Catch2 v2.13.7.

### `src` `/` `single_header` `/` `multiple_test_files`

- Uses and includes the single header version of Catch2 v2.13.7.
- Multiple test files, one for each source file in `libtestee`.

```
$ ./build/src/single_header/multiple_test_files/single_header_multiple_test_files
Everything seems to be working.

$ ./build/src/single_header/multiple_test_files/test_add
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/single_header/multiple_test_files/test_mul
===============================================================================
All tests passed (5 assertions in 1 test case)

$ ./build/src/single_header/multiple_test_files/test_sub
===============================================================================
All tests passed (6 assertions in 1 test case)
```

### `src` `/` `single_header` `/` `single_test_file_one_source`

- Uses and includes the single header version of Catch2 v2.13.7.
- One big test file, containing multiple sections.

```
$ ./build/src/single_header/single_test_file_one_source/single_header_single_test_file_one_source
Everything seems to be working.

$ ./build/src/single_header/single_test_file_one_source/tests
===============================================================================
All tests passed (16 assertions in 1 test case)
```

### `src` `/` `single_header` `/` `single_test_file_multiple_sources`

- Uses and includes the single header version of Catch2 v2.13.7.
- One test file, combining multiple sources into one binary.

```
$ ./build/src/single_header/single_test_file_multiple_sources/single_header_single_test_file_multiple_sources
Everything seems to be working.

$ ./build/src/single_header/single_test_file_multiple_sources/tests
===============================================================================
All tests passed (16 assertions in 3 test cases)
```

## CTest

You can either run each test file individually (see above) or run them with CTest.

```
$ cd build

$ ctest -N
Test project /home/toxe/Programmierung/catch2-examples/build
  Test #1: test_add
  Test #2: test_mul
  Test #3: test_sub
  Test #4: single_header_single_test_file_multiple_sources_tests
  Test #5: single_header_single_test_file_one_source_tests

Total Tests: 5

$ ctest
Test project /home/toxe/Programmierung/catch2-examples/build
    Start 1: test_add
1/5 Test #1: test_add ................................................   Passed    0.01 sec
    Start 2: test_mul
2/5 Test #2: test_mul ................................................   Passed    0.01 sec
    Start 3: test_sub
3/5 Test #3: test_sub ................................................   Passed    0.01 sec
    Start 4: single_header_single_test_file_multiple_sources_tests
4/5 Test #4: single_header_single_test_file_multiple_sources_tests ...   Passed    0.01 sec
    Start 5: single_header_single_test_file_one_source_tests
5/5 Test #5: single_header_single_test_file_one_source_tests .........   Passed    0.01 sec

100% tests passed, 0 tests failed out of 5

Total Test time (real) =   0.05 sec
```

To run the tests in parallel:

```
$ ctest --progress -j4
Test project /home/toxe/Programmierung/catch2-examples/build
5/5 Test #3: test_sub
100% tests passed, 0 tests failed out of 5

Total Test time (real) =   0.02 sec
```
