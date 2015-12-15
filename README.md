# Raytracer

A simple raytracer, implemented in C++, using backwards raytracing.

It is possible to move the camera by using the arrow keys.

To compile:
- If you don't have the SDL2 installed, you can do it via brew:
	- brew update
	- brew install sdl2
- Run the commands: 
	- sdl2-config --cflags
	- sdl2-config --libs
- Copy/Paste the results in the SDL_INC and SDL_LIB fields of the Makefile
- make && ./raytracer
