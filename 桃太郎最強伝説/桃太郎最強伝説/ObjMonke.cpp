//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "ObjMonke.h"
#include "GameHead.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMonke::Init()
{

}

//�A�N�V����
void CObjMonke::Action()
{

}

void CObjMonke::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 64.0f;
	src.m_right = 96.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 150.0f;
	dst.m_left = 100.0f;
	dst.m_right = 32.0f + 100.0f;
	dst.m_bottom = 32.0f + 150.0f;

	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);

}