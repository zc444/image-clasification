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

# Utility rule file for NightlyStart.

# Include the progress variables for this target.
include CMakeFiles/NightlyStart.dir/progress.make

CMakeFiles/NightlyStart:
	/opt/cmake/cmake-3.9.6/bin/ctest -D NightlyStart

NightlyStart: CMakeFiles/NightlyStart
NightlyStart: CMakeFiles/NightlyStart.dir/build.make

.PHONY : NightlyStart

# Rule to build all files generated by this target.
CMakeFiles/NightlyStart.dir/build: NightlyStart

.PHONY : CMakeFiles/NightlyStart.dir/build

CMakeFiles/NightlyStart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NightlyStart.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NightlyStart.dir/clean

CMakeFiles/NightlyStart.dir/depend:
	cd /home/zc444/ece2400/group07/pa5-sys/build-eval && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys/build-eval /home/zc444/ece2400/group07/pa5-sys/build-eval /home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles/NightlyStart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NightlyStart.dir/depend

