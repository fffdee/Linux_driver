# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bango/linux_driver/d1/key/key-input

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bango/linux_driver/d1/key/key-input/build

# Include any dependencies generated for this target.
include CMakeFiles/key_input_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/key_input_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/key_input_test.dir/flags.make

CMakeFiles/key_input_test.dir/key_input_test.c.o: CMakeFiles/key_input_test.dir/flags.make
CMakeFiles/key_input_test.dir/key_input_test.c.o: ../key_input_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bango/linux_driver/d1/key/key-input/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/key_input_test.dir/key_input_test.c.o"
	/home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/key_input_test.dir/key_input_test.c.o   -c /home/bango/linux_driver/d1/key/key-input/key_input_test.c

CMakeFiles/key_input_test.dir/key_input_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/key_input_test.dir/key_input_test.c.i"
	/home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bango/linux_driver/d1/key/key-input/key_input_test.c > CMakeFiles/key_input_test.dir/key_input_test.c.i

CMakeFiles/key_input_test.dir/key_input_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/key_input_test.dir/key_input_test.c.s"
	/home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bango/linux_driver/d1/key/key-input/key_input_test.c -o CMakeFiles/key_input_test.dir/key_input_test.c.s

# Object files for target key_input_test
key_input_test_OBJECTS = \
"CMakeFiles/key_input_test.dir/key_input_test.c.o"

# External object files for target key_input_test
key_input_test_EXTERNAL_OBJECTS =

key_input_test: CMakeFiles/key_input_test.dir/key_input_test.c.o
key_input_test: CMakeFiles/key_input_test.dir/build.make
key_input_test: CMakeFiles/key_input_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bango/linux_driver/d1/key/key-input/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable key_input_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/key_input_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/key_input_test.dir/build: key_input_test

.PHONY : CMakeFiles/key_input_test.dir/build

CMakeFiles/key_input_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/key_input_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/key_input_test.dir/clean

CMakeFiles/key_input_test.dir/depend:
	cd /home/bango/linux_driver/d1/key/key-input/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bango/linux_driver/d1/key/key-input /home/bango/linux_driver/d1/key/key-input /home/bango/linux_driver/d1/key/key-input/build /home/bango/linux_driver/d1/key/key-input/build /home/bango/linux_driver/d1/key/key-input/build/CMakeFiles/key_input_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/key_input_test.dir/depend

