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
}

//�A�N�V����
void CObjHero::Action()
{
	//�x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//��l���@�̈ړ��Ƀx�N�g��������
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 1.0f;
		m_posture = 2.0f;
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 1.0f;
		m_posture = 3.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 1.0f;
		m_posture = 0.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 1.0f;
		m_posture = 1.0f;
	}

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�ړ��x�N�g�������W�ɉ��Z����(�������ňړ����x�ύX�o����)
	m_px += m_vx * 2.0f;			
	m_py += m_vy * 2.0f;
}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] = { 1,0,2,0, };
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top	=50.0f *  m_posture;
	src.m_left	=48.0f;
	src.m_right	=96.0f;
	src.m_bottom=50.0f * (m_posture + 1);


				//�\���ʒu�̐ݒ�
	dst.m_top	= 0.0f +m_py;
	dst.m_left	= 0.0f +m_px;
	dst.m_right =32.0f +m_px;
	dst.m_bottom=32.0f +m_py;


	Draw::Draw(0, &src, &dst, c, 0.0f);

}