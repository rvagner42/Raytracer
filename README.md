# Raytracer

A simple raytracer, implemented in C++, using backwards raytracing.

(does not currently compile)
To compile:
- If you don't have the SDL2 installed, you can do it via brew:
	- brew update
	- brew install sdl2
- Run the commands: 
	- sdl2-config --cflags
	- sdl2-config --libs
- Copy/Paste the results in the SDL_INC and SDL_LIB fields of the Makefile
- make && ./raytracer
