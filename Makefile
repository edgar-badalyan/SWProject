# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/rajky/SWProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rajky/SWProject

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rajky/SWProject/CMakeFiles /home/rajky/SWProject/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rajky/SWProject/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named swipe

# Build rule for target.
swipe: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 swipe
.PHONY : swipe

# fast build rule for target.
swipe/fast:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/build
.PHONY : swipe/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/main.cpp.s
.PHONY : main.cpp.s

phrReader.o: phrReader.cpp.o

.PHONY : phrReader.o

# target to build an object file
phrReader.cpp.o:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/phrReader.cpp.o
.PHONY : phrReader.cpp.o

phrReader.i: phrReader.cpp.i

.PHONY : phrReader.i

# target to preprocess a source file
phrReader.cpp.i:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/phrReader.cpp.i
.PHONY : phrReader.cpp.i

phrReader.s: phrReader.cpp.s

.PHONY : phrReader.s

# target to generate assembly for a file
phrReader.cpp.s:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/phrReader.cpp.s
.PHONY : phrReader.cpp.s

pinReader.o: pinReader.cpp.o

.PHONY : pinReader.o

# target to build an object file
pinReader.cpp.o:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/pinReader.cpp.o
.PHONY : pinReader.cpp.o

pinReader.i: pinReader.cpp.i

.PHONY : pinReader.i

# target to preprocess a source file
pinReader.cpp.i:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/pinReader.cpp.i
.PHONY : pinReader.cpp.i

pinReader.s: pinReader.cpp.s

.PHONY : pinReader.s

# target to generate assembly for a file
pinReader.cpp.s:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/pinReader.cpp.s
.PHONY : pinReader.cpp.s

psqReader.o: psqReader.cpp.o

.PHONY : psqReader.o

# target to build an object file
psqReader.cpp.o:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/psqReader.cpp.o
.PHONY : psqReader.cpp.o

psqReader.i: psqReader.cpp.i

.PHONY : psqReader.i

# target to preprocess a source file
psqReader.cpp.i:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/psqReader.cpp.i
.PHONY : psqReader.cpp.i

psqReader.s: psqReader.cpp.s

.PHONY : psqReader.s

# target to generate assembly for a file
psqReader.cpp.s:
	$(MAKE) -f CMakeFiles/swipe.dir/build.make CMakeFiles/swipe.dir/psqReader.cpp.s
.PHONY : psqReader.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... swipe"
	@echo "... edit_cache"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... phrReader.o"
	@echo "... phrReader.i"
	@echo "... phrReader.s"
	@echo "... pinReader.o"
	@echo "... pinReader.i"
	@echo "... pinReader.s"
	@echo "... psqReader.o"
	@echo "... psqReader.i"
	@echo "... psqReader.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

