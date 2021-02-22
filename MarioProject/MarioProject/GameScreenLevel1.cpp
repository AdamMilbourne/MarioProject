#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "Character.h"
using namespace std;

//constructor
GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	m_renderer = renderer;
	SetUpLevel1();
}

//destructor
GameScreenLevel1::~GameScreenLevel1()
{
	m_renderer = nullptr;

	delete m_background_texture;
	m_background_texture = nullptr;

	delete my_character;
	my_character = nullptr;
}


void GameScreenLevel1::Render()
{
	//draw background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	my_character->Render();
}


void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//update character
	my_character->Update(deltaTime, e);
}

bool GameScreenLevel1::SetUpLevel1()
{
	//set up player
	my_character = new Character(m_renderer, "images/Mario.png", Vector2D(64, 330));
	

	//Load Texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("images/test.bmp"))
	{
		cout << "Failed to load background texture!" << endl;
		return false;
	}

	


}
