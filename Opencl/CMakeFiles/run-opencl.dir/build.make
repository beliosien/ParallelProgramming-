# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tmp/ParallelProgramming-/Opencl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tmp/ParallelProgramming-/Opencl

# Utility rule file for run-opencl.

# Include the progress variables for this target.
include CMakeFiles/run-opencl.dir/progress.make

CMakeFiles/run-opencl:
	time /home/tmp/ParallelProgramming-/Opencl/sample --directory /home/tmp/ParallelProgramming-/Opencl/data --method opencl

run-opencl: CMakeFiles/run-opencl
run-opencl: CMakeFiles/run-opencl.dir/build.make

.PHONY : run-opencl

# Rule to build all files generated by this target.
CMakeFiles/run-opencl.dir/build: run-opencl

.PHONY : CMakeFiles/run-opencl.dir/build

CMakeFiles/run-opencl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run-opencl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run-opencl.dir/clean

CMakeFiles/run-opencl.dir/depend:
	cd /home/tmp/ParallelProgramming-/Opencl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tmp/ParallelProgramming-/Opencl /home/tmp/ParallelProgramming-/Opencl /home/tmp/ParallelProgramming-/Opencl /home/tmp/ParallelProgramming-/Opencl /home/tmp/ParallelProgramming-/Opencl/CMakeFiles/run-opencl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run-opencl.dir/depend

