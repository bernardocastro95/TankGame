#include "TankScene.h"
#include "ScoreBoardManager.h"
#include "CollisionManager.h"
#include "Game.h"

TankScene::TankScene()
{
	start();
}

TankScene::~TankScene()
{
}

void TankScene::draw()
{
	m_pCity -> draw();
	m_pTank->draw();

	ScoreBoardManager::Instance()->Draw();
}

void TankScene::update()
{
	m_pCity->update();
	m_pTank->setPosition(glm::vec2(m_mousePosition.x, m_pTank->getPosition().y));
	m_pTank->update();
	CollisionManager::squaredRadiusCheck(m_pTank, m_pCity);
	
}

void TankScene::clean()
{
}

void TankScene::handleEvents()
{
	auto wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:

				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:

				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;


				/************************************************************************/
			case SDLK_w:

				break;
			case SDLK_s:

				break;
			case SDLK_a:
				m_pTank->move(LEFT);
				break;
			case SDLK_d:
				m_pTank->move(RIGHT);
				break;
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:

				break;

			case SDLK_s:

				break;

			case SDLK_a:
				m_pTank->setIsMoving(false);
				break;
			case SDLK_d:
				m_pTank->setIsMoving(false);
				break;
			}

			break;
		default:
			break;
		}
	}
}

void TankScene::start()
{
	m_pCity = new City();
	addChild(m_pCity);

	m_pTank = new Tank();
	addChild(m_pTank);

	ScoreBoardManager::Instance()->Start();
}

glm::vec2 TankScene::getMousePosition()
{
	return m_mousePosition;
}
