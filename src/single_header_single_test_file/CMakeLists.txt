add_executable(single_header_single_test_file main.cpp)

set_target_properties(single_header_single_test_file PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(single_header_single_test_file PUBLIC cxx_std_20)
target_compile_options(single_header_single_test_file PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_libraries(single_header_single_test_file PRIVATE ${SANITIZER_FLAGS} testee)

# Tests
add_executable(tests tests.cpp)

set_target_properties(tests PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(tests PUBLIC cxx_std_20)
target_compile_options(tests PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(tests PRIVATE ${SANITIZER_FLAGS} testee)
