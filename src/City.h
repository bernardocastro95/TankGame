#pragma once
#ifndef __CITY__
#define __CITY__
#include "DisplayObject.h"

class City : public DisplayObject
{
public:
	City();
	~City();
	void draw() override;
	void update() override;
	void clean() override;
private:
	void m_move();
	void m_checkBounds();
	void m_reset();
};
#endif

