# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rohan/VSCode/finalysis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rohan/VSCode/finalysis/build

# Include any dependencies generated for this target.
include CMakeFiles/Finalysis.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Finalysis.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Finalysis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Finalysis.dir/flags.make

CMakeFiles/Finalysis.dir/src/main.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/main.cpp.o: /Users/rohan/VSCode/finalysis/src/main.cpp
CMakeFiles/Finalysis.dir/src/main.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Finalysis.dir/src/main.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/main.cpp.o -MF CMakeFiles/Finalysis.dir/src/main.cpp.o.d -o CMakeFiles/Finalysis.dir/src/main.cpp.o -c /Users/rohan/VSCode/finalysis/src/main.cpp

CMakeFiles/Finalysis.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/main.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/main.cpp > CMakeFiles/Finalysis.dir/src/main.cpp.i

CMakeFiles/Finalysis.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/main.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/main.cpp -o CMakeFiles/Finalysis.dir/src/main.cpp.s

CMakeFiles/Finalysis.dir/src/base64.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/base64.cpp.o: /Users/rohan/VSCode/finalysis/src/base64.cpp
CMakeFiles/Finalysis.dir/src/base64.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Finalysis.dir/src/base64.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/base64.cpp.o -MF CMakeFiles/Finalysis.dir/src/base64.cpp.o.d -o CMakeFiles/Finalysis.dir/src/base64.cpp.o -c /Users/rohan/VSCode/finalysis/src/base64.cpp

CMakeFiles/Finalysis.dir/src/base64.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/base64.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/base64.cpp > CMakeFiles/Finalysis.dir/src/base64.cpp.i

CMakeFiles/Finalysis.dir/src/base64.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/base64.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/base64.cpp -o CMakeFiles/Finalysis.dir/src/base64.cpp.s

CMakeFiles/Finalysis.dir/src/common_utils.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/common_utils.cpp.o: /Users/rohan/VSCode/finalysis/src/common_utils.cpp
CMakeFiles/Finalysis.dir/src/common_utils.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Finalysis.dir/src/common_utils.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/common_utils.cpp.o -MF CMakeFiles/Finalysis.dir/src/common_utils.cpp.o.d -o CMakeFiles/Finalysis.dir/src/common_utils.cpp.o -c /Users/rohan/VSCode/finalysis/src/common_utils.cpp

CMakeFiles/Finalysis.dir/src/common_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/common_utils.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/common_utils.cpp > CMakeFiles/Finalysis.dir/src/common_utils.cpp.i

CMakeFiles/Finalysis.dir/src/common_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/common_utils.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/common_utils.cpp -o CMakeFiles/Finalysis.dir/src/common_utils.cpp.s

CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o: /Users/rohan/VSCode/finalysis/src/data_fetcher.cpp
CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o -MF CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o.d -o CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o -c /Users/rohan/VSCode/finalysis/src/data_fetcher.cpp

CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/data_fetcher.cpp > CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.i

CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/data_fetcher.cpp -o CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.s

CMakeFiles/Finalysis.dir/src/data_processor.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/data_processor.cpp.o: /Users/rohan/VSCode/finalysis/src/data_processor.cpp
CMakeFiles/Finalysis.dir/src/data_processor.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Finalysis.dir/src/data_processor.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/data_processor.cpp.o -MF CMakeFiles/Finalysis.dir/src/data_processor.cpp.o.d -o CMakeFiles/Finalysis.dir/src/data_processor.cpp.o -c /Users/rohan/VSCode/finalysis/src/data_processor.cpp

CMakeFiles/Finalysis.dir/src/data_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/data_processor.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/data_processor.cpp > CMakeFiles/Finalysis.dir/src/data_processor.cpp.i

CMakeFiles/Finalysis.dir/src/data_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/data_processor.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/data_processor.cpp -o CMakeFiles/Finalysis.dir/src/data_processor.cpp.s

CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o: /Users/rohan/VSCode/finalysis/src/trend_analyzer.cpp
CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o -MF CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o.d -o CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o -c /Users/rohan/VSCode/finalysis/src/trend_analyzer.cpp

CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/trend_analyzer.cpp > CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.i

CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/trend_analyzer.cpp -o CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.s

CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o: /Users/rohan/VSCode/finalysis/src/risk_assessor.cpp
CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o -MF CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o.d -o CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o -c /Users/rohan/VSCode/finalysis/src/risk_assessor.cpp

CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/risk_assessor.cpp > CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.i

CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/risk_assessor.cpp -o CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.s

CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o: CMakeFiles/Finalysis.dir/flags.make
CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o: /Users/rohan/VSCode/finalysis/src/aylien_data.cpp
CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o: CMakeFiles/Finalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o -MF CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o.d -o CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o -c /Users/rohan/VSCode/finalysis/src/aylien_data.cpp

CMakeFiles/Finalysis.dir/src/aylien_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Finalysis.dir/src/aylien_data.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohan/VSCode/finalysis/src/aylien_data.cpp > CMakeFiles/Finalysis.dir/src/aylien_data.cpp.i

CMakeFiles/Finalysis.dir/src/aylien_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Finalysis.dir/src/aylien_data.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohan/VSCode/finalysis/src/aylien_data.cpp -o CMakeFiles/Finalysis.dir/src/aylien_data.cpp.s

# Object files for target Finalysis
Finalysis_OBJECTS = \
"CMakeFiles/Finalysis.dir/src/main.cpp.o" \
"CMakeFiles/Finalysis.dir/src/base64.cpp.o" \
"CMakeFiles/Finalysis.dir/src/common_utils.cpp.o" \
"CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o" \
"CMakeFiles/Finalysis.dir/src/data_processor.cpp.o" \
"CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o" \
"CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o" \
"CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o"

# External object files for target Finalysis
Finalysis_EXTERNAL_OBJECTS =

Finalysis: CMakeFiles/Finalysis.dir/src/main.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/src/base64.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/src/common_utils.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/src/data_fetcher.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/src/data_processor.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/src/trend_analyzer.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/src/risk_assessor.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/src/aylien_data.cpp.o
Finalysis: CMakeFiles/Finalysis.dir/build.make
Finalysis: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/usr/lib/libcurl.tbd
Finalysis: /opt/homebrew/lib/libdlib.19.24.4.dylib
Finalysis: /opt/homebrew/opt/llvm/lib/libomp.dylib
Finalysis: /opt/homebrew/opt/openblas/lib/libopenblas.dylib
Finalysis: CMakeFiles/Finalysis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/rohan/VSCode/finalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Finalysis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Finalysis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Finalysis.dir/build: Finalysis
.PHONY : CMakeFiles/Finalysis.dir/build

CMakeFiles/Finalysis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Finalysis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Finalysis.dir/clean

CMakeFiles/Finalysis.dir/depend:
	cd /Users/rohan/VSCode/finalysis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rohan/VSCode/finalysis /Users/rohan/VSCode/finalysis /Users/rohan/VSCode/finalysis/build /Users/rohan/VSCode/finalysis/build /Users/rohan/VSCode/finalysis/build/CMakeFiles/Finalysis.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Finalysis.dir/depend

