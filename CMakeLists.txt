# CMakeList.txt : CMake project for StlStudy, include source and define
# project specific logic here.
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
PROJECT("StlStudy")

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF()

SET(CMAKE_CXX_STANDARD 11)

OPTION(BUILD_STL_STUDY "build stl study" ON)
OPTION(BUILD_VECTOR "build vector" ON)
OPTION(BUILD_TEST_CXXOPTS "build vector" OFF)

MESSAGE("CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")
#---------------------------------------------------------
# 设置生成的库和可执行文件的路径
#---------------------------------------------------------
#以下三行命令要写在根（root）CmakeLists.txt的里面

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
# 设置生成的库所在路径，如 *.lib/*.a, *.dll/*.so 等
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
# 设置可执行程序所在目录
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

# 分别设置Debug和Release
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Bin)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Bin)
#-------------------------------------------------------------------

ADD_SUBDIRECTORY(Common)

INCLUDE_DIRECTORIES(Common)

MESSAGE("ProjectDir0 ${PROJECT_SOURCE_DIR}")

IF (BUILD_STL_STUDY)
    ADD_SUBDIRECTORY(StlStudy)
ENDIF()

IF (BUILD_VECTOR)
    # 会在Build目录创建相关的独立文件夹
    ADD_SUBDIRECTORY(Vector)

    # 在当前Build目录下直构建相关文件
    # INCLUDE(Vector/CMakeLists.txt)
ENDIF()

IF(BUILD_TEST_CXXOPTS)
    ADD_SUBDIRECTORY(TestCxxOpts)
ENDIF()