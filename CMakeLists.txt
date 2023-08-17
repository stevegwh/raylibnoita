cmake_minimum_required(VERSION 3.26)
project(raylibnoita)

set(CMAKE_CXX_STANDARD 17)
find_package(raylib REQUIRED)
add_executable(raylibnoita main.cpp
        Grid.cpp
        Grid.hpp
        SandBlock.cpp
        SandBlock.hpp
        Block.hpp
        Constants.hpp
        WaterBlock.cpp
        WaterBlock.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
