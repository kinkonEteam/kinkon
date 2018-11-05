//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\SceneObjManager.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//BGM・SEの読み込み
	//Audio::LoadAudio(0, L"", SOUND_TYPE::BACK_MUSIC);

	//Audio::LoadAudio(0, L"", SOUND_TYPE::EFFECT);


	//外部グラフィックを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"鬼原画 青鬼 新二.png", 0, TEX_SIZE_151_200);
	Draw::LoadImage(L"鬼原画 黄鬼 新二.png", 1, TEX_SIZE_151_200);
	Draw::LoadImage(L"鬼原画 緑鬼 新二.png", 2, TEX_SIZE_151_200);

/*	//外部グラフィックを読み込み1番に登録(512×512ピクセル)
	Draw::LoadImage(L"アイテム.png", 1, TEX_SIZE_512);*/

	//敵オブジェクト作成
	CObjEnemy* obj = new CObjEnemy();//オブジェクト作成
	Objs::InsertObj(obj, OBJ_ENEMY, 1);//マネージャに登録

	//敵オブジェクト作成
	CObjEnemy2* obj2 = new CObjEnemy2();//オブジェクト作成
	Objs::InsertObj(obj2, OBJ_ENEMY2, 2);//マネージャに登録

	//敵オブジェクト作成
	CObjEnemy3* obj3 = new CObjEnemy3();//オブジェクト作成
	Objs::InsertObj(obj3, OBJ_ENEMY3, 3);//マネージャに登録

/*	//アイテムオブジェクト作成
	CObjItem* i = new CObjItem();//オブジェクト作成
	Objs::InsertObj(i, OBJ_ITEM, 1);//マネージャに登録*/


}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}