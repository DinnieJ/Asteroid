cmake_minimum_required(VERSION 3.10)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug FORCE)
endif()

project(Asteroid)


include_directories("${PROJECT_SOURCE_DIR}")

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/SFML-2.4.2/cmake/Modules")
set (CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/SFML-2.4.2")
set (SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML-2.4.2/include") 
find_library(SFML REQUIRED system window graphics network audio)

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
target_include_directories(Asteroid PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(Asteroid ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})