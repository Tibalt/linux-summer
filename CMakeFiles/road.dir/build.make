# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/tibalt/linux-summer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tibalt/linux-summer

# Include any dependencies generated for this target.
include CMakeFiles/road.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/road.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/road.dir/flags.make

CMakeFiles/road.dir/simulation.cpp.o: CMakeFiles/road.dir/flags.make
CMakeFiles/road.dir/simulation.cpp.o: simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tibalt/linux-summer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/road.dir/simulation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/road.dir/simulation.cpp.o -c /home/tibalt/linux-summer/simulation.cpp

CMakeFiles/road.dir/simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/road.dir/simulation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tibalt/linux-summer/simulation.cpp > CMakeFiles/road.dir/simulation.cpp.i

CMakeFiles/road.dir/simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/road.dir/simulation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tibalt/linux-summer/simulation.cpp -o CMakeFiles/road.dir/simulation.cpp.s

CMakeFiles/road.dir/simulation.cpp.o.requires:

.PHONY : CMakeFiles/road.dir/simulation.cpp.o.requires

CMakeFiles/road.dir/simulation.cpp.o.provides: CMakeFiles/road.dir/simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/road.dir/build.make CMakeFiles/road.dir/simulation.cpp.o.provides.build
.PHONY : CMakeFiles/road.dir/simulation.cpp.o.provides

CMakeFiles/road.dir/simulation.cpp.o.provides.build: CMakeFiles/road.dir/simulation.cpp.o


CMakeFiles/road.dir/road.cpp.o: CMakeFiles/road.dir/flags.make
CMakeFiles/road.dir/road.cpp.o: road.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tibalt/linux-summer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/road.dir/road.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/road.dir/road.cpp.o -c /home/tibalt/linux-summer/road.cpp

CMakeFiles/road.dir/road.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/road.dir/road.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tibalt/linux-summer/road.cpp > CMakeFiles/road.dir/road.cpp.i

CMakeFiles/road.dir/road.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/road.dir/road.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tibalt/linux-summer/road.cpp -o CMakeFiles/road.dir/road.cpp.s

CMakeFiles/road.dir/road.cpp.o.requires:

.PHONY : CMakeFiles/road.dir/road.cpp.o.requires

CMakeFiles/road.dir/road.cpp.o.provides: CMakeFiles/road.dir/road.cpp.o.requires
	$(MAKE) -f CMakeFiles/road.dir/build.make CMakeFiles/road.dir/road.cpp.o.provides.build
.PHONY : CMakeFiles/road.dir/road.cpp.o.provides

CMakeFiles/road.dir/road.cpp.o.provides.build: CMakeFiles/road.dir/road.cpp.o


CMakeFiles/road.dir/vehicle.cpp.o: CMakeFiles/road.dir/flags.make
CMakeFiles/road.dir/vehicle.cpp.o: vehicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tibalt/linux-summer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/road.dir/vehicle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/road.dir/vehicle.cpp.o -c /home/tibalt/linux-summer/vehicle.cpp

CMakeFiles/road.dir/vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/road.dir/vehicle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tibalt/linux-summer/vehicle.cpp > CMakeFiles/road.dir/vehicle.cpp.i

CMakeFiles/road.dir/vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/road.dir/vehicle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tibalt/linux-summer/vehicle.cpp -o CMakeFiles/road.dir/vehicle.cpp.s

CMakeFiles/road.dir/vehicle.cpp.o.requires:

.PHONY : CMakeFiles/road.dir/vehicle.cpp.o.requires

CMakeFiles/road.dir/vehicle.cpp.o.provides: CMakeFiles/road.dir/vehicle.cpp.o.requires
	$(MAKE) -f CMakeFiles/road.dir/build.make CMakeFiles/road.dir/vehicle.cpp.o.provides.build
.PHONY : CMakeFiles/road.dir/vehicle.cpp.o.provides

CMakeFiles/road.dir/vehicle.cpp.o.provides.build: CMakeFiles/road.dir/vehicle.cpp.o


CMakeFiles/road.dir/van.cpp.o: CMakeFiles/road.dir/flags.make
CMakeFiles/road.dir/van.cpp.o: van.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tibalt/linux-summer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/road.dir/van.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/road.dir/van.cpp.o -c /home/tibalt/linux-summer/van.cpp

CMakeFiles/road.dir/van.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/road.dir/van.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tibalt/linux-summer/van.cpp > CMakeFiles/road.dir/van.cpp.i

CMakeFiles/road.dir/van.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/road.dir/van.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tibalt/linux-summer/van.cpp -o CMakeFiles/road.dir/van.cpp.s

CMakeFiles/road.dir/van.cpp.o.requires:

.PHONY : CMakeFiles/road.dir/van.cpp.o.requires

CMakeFiles/road.dir/van.cpp.o.provides: CMakeFiles/road.dir/van.cpp.o.requires
	$(MAKE) -f CMakeFiles/road.dir/build.make CMakeFiles/road.dir/van.cpp.o.provides.build
.PHONY : CMakeFiles/road.dir/van.cpp.o.provides

CMakeFiles/road.dir/van.cpp.o.provides.build: CMakeFiles/road.dir/van.cpp.o


CMakeFiles/road.dir/bold.cpp.o: CMakeFiles/road.dir/flags.make
CMakeFiles/road.dir/bold.cpp.o: bold.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tibalt/linux-summer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/road.dir/bold.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/road.dir/bold.cpp.o -c /home/tibalt/linux-summer/bold.cpp

CMakeFiles/road.dir/bold.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/road.dir/bold.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tibalt/linux-summer/bold.cpp > CMakeFiles/road.dir/bold.cpp.i

CMakeFiles/road.dir/bold.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/road.dir/bold.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tibalt/linux-summer/bold.cpp -o CMakeFiles/road.dir/bold.cpp.s

CMakeFiles/road.dir/bold.cpp.o.requires:

.PHONY : CMakeFiles/road.dir/bold.cpp.o.requires

CMakeFiles/road.dir/bold.cpp.o.provides: CMakeFiles/road.dir/bold.cpp.o.requires
	$(MAKE) -f CMakeFiles/road.dir/build.make CMakeFiles/road.dir/bold.cpp.o.provides.build
.PHONY : CMakeFiles/road.dir/bold.cpp.o.provides

CMakeFiles/road.dir/bold.cpp.o.provides.build: CMakeFiles/road.dir/bold.cpp.o


CMakeFiles/road.dir/cautious.cpp.o: CMakeFiles/road.dir/flags.make
CMakeFiles/road.dir/cautious.cpp.o: cautious.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tibalt/linux-summer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/road.dir/cautious.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/road.dir/cautious.cpp.o -c /home/tibalt/linux-summer/cautious.cpp

CMakeFiles/road.dir/cautious.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/road.dir/cautious.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tibalt/linux-summer/cautious.cpp > CMakeFiles/road.dir/cautious.cpp.i

CMakeFiles/road.dir/cautious.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/road.dir/cautious.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tibalt/linux-summer/cautious.cpp -o CMakeFiles/road.dir/cautious.cpp.s

CMakeFiles/road.dir/cautious.cpp.o.requires:

.PHONY : CMakeFiles/road.dir/cautious.cpp.o.requires

CMakeFiles/road.dir/cautious.cpp.o.provides: CMakeFiles/road.dir/cautious.cpp.o.requires
	$(MAKE) -f CMakeFiles/road.dir/build.make CMakeFiles/road.dir/cautious.cpp.o.provides.build
.PHONY : CMakeFiles/road.dir/cautious.cpp.o.provides

CMakeFiles/road.dir/cautious.cpp.o.provides.build: CMakeFiles/road.dir/cautious.cpp.o


# Object files for target road
road_OBJECTS = \
"CMakeFiles/road.dir/simulation.cpp.o" \
"CMakeFiles/road.dir/road.cpp.o" \
"CMakeFiles/road.dir/vehicle.cpp.o" \
"CMakeFiles/road.dir/van.cpp.o" \
"CMakeFiles/road.dir/bold.cpp.o" \
"CMakeFiles/road.dir/cautious.cpp.o"

# External object files for target road
road_EXTERNAL_OBJECTS =

road: CMakeFiles/road.dir/simulation.cpp.o
road: CMakeFiles/road.dir/road.cpp.o
road: CMakeFiles/road.dir/vehicle.cpp.o
road: CMakeFiles/road.dir/van.cpp.o
road: CMakeFiles/road.dir/bold.cpp.o
road: CMakeFiles/road.dir/cautious.cpp.o
road: CMakeFiles/road.dir/build.make
road: CMakeFiles/road.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tibalt/linux-summer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable road"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/road.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/road.dir/build: road

.PHONY : CMakeFiles/road.dir/build

CMakeFiles/road.dir/requires: CMakeFiles/road.dir/simulation.cpp.o.requires
CMakeFiles/road.dir/requires: CMakeFiles/road.dir/road.cpp.o.requires
CMakeFiles/road.dir/requires: CMakeFiles/road.dir/vehicle.cpp.o.requires
CMakeFiles/road.dir/requires: CMakeFiles/road.dir/van.cpp.o.requires
CMakeFiles/road.dir/requires: CMakeFiles/road.dir/bold.cpp.o.requires
CMakeFiles/road.dir/requires: CMakeFiles/road.dir/cautious.cpp.o.requires

.PHONY : CMakeFiles/road.dir/requires

CMakeFiles/road.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/road.dir/cmake_clean.cmake
.PHONY : CMakeFiles/road.dir/clean

CMakeFiles/road.dir/depend:
	cd /home/tibalt/linux-summer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tibalt/linux-summer /home/tibalt/linux-summer /home/tibalt/linux-summer /home/tibalt/linux-summer /home/tibalt/linux-summer/CMakeFiles/road.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/road.dir/depend
