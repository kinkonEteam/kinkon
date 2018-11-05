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

	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}
//アクション
void CObjEnemy::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
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