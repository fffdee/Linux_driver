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
CMAKE_SOURCE_DIR = /home/bango/linux_driver/d1/dth11U

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bango/linux_driver/d1/dth11U/build

# Include any dependencies generated for this target.
include CMakeFiles/dth11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dth11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dth11.dir/flags.make

CMakeFiles/dth11.dir/dth11.c.o: CMakeFiles/dth11.dir/flags.make
CMakeFiles/dth11.dir/dth11.c.o: ../dth11.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bango/linux_driver/d1/dth11U/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dth11.dir/dth11.c.o"
	/home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dth11.dir/dth11.c.o   -c /home/bango/linux_driver/d1/dth11U/dth11.c

CMakeFiles/dth11.dir/dth11.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dth11.dir/dth11.c.i"
	/home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bango/linux_driver/d1/dth11U/dth11.c > CMakeFiles/dth11.dir/dth11.c.i

CMakeFiles/dth11.dir/dth11.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dth11.dir/dth11.c.s"
	/home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bango/linux_driver/d1/dth11U/dth11.c -o CMakeFiles/dth11.dir/dth11.c.s

# Object files for target dth11
dth11_OBJECTS = \
"CMakeFiles/dth11.dir/dth11.c.o"

# External object files for target dth11
dth11_EXTERNAL_OBJECTS =

dth11: CMakeFiles/dth11.dir/dth11.c.o
dth11: CMakeFiles/dth11.dir/build.make
dth11: CMakeFiles/dth11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bango/linux_driver/d1/dth11U/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dth11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dth11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dth11.dir/build: dth11

.PHONY : CMakeFiles/dth11.dir/build

CMakeFiles/dth11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dth11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dth11.dir/clean

CMakeFiles/dth11.dir/depend:
	cd /home/bango/linux_driver/d1/dth11U/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bango/linux_driver/d1/dth11U /home/bango/linux_driver/d1/dth11U /home/bango/linux_driver/d1/dth11U/build /home/bango/linux_driver/d1/dth11U/build /home/bango/linux_driver/d1/dth11U/build/CMakeFiles/dth11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dth11.dir/depend

