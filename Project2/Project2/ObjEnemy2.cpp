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
	m_x = 0;
	m_y = 0;

	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY2, 1);
}
//アクション
void CObjEnemy2::Action()
{
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

	Draw::Draw(1, &src, &dst, c, 0.0f);
}