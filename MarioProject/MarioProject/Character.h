#pragma once
#include <SDL.h>
#include <iostream>
#include "Commons.h"
using namespace std;

class Texture2D;

class Character
{
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

	bool m_moving_left;
	bool m_moving_right;
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;

	

	virtual void MoveLeft(float deltatime);
	virtual void MoveRight(float deltatime);
	virtual void AddGravity(float deltatime);
	virtual void Jump();
	
public:
	Character(SDL_Renderer* renderer, string imagepath, Vector2D start_position);
	~Character();

	virtual void Render();
	virtual void Update(float deltatime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPostion();
private:

	FACING m_facing_direction;
};

