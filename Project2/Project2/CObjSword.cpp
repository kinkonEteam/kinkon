//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSword::CObjSword(float x, float y, int m_pos)//�n����邾���̕ϐ�
{//�n���ꂽ�ʒu�ƌ����f�[�^��Draw�Ŏg����ϐ��ɑ��
	m_x = x;
	m_y = y;
	pos = m_pos;
}

//�C�j�V�����C�Y
void CObjSword::Init()
{
	px = 0;
	py = 0;
}

//�A�N�V����
void CObjSword::Action()
{

}

//�h���[
void CObjSword::Draw()
{
	int AniData[4] = { 0,1,2,3, };
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu
				//�؂���ʒu�̐ݒ�

	//��l�������Ő؂���ʒu�ύX�ƕ\���ʒu�̕ύX
	if (pos == 0)     //��
	{
		py = 1;
	}
	else if (pos == 1)//��
	{
		px = -1;
	}
	else if (pos == 2)//��
	{
		px = 1;
	}
	else			  //��
	{
		py = -1;
	}

	src.m_top	= 0.0f;
	src.m_left	= 0.0f;
	src.m_right =32.0f;
	src.m_bottom=40.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	=(  0.0f + m_y) + (32 * py);
	dst.m_left	=(  0.0f + m_x) + (32 * px);
	dst.m_right =( 32.0f + m_x) + (32 * px);
	dst.m_bottom=( 32.0f + m_y) + (32 * py);
		
	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);
}