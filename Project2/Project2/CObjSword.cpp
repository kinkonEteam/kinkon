//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSword::Init()
{

}

//�A�N�V����
void CObjSword::Action()
{

}

//�h���[
void CObjSword::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


				//�؂���ʒu�̐ݒ�
	src.m_top	= 0.0f;
	src.m_left	= 0.0f;
	src.m_right =50.0f;
	src.m_bottom=40.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	= 0.0f;
	dst.m_left	= 0.0f;
	dst.m_right =50.0f;
	dst.m_bottom=40.0f;

	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);
}