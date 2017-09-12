SET(SRC_LIST main.cpp)
ADD_EXECUTABLE(demo ${SRC_LIST})
#TARGET_LINK_LIBRARIES(demo Module_based_autodiff)
#TARGET_LINK_LIBRARIES(demo class_based_autodiff)
TARGET_LINK_LIBRARIES(demo functional_autodiff)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin/)

