cmake_minimum_required(VERSION 3.10)

project(Asteroid)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIR})
add_executable(
    Asteroid
    main.cpp
    Animation.hpp
    Animation.cpp
    Asteroid.hpp
    Asteroid.cpp
    Bullet.hpp
    Bullet.cpp
    Entity.cpp
    Entity.hpp
    Game.cpp
    Game.hpp
    Player.cpp
    Player.hpp
)
target_link_libraries(Asteroid ${SFML_LIBRARY} ${SFML_DEPENDENCIES})