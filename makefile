all:
	gcc -IInclude/ Source/callbacks.c Source/camera.c Source/helpmenu.c Source/draw.c Source/game.c Source/light.c Source/model.c Source/texture.c Source/main.c -std=c11 -lSOIL -lglut32 -lopengl32 -lglu32 -lm -o beadando.exe
