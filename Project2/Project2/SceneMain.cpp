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
	Audio::LoadAudio(0, L"", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(0, L"", SOUND_TYPE::EFFECT);


	//外部グラフィックを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"桃太郎.png", 0,TEX_SIZE_512);

	//外部グラフィックを読み込み1番に登録(512×512ピクセル)
	Draw::LoadImage(L"アイテム.png", 1, TEX_SIZE_512);
	
	//外部グラフィックを読み込み2番に登録(512×512ピクセル)
	Draw::LoadImage(L"OTOMO.GIF", 2, TEX_SIZE_512);

	//外部グラフィックを読み込み3番に登録(512×512ピクセル)
	Draw::LoadImage(L"Sword.png", 3, TEX_SIZE_512);
	
	
	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();		//オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 1);	//マネージャに登録

	//アイテムオブジェクト作成
	CObjItem* i = new CObjItem();		//オブジェクト作成
	Objs::InsertObj(i, OBJ_ITEM, 1);	//マネージャに登録

	//犬オブジェクト作成
	CObjDog* D = new CObjDog();			//オブジェクト作成
	Objs::InsertObj(D, OBJ_DOG, 2);		//マネージャに登録
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}