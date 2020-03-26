#pragma once
#ifndef __TANK__
#define __TANK__
#include "DisplayObject.h"
#include "Move.h"

class Tank : public DisplayObject
{
public:
	Tank();
	~Tank();

	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void move(Move move);
	bool getIsMoving();
	void setIsMoving(bool newState);
private:
	float m_maxSpeed;
	bool m_moving;

	void m_checkBounds();
};
#endif

