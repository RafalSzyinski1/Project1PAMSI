file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.cpp)

add_executable(TEST ${TEST_SOURCES})

enable_testing()
add_test(NAME TEST COMMAND TEST)
target_link_libraries(TEST PRIVATE ${PROJECT_LIB} gtest)