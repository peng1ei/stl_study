MESSAGE("vec ${CMAKE_CURRENT_LIST_DIR}")
MESSAGE("vec ${PROJECT_SOURCE_DIR}")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/Common)

MESSAGE("ProjectDirStlStudy ${PROJECT_SOURCE_DIR}")
MESSAGE("CMAKE_BINARY_DIR-StlStudy ${CMAKE_BINARY_DIR}")

LIST(APPEND STLSTUDY_SRCS ${CMAKE_CURRENT_LIST_DIR}/StlStudy.cpp)

set(TAG StlStudy)
ADD_EXECUTABLE(${TAG} ${STLSTUDY_SRCS})
TARGET_LINK_LIBRARIES(${TAG} Common)
