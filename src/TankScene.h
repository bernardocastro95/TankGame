#pragma once
#ifndef __TANK_SCENE__
#define __TANK_SCENE__
#include "Scene.h"
#include "City.h"
#include "Tank.h"
#include "Config.h"


class TankScene : public Scene
{
public:
	TankScene();
	~TankScene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	glm::vec2 getMousePosition();

private:
	Tank* m_pTank;
	City* m_pCity;

	glm::vec2 m_mousePosition;
};
#endif
