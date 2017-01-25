cmake_minimum_required (VERSION 3.7.1)
project (Merge-Sort)

set (Merge-Sort_VERSION_MAJOR 1)
set (Merge-Sort_VERSION_MINOR 0)


include_directories(include)
file(GLOB SOURCES “src/.*.cpp”)

add_library(ms_lib ms_lib.cpp)
add_executable(Merge-Sort merge_sort.cpp)

target_link_libraries(Merge-Sort ms_lib)

################################
# Testing
################################
if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(lib/gtest)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests merge_sort_unittest.cpp)

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  target_link_libraries(runUnitTests ms_lib)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(Backwards COMMAND runUnitTests)

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  add_test(JustZero COMMAND runUnitTests)
  add_test(AllEights COMMAND runUnitTests)
  add_test(Empty COMMAND  runUnitTests)
endif()



