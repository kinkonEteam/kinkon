//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSword::CObjSword(float x, float y, int pos)//�n����邾���̕ϐ�
{						//�n���ꂽ�f�[�^��Draw�Ŏg���郁���o�ϐ��ɑ��
	m_x = x;
	m_y = y;
	m_pos = pos;
}

//�C�j�V�����C�Y
void CObjSword::Init()
{
	m_sx = 0;
	m_sy = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_s = 1;
}

//�A�N�V����
void CObjSword::Action()
{
	//��l���̈ʒu����Ɏ擾���A���
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_x = obj->GetX();
	m_y = obj->GetY();

	//��l�������ŕ\���ʒu�̕ύX�ppy,px
	if (m_pos == 0)     //��
	{
		m_sy = 1;
	}
	else if (m_pos == 1)//��
	{
		m_sx = -1;
	}
	else if (m_pos == 2)//��
	{
		m_sx = 1;
	}
	else			  //��
	{
		m_sy = -1;
	}


	m_ani_time+=m_s;			//�폜�����܂ŏ�ɑ���������
	if (m_ani_time > 5)		//�A�j���[�V��������Ԋu(�������ŃA�j���[�V�������x�ύX�o����)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
		m_s++;
	}

	if (m_ani_frame == 4)
	{
		this->SetStatus(false);	//�I�u�W�F�N�g�폜
		//Hits::DeleteHitBox;		//HitBox�폜
	}
}

//�h���[
void CObjSword::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top	= 0.0f + (32.0f*m_pos);
	src.m_left	= 0.0f + (32.0f*m_ani_frame);
	src.m_right =32.0f + (32.0f*m_ani_frame);
	src.m_bottom=32.0f + (32.0f*m_pos);

	//�\���ʒu�̐ݒ�
	dst.m_top	=(  0.0f + m_y) + (32 * m_sy);
	dst.m_left	=(  0.0f + m_x) + (32 * m_sx);
	dst.m_right =( 32.0f + m_x) + (32 * m_sx);
	dst.m_bottom=( 32.0f + m_y) + (32 * m_sy);
		
	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);
}