# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/lib/python2.7/site-packages/cmake/data/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python2.7/site-packages/cmake/data/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chris/Merge-Sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chris/Merge-Sort/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/MS-Lib.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/MS-Lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/MS-Lib.dir/flags.make

lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o: lib/CMakeFiles/MS-Lib.dir/flags.make
lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o: ../lib/ms_lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chris/Merge-Sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o"
	cd /Users/chris/Merge-Sort/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MS-Lib.dir/ms_lib.cpp.o -c /Users/chris/Merge-Sort/lib/ms_lib.cpp

lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MS-Lib.dir/ms_lib.cpp.i"
	cd /Users/chris/Merge-Sort/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chris/Merge-Sort/lib/ms_lib.cpp > CMakeFiles/MS-Lib.dir/ms_lib.cpp.i

lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MS-Lib.dir/ms_lib.cpp.s"
	cd /Users/chris/Merge-Sort/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chris/Merge-Sort/lib/ms_lib.cpp -o CMakeFiles/MS-Lib.dir/ms_lib.cpp.s

lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.requires:

.PHONY : lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.requires

lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.provides: lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/MS-Lib.dir/build.make lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.provides.build
.PHONY : lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.provides

lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.provides.build: lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o


# Object files for target MS-Lib
MS__Lib_OBJECTS = \
"CMakeFiles/MS-Lib.dir/ms_lib.cpp.o"

# External object files for target MS-Lib
MS__Lib_EXTERNAL_OBJECTS =

lib/libMS-Lib.a: lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o
lib/libMS-Lib.a: lib/CMakeFiles/MS-Lib.dir/build.make
lib/libMS-Lib.a: lib/CMakeFiles/MS-Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chris/Merge-Sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMS-Lib.a"
	cd /Users/chris/Merge-Sort/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/MS-Lib.dir/cmake_clean_target.cmake
	cd /Users/chris/Merge-Sort/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MS-Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/MS-Lib.dir/build: lib/libMS-Lib.a

.PHONY : lib/CMakeFiles/MS-Lib.dir/build

lib/CMakeFiles/MS-Lib.dir/requires: lib/CMakeFiles/MS-Lib.dir/ms_lib.cpp.o.requires

.PHONY : lib/CMakeFiles/MS-Lib.dir/requires

lib/CMakeFiles/MS-Lib.dir/clean:
	cd /Users/chris/Merge-Sort/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/MS-Lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/MS-Lib.dir/clean

lib/CMakeFiles/MS-Lib.dir/depend:
	cd /Users/chris/Merge-Sort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chris/Merge-Sort /Users/chris/Merge-Sort/lib /Users/chris/Merge-Sort/build /Users/chris/Merge-Sort/build/lib /Users/chris/Merge-Sort/build/lib/CMakeFiles/MS-Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/MS-Lib.dir/depend

