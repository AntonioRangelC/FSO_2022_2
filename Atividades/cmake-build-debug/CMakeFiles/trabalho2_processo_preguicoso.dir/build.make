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
include CMakeFiles/trabalho2_processo_preguicoso.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/trabalho2_processo_preguicoso.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trabalho2_processo_preguicoso.dir/flags.make

CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.obj: CMakeFiles/trabalho2_processo_preguicoso.dir/flags.make
CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.obj: ../trabalho2_processo_preguicoso.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\trabalho2_processo_preguicoso.dir\trabalho2_processo_preguicoso.c.obj -c C:\Users\anton\Desktop\FSO-2022.2\trabalho2_processo_preguicoso.c

CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\anton\Desktop\FSO-2022.2\trabalho2_processo_preguicoso.c > CMakeFiles\trabalho2_processo_preguicoso.dir\trabalho2_processo_preguicoso.c.i

CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\anton\Desktop\FSO-2022.2\trabalho2_processo_preguicoso.c -o CMakeFiles\trabalho2_processo_preguicoso.dir\trabalho2_processo_preguicoso.c.s

# Object files for target trabalho2_processo_preguicoso
trabalho2_processo_preguicoso_OBJECTS = \
"CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.obj"

# External object files for target trabalho2_processo_preguicoso
trabalho2_processo_preguicoso_EXTERNAL_OBJECTS =

trabalho2_processo_preguicoso.exe: CMakeFiles/trabalho2_processo_preguicoso.dir/trabalho2_processo_preguicoso.c.obj
trabalho2_processo_preguicoso.exe: CMakeFiles/trabalho2_processo_preguicoso.dir/build.make
trabalho2_processo_preguicoso.exe: CMakeFiles/trabalho2_processo_preguicoso.dir/linklibs.rsp
trabalho2_processo_preguicoso.exe: CMakeFiles/trabalho2_processo_preguicoso.dir/objects1.rsp
trabalho2_processo_preguicoso.exe: CMakeFiles/trabalho2_processo_preguicoso.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable trabalho2_processo_preguicoso.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\trabalho2_processo_preguicoso.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trabalho2_processo_preguicoso.dir/build: trabalho2_processo_preguicoso.exe
.PHONY : CMakeFiles/trabalho2_processo_preguicoso.dir/build

CMakeFiles/trabalho2_processo_preguicoso.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\trabalho2_processo_preguicoso.dir\cmake_clean.cmake
.PHONY : CMakeFiles/trabalho2_processo_preguicoso.dir/clean

CMakeFiles/trabalho2_processo_preguicoso.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\anton\Desktop\FSO-2022.2 C:\Users\anton\Desktop\FSO-2022.2 C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug C:\Users\anton\Desktop\FSO-2022.2\cmake-build-debug\CMakeFiles\trabalho2_processo_preguicoso.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trabalho2_processo_preguicoso.dir/depend

