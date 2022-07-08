cmake_minimum_required(VERSION 3.23.2)

project(SDLProject 
    VERSION 1.0.0
    LANGUAGES CXX
    )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES 
    src/Main.cpp 
    src/Program.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_directories(${PROJECT_NAME} 
    PUBLIC lib/SDL2
    )

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC include
    )

target_link_libraries(${PROJECT_NAME}
    SDL2main
    SDL2
    )

