#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
//m_�̓����o(�N���X���̕ϐ���֐�)�ŁApx�̓v���C���[��x���W
//�����o�֐��͒��ڌĂяo�����̂�public�A�֐����Ŏg����ϐ���private
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();	 //�C�j�V�����C�Y
	void Action();	 //�A�N�V����
	void Draw();	 //�h���[

	void SetX(float x);	//�ʒu�ύX�p
	void SetY(float y);
	float GetX();		//�ʒu�擾�p
	float GetY();
private:
//��l���̈ʒu�ƈړ��p
	float m_px;		 //�ʒu
	float m_py;
	float m_vx;		 //�ړ��x�N�g���p�ϐ�
	float m_vy;
	float m_posture; //�p��

	int m_ani_time;  //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��

	bool m_f;		//�U������p(true��false����)

	int m_hp;		//HP
};