# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\anton\Desktop\FSO-2022.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/flags.make

CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.obj: CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/flags.make
CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.obj: ../OPT_algoritmo_reposicao_paginas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\OPT_algoritmo_reposicao_paginas.dir\OPT_algoritmo_reposicao_paginas.c.obj -c C:\Users\anton\Desktop\FSO-2022.2\OPT_algoritmo_reposicao_paginas.c

CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\anton\Desktop\FSO-2022.2\OPT_algoritmo_reposicao_paginas.c > CMakeFiles\OPT_algoritmo_reposicao_paginas.dir\OPT_algoritmo_reposicao_paginas.c.i

CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\anton\Desktop\FSO-2022.2\OPT_algoritmo_reposicao_paginas.c -o CMakeFiles\OPT_algoritmo_reposicao_paginas.dir\OPT_algoritmo_reposicao_paginas.c.s

# Object files for target OPT_algoritmo_reposicao_paginas
OPT_algoritmo_reposicao_paginas_OBJECTS = \
"CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.obj"

# External object files for target OPT_algoritmo_reposicao_paginas
OPT_algoritmo_reposicao_paginas_EXTERNAL_OBJECTS =

OPT_algoritmo_reposicao_paginas.exe: CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/OPT_algoritmo_reposicao_paginas.c.obj
OPT_algoritmo_reposicao_paginas.exe: CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/build.make
OPT_algoritmo_reposicao_paginas.exe: CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/linklibs.rsp
OPT_algoritmo_reposicao_paginas.exe: CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/objects1.rsp
OPT_algoritmo_reposicao_paginas.exe: CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable OPT_algoritmo_reposicao_paginas.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OPT_algoritmo_reposicao_paginas.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/build: OPT_algoritmo_reposicao_paginas.exe
.PHONY : CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/build

CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OPT_algoritmo_reposicao_paginas.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/clean

CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\anton\Desktop\FSO-2022.2 C:\Users\anton\Desktop\FSO-2022.2 C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug\CMakeFiles\OPT_algoritmo_reposicao_paginas.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OPT_algoritmo_reposicao_paginas.dir/depend

