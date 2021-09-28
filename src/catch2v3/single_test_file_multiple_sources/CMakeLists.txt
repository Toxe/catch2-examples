add_executable(catch2v3_single_test_file_multiple_sources main.cpp)

set_target_properties(catch2v3_single_test_file_multiple_sources PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME single_test_file_multiple_sources)
target_compile_features(catch2v3_single_test_file_multiple_sources PUBLIC cxx_std_20)
target_compile_options(catch2v3_single_test_file_multiple_sources PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_libraries(catch2v3_single_test_file_multiple_sources PRIVATE ${SANITIZER_FLAGS} testee)

# Tests
if(BUILD_TESTING)
    add_executable(catch2v3_single_test_file_multiple_sources_tests
        add.test.cpp
        mul.test.cpp
        sub.test.cpp
    )

    set_target_properties(catch2v3_single_test_file_multiple_sources_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(catch2v3_single_test_file_multiple_sources_tests PUBLIC cxx_std_20)
    target_compile_options(catch2v3_single_test_file_multiple_sources_tests PRIVATE ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_link_libraries(catch2v3_single_test_file_multiple_sources_tests PRIVATE testee Catch2::Catch2WithMain)

    add_test(NAME catch2v3_single_test_file_multiple_sources_tests COMMAND catch2v3_single_test_file_multiple_sources_tests)
endif()
