/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Process.cpp                                        .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 13:03:15 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 14:09:44 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Process.hpp"

Process::Process(void): _win(NULL), _screen(NULL)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL_Init() error." << std::endl;
		exit(0);
	}
	this->_win = SDL_CreateWindow("Window", 0, 0, W, H, SDL_WINDOW_SHOWN);
	if (this->_win == NULL)
	{
		std::cerr << "SDL_CreateWindow() error." << std::endl;
		exit(0);
	}
	this->_screen = SDL_GetWindowSurface(this->_win);
	if (this->_screen == NULL)
	{
		std::cerr << "SDL_GetWindowSurface() error." << std::endl;
		exit(0);
	}
	SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0x00, 0x00, 0x00));
	SDL_UpdateWindowSurface(this->_win);
	return ;
}

Process::Process(char const *win_name): _win(NULL), _screen(NULL)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL_Init() error." << std::endl;
		exit(0);
	}
	this->_win = SDL_CreateWindow(win_name, 0, 0, W, H, SDL_WINDOW_SHOWN);
	if (this->_win == NULL)
	{
		std::cerr << "SDL_CreateWindow() error." << std::endl;
		exit(0);
	}
	this->_screen = SDL_GetWindowSurface(this->_win);
	if (this->_screen == NULL)
	{
		std::cerr << "SDL_GetWindowSurface() error." << std::endl;
		exit(0);
	}
	SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0x00, 0x00, 0x00));
	SDL_UpdateWindowSurface(this->_win);
	return ;
}

Process::~Process(void)
{
	SDL_DestroyWindow(this->_win);
	SDL_Quit();
	return ;
}

// ----- Member functions -----

void					Process::update(void)
{
	SDL_UpdateWindowSurface(this->_win);
}

bool					Process::check_ticks(int n)
{
	static Uint32		ticks = SDL_GetTicks();

	if (ticks + n < SDL_GetTicks())
	{
		ticks = SDL_GetTicks();
		return (true);
	}
	return (false);
}

// ----- Getters & Setters -----

SDL_Surface				*Process::getScreen(void) const
{
	return (this->_screen);
}
