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
CMAKE_BINARY_DIR = /home/tmp/ParallelProgramming-/Opencl/build

# Include any dependencies generated for this target.
include CMakeFiles/sample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample.dir/flags.make

CMakeFiles/sample.dir/source/main.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/main.cpp.o: ../source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sample.dir/source/main.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/source/main.cpp.o -c /home/tmp/ParallelProgramming-/Opencl/source/main.cpp

CMakeFiles/sample.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/source/main.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/main.cpp > CMakeFiles/sample.dir/source/main.cpp.i

CMakeFiles/sample.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/source/main.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/main.cpp -o CMakeFiles/sample.dir/source/main.cpp.s

CMakeFiles/sample.dir/source/opencl.c.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/opencl.c.o: ../source/opencl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sample.dir/source/opencl.c.o"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sample.dir/source/opencl.c.o   -c /home/tmp/ParallelProgramming-/Opencl/source/opencl.c

CMakeFiles/sample.dir/source/opencl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sample.dir/source/opencl.c.i"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/opencl.c > CMakeFiles/sample.dir/source/opencl.c.i

CMakeFiles/sample.dir/source/opencl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sample.dir/source/opencl.c.s"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/opencl.c -o CMakeFiles/sample.dir/source/opencl.c.s

CMakeFiles/sample.dir/source/image.c.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/image.c.o: ../source/image.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sample.dir/source/image.c.o"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sample.dir/source/image.c.o   -c /home/tmp/ParallelProgramming-/Opencl/source/image.c

CMakeFiles/sample.dir/source/image.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sample.dir/source/image.c.i"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/image.c > CMakeFiles/sample.dir/source/image.c.i

CMakeFiles/sample.dir/source/image.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sample.dir/source/image.c.s"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/image.c -o CMakeFiles/sample.dir/source/image.c.s

CMakeFiles/sample.dir/source/image-opencl.c.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/image-opencl.c.o: ../source/image-opencl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/sample.dir/source/image-opencl.c.o"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sample.dir/source/image-opencl.c.o   -c /home/tmp/ParallelProgramming-/Opencl/source/image-opencl.c

CMakeFiles/sample.dir/source/image-opencl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sample.dir/source/image-opencl.c.i"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/image-opencl.c > CMakeFiles/sample.dir/source/image-opencl.c.i

CMakeFiles/sample.dir/source/image-opencl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sample.dir/source/image-opencl.c.s"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/image-opencl.c -o CMakeFiles/sample.dir/source/image-opencl.c.s

CMakeFiles/sample.dir/source/texture.c.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/texture.c.o: ../source/texture.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/sample.dir/source/texture.c.o"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sample.dir/source/texture.c.o   -c /home/tmp/ParallelProgramming-/Opencl/source/texture.c

CMakeFiles/sample.dir/source/texture.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sample.dir/source/texture.c.i"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/texture.c > CMakeFiles/sample.dir/source/texture.c.i

CMakeFiles/sample.dir/source/texture.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sample.dir/source/texture.c.s"
	/bin/clang-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/texture.c -o CMakeFiles/sample.dir/source/texture.c.s

CMakeFiles/sample.dir/source/display.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/display.cpp.o: ../source/display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sample.dir/source/display.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/source/display.cpp.o -c /home/tmp/ParallelProgramming-/Opencl/source/display.cpp

CMakeFiles/sample.dir/source/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/source/display.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/display.cpp > CMakeFiles/sample.dir/source/display.cpp.i

CMakeFiles/sample.dir/source/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/source/display.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/display.cpp -o CMakeFiles/sample.dir/source/display.cpp.s

CMakeFiles/sample.dir/source/vertexBuffer.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/vertexBuffer.cpp.o: ../source/vertexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sample.dir/source/vertexBuffer.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/source/vertexBuffer.cpp.o -c /home/tmp/ParallelProgramming-/Opencl/source/vertexBuffer.cpp

CMakeFiles/sample.dir/source/vertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/source/vertexBuffer.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/vertexBuffer.cpp > CMakeFiles/sample.dir/source/vertexBuffer.cpp.i

CMakeFiles/sample.dir/source/vertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/source/vertexBuffer.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/vertexBuffer.cpp -o CMakeFiles/sample.dir/source/vertexBuffer.cpp.s

CMakeFiles/sample.dir/source/indexBuffer.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/indexBuffer.cpp.o: ../source/indexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sample.dir/source/indexBuffer.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/source/indexBuffer.cpp.o -c /home/tmp/ParallelProgramming-/Opencl/source/indexBuffer.cpp

CMakeFiles/sample.dir/source/indexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/source/indexBuffer.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/indexBuffer.cpp > CMakeFiles/sample.dir/source/indexBuffer.cpp.i

