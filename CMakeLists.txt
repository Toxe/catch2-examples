cmake_minimum_required(VERSION 3.18)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("Catch2 Examples" LANGUAGES CXX)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptionsAndWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

add_subdirectory(src/libtestee)
add_subdirectory(src/single_header/multiple_test_files)
add_subdirectory(src/single_header/single_test_file_multiple_sources)
add_subdirectory(src/single_header/single_test_file_one_source)
