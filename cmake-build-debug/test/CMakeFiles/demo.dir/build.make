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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shanghaitech/work_space/he_ws/audi_lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/demo.dir/flags.make

test/CMakeFiles/demo.dir/main.cpp.o: test/CMakeFiles/demo.dir/flags.make
test/CMakeFiles/demo.dir/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/demo.dir/main.cpp.o"
	cd /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/main.cpp.o -c /home/shanghaitech/work_space/he_ws/audi_lib/test/main.cpp

test/CMakeFiles/demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/main.cpp.i"
	cd /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shanghaitech/work_space/he_ws/audi_lib/test/main.cpp > CMakeFiles/demo.dir/main.cpp.i

test/CMakeFiles/demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/main.cpp.s"
	cd /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shanghaitech/work_space/he_ws/audi_lib/test/main.cpp -o CMakeFiles/demo.dir/main.cpp.s

test/CMakeFiles/demo.dir/main.cpp.o.requires:

.PHONY : test/CMakeFiles/demo.dir/main.cpp.o.requires

test/CMakeFiles/demo.dir/main.cpp.o.provides: test/CMakeFiles/demo.dir/main.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/demo.dir/build.make test/CMakeFiles/demo.dir/main.cpp.o.provides.build
.PHONY : test/CMakeFiles/demo.dir/main.cpp.o.provides

test/CMakeFiles/demo.dir/main.cpp.o.provides.build: test/CMakeFiles/demo.dir/main.cpp.o


# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/main.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

../bin/demo: test/CMakeFiles/demo.dir/main.cpp.o
../bin/demo: test/CMakeFiles/demo.dir/build.make
../bin/demo: ../lib/libfunctional_autodiff.so
../bin/demo: test/CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/demo"
	cd /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/demo.dir/build: ../bin/demo

.PHONY : test/CMakeFiles/demo.dir/build

test/CMakeFiles/demo.dir/requires: test/CMakeFiles/demo.dir/main.cpp.o.requires

.PHONY : test/CMakeFiles/demo.dir/requires

test/CMakeFiles/demo.dir/clean:
	cd /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/demo.dir/clean

test/CMakeFiles/demo.dir/depend:
	cd /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shanghaitech/work_space/he_ws/audi_lib /home/shanghaitech/work_space/he_ws/audi_lib/test /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/test /home/shanghaitech/work_space/he_ws/audi_lib/cmake-build-debug/test/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/demo.dir/depend

