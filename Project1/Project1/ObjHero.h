#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
					//��l���̈ʒu�ƈړ��p
	float m_px;		//�ʒu
	float m_py;
	float m_vx;		//�ړ��x�N�g���p�ϐ�
	float m_vy;
};