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
CMAKE_SOURCE_DIR = /home/david/setr-tp5/serveur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/setr-tp5/serveur/build

# Include any dependencies generated for this target.
include CMakeFiles/tp5bluetooth.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tp5bluetooth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tp5bluetooth.dir/flags.make

CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.o: CMakeFiles/tp5bluetooth.dir/flags.make
CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.o: ../Bluetooth_Server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/setr-tp5/serveur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.o"
	/home/david/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/bin/arm-raspbian-linux-gnueabihf-gcc --sysroot=/home/david/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/arm-raspbian-linux-gnueabihf/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.o   -c /home/david/setr-tp5/serveur/Bluetooth_Server.c

CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.i"
	/home/david/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/bin/arm-raspbian-linux-gnueabihf-gcc --sysroot=/home/david/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/arm-raspbian-linux-gnueabihf/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/david/setr-tp5/serveur/Bluetooth_Server.c > CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.i

CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.s"
	/home/david/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/bin/arm-raspbian-linux-gnueabihf-gcc --sysroot=/home/david/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/arm-raspbian-linux-gnueabihf/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/david/setr-tp5/serveur/Bluetooth_Server.c -o CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.s

# Object files for target tp5bluetooth
tp5bluetooth_OBJECTS = \
"CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.o"

# External object files for target tp5bluetooth
tp5bluetooth_EXTERNAL_OBJECTS =

tp5bluetooth: CMakeFiles/tp5bluetooth.dir/Bluetooth_Server.c.o
tp5bluetooth: CMakeFiles/tp5bluetooth.dir/build.make
tp5bluetooth: CMakeFiles/tp5bluetooth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/setr-tp5/serveur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable tp5bluetooth"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tp5bluetooth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tp5bluetooth.dir/build: tp5bluetooth

.PHONY : CMakeFiles/tp5bluetooth.dir/build

CMakeFiles/tp5bluetooth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tp5bluetooth.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tp5bluetooth.dir/clean

CMakeFiles/tp5bluetooth.dir/depend:
	cd /home/david/setr-tp5/serveur/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/setr-tp5/serveur /home/david/setr-tp5/serveur /home/david/setr-tp5/serveur/build /home/david/setr-tp5/serveur/build /home/david/setr-tp5/serveur/build/CMakeFiles/tp5bluetooth.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tp5bluetooth.dir/depend

