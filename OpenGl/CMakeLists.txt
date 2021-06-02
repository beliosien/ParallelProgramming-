cmake_minimum_required(VERSION 3.13.5)
project(opengl_tuto LANGUAGES CXX)


find_package(SDL2 REQUIRED)

include_directories(include ${SDL2_INCLUDE_DIRS})
add_executable(opengl)
target_link_libraries(opengl -lGL -lGLU -lglut ${SDL2_LIBRARIES})

target_sources(opengl PUBLIC
    source/Display.cpp
    source/shader.cpp
    source/Mesh.cpp
    source/stb_image.cpp
    source/Texture.cpp
    source/main.cpp
)


include(FindOpenGL)
if(OPENGL_FOUND)
    if(NOT OPENGL_GLU_FOUND)
        message(FATAL_ERROR "glu is required for building the application")
    endif()

    target_link_libraries(opengl ${OPENGL_LIBRARIES})
    target_include_directories(opengl PUBLIC ${OPENGL_INCLUDE_DIR})
else()
    message(FATAL_ERROR "opengl is required for building the application")
endif()

include(FindGLUT)
if(GLUT_FOUND)
    target_link_libraries(opengl ${GLUT_LIBRARIES})
    target_include_directories(opengl PUBLIC ${GLUT_INCLUDE_DIR})
else()
    message(FATAL_ERROR "glut is required for building the application")
endif()

include(FindGLEW)
if(GLEW_FOUND)
    target_link_libraries(opengl ${GLEW_LIBRARIES})
    target_include_directories(opengl PUBLIC ${GLEW_INCLUDE_DIRS})
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
            source/*.cpp include/*.h shaders/*.glsl opengl
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
add_dependencies(remise opengl)