CMakeFiles/sample.dir/source/indexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/source/indexBuffer.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/indexBuffer.cpp -o CMakeFiles/sample.dir/source/indexBuffer.cpp.s

CMakeFiles/sample.dir/source/vertexArray.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/vertexArray.cpp.o: ../source/vertexArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sample.dir/source/vertexArray.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/source/vertexArray.cpp.o -c /home/tmp/ParallelProgramming-/Opencl/source/vertexArray.cpp

CMakeFiles/sample.dir/source/vertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/source/vertexArray.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/vertexArray.cpp > CMakeFiles/sample.dir/source/vertexArray.cpp.i

CMakeFiles/sample.dir/source/vertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/source/vertexArray.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/vertexArray.cpp -o CMakeFiles/sample.dir/source/vertexArray.cpp.s

CMakeFiles/sample.dir/source/shader.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/shader.cpp.o: ../source/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sample.dir/source/shader.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/source/shader.cpp.o -c /home/tmp/ParallelProgramming-/Opencl/source/shader.cpp

CMakeFiles/sample.dir/source/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/source/shader.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/shader.cpp > CMakeFiles/sample.dir/source/shader.cpp.i

CMakeFiles/sample.dir/source/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/source/shader.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/shader.cpp -o CMakeFiles/sample.dir/source/shader.cpp.s

CMakeFiles/sample.dir/source/renderer.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/source/renderer.cpp.o: ../source/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sample.dir/source/renderer.cpp.o"
	/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/source/renderer.cpp.o -c /home/tmp/ParallelProgramming-/Opencl/source/renderer.cpp

CMakeFiles/sample.dir/source/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/source/renderer.cpp.i"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tmp/ParallelProgramming-/Opencl/source/renderer.cpp > CMakeFiles/sample.dir/source/renderer.cpp.i

CMakeFiles/sample.dir/source/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/source/renderer.cpp.s"
	/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tmp/ParallelProgramming-/Opencl/source/renderer.cpp -o CMakeFiles/sample.dir/source/renderer.cpp.s

# Object files for target sample
sample_OBJECTS = \
"CMakeFiles/sample.dir/source/main.cpp.o" \
"CMakeFiles/sample.dir/source/opencl.c.o" \
"CMakeFiles/sample.dir/source/image.c.o" \
"CMakeFiles/sample.dir/source/image-opencl.c.o" \
"CMakeFiles/sample.dir/source/texture.c.o" \
"CMakeFiles/sample.dir/source/display.cpp.o" \
"CMakeFiles/sample.dir/source/vertexBuffer.cpp.o" \
"CMakeFiles/sample.dir/source/indexBuffer.cpp.o" \
"CMakeFiles/sample.dir/source/vertexArray.cpp.o" \
"CMakeFiles/sample.dir/source/shader.cpp.o" \
"CMakeFiles/sample.dir/source/renderer.cpp.o"

# External object files for target sample
sample_EXTERNAL_OBJECTS =

sample: CMakeFiles/sample.dir/source/main.cpp.o
sample: CMakeFiles/sample.dir/source/opencl.c.o
sample: CMakeFiles/sample.dir/source/image.c.o
sample: CMakeFiles/sample.dir/source/image-opencl.c.o
sample: CMakeFiles/sample.dir/source/texture.c.o
sample: CMakeFiles/sample.dir/source/display.cpp.o
sample: CMakeFiles/sample.dir/source/vertexBuffer.cpp.o
sample: CMakeFiles/sample.dir/source/indexBuffer.cpp.o
sample: CMakeFiles/sample.dir/source/vertexArray.cpp.o
sample: CMakeFiles/sample.dir/source/shader.cpp.o
sample: CMakeFiles/sample.dir/source/renderer.cpp.o
sample: CMakeFiles/sample.dir/build.make
sample: /usr/lib64/libOpenCL.so.1
sample: /usr/lib64/libOpenGL.so
sample: /usr/lib64/libGLX.so
sample: /usr/lib64/libGLU.so
sample: /usr/lib64/libglut.so
sample: /usr/lib64/libXmu.so
sample: /usr/lib64/libXi.so
sample: /usr/lib64/libGLEW.so
sample: /usr/lib64/libGLEW.so
sample: CMakeFiles/sample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable sample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample.dir/build: sample

.PHONY : CMakeFiles/sample.dir/build

CMakeFiles/sample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample.dir/clean

CMakeFiles/sample.dir/depend:
	cd /home/tmp/ParallelProgramming-/Opencl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tmp/ParallelProgramming-/Opencl /home/tmp/ParallelProgramming-/Opencl /home/tmp/ParallelProgramming-/Opencl/build /home/tmp/ParallelProgramming-/Opencl/build /home/tmp/ParallelProgramming-/Opencl/build/CMakeFiles/sample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample.dir/depend

