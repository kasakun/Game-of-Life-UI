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

# Utility rule file for uninstall.

# Include the progress variables for this target.
include include/glfw/CMakeFiles/uninstall.dir/progress.make

include/glfw/CMakeFiles/uninstall:
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw && /home/chenzy/clion/bin/cmake/bin/cmake -P /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/cmake_uninstall.cmake

uninstall: include/glfw/CMakeFiles/uninstall
uninstall: include/glfw/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
include/glfw/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : include/glfw/CMakeFiles/uninstall.dir/build

include/glfw/CMakeFiles/uninstall.dir/clean:
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : include/glfw/CMakeFiles/uninstall.dir/clean

include/glfw/CMakeFiles/uninstall.dir/depend:
	cd /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chenzy/Desktop/Code/C++/Game-of-Life-UI /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/include/glfw /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw /home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/glfw/CMakeFiles/uninstall.dir/depend

