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
CMAKE_BINARY_DIR = /home/zc444/ece2400/group07/pa5-sys/build-eval

# Include any dependencies generated for this target.
include CMakeFiles/hrs-alternative2-directed-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hrs-alternative2-directed-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hrs-alternative2-directed-test.dir/flags.make

CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o: CMakeFiles/hrs-alternative2-directed-test.dir/flags.make
CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o: ../test/hrs-alternative2-directed-test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o -c /home/zc444/ece2400/group07/pa5-sys/test/hrs-alternative2-directed-test.cc

CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/test/hrs-alternative2-directed-test.cc > CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.i

CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/test/hrs-alternative2-directed-test.cc -o CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.s

CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.requires:

.PHONY : CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.requires

CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.provides: CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.requires
	$(MAKE) -f CMakeFiles/hrs-alternative2-directed-test.dir/build.make CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.provides.build
.PHONY : CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.provides

CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.provides.build: CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o


# Object files for target hrs-alternative2-directed-test
hrs__alternative2__directed__test_OBJECTS = \
"CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o"

# External object files for target hrs-alternative2-directed-test
hrs__alternative2__directed__test_EXTERNAL_OBJECTS =

hrs-alternative2-directed-test: CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o
hrs-alternative2-directed-test: CMakeFiles/hrs-alternative2-directed-test.dir/build.make
hrs-alternative2-directed-test: libpa5-sys.a
hrs-alternative2-directed-test: CMakeFiles/hrs-alternative2-directed-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hrs-alternative2-directed-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hrs-alternative2-directed-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hrs-alternative2-directed-test.dir/build: hrs-alternative2-directed-test

.PHONY : CMakeFiles/hrs-alternative2-directed-test.dir/build

CMakeFiles/hrs-alternative2-directed-test.dir/requires: CMakeFiles/hrs-alternative2-directed-test.dir/test/hrs-alternative2-directed-test.cc.o.requires

.PHONY : CMakeFiles/hrs-alternative2-directed-test.dir/requires

CMakeFiles/hrs-alternative2-directed-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hrs-alternative2-directed-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hrs-alternative2-directed-test.dir/clean

CMakeFiles/hrs-alternative2-directed-test.dir/depend:
	cd /home/zc444/ece2400/group07/pa5-sys/build-eval && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys/build-eval /home/zc444/ece2400/group07/pa5-sys/build-eval /home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles/hrs-alternative2-directed-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hrs-alternative2-directed-test.dir/depend
