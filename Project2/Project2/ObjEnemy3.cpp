//�g�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemy3.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�C�j�V�����C�Y
void CObjEnemy3::Init()
{
	m_x = 200;
	m_y = 300;

	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY3, 1);
}
//�A�N�V����
void CObjEnemy3::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
}
//�h���[
void CObjEnemy3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�؂���ʒu
	RECT_F dst;//�\���ʒu

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 50.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}