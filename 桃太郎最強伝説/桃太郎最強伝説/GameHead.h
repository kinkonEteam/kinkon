#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
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

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
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
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--
enum ITEM_ID
{
	ITEM_PEACH,				//アイテム　桃です
	ITEM_YELLOW_PEACH,		//アイテム　黄桃
	ITEM_PLUM,				//アイテム　すもも
	ITEM_HORN,				//アイテム　つの
	ITEM_GOLD_BULLION,		//アイテム　金の延べ棒
	ITEM_SILVER_BULLION,	//アイテム　銀の延べ棒
	ITEM_CLUB,				//アイテム　棍棒
};
//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
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

//ゲームシーンクラスヘッダ------------------------

#include "Scenefloor1.h"
#include "Scenefloor2.h"
#include "Scenefloor3.h"
#include "Scenefloor4.h"
#include "Scenefloor5.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include"SceneGameOver.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------