add_executable(catch2v3_single_test_file_one_source main.cpp)

set_target_properties(catch2v3_single_test_file_one_source PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME single_test_file_one_source)
target_compile_features(catch2v3_single_test_file_one_source PUBLIC cxx_std_20)
target_compile_options(catch2v3_single_test_file_one_source PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_libraries(catch2v3_single_test_file_one_source PRIVATE ${SANITIZER_FLAGS} testee)

# Tests
if(BUILD_TESTING)
    add_executable(catch2v3_single_test_file_one_source_tests tests.cpp)

    set_target_properties(catch2v3_single_test_file_one_source_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(catch2v3_single_test_file_one_source_tests PUBLIC cxx_std_20)
    target_compile_options(catch2v3_single_test_file_one_source_tests PRIVATE ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_link_libraries(catch2v3_single_test_file_one_source_tests PRIVATE testee Catch2::Catch2WithMain)

    add_test(NAME catch2v3_single_test_file_one_source_tests COMMAND catch2v3_single_test_file_one_source_tests)
endif()
