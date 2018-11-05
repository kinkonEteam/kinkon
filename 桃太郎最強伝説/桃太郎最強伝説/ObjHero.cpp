//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 0.0f;		//�ʒu
	m_py = 0.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;

	m_posture = 0.0f;	//����(0.0f)��(1.0f) �E(2.0f) �w��(3.0f)
	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[��
}

//�A�N�V����
void CObjHero::Action()
{
	//�x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//��l���̈ړ��Ƀx�N�g��������
	if (Input::GetVKey(VK_RIGHT) == true)//��
	{
		m_vx += 1.0f;
		m_posture = 2.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_UP) == true)	//��
	{
		m_vy -= 1.0f;
		m_posture = 3.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_DOWN) == true)//��
	{
		m_vy += 1.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)//��
	{
		m_vx -= 1.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;	//�L�[���͂��Ȃ��ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;		
	}

	if (m_ani_time > 6)		//�A�j���[�V��������Ԋu(�������ŃA�j���[�V�������x�ύX�o����)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
		m_ani_frame = 0;	//�t���[��4��0�ɖ߂�

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�ړ��x�N�g�������W�ɉ��Z����(�������ňړ����x�ύX�o����)
	m_px += m_vx * 2.0f;			
	m_py += m_vy * 2.0f;

	//�X�N���[��
	CObjMap1*b = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	//����
//	if (m_px < 80)
	{
		m_px = 0;
		b->SetScroll(b->GetScroll());
	}
	//�E��
//	if (m_px > 300)
	{
		m_px = 400;
		b->SetScroll(b->GetScroll());
	}
	//���
	//	if (m_py > 80)
	{
		m_py = 0;
		b->SetScrolly(b->GetScrolly());
	}
	//����
	//	if (m_py > 80)
	{
		m_py = 300;
		b->SetScrolly(b->GetScrolly());
	}

/*	//�u���b�N�Ƃ̓����蔻��
	CObjMap1*pb = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	pb->Map1Hit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);*/
}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] = { 0,1,2,1, };
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top	=50.0f *  m_posture-1;
	src.m_left  = 0.0f + (AniData[m_ani_frame] * 48);
	src.m_right	=48.0f + (AniData[m_ani_frame] * 48);
	src.m_bottom=50.0f * (m_posture + 1)-3;


	//�\���ʒu�̐ݒ�
	dst.m_top	= 0.0f +m_py;
	dst.m_left	= 0.0f +m_px;
	dst.m_right =50.0f +m_px;
	dst.m_bottom=50.0f +m_py;


	Draw::Draw(0, &src, &dst, c, 0.0f);

}