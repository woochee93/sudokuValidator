cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

add_executable(app main.cpp Sudoku.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)
add_compile_options(-lpthread -ggdb)
enable_testing()

add_executable(
  my_tests
  tests.cpp
  Sudoku.cpp
)
target_link_libraries(
  my_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_tests)