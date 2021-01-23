#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include <iostream>
using namespace std;

SDL_Window* g_window = nullptr;

//functions initiated
bool InitSDL();
void CloseSDL();
bool Update();

int main(int argc, char* args[])
{
	bool quit = false;

	if (InitSDL())
	{
		while (!quit)
		{
			quit = Update();
		}
	}
	CloseSDL();

	return 0;
}

bool InitSDL()
{
	//setup SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. ERROR: " << SDL_GetError();
		return false;
	}
	else
	{
		//create window if setup success
		g_window = SDL_CreateWindow("Games Engine Creation",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (g_window == nullptr)
		{
			cout << "window was not created. ERROR: " << SDL_GetError();
			return false;
		}
	}
}

void CloseSDL()
{
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	IMG_Quit();
	SDL_Quit();

}

bool Update()
{
	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type)
	{
		//click x = quit
	case SDL_QUIT:
			return true;


		switch (e.key.keysym.sym==SDLK_q);
		//quit on q pressed
	case SDL_KEYUP:
		return true;


		switch (e.key.keysym.sym == SDL_BUTTON_RIGHT);
		//quit when right click anywhere in the window
	case SDL_MOUSEBUTTONDOWN:
		return true;
	}
	return false;
}

