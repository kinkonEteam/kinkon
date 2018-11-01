//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include <stdlib.h>
#include <time.h>
#include "ObjItem.h"
#include "GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjItem::Init()
{
	srand(time(NULL));
	m_id = ITEM_PEACH + rand() % ITEM_CLUB;
}

//�A�N�V����
void CObjItem::Action()
{

}

void CObjItem::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	
	//�؂���ʒu�̐ݒ�
	src.m_top =ITEM_RESOURCE_TOP;
	src.m_left = ITEM_RESOURCE_SIZE*(m_id-ITEM_PEACH)+ITEM_LEFT_OFF_SET;
	src.m_right = src.m_left + ITEM_SIZE + ITEM_LEFT_OFF_SET;
	src.m_bottom = src.m_top + ITEM_SIZE - ITEM_TOP_OFF_SET;

	//�\���ʒu�̐ݒ�
	dst.m_top = 128.0f ;
	dst.m_left = 128.0f;
	dst.m_right = dst.m_left+ITEM_SIZE;
	dst.m_bottom = dst.m_top+ITEM_SIZE;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}