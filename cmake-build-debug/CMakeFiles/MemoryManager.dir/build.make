# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ProjectsC\LabaOS\MemoryManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MemoryManager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MemoryManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MemoryManager.dir/flags.make

CMakeFiles/MemoryManager.dir/main.c.obj: CMakeFiles/MemoryManager.dir/flags.make
CMakeFiles/MemoryManager.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MemoryManager.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MemoryManager.dir\main.c.obj   -c D:\ProjectsC\LabaOS\MemoryManager\main.c

CMakeFiles/MemoryManager.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MemoryManager.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ProjectsC\LabaOS\MemoryManager\main.c > CMakeFiles\MemoryManager.dir\main.c.i

CMakeFiles/MemoryManager.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MemoryManager.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ProjectsC\LabaOS\MemoryManager\main.c -o CMakeFiles\MemoryManager.dir\main.c.s

CMakeFiles/MemoryManager.dir/main.c.obj.requires:

.PHONY : CMakeFiles/MemoryManager.dir/main.c.obj.requires

CMakeFiles/MemoryManager.dir/main.c.obj.provides: CMakeFiles/MemoryManager.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\MemoryManager.dir\build.make CMakeFiles/MemoryManager.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/MemoryManager.dir/main.c.obj.provides

CMakeFiles/MemoryManager.dir/main.c.obj.provides.build: CMakeFiles/MemoryManager.dir/main.c.obj


CMakeFiles/MemoryManager.dir/mmemory.c.obj: CMakeFiles/MemoryManager.dir/flags.make
CMakeFiles/MemoryManager.dir/mmemory.c.obj: ../mmemory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MemoryManager.dir/mmemory.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MemoryManager.dir\mmemory.c.obj   -c D:\ProjectsC\LabaOS\MemoryManager\mmemory.c

CMakeFiles/MemoryManager.dir/mmemory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MemoryManager.dir/mmemory.c.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ProjectsC\LabaOS\MemoryManager\mmemory.c > CMakeFiles\MemoryManager.dir\mmemory.c.i

CMakeFiles/MemoryManager.dir/mmemory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MemoryManager.dir/mmemory.c.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ProjectsC\LabaOS\MemoryManager\mmemory.c -o CMakeFiles\MemoryManager.dir\mmemory.c.s

CMakeFiles/MemoryManager.dir/mmemory.c.obj.requires:

.PHONY : CMakeFiles/MemoryManager.dir/mmemory.c.obj.requires

CMakeFiles/MemoryManager.dir/mmemory.c.obj.provides: CMakeFiles/MemoryManager.dir/mmemory.c.obj.requires
	$(MAKE) -f CMakeFiles\MemoryManager.dir\build.make CMakeFiles/MemoryManager.dir/mmemory.c.obj.provides.build
.PHONY : CMakeFiles/MemoryManager.dir/mmemory.c.obj.provides

CMakeFiles/MemoryManager.dir/mmemory.c.obj.provides.build: CMakeFiles/MemoryManager.dir/mmemory.c.obj


CMakeFiles/MemoryManager.dir/memory_area.c.obj: CMakeFiles/MemoryManager.dir/flags.make
CMakeFiles/MemoryManager.dir/memory_area.c.obj: ../memory_area.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MemoryManager.dir/memory_area.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MemoryManager.dir\memory_area.c.obj   -c D:\ProjectsC\LabaOS\MemoryManager\memory_area.c

CMakeFiles/MemoryManager.dir/memory_area.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MemoryManager.dir/memory_area.c.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\ProjectsC\LabaOS\MemoryManager\memory_area.c > CMakeFiles\MemoryManager.dir\memory_area.c.i

CMakeFiles/MemoryManager.dir/memory_area.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MemoryManager.dir/memory_area.c.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\ProjectsC\LabaOS\MemoryManager\memory_area.c -o CMakeFiles\MemoryManager.dir\memory_area.c.s

CMakeFiles/MemoryManager.dir/memory_area.c.obj.requires:

.PHONY : CMakeFiles/MemoryManager.dir/memory_area.c.obj.requires

CMakeFiles/MemoryManager.dir/memory_area.c.obj.provides: CMakeFiles/MemoryManager.dir/memory_area.c.obj.requires
	$(MAKE) -f CMakeFiles\MemoryManager.dir\build.make CMakeFiles/MemoryManager.dir/memory_area.c.obj.provides.build
.PHONY : CMakeFiles/MemoryManager.dir/memory_area.c.obj.provides

CMakeFiles/MemoryManager.dir/memory_area.c.obj.provides.build: CMakeFiles/MemoryManager.dir/memory_area.c.obj


# Object files for target MemoryManager
MemoryManager_OBJECTS = \
"CMakeFiles/MemoryManager.dir/main.c.obj" \
"CMakeFiles/MemoryManager.dir/mmemory.c.obj" \
"CMakeFiles/MemoryManager.dir/memory_area.c.obj"

# External object files for target MemoryManager
MemoryManager_EXTERNAL_OBJECTS =

MemoryManager.exe: CMakeFiles/MemoryManager.dir/main.c.obj
MemoryManager.exe: CMakeFiles/MemoryManager.dir/mmemory.c.obj
MemoryManager.exe: CMakeFiles/MemoryManager.dir/memory_area.c.obj
MemoryManager.exe: CMakeFiles/MemoryManager.dir/build.make
MemoryManager.exe: CMakeFiles/MemoryManager.dir/linklibs.rsp
MemoryManager.exe: CMakeFiles/MemoryManager.dir/objects1.rsp
MemoryManager.exe: CMakeFiles/MemoryManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable MemoryManager.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MemoryManager.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MemoryManager.dir/build: MemoryManager.exe

.PHONY : CMakeFiles/MemoryManager.dir/build

CMakeFiles/MemoryManager.dir/requires: CMakeFiles/MemoryManager.dir/main.c.obj.requires
CMakeFiles/MemoryManager.dir/requires: CMakeFiles/MemoryManager.dir/mmemory.c.obj.requires
CMakeFiles/MemoryManager.dir/requires: CMakeFiles/MemoryManager.dir/memory_area.c.obj.requires

.PHONY : CMakeFiles/MemoryManager.dir/requires

CMakeFiles/MemoryManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MemoryManager.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MemoryManager.dir/clean

CMakeFiles/MemoryManager.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ProjectsC\LabaOS\MemoryManager D:\ProjectsC\LabaOS\MemoryManager D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug D:\ProjectsC\LabaOS\MemoryManager\cmake-build-debug\CMakeFiles\MemoryManager.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MemoryManager.dir/depend

