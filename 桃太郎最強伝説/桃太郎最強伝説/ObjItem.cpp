//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjItem.h"
#include "GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjItem::CObjItem(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjItem::Init()
{

	srand((unsigned)time(NULL)); // �����̏�����

	pb = rand() % 100;

	if (0 <= pb  && pb <= 50)
	{
		m_id = ITEM_CLUB;
	}
	else
	{
		m_id = ITEM_GOLD_BULLION;
	}

	//�A�C�e���̃q�b�g�{�b�N�X���쐬
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_ITEM, OBJ_ITEM, 1);


}

//�A�N�V����
void CObjItem::Action()
{
	switch (m_id)
	{
	case ITEM_PEACH:
				

		break;
	case ITEM_YELLOW_PEACH:

		break;
	case ITEM_PLUM:

		break;
	case ITEM_HORN:

		break;
	case ITEM_GOLD_BULLION:

		break;
	case ITEM_SILVER_BULLION:

		break;
	case ITEM_CLUB:

		break;
	}
}

void CObjItem::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	
	//�؂���ʒu�̐ݒ�
	src.m_top = 31.0f;
	src.m_left = 0.0f;
	src.m_right = 0.0f;
	src.m_bottom = 31.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 50.0f	+ m_px;
	dst.m_bottom = 50.0f + m_py;

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);

}