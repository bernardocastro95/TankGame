#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Island.h"
#include "Ocean.h"
#include "Cloud.h"
#include "Config.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	Plane* m_pPlane;
	Island* m_pIsland;
	Ocean* m_pOcean;

	int m_cloudNum = Config::CLOUD_NUM;
	std::vector<Cloud*> m_pClouds;
	void m_buildClouds();

	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
