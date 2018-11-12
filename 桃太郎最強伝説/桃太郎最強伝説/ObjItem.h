#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define ITEM_TOP	(111.0f)
#define ITEM_LEFT	(256.0f)
#define ITEM_SIZE	(50.0f)

#define ITEM_LEFT_OFF_SET	(2)
#define ITEM_TOP_OFF_SET	(1)
#define ITEM_RESOURCE_TOP	(50.0f)
#define ITEM_RESOURCE_SIZE	(50.0f)

//�I�u�W�F�N�g�F�L�����N�^�[�u���b�N
class CObjItem : public CObj
{
	public:
		CObjItem(float x,float y);
		~CObjItem() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		//�A�C�e���q�b�g�{�b�N�X�p
		float m_x;	
		float m_y;
		//�}�b�v�ʒu�ݒ�p
		float m_px;
		float m_py;

		int m_id;	//�A�C�e��ID
		int pb;
};




