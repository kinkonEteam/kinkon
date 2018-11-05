#pragma once

#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjEnemy :public CObj
{
public:
	CObjEnemy() {};
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
};