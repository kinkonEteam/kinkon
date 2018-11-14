//使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemy.h"

//使用するネームスペース
using namespace GameL;
//イニシャライズ
void CObjEnemy::Init()
{
	m_x = 600;
	m_y = 400;
	m_vx = 0.0f;
	m_vy = 0.0f;


	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY, 1);

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

}
//アクション
void CObjEnemy::Action()
{
	m_vx = -10.0f;
	m_vy = 0.0f;

	float r = 0.0f;
	r = m_vx*m_vx + m_vy*m_vy;
	r = sqrt(r);
	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r*m_vx;
		m_vy = 1.0f / r*m_vy;
	}
	m_vx *= 2.0f;
	m_vy *= 2.0f;

	m_x += m_vx;
	m_y *= m_vy;
}
//ドロー
void CObjEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//切り取り位置
	RECT_F dst;//表示位置

	src.m_top   = 0.0f;
	src.m_left  = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom= 50.0f;

	dst.m_top   = 0.0f+m_y;
	dst.m_left  = 32.0f+m_x;
	dst.m_right = 0.0f+m_x;
	dst.m_bottom= 32.0f+m_y;

	Draw::Draw(5, &src, &dst, c, 0.0f);
}