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
include include/glfw/examples/CMakeFiles/splitview.dir/depend.make

# Include the progress variables for this target.
include include/glfw/examples/CMakeFiles/splitview.dir/progress.make

# Include the compile flags for this target's objects.
include include/glfw/examples/CMakeFiles/splitview.dir/flags.make

include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o: include/glfw/examples/CMakeFiles/splitview.dir/flags.make
include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o: ../include/glfw/examples/splitview.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/splitview.dir/splitview.c.o   -c /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/examples/splitview.c

include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/splitview.c.i"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/examples/splitview.c > CMakeFiles/splitview.dir/splitview.c.i

include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/splitview.c.s"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/examples/splitview.c -o CMakeFiles/splitview.dir/splitview.c.s

include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires:

.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires

include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides: include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires
	$(MAKE) -f include/glfw/examples/CMakeFiles/splitview.dir/build.make include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides.build
.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides

include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides.build: include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o


include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o: include/glfw/examples/CMakeFiles/splitview.dir/flags.make
include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o: ../include/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/splitview.dir/__/deps/glad.c.o   -c /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/glad.c

include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/__/deps/glad.c.i"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/glad.c > CMakeFiles/splitview.dir/__/deps/glad.c.i

include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/__/deps/glad.c.s"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/deps/glad.c -o CMakeFiles/splitview.dir/__/deps/glad.c.s

include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires:

.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires

include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides: include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires
	$(MAKE) -f include/glfw/examples/CMakeFiles/splitview.dir/build.make include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides.build
.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides

include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides.build: include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o


# Object files for target splitview
splitview_OBJECTS = \
"CMakeFiles/splitview.dir/splitview.c.o" \
"CMakeFiles/splitview.dir/__/deps/glad.c.o"

# External object files for target splitview
splitview_EXTERNAL_OBJECTS =

include/glfw/examples/splitview: include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o
include/glfw/examples/splitview: include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o
include/glfw/examples/splitview: include/glfw/examples/CMakeFiles/splitview.dir/build.make
include/glfw/examples/splitview: include/glfw/src/libglfw3.a
include/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/librt.so
include/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libm.so
include/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libX11.so
include/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libXrandr.so
include/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libXinerama.so
include/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
include/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libXcursor.so
include/glfw/examples/splitview: include/glfw/examples/CMakeFiles/splitview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable splitview"
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splitview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/glfw/examples/CMakeFiles/splitview.dir/build: include/glfw/examples/splitview

.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/build

include/glfw/examples/CMakeFiles/splitview.dir/requires: include/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires
include/glfw/examples/CMakeFiles/splitview.dir/requires: include/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires

.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/requires

include/glfw/examples/CMakeFiles/splitview.dir/clean:
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/splitview.dir/cmake_clean.cmake
.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/clean

include/glfw/examples/CMakeFiles/splitview.dir/depend:
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chenzy/Desktop/Code/C++/Game-of-Life-UI /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw/examples /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/examples/CMakeFiles/splitview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/glfw/examples/CMakeFiles/splitview.dir/depend

