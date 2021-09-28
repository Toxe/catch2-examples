add_executable(catch2v3_multiple_test_files main.cpp)

set_target_properties(catch2v3_multiple_test_files PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME multiple_test_files)
target_compile_features(catch2v3_multiple_test_files PUBLIC cxx_std_20)
target_compile_options(catch2v3_multiple_test_files PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_libraries(catch2v3_multiple_test_files PRIVATE ${SANITIZER_FLAGS} testee)

# Tests
if(BUILD_TESTING)
    set(ALL_TESTS
        catch2v3_test_add
        catch2v3_test_mul
        catch2v3_test_sub
    )

    add_executable(catch2v3_test_add add.test.cpp)
    add_executable(catch2v3_test_mul mul.test.cpp)
    add_executable(catch2v3_test_sub sub.test.cpp)

    foreach(target ${ALL_TESTS})
        set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
        target_compile_features(${target} PUBLIC cxx_std_20)
        target_compile_options(${target} PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
        target_link_libraries(${target} PRIVATE ${SANITIZER_FLAGS} testee Catch2::Catch2WithMain)

        add_test(NAME ${target} COMMAND ${target})
    endforeach()
endif()
