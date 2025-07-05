cmake_minimum_required(VERSION 3.10)
project(teleportal)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include(FetchContent)

FetchContent_Declare(
	sdl2
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.32.6
)
FetchContent_MakeAvailable(sdl2)

FetchContent_Declare(
	sdl2_image 
	GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
	GIT_TAG release-2.8.8
)
FetchContent_MakeAvailable(sdl2_image)

FetchContent_Declare(
	vecmath
	GIT_REPOSITORY https://github.com/jhemdan/vecmath.git
	GIT_TAG master
)
FetchContent_MakeAvailable(vecmath)

set(SRCS
	src/main.cpp
	src/game.cpp
	src/resourceLoader.cpp
	src/entity.cpp
	src/ECS.cpp
	src/SpriteComponent.cpp
	src/TransformComponent.cpp
)

add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_sources(${PROJECT_NAME} PRIVATE ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_image_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image::SDL2_image)

target_include_directories(${PROJECT_NAME} PRIVATE ${vecmath_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE vecmath)

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})
