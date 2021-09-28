cmake_minimum_required(VERSION 3.18)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("Catch2 Examples" LANGUAGES CXX)

# enable testing with CTest
include(CTest)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptionsAndWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

# Catch2 v3
if(NOT DISABLE_CATCH2v3)
    include(FetchContent)

    FetchContent_Declare(Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG devel)
    FetchContent_MakeAvailable(Catch2)
endif()

add_subdirectory(src/libtestee)

if(NOT DISABLE_CATCH2v2)
    add_subdirectory(src/single_header/multiple_test_files)
    add_subdirectory(src/single_header/single_test_file_multiple_sources)
    add_subdirectory(src/single_header/single_test_file_one_source)
endif()

if(NOT DISABLE_CATCH2v3)
    add_subdirectory(src/catch2v3/multiple_test_files)
    add_subdirectory(src/catch2v3/single_test_file_multiple_sources)
    add_subdirectory(src/catch2v3/single_test_file_one_source)
endif()
