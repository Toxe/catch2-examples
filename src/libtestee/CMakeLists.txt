add_library(testee
    add.cpp
    mul.cpp
    sub.cpp
)

set_target_properties(testee PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(testee PUBLIC cxx_std_20)
target_compile_options(testee PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_link_libraries(testee PRIVATE ${SANITIZER_FLAGS})
target_include_directories(testee PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
