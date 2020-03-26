#include "Tank.h"
#include "Game.h"

Tank::Tank()
{
	TheTextureManager::Instance()->load("../Assets/textures/Tank.png",
		"tank", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("tank");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::TANK);
	setVelocity(glm::vec2(0.0f, 0.0f));
}

Tank::~Tank()
{
}

void Tank::draw()
{
	int x = getPosition().x;
	int y = getPosition().y;

	TheTextureManager::Instance()->draw("tank", x, y,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Tank::update()
{
	m_checkBounds();
}

void Tank::clean()
{
}

void Tank::move(Move move)
{
	auto velocity = getVelocity();

	switch (move)
	{
	case RIGHT:
		setVelocity(glm::vec2(1.0 * m_maxSpeed, 0.0f));
		break;
	case LEFT:
		setVelocity(glm::vec2(-1.0 * m_maxSpeed, 0.0f));
		break;
	}
}


bool Tank::getIsMoving()
{
	return m_moving;
}

void Tank::setIsMoving(bool newState)
{
	m_moving = newState;
}

void Tank::m_checkBounds()
{
	if (getPosition().x >= Config::SCREEN_WIDTH - getWidth() * 0.5f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH - getWidth() * 0.5f, getPosition().y));
	}
	if (getPosition().x <= getWidth() * 0.5f)
	{
		setPosition(glm::vec2(getWidth() * 0.5f, getPosition().y));
	}
}
