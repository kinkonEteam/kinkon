#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define ITEM_KIND (2)
#define ITEM_NUM (6)


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
	bool item_id[ITEM_KIND][ITEM_NUM];//�A�C�e���ۑ��p:[���][��]

	
};





