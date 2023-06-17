cmake_minimum_required(VERSION 3.22)
project(snaker)
	
set(GREETING_MESSAGE "Snake Game")
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "CMake Version = ${CMAKE_VERSION}")
message(STATUS "CMAKE PROJECT NAME = ${CMAKE_PROJECT_NAME}")
message(STATUS "GREETING MESSAGE = ${GREETING_MESSAGE}")
message(STATUS "Compiler Id = ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CXX Compiler Version = ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "CXX Compiler Path = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMake Include Path = ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}")
message(STATUS "CMake Link Path = ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak,address, -lcurses")
add_executable(
	${PROJECT_NAME}
	src/main.cpp src/game.cpp src/gate.cpp src/item.cpp src/mission.cpp src/point.cpp src/score.cpp src/screen.cpp src/snake.cpp src/snakeGame.cpp src/stage.cpp
)
