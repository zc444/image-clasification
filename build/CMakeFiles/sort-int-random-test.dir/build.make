# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/cmake/cmake-3.9.6/bin/cmake

# The command to remove a file.
RM = /opt/cmake/cmake-3.9.6/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zc444/ece2400/group07/pa5-sys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zc444/ece2400/group07/pa5-sys/build

# Include any dependencies generated for this target.
include CMakeFiles/sort-int-random-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort-int-random-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort-int-random-test.dir/flags.make

CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o: CMakeFiles/sort-int-random-test.dir/flags.make
CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o: ../test/sort-int-random-test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o -c /home/zc444/ece2400/group07/pa5-sys/test/sort-int-random-test.cc

CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/test/sort-int-random-test.cc > CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.i

CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/test/sort-int-random-test.cc -o CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.s

CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.requires:

.PHONY : CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.requires

CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.provides: CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.requires
	$(MAKE) -f CMakeFiles/sort-int-random-test.dir/build.make CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.provides.build
.PHONY : CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.provides

CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.provides.build: CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o


# Object files for target sort-int-random-test
sort__int__random__test_OBJECTS = \
"CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o"

# External object files for target sort-int-random-test
sort__int__random__test_EXTERNAL_OBJECTS =

sort-int-random-test: CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o
sort-int-random-test: CMakeFiles/sort-int-random-test.dir/build.make
sort-int-random-test: libpa5-sys.a
sort-int-random-test: CMakeFiles/sort-int-random-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sort-int-random-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort-int-random-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort-int-random-test.dir/build: sort-int-random-test

.PHONY : CMakeFiles/sort-int-random-test.dir/build

CMakeFiles/sort-int-random-test.dir/requires: CMakeFiles/sort-int-random-test.dir/test/sort-int-random-test.cc.o.requires

.PHONY : CMakeFiles/sort-int-random-test.dir/requires

CMakeFiles/sort-int-random-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort-int-random-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort-int-random-test.dir/clean

CMakeFiles/sort-int-random-test.dir/depend:
	cd /home/zc444/ece2400/group07/pa5-sys/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys/build /home/zc444/ece2400/group07/pa5-sys/build /home/zc444/ece2400/group07/pa5-sys/build/CMakeFiles/sort-int-random-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort-int-random-test.dir/depend

