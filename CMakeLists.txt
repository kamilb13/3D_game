cmake_minimum_required(VERSION 3.29)
project(FPS_3D_OpenGL)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        GLEW
        GIT_REPOSITORY https://github.com/nigels-com/glew.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(GLEW)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(glm)

add_executable(${PROJECT_NAME}
        main.cpp
        Crosshair.cpp
        Crosshair.h
        Bullet.cpp
        Bullet.h
        EventHandler.cpp
        EventHandler.h
        Target.h
        Target.cpp
        Map.cpp
        Map.h
        GLEWInitializer.h
        GLEWInitializer.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw GLEW glm GL)

