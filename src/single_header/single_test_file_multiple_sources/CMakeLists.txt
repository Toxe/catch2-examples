add_executable(single_header_single_test_file_multiple_sources main.cpp)

set_target_properties(single_header_single_test_file_multiple_sources PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME single_test_file_multiple_sources)
target_compile_features(single_header_single_test_file_multiple_sources PUBLIC cxx_std_20)
target_compile_options(single_header_single_test_file_multiple_sources PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_libraries(single_header_single_test_file_multiple_sources PRIVATE ${SANITIZER_FLAGS} testee)

# Tests
if(BUILD_TESTING)
    add_executable(single_header_single_test_file_multiple_sources_tests
        tests.cpp
        add.test.cpp
        mul.test.cpp
        sub.test.cpp
    )

    set_target_properties(single_header_single_test_file_multiple_sources_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(single_header_single_test_file_multiple_sources_tests PUBLIC cxx_std_20)
    target_compile_options(single_header_single_test_file_multiple_sources_tests PRIVATE ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_include_directories(single_header_single_test_file_multiple_sources_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    target_link_libraries(single_header_single_test_file_multiple_sources_tests PRIVATE testee)

    add_test(NAME single_header_single_test_file_multiple_sources_tests COMMAND single_header_single_test_file_multiple_sources_tests)
endif()
