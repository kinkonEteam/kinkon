#pragma once

#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjEnemy2 :public CObj
{
public:
	CObjEnemy2() {};
	~CObjEnemy2() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
}; 
