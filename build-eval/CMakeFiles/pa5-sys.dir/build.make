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
include CMakeFiles/pa5-sys.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pa5-sys.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pa5-sys.dir/flags.make

CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o: ../src/ece2400-stdlib.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/ece2400-stdlib.cc

CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/ece2400-stdlib.cc > CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.i

CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/ece2400-stdlib.cc -o CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.s

CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.requires

CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.provides: CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.provides

CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o


CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o: ../src/mnist-utils.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/mnist-utils.cc

CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/mnist-utils.cc > CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.i

CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/mnist-utils.cc -o CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.s

CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.requires

CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.provides: CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.provides

CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o


CMakeFiles/pa5-sys.dir/src/Image.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/Image.cc.o: ../src/Image.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pa5-sys.dir/src/Image.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/Image.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/Image.cc

CMakeFiles/pa5-sys.dir/src/Image.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/Image.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/Image.cc > CMakeFiles/pa5-sys.dir/src/Image.cc.i

CMakeFiles/pa5-sys.dir/src/Image.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/Image.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/Image.cc -o CMakeFiles/pa5-sys.dir/src/Image.cc.s

CMakeFiles/pa5-sys.dir/src/Image.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/Image.cc.o.requires

CMakeFiles/pa5-sys.dir/src/Image.cc.o.provides: CMakeFiles/pa5-sys.dir/src/Image.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/Image.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/Image.cc.o.provides

CMakeFiles/pa5-sys.dir/src/Image.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/Image.cc.o


CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o: ../src/HRSLinearSearch.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/HRSLinearSearch.cc

CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/HRSLinearSearch.cc > CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.i

CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/HRSLinearSearch.cc -o CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.s

CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.requires

CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.provides: CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.provides

CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o


CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o: ../src/HRSBinarySearch.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/HRSBinarySearch.cc

CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/HRSBinarySearch.cc > CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.i

CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/HRSBinarySearch.cc -o CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.s

CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.requires

CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.provides: CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.provides

CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o


CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o: ../src/HRSTreeSearch.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/HRSTreeSearch.cc

CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/HRSTreeSearch.cc > CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.i

CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/HRSTreeSearch.cc -o CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.s

CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.requires

CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.provides: CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.provides

CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o


CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o: ../src/HRSTableSearch.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/HRSTableSearch.cc

CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/HRSTableSearch.cc > CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.i

CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/HRSTableSearch.cc -o CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.s

CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.requires

CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.provides: CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.provides

CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o


CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o: ../src/HRSAlternative.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/HRSAlternative.cc

CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/HRSAlternative.cc > CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.i

CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/HRSAlternative.cc -o CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.s

CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.requires

CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.provides: CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.provides

CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o


CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o: CMakeFiles/pa5-sys.dir/flags.make
CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o: ../src/HRSAlterative2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o -c /home/zc444/ece2400/group07/pa5-sys/src/HRSAlterative2.cc

CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zc444/ece2400/group07/pa5-sys/src/HRSAlterative2.cc > CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.i

CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zc444/ece2400/group07/pa5-sys/src/HRSAlterative2.cc -o CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.s

CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.requires:

.PHONY : CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.requires

CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.provides: CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.requires
	$(MAKE) -f CMakeFiles/pa5-sys.dir/build.make CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.provides.build
.PHONY : CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.provides

CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.provides.build: CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o


# Object files for target pa5-sys
pa5__sys_OBJECTS = \
"CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o" \
"CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o" \
"CMakeFiles/pa5-sys.dir/src/Image.cc.o" \
"CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o" \
"CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o" \
"CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o" \
"CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o" \
"CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o" \
"CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o"

# External object files for target pa5-sys
pa5__sys_EXTERNAL_OBJECTS =

libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/Image.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o
libpa5-sys.a: CMakeFiles/pa5-sys.dir/build.make
libpa5-sys.a: CMakeFiles/pa5-sys.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libpa5-sys.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pa5-sys.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pa5-sys.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pa5-sys.dir/build: libpa5-sys.a

.PHONY : CMakeFiles/pa5-sys.dir/build

CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/ece2400-stdlib.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/mnist-utils.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/Image.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/HRSLinearSearch.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/HRSBinarySearch.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/HRSTreeSearch.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/HRSTableSearch.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/HRSAlternative.cc.o.requires
CMakeFiles/pa5-sys.dir/requires: CMakeFiles/pa5-sys.dir/src/HRSAlterative2.cc.o.requires

.PHONY : CMakeFiles/pa5-sys.dir/requires

CMakeFiles/pa5-sys.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pa5-sys.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pa5-sys.dir/clean

CMakeFiles/pa5-sys.dir/depend:
	cd /home/zc444/ece2400/group07/pa5-sys/build-eval && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys /home/zc444/ece2400/group07/pa5-sys/build-eval /home/zc444/ece2400/group07/pa5-sys/build-eval /home/zc444/ece2400/group07/pa5-sys/build-eval/CMakeFiles/pa5-sys.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pa5-sys.dir/depend
