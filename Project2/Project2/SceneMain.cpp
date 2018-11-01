//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\SceneObjManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//BGM�ESE�̓ǂݍ���
	Audio::LoadAudio(0, L"", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(0, L"", SOUND_TYPE::EFFECT);


	//�O���O���t�B�b�N��ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�����Y.png", 0,TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�A�C�e��.png", 1, TEX_SIZE_512);
	
	//�O���O���t�B�b�N��ǂݍ���2�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"OTOMO.GIF", 2, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"Sword.png", 3, TEX_SIZE_512);
	
	
	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();		//�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 1);	//�}�l�[�W���ɓo�^

	//�A�C�e���I�u�W�F�N�g�쐬
	CObjItem* i = new CObjItem();		//�I�u�W�F�N�g�쐬
	Objs::InsertObj(i, OBJ_ITEM, 1);	//�}�l�[�W���ɓo�^

	//���I�u�W�F�N�g�쐬
	CObjDog* D = new CObjDog();			//�I�u�W�F�N�g�쐬
	Objs::InsertObj(D, OBJ_DOG, 2);		//�}�l�[�W���ɓo�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}