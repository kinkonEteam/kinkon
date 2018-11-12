//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include"GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"Scenefloor1.h"
#include"GameHead.h"

//�R���X�g���N�^
CScenefloor1::CScenefloor1()
{

}

//�f�X�g���N�^
CScenefloor1::~CScenefloor1()
{

}

//���������\�b�h
void CScenefloor1::InitScene()
{
	//�O���f�[�^�̓ǂݍ��݁i�K�w1���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;			//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"Book1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[56][56];
	int count = 1;
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 1;
			}

			count += 2;
		}
	}

	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"�}�b�v�`�b�v.png", 1, TEX_SIZE_141_47);	//�}�b�v
	Draw::LoadImage(L"�����Y.png", 0, TEX_SIZE_512);	//�����Y
	Draw::LoadImage(L"�A�C�e��.png", 4, TEX_SIZE_512);

	//�K�w1�I�u�W�F�N�g�쐬
	CObjMap1* objb = new CObjMap1(map);
	Objs::InsertObj(objb, OBJ_MAP1, 1);
}

//���s�����\�b�h
void CScenefloor1::Scene()
{

}