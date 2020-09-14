# CMakeList.txt : CMake project for StlStudy, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("StlStudy")

add_subdirectory("Common")

# Add source to this project's executable.
add_executable (StlStudy "StlStudy.cpp" "StlStudy.h")
target_link_libraries(StlStudy Common)

# TODO: Add tests and install targets if needed.


