# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Leepl\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Leepl\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Leepl\CLionProjects\BreakingBricks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Leepl\CLionProjects\BreakingBricks\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BreakingBricks.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BreakingBricks.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BreakingBricks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BreakingBricks.dir/flags.make

CMakeFiles/BreakingBricks.dir/main.c.obj: CMakeFiles/BreakingBricks.dir/flags.make
CMakeFiles/BreakingBricks.dir/main.c.obj: C:/Users/Leepl/CLionProjects/BreakingBricks/main.c
CMakeFiles/BreakingBricks.dir/main.c.obj: CMakeFiles/BreakingBricks.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Leepl\CLionProjects\BreakingBricks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BreakingBricks.dir/main.c.obj"
	C:\Users\Leepl\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BreakingBricks.dir/main.c.obj -MF CMakeFiles\BreakingBricks.dir\main.c.obj.d -o CMakeFiles\BreakingBricks.dir\main.c.obj -c C:\Users\Leepl\CLionProjects\BreakingBricks\main.c

CMakeFiles/BreakingBricks.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BreakingBricks.dir/main.c.i"
	C:\Users\Leepl\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Leepl\CLionProjects\BreakingBricks\main.c > CMakeFiles\BreakingBricks.dir\main.c.i

CMakeFiles/BreakingBricks.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BreakingBricks.dir/main.c.s"
	C:\Users\Leepl\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Leepl\CLionProjects\BreakingBricks\main.c -o CMakeFiles\BreakingBricks.dir\main.c.s

# Object files for target BreakingBricks
BreakingBricks_OBJECTS = \
"CMakeFiles/BreakingBricks.dir/main.c.obj"

# External object files for target BreakingBricks
BreakingBricks_EXTERNAL_OBJECTS =

BreakingBricks.exe: CMakeFiles/BreakingBricks.dir/main.c.obj
BreakingBricks.exe: CMakeFiles/BreakingBricks.dir/build.make
BreakingBricks.exe: CMakeFiles/BreakingBricks.dir/linkLibs.rsp
BreakingBricks.exe: CMakeFiles/BreakingBricks.dir/objects1.rsp
BreakingBricks.exe: CMakeFiles/BreakingBricks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Leepl\CLionProjects\BreakingBricks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BreakingBricks.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BreakingBricks.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BreakingBricks.dir/build: BreakingBricks.exe
.PHONY : CMakeFiles/BreakingBricks.dir/build

CMakeFiles/BreakingBricks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BreakingBricks.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BreakingBricks.dir/clean

CMakeFiles/BreakingBricks.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Leepl\CLionProjects\BreakingBricks C:\Users\Leepl\CLionProjects\BreakingBricks C:\Users\Leepl\CLionProjects\BreakingBricks\cmake-build-debug C:\Users\Leepl\CLionProjects\BreakingBricks\cmake-build-debug C:\Users\Leepl\CLionProjects\BreakingBricks\cmake-build-debug\CMakeFiles\BreakingBricks.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BreakingBricks.dir/depend

