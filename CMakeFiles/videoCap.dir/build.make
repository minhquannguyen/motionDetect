# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/minh/Projects/JetsonTK1Projects/OpenCVTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/minh/Projects/JetsonTK1Projects/OpenCVTest

# Include any dependencies generated for this target.
include CMakeFiles/videoCap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/videoCap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/videoCap.dir/flags.make

CMakeFiles/videoCap.dir/videoCap.cpp.o: CMakeFiles/videoCap.dir/flags.make
CMakeFiles/videoCap.dir/videoCap.cpp.o: videoCap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/minh/Projects/JetsonTK1Projects/OpenCVTest/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/videoCap.dir/videoCap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/videoCap.dir/videoCap.cpp.o -c /home/minh/Projects/JetsonTK1Projects/OpenCVTest/videoCap.cpp

CMakeFiles/videoCap.dir/videoCap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/videoCap.dir/videoCap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/minh/Projects/JetsonTK1Projects/OpenCVTest/videoCap.cpp > CMakeFiles/videoCap.dir/videoCap.cpp.i

CMakeFiles/videoCap.dir/videoCap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/videoCap.dir/videoCap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/minh/Projects/JetsonTK1Projects/OpenCVTest/videoCap.cpp -o CMakeFiles/videoCap.dir/videoCap.cpp.s

CMakeFiles/videoCap.dir/videoCap.cpp.o.requires:
.PHONY : CMakeFiles/videoCap.dir/videoCap.cpp.o.requires

CMakeFiles/videoCap.dir/videoCap.cpp.o.provides: CMakeFiles/videoCap.dir/videoCap.cpp.o.requires
	$(MAKE) -f CMakeFiles/videoCap.dir/build.make CMakeFiles/videoCap.dir/videoCap.cpp.o.provides.build
.PHONY : CMakeFiles/videoCap.dir/videoCap.cpp.o.provides

CMakeFiles/videoCap.dir/videoCap.cpp.o.provides.build: CMakeFiles/videoCap.dir/videoCap.cpp.o

# Object files for target videoCap
videoCap_OBJECTS = \
"CMakeFiles/videoCap.dir/videoCap.cpp.o"

# External object files for target videoCap
videoCap_EXTERNAL_OBJECTS =

videoCap: CMakeFiles/videoCap.dir/videoCap.cpp.o
videoCap: CMakeFiles/videoCap.dir/build.make
videoCap: /usr/local/lib/libopencv_videostab.so.2.4.10
videoCap: /usr/local/lib/libopencv_video.so.2.4.10
videoCap: /usr/local/lib/libopencv_ts.a
videoCap: /usr/local/lib/libopencv_superres.so.2.4.10
videoCap: /usr/local/lib/libopencv_stitching.so.2.4.10
videoCap: /usr/local/lib/libopencv_photo.so.2.4.10
videoCap: /usr/local/lib/libopencv_ocl.so.2.4.10
videoCap: /usr/local/lib/libopencv_objdetect.so.2.4.10
videoCap: /usr/local/lib/libopencv_nonfree.so.2.4.10
videoCap: /usr/local/lib/libopencv_ml.so.2.4.10
videoCap: /usr/local/lib/libopencv_legacy.so.2.4.10
videoCap: /usr/local/lib/libopencv_imgproc.so.2.4.10
videoCap: /usr/local/lib/libopencv_highgui.so.2.4.10
videoCap: /usr/local/lib/libopencv_gpu.so.2.4.10
videoCap: /usr/local/lib/libopencv_flann.so.2.4.10
videoCap: /usr/local/lib/libopencv_features2d.so.2.4.10
videoCap: /usr/local/lib/libopencv_core.so.2.4.10
videoCap: /usr/local/lib/libopencv_contrib.so.2.4.10
videoCap: /usr/local/lib/libopencv_calib3d.so.2.4.10
videoCap: /usr/lib/x86_64-linux-gnu/libGLU.so
videoCap: /usr/lib/x86_64-linux-gnu/libGL.so
videoCap: /usr/lib/x86_64-linux-gnu/libSM.so
videoCap: /usr/lib/x86_64-linux-gnu/libICE.so
videoCap: /usr/lib/x86_64-linux-gnu/libX11.so
videoCap: /usr/lib/x86_64-linux-gnu/libXext.so
videoCap: /usr/local/lib/libopencv_nonfree.so.2.4.10
videoCap: /usr/local/lib/libopencv_ocl.so.2.4.10
videoCap: /usr/local/lib/libopencv_gpu.so.2.4.10
videoCap: /usr/local/lib/libopencv_photo.so.2.4.10
videoCap: /usr/local/lib/libopencv_objdetect.so.2.4.10
videoCap: /usr/local/lib/libopencv_legacy.so.2.4.10
videoCap: /usr/local/lib/libopencv_video.so.2.4.10
videoCap: /usr/local/lib/libopencv_ml.so.2.4.10
videoCap: /usr/local/lib/libopencv_calib3d.so.2.4.10
videoCap: /usr/local/lib/libopencv_features2d.so.2.4.10
videoCap: /usr/local/lib/libopencv_highgui.so.2.4.10
videoCap: /usr/local/lib/libopencv_imgproc.so.2.4.10
videoCap: /usr/local/lib/libopencv_flann.so.2.4.10
videoCap: /usr/local/lib/libopencv_core.so.2.4.10
videoCap: CMakeFiles/videoCap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable videoCap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/videoCap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/videoCap.dir/build: videoCap
.PHONY : CMakeFiles/videoCap.dir/build

CMakeFiles/videoCap.dir/requires: CMakeFiles/videoCap.dir/videoCap.cpp.o.requires
.PHONY : CMakeFiles/videoCap.dir/requires

CMakeFiles/videoCap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/videoCap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/videoCap.dir/clean

CMakeFiles/videoCap.dir/depend:
	cd /home/minh/Projects/JetsonTK1Projects/OpenCVTest && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minh/Projects/JetsonTK1Projects/OpenCVTest /home/minh/Projects/JetsonTK1Projects/OpenCVTest /home/minh/Projects/JetsonTK1Projects/OpenCVTest /home/minh/Projects/JetsonTK1Projects/OpenCVTest /home/minh/Projects/JetsonTK1Projects/OpenCVTest/CMakeFiles/videoCap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/videoCap.dir/depend

