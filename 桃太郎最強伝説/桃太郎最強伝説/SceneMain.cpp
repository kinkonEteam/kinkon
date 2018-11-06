//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\SceneObjManager.h"
#include"GameL\UserData.h"


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
	//外部データの読み込み（階層1情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;			//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"Book1.csv", &size);//外部データ読み込み

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


	//BGM・SEの読み込み
	Audio::LoadAudio(0, L"", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(0, L"", SOUND_TYPE::EFFECT);


	//外部グラフィックを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"桃太郎.png", 0,TEX_SIZE_512);

	//外部グラフィックを読み込み1番に登録(512×512ピクセル)
	Draw::LoadImageW(L"マップチップ.png", 1, TEX_SIZE_141_47);	//マップ
	
	//外部グラフィックを読み込み2番に登録(512×512ピクセル)
	Draw::LoadImage(L"OTOMO.GIF", 2, TEX_SIZE_512);

	//外部グラフィックを読み込み3番に登録(512×512ピクセル)
	Draw::LoadImage(L"Sword.png", 3, TEX_SIZE_512);

	//外部グラフィックを読み込み4番に登録(512×512ピクセル)
	Draw::LoadImage(L"アイテム.png", 4, TEX_SIZE_512);
	
	
	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();		//オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 1);	//マネージャに登録

	//アイテムオブジェクト作成
	CObjItem* i = new CObjItem();		//オブジェクト作成
	Objs::InsertObj(i, OBJ_ITEM, 1);	//マネージャに登録

	//犬オブジェクト作成
	CObjDog* D = new CObjDog();			//オブジェクト作成
	Objs::InsertObj(D, OBJ_DOG, 2);		//マネージャに登録

	//階層1オブジェクト作成
	CObjMap1* objb = new CObjMap1(map);
	Objs::InsertObj(objb, OBJ_MAP1, 1);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}