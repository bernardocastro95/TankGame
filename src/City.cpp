#include "City.h"
#include "Game.h"

City::City()
{
	TheTextureManager::Instance()->load("../Assets/textures/Cyberpunk.png",
		"city", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("city");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0.0f, -960.0f));
	setIsColliding(false);
	setType(CITY);
	setVelocity(glm::vec2(0.0f, 5.0f));
}

City::~City()
{
}

void City::draw()
{
	int x = getPosition().x;
	int y = getPosition().y;

	TheTextureManager::Instance()->draw("city", x, y,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void City::update()
{
	m_move();
	m_checkBounds();
}

void City::clean()
{
}

void City::m_move()
{
	setPosition(getPosition() + getVelocity());
}

void City::m_checkBounds()
{
	if (getPosition().y >= 0.0f)
	{
		m_reset();
	}
}

void City::m_reset()
{
	setPosition(glm::vec2(0.0f, -960.0f));
}
