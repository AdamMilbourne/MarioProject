#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include <iostream>
#include "Texture2D.h"
#include "Commons.h"
#include "GameScreenManager.h"
using namespace std;

GameScreenManager* game_screen_manager;
Uint32 g_old_time;

SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
//Texture2D* g_texture = nullptr;

//functions initiated
bool InitSDL();
void CloseSDL();
bool Update();
void Render();

int main(int argc, char* args[])
{
	bool quit = false;

	if (InitSDL())
	{
		game_screen_manager = new GameScreenManager(g_renderer, SCREEN_LEVEL1);
		//start time
		g_old_time = SDL_GetTicks();
		while (!quit)
		{
			Render();
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

	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

	if (g_renderer != nullptr)
	{
		//init png
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags))
		{
			cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
			return false;
		}
	}
	else
	{
		cout << "Renderer could not initialise. Error: " << SDL_GetError();
		return false;
	}
	//load background texture
	//g_texture = new Texture2D(g_renderer);

	//if(!g_texture->LoadFromFile("Images/test.bmp"))
	//{
	//	return false;
	//}

	SDL_Texture* LoadTextureFromFile(string path);
}

void CloseSDL()
{
	//destroy game screen manager
	delete game_screen_manager;
	game_screen_manager = nullptr;

	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	IMG_Quit();
	SDL_Quit();

	SDL_DestroyRenderer(g_renderer);

	g_renderer = nullptr;

	//release texture
	//delete g_texture;
	//g_texture = nullptr;
}

bool Update()
{
	Uint32 new_time = SDL_GetTicks();
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
	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;
	return false;
}

void Render()
{
	//clear screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);
	
	//g_texture->Render(Vector2D(), SDL_FLIP_NONE);
	game_screen_manager->Render();

	//update the screen
	SDL_RenderPresent(g_renderer);
}





