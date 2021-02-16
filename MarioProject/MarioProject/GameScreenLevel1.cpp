#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
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
}


void GameScreenLevel1::Render()
{
	//draw background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}


void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}

bool GameScreenLevel1::SetUpLevel1()
{
	//Load Texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("images/test.bmp"))
	{
		cout << "Failed to load background texture!" << endl;
		return false;
	}
}
