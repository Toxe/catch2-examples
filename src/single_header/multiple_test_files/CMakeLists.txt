add_executable(single_header_multiple_test_files main.cpp)

set_target_properties(single_header_multiple_test_files PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME multiple_test_files)
target_compile_features(single_header_multiple_test_files PUBLIC cxx_std_20)
target_compile_options(single_header_multiple_test_files PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_libraries(single_header_multiple_test_files PRIVATE ${SANITIZER_FLAGS} testee)

# Tests
set(ALL_TESTS
    test_add
    test_mul
    test_sub
)

add_executable(test_add add.test.cpp)
add_executable(test_mul mul.test.cpp)
add_executable(test_sub sub.test.cpp)

foreach(target ${ALL_TESTS})
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${target} PUBLIC cxx_std_20)
    target_compile_options(${target} PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    target_link_libraries(${target} PRIVATE ${SANITIZER_FLAGS} testee)
endforeach()
