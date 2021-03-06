//使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemy2.h"

//使用するネームスペース
using namespace GameL;
//イニシャライズ
void CObjEnemy2::Init()
{
	m_x = 500;
	m_y = 950;

	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY2, 1);
}
//アクション
void CObjEnemy2::Action()
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
	m_vx *= 2.5f;
	m_vy *= 2.5f;

	m_x += m_vx;
	m_y *= m_vy;

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

}
//ドロー
void CObjEnemy2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//切り取り位置
	RECT_F dst;//表示位置

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 50.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(6, &src, &dst, c, 0.0f);
}