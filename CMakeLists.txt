cmake_minimum_required(VERSION 3.13)
project(beadando C)

set(CMAKE_C_STANDARD 11)

add_executable(beadando Include/callbacks.h Include/camera.h Include/constants.h Include/draw.h Include/model.h Include/helpmenu.h Include/texture.h Include/light.h Include/game.h Source/callbacks.c Source/camera.c Source/helpmenu.c Source/draw.c Source/game.c Source/light.c Source/model.c Source/texture.c Source/main.c)
target_link_libraries(beadando -lSOIL -lglut32 -lopengl32 -lglu32 -lm )