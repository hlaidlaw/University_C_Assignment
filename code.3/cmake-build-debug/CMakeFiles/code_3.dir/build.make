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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/code_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/code_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/code_3.dir/flags.make

CMakeFiles/code_3.dir/main.c.o: CMakeFiles/code_3.dir/flags.make
CMakeFiles/code_3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/code_3.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/code_3.dir/main.c.o   -c "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/main.c"

CMakeFiles/code_3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/code_3.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/main.c" > CMakeFiles/code_3.dir/main.c.i

CMakeFiles/code_3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/code_3.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/main.c" -o CMakeFiles/code_3.dir/main.c.s

CMakeFiles/code_3.dir/functions.c.o: CMakeFiles/code_3.dir/flags.make
CMakeFiles/code_3.dir/functions.c.o: ../functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/code_3.dir/functions.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/code_3.dir/functions.c.o   -c "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/functions.c"

CMakeFiles/code_3.dir/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/code_3.dir/functions.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/functions.c" > CMakeFiles/code_3.dir/functions.c.i

CMakeFiles/code_3.dir/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/code_3.dir/functions.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/functions.c" -o CMakeFiles/code_3.dir/functions.c.s

CMakeFiles/code_3.dir/generateMovements.c.o: CMakeFiles/code_3.dir/flags.make
CMakeFiles/code_3.dir/generateMovements.c.o: ../generateMovements.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/code_3.dir/generateMovements.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/code_3.dir/generateMovements.c.o   -c "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/generateMovements.c"

CMakeFiles/code_3.dir/generateMovements.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/code_3.dir/generateMovements.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/generateMovements.c" > CMakeFiles/code_3.dir/generateMovements.c.i

CMakeFiles/code_3.dir/generateMovements.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/code_3.dir/generateMovements.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/generateMovements.c" -o CMakeFiles/code_3.dir/generateMovements.c.s

CMakeFiles/code_3.dir/ExtensionFeature.c.o: CMakeFiles/code_3.dir/flags.make
CMakeFiles/code_3.dir/ExtensionFeature.c.o: ../ExtensionFeature.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/code_3.dir/ExtensionFeature.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/code_3.dir/ExtensionFeature.c.o   -c "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/ExtensionFeature.c"

CMakeFiles/code_3.dir/ExtensionFeature.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/code_3.dir/ExtensionFeature.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/ExtensionFeature.c" > CMakeFiles/code_3.dir/ExtensionFeature.c.i

CMakeFiles/code_3.dir/ExtensionFeature.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/code_3.dir/ExtensionFeature.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/ExtensionFeature.c" -o CMakeFiles/code_3.dir/ExtensionFeature.c.s

CMakeFiles/code_3.dir/mainFunction.c.o: CMakeFiles/code_3.dir/flags.make
CMakeFiles/code_3.dir/mainFunction.c.o: ../mainFunction.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/code_3.dir/mainFunction.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/code_3.dir/mainFunction.c.o   -c "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/mainFunction.c"

CMakeFiles/code_3.dir/mainFunction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/code_3.dir/mainFunction.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/mainFunction.c" > CMakeFiles/code_3.dir/mainFunction.c.i

CMakeFiles/code_3.dir/mainFunction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/code_3.dir/mainFunction.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/mainFunction.c" -o CMakeFiles/code_3.dir/mainFunction.c.s

# Object files for target code_3
code_3_OBJECTS = \
"CMakeFiles/code_3.dir/main.c.o" \
"CMakeFiles/code_3.dir/functions.c.o" \
"CMakeFiles/code_3.dir/generateMovements.c.o" \
"CMakeFiles/code_3.dir/ExtensionFeature.c.o" \
"CMakeFiles/code_3.dir/mainFunction.c.o"

# External object files for target code_3
code_3_EXTERNAL_OBJECTS =

code_3: CMakeFiles/code_3.dir/main.c.o
code_3: CMakeFiles/code_3.dir/functions.c.o
code_3: CMakeFiles/code_3.dir/generateMovements.c.o
code_3: CMakeFiles/code_3.dir/ExtensionFeature.c.o
code_3: CMakeFiles/code_3.dir/mainFunction.c.o
code_3: CMakeFiles/code_3.dir/build.make
code_3: CMakeFiles/code_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable code_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/code_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/code_3.dir/build: code_3

.PHONY : CMakeFiles/code_3.dir/build

CMakeFiles/code_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/code_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/code_3.dir/clean

CMakeFiles/code_3.dir/depend:
	cd "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3" "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3" "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug" "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug" "/Users/hannahlaidlaw/BT Cloud/HANNAH/Aberyswtwyth/Second Year/CS23820 - C and C ++/Main Assignment/TOSUBMIT/code.3/cmake-build-debug/CMakeFiles/code_3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/code_3.dir/depend

