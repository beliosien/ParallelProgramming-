cmake_minimum_required(VERSION 3.13.5)
project(filterSystem LANGUAGES CXX)


include_directories(include)
add_executable(filter)

target_sources(filter PUBLIC
    source/image.cpp
    source/stb_image.cpp
    source/stb_image_write.cpp
    source/filter.cpp
    source/main.cpp
)

add_custom_target(format
    COMMAND clang-format -i `find source -type f -iname '*.c'` `find include -type f -iname '*.h'`
    COMMAND clang-format -i `find source -type f -iname '*.cpp'` `find include -type f -iname '*.hpp'`
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

add_custom_target(remise
    COMMAND zip --must-match -r ${CMAKE_CURRENT_BINARY_DIR}/filter_system.zip
            src/*.cpp include/*.h filter
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
add_dependencies(remise filter)



