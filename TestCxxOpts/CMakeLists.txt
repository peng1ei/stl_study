include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/Common)

set(TAG TestCxxOpts)
add_executable(${TAG} TestCxxOpts.cpp)
target_link_libraries(${TAG} Common)