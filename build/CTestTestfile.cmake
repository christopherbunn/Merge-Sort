# CMake generated Testfile for 
# Source directory: /Users/chris/Merge-Sort
# Build directory: /Users/chris/Merge-Sort/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Backwards "COMMAND" "runUnitTests")
add_test(JustZero "COMMAND" "runUnitTests")
add_test(AllEights "COMMAND" "runUnitTests")
add_test(Empty "COMMAND" "runUnitTests")
subdirs("lib/gtest")
