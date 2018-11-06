#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_MAP1,
	OBJ_MAP2,
	OBJ_MAP3,
	OBJ_MAP4,
	OBJ_MAP5,
	OBJ_BOSS,
	OBJ_HERO,
	OBJ_SWORD,
	OBJ_FLYKIJI,
	OBJ_ITEM,
	OBJ_ENEMY,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_DOG,
	

	OBJ_TITLE,
	OBJ_GAME_OVER,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--
enum ITEM_ID
{
	ITEM_PEACH,				//�A�C�e���@���ł�
	ITEM_YELLOW_PEACH,		//�A�C�e���@����
	ITEM_PLUM,				//�A�C�e���@������
	ITEM_HORN,				//�A�C�e���@��
	ITEM_GOLD_BULLION,		//�A�C�e���@���̉��ז_
	ITEM_SILVER_BULLION,	//�A�C�e���@��̉��ז_
	ITEM_CLUB,				//�A�C�e���@���_
};
//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "SceneTitle.h"
#include "ObjMap1.h"
#include "ObjMap2.h"
#include "ObjMap3.h"
#include "ObjMap4.h"
#include "ObjMap5.h"
#include "ObjBoss.h"
#include "ObjHero.h"
#include"ObjItem.h"
#include"ObjDog.h"
#include"CObjSword.h"
#include"ObjEnemy.h"
#include"ObjEnemy2.h"
#include"ObjEnemy3.h"
#include"ObjTitle.h"
#include"Inventory.h"
#include"ObjGameOver.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------

#include "Scenefloor1.h"
#include "Scenefloor2.h"
#include "Scenefloor3.h"
#include "Scenefloor4.h"
#include "Scenefloor5.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include"SceneGameOver.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------