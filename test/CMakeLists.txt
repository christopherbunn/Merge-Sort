
################################
# Testing
################################
#if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(../lib/gtest ${CMAKE_CURRENT_BINARY_DIR}/build)
  add_library(MS-Lib ../lib/ms_lib.cpp)

  #enable_testing()

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
  target_link_libraries(runUnitTests MS-Lib)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(Backwards COMMAND runUnitTests)
  add_test(JustZero COMMAND runUnitTests)
  add_test(AllEights COMMAND runUnitTests)
  add_test(Empty COMMAND  runUnitTests)
  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  add_test (NAME runUnitTests COMMAND test)

#endif()



