#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��
class CObjSword :public CObj
{
public:
	CObjSword(float x, float y,int m_pos);//�R���X�g���N�^
	~CObjSword() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;		//�ʒu
	float m_y;
	int pos;
};