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

# Utility rule file for memcheck.

# Include the progress variables for this target.
include CMakeFiles/memcheck.dir/progress.make

CMakeFiles/memcheck:
	/opt/cmake/cmake-3.9.6/bin/ctest --test-action memcheck --timeout 700

memcheck: CMakeFiles/memcheck
memcheck: CMakeFiles/memcheck.dir/build.make

.PHONY : memcheck

# Rule to build all files generated by this target.
CMakeFiles/memcheck.dir/build: memcheck

.PHONY : CMakeFiles/memcheck.dir/build

CMakeFiles/memcheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memcheck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memcheck.dir/clean

CMakeFiles/memcheck.dir/depend:
	cd /home/zc444/ece2400/group07/pa5-sys/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys/build /home/zc444/ece2400/group07/pa5-sys/build /home/zc444/ece2400/group07/pa5-sys/build/CMakeFiles/memcheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memcheck.dir/depend

