# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/chenzy/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/chenzy/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chenzy/Desktop/Code/C++/Game-of-Life-UI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug

# Include any dependencies generated for this target.
include include/glfw/tests/CMakeFiles/events.dir/depend.make

# Include the progress variables for this target.
include include/glfw/tests/CMakeFiles/events.dir/progress.make

# Include the compile flags for this target's objects.
include include/glfw/tests/CMakeFiles/events.dir/flags.make

include/glfw/tests/CMakeFiles/events.dir/events.c.o: include/glfw/tests/CMakeFiles/events.dir/flags.make
include/glfw/tests/CMakeFiles/events.dir/events.c.o: ../include/glfw/tests/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object include/glfw/tests/CMakeFiles/events.dir/events.c.o"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/events.c.o   -c /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/tests/events.c

include/glfw/tests/CMakeFiles/events.dir/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/events.c.i"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/tests/events.c > CMakeFiles/events.dir/events.c.i

include/glfw/tests/CMakeFiles/events.dir/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/events.c.s"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/tests/events.c -o CMakeFiles/events.dir/events.c.s

include/glfw/tests/CMakeFiles/events.dir/events.c.o.requires:

.PHONY : include/glfw/tests/CMakeFiles/events.dir/events.c.o.requires

include/glfw/tests/CMakeFiles/events.dir/events.c.o.provides: include/glfw/tests/CMakeFiles/events.dir/events.c.o.requires
	$(MAKE) -f include/glfw/tests/CMakeFiles/events.dir/build.make include/glfw/tests/CMakeFiles/events.dir/events.c.o.provides.build
.PHONY : include/glfw/tests/CMakeFiles/events.dir/events.c.o.provides

include/glfw/tests/CMakeFiles/events.dir/events.c.o.provides.build: include/glfw/tests/CMakeFiles/events.dir/events.c.o


include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o: include/glfw/tests/CMakeFiles/events.dir/flags.make
include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o: ../include/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/__/deps/getopt.c.o   -c /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/getopt.c

include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/getopt.c.i"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/getopt.c > CMakeFiles/events.dir/__/deps/getopt.c.i

include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/getopt.c.s"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/getopt.c -o CMakeFiles/events.dir/__/deps/getopt.c.s

include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires:

.PHONY : include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires

include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides: include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f include/glfw/tests/CMakeFiles/events.dir/build.make include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides.build
.PHONY : include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides

include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides.build: include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o


include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o: include/glfw/tests/CMakeFiles/events.dir/flags.make
include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o: ../include/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/__/deps/glad.c.o   -c /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/glad.c

include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/glad.c.i"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/glad.c > CMakeFiles/events.dir/__/deps/glad.c.i

include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/glad.c.s"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/glad.c -o CMakeFiles/events.dir/__/deps/glad.c.s

include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires:

.PHONY : include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires

include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides: include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires
	$(MAKE) -f include/glfw/tests/CMakeFiles/events.dir/build.make include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides.build
.PHONY : include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides

include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides.build: include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o


# Object files for target events
events_OBJECTS = \
"CMakeFiles/events.dir/events.c.o" \
"CMakeFiles/events.dir/__/deps/getopt.c.o" \
"CMakeFiles/events.dir/__/deps/glad.c.o"

# External object files for target events
events_EXTERNAL_OBJECTS =

include/glfw/tests/events: include/glfw/tests/CMakeFiles/events.dir/events.c.o
include/glfw/tests/events: include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o
include/glfw/tests/events: include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o
include/glfw/tests/events: include/glfw/tests/CMakeFiles/events.dir/build.make
include/glfw/tests/events: include/glfw/src/libglfw3.a
include/glfw/tests/events: /usr/lib/x86_64-linux-gnu/librt.so
include/glfw/tests/events: /usr/lib/x86_64-linux-gnu/libm.so
include/glfw/tests/events: /usr/lib/x86_64-linux-gnu/libX11.so
include/glfw/tests/events: /usr/lib/x86_64-linux-gnu/libXrandr.so
include/glfw/tests/events: /usr/lib/x86_64-linux-gnu/libXinerama.so
include/glfw/tests/events: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
include/glfw/tests/events: /usr/lib/x86_64-linux-gnu/libXcursor.so
include/glfw/tests/events: include/glfw/tests/CMakeFiles/events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable events"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/events.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/glfw/tests/CMakeFiles/events.dir/build: include/glfw/tests/events

.PHONY : include/glfw/tests/CMakeFiles/events.dir/build

include/glfw/tests/CMakeFiles/events.dir/requires: include/glfw/tests/CMakeFiles/events.dir/events.c.o.requires
include/glfw/tests/CMakeFiles/events.dir/requires: include/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires
include/glfw/tests/CMakeFiles/events.dir/requires: include/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires

.PHONY : include/glfw/tests/CMakeFiles/events.dir/requires

include/glfw/tests/CMakeFiles/events.dir/clean:
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/events.dir/cmake_clean.cmake
.PHONY : include/glfw/tests/CMakeFiles/events.dir/clean

include/glfw/tests/CMakeFiles/events.dir/depend:
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chenzy/Desktop/Code/C++/Game-of-Life-UI /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/tests /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/tests/CMakeFiles/events.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/glfw/tests/CMakeFiles/events.dir/depend

