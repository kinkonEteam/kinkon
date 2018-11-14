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

	int m_ani_time;
	int m_ani_frame;

	float m_speed_power;
	float m_ani_max_time;

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};