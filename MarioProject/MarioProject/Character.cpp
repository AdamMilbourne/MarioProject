#include "Character.h"
#include "Texture2D.h"

Character::Character(SDL_Renderer* renderer, string imagepath, Vector2D start_position)
{
	m_renderer = renderer;

	m_position = start_position;

	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagepath))
	{
		cout << "Failed to load Mario Image" << endl;
	}

	m_facing_direction = FACING_RIGHT;

	m_moving_left = false;
	m_moving_right = false;
}
Character::~Character()
{
	m_renderer = nullptr;
}

void Character::Render()
{
	m_texture->Render(m_position, SDL_FLIP_NONE);

	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}
void Character::Update(float deltatime, SDL_Event e)
{
	if (m_moving_left)
	{
		MoveLeft(deltatime);
	}
	else if(m_moving_right)
	{
		MoveRight(deltatime);
	}
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			//m_position.x = m_position.x - 1;
			//m_facing_direction = FACING_LEFT;
			m_moving_left = true;
			cout << "left key pressed" << endl;


		case SDLK_RIGHT:
			//m_position.x = m_position.x + 1;
			//m_facing_direction = FACING_RIGHT;
			m_moving_right = true;
			cout << "right key pressed" << endl;
		}
		
		break;
	case SDL_KEYUP:
	{
	case SDLK_LEFT:
		//m_position.x = m_position.x - 1;
		//m_facing_direction = FACING_LEFT;
		m_moving_left = false;
		cout << "left key pressed" << endl;


	case SDLK_RIGHT:
		//m_position.x = m_position.x + 1;
		//m_facing_direction = FACING_RIGHT;
		m_moving_right = false;
		cout << "right key pressed" << endl;
	}

	}
}
void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;

}
Vector2D Character::GetPostion()
{
	return m_position;
}

void Character::MoveRight(float deltatime)
{
	m_position.x = m_position.x + 1;
	m_facing_direction = FACING_RIGHT;
}

void Character::MoveLeft(float deltatime)
{
	m_position.x = m_position.x - 1;
	m_facing_direction = FACING_LEFT;
}

