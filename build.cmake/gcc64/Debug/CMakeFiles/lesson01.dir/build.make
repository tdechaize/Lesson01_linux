# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thierry/Sources/Opengl/Lesson01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thierry/Sources/Opengl/Lesson01/build.cmake/gcc64/Debug

# Include any dependencies generated for this target.
include CMakeFiles/lesson01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lesson01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lesson01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson01.dir/flags.make

CMakeFiles/lesson01.dir/src/lesson01.c.o: CMakeFiles/lesson01.dir/flags.make
CMakeFiles/lesson01.dir/src/lesson01.c.o: /home/thierry/Sources/Opengl/Lesson01/src/lesson01.c
CMakeFiles/lesson01.dir/src/lesson01.c.o: CMakeFiles/lesson01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thierry/Sources/Opengl/Lesson01/build.cmake/gcc64/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lesson01.dir/src/lesson01.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lesson01.dir/src/lesson01.c.o -MF CMakeFiles/lesson01.dir/src/lesson01.c.o.d -o CMakeFiles/lesson01.dir/src/lesson01.c.o -c /home/thierry/Sources/Opengl/Lesson01/src/lesson01.c

CMakeFiles/lesson01.dir/src/lesson01.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lesson01.dir/src/lesson01.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/thierry/Sources/Opengl/Lesson01/src/lesson01.c > CMakeFiles/lesson01.dir/src/lesson01.c.i

CMakeFiles/lesson01.dir/src/lesson01.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lesson01.dir/src/lesson01.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/thierry/Sources/Opengl/Lesson01/src/lesson01.c -o CMakeFiles/lesson01.dir/src/lesson01.c.s

# Object files for target lesson01
lesson01_OBJECTS = \
"CMakeFiles/lesson01.dir/src/lesson01.c.o"

# External object files for target lesson01
lesson01_EXTERNAL_OBJECTS =

/home/thierry/Sources/Opengl/Lesson01/bingcc64/Debug/lesson01.exe: CMakeFiles/lesson01.dir/src/lesson01.c.o
/home/thierry/Sources/Opengl/Lesson01/bingcc64/Debug/lesson01.exe: CMakeFiles/lesson01.dir/build.make
/home/thierry/Sources/Opengl/Lesson01/bingcc64/Debug/lesson01.exe: CMakeFiles/lesson01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thierry/Sources/Opengl/Lesson01/build.cmake/gcc64/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/thierry/Sources/Opengl/Lesson01/bingcc64/Debug/lesson01.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lesson01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson01.dir/build: /home/thierry/Sources/Opengl/Lesson01/bingcc64/Debug/lesson01.exe
.PHONY : CMakeFiles/lesson01.dir/build

CMakeFiles/lesson01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lesson01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lesson01.dir/clean

CMakeFiles/lesson01.dir/depend:
	cd /home/thierry/Sources/Opengl/Lesson01/build.cmake/gcc64/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thierry/Sources/Opengl/Lesson01 /home/thierry/Sources/Opengl/Lesson01 /home/thierry/Sources/Opengl/Lesson01/build.cmake/gcc64/Debug /home/thierry/Sources/Opengl/Lesson01/build.cmake/gcc64/Debug /home/thierry/Sources/Opengl/Lesson01/build.cmake/gcc64/Debug/CMakeFiles/lesson01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lesson01.dir/depend

