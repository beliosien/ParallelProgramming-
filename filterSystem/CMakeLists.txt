cmake_minimum_required(VERSION 3.13.5)
project(filterSystem LANGUAGES CXX)


include_directories(include)
add_executable(filter)
target_link_libraries(filter -lGL -lGLU -lglut)

target_sources(filter PUBLIC
    source/image.cpp
    source/utilitary.cpp
    source/viewer.cpp
    source/viewer_utilitary.cpp
    source/stb_image.cpp
    source/stb_image_write.cpp
    source/shader.cpp
    source/filter.cpp
    source/main.cpp
)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
else()
    message(FATAL_ERROR "openmp is required for building the application")
endif()


include(FindOpenGL)
if(OPENGL_FOUND)
    if(NOT OPENGL_GLU_FOUND)
        message(FATAL_ERROR "glu is required for building the application")
    endif()

    target_link_libraries(filter ${OPENGL_LIBRARIES})
    target_include_directories(filter PUBLIC ${OPENGL_INCLUDE_DIR})
else()
    message(FATAL_ERROR "opengl is required for building the application")
endif()

include(FindGLUT)
if(GLUT_FOUND)
    target_link_libraries(filter ${GLUT_LIBRARIES})
    target_include_directories(filter PUBLIC ${GLUT_INCLUDE_DIR})
else()
    message(FATAL_ERROR "glut is required for building the application")
endif()

include(FindGLEW)
if(GLEW_FOUND)
    target_link_libraries(filter ${GLEW_LIBRARIES})
    target_include_directories(filter PUBLIC ${GLEW_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "glew is required for building the application")
endif()


add_custom_target(format
    COMMAND clang-format -i `find source -type f -iname '*.c'` `find include -type f -iname '*.h'`
    COMMAND clang-format -i `find source -type f -iname '*.cpp'` `find include -type f -iname '*.hpp'`
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

add_custom_target(remise
    COMMAND zip --must-match -r ${CMAKE_CURRENT_BINARY_DIR}/filter_system.zip
            source/*.cpp include/*.h res/shaders/*.glsl filter
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
add_dependencies(remise filter)



