cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(untitled main.cpp Player.cpp Player.h Game.cpp Game.h Item.cpp)


set(SFML_DIR "C:/Users/User/CLionProjects/lib/SFML-2.5.1/lib/cmake/SFML")

target_link_libraries(untitled sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)
