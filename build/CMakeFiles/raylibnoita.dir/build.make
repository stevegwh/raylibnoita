# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/roxie/CLionProjects/raylibnoita

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roxie/CLionProjects/raylibnoita/build

# Include any dependencies generated for this target.
include CMakeFiles/raylibnoita.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raylibnoita.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raylibnoita.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raylibnoita.dir/flags.make

CMakeFiles/raylibnoita.dir/main.cpp.o: CMakeFiles/raylibnoita.dir/flags.make
CMakeFiles/raylibnoita.dir/main.cpp.o: /home/roxie/CLionProjects/raylibnoita/main.cpp
CMakeFiles/raylibnoita.dir/main.cpp.o: CMakeFiles/raylibnoita.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/roxie/CLionProjects/raylibnoita/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raylibnoita.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raylibnoita.dir/main.cpp.o -MF CMakeFiles/raylibnoita.dir/main.cpp.o.d -o CMakeFiles/raylibnoita.dir/main.cpp.o -c /home/roxie/CLionProjects/raylibnoita/main.cpp

CMakeFiles/raylibnoita.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/raylibnoita.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roxie/CLionProjects/raylibnoita/main.cpp > CMakeFiles/raylibnoita.dir/main.cpp.i

CMakeFiles/raylibnoita.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/raylibnoita.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roxie/CLionProjects/raylibnoita/main.cpp -o CMakeFiles/raylibnoita.dir/main.cpp.s

# Object files for target raylibnoita
raylibnoita_OBJECTS = \
"CMakeFiles/raylibnoita.dir/main.cpp.o"

# External object files for target raylibnoita
raylibnoita_EXTERNAL_OBJECTS =

raylibnoita: CMakeFiles/raylibnoita.dir/main.cpp.o
raylibnoita: CMakeFiles/raylibnoita.dir/build.make
raylibnoita: CMakeFiles/raylibnoita.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/roxie/CLionProjects/raylibnoita/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raylibnoita"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raylibnoita.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raylibnoita.dir/build: raylibnoita
.PHONY : CMakeFiles/raylibnoita.dir/build

CMakeFiles/raylibnoita.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raylibnoita.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raylibnoita.dir/clean

CMakeFiles/raylibnoita.dir/depend:
	cd /home/roxie/CLionProjects/raylibnoita/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roxie/CLionProjects/raylibnoita /home/roxie/CLionProjects/raylibnoita /home/roxie/CLionProjects/raylibnoita/build /home/roxie/CLionProjects/raylibnoita/build /home/roxie/CLionProjects/raylibnoita/build/CMakeFiles/raylibnoita.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/raylibnoita.dir/depend
