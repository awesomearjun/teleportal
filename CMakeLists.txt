cmake_minimum_required(VERSION 3.10)
project(teleportal)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    sdl2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.32.6
)

FetchContent_MakeAvailable(sdl2)

set(SRCS
    src/main.cpp
    src/game.cpp
)

add_executable(${PROJECT_NAME})

include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_sources(${PROJECT_NAME} PRIVATE ${SRCS})
include_directories(${PROJECT_NAME} PRIVATE ${SDL2_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
