#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class CObjInventory : public CObj
{
public:
	CObjInventory() {};
	~CObjInventory() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;	//�A�C�e���q�b�g�{�b�N�X�p
	float m_y;	//�A�C�e���q�b�g�{�b�N�X�p
	int m_id;	//�A�C�e��ID
	int pb;		//�m���p�ϐ�
	bool m_del;	//�폜�`�F�b�N


};





