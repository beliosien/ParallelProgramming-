cmake_minimum_required(VERSION 3.13.5)
project(Opencl LANGUAGES C CXX)

include_directories(sample include)
add_executable(sample)
target_link_libraries(sample -lm -lpthread -lpng /usr/lib64/libOpenCL.so.1)
target_sources(sample PUBLIC
    source/main.c
    source/opencl.c
    source/image.c
    source/image-opencl.c
    source/display.c
    source/texture.c
)

add_custom_target(format
    COMMAND clang-format -i `find source -type f -iname '*.c'` `find include -type f -iname '*.h'`
    COMMAND clang-format -i `find source -type f -iname '*.cpp'` `find include -type f -iname '*.hpp'`
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

#include(FindOpenCL)
#if(OpenCL_FOUND)
#    target_link_libraries(sinoscope ${OpenCL_LIBRARY})
#    target_include_directories(sinoscope PUBLIC ${OpenCL_INCLUDE_DIR})
#else()
#   message(FATAL_ERROR "opencl is required for building the application")
#endif()

include(FindOpenGL)
if(OPENGL_FOUND)
    if(NOT OPENGL_GLU_FOUND)
        message(FATAL_ERROR "glu is required for building the application")
    endif()

    target_link_libraries(sample ${OPENGL_LIBRARIES})
    target_include_directories(sample PUBLIC ${OPENGL_INCLUDE_DIR})
else()
    message(FATAL_ERROR "opengl is required for building the application")
endif()

include(FindGLUT)
if(GLUT_FOUND)
    target_link_libraries(sample ${GLUT_LIBRARIES})
    target_include_directories(sample PUBLIC ${GLUT_INCLUDE_DIR})
else()
    message(FATAL_ERROR "glut is required for building the application")
endif()

include(FindGLEW)
if(GLEW_FOUND)
    target_link_libraries(sample ${GLEW_LIBRARIES})
    target_include_directories(sample PUBLIC ${GLEW_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "glew is required for building the application")
endif()

include(FindGLEW)
if(GLEW_FOUND)
    target_link_libraries(sample ${GLEW_LIBRARIES})
    target_include_directories(sample PUBLIC ${GLEW_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "glew is required for building the application")
endif()

#set_source_files_properties(source/sinoscope-openmp.c PROPERTIES COMPILE_FLAGS -fopenmp)
add_definitions(-D__KERNEL_FILE__="${PROJECT_SOURCE_DIR}/source/kernel/traitement.cl")
add_definitions(-D__OPENCL_INCLUDE__="${PROJECT_SOURCE_DIR}/source/kernel")
add_definitions(-DCL_TARGET_OPENCL_VERSION=220)


add_custom_target(run-opencl
    COMMAND time ${CMAKE_CURRENT_BINARY_DIR}/sample --directory ${PROJECT_SOURCE_DIR}/data --method opencl
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
add_dependencies(run-opencl sample)


