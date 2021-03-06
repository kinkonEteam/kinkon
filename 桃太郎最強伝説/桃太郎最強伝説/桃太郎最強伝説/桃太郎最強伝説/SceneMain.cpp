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

	//外部グラフィックを読み込み5番に登録(151*200ピクセル)
	Draw::LoadImage(L"鬼原画 青鬼 新二.png", 5, TEX_SIZE_151_200);

	//外部グラフィックを読み込み6番に登録(151*200ピクセル)
	Draw::LoadImage(L"鬼原画 黄鬼 新二.png", 6, TEX_SIZE_151_200);

	//外部グラフィックを読み込み7番に登録(151*200ピクセル)
	Draw::LoadImage(L"鬼原画 緑鬼 新二.png", 7, TEX_SIZE_151_200);
	
	//外部グラフィックファイルを読み込み8番に登録
	Draw::LoadImage(L"鬼原画 赤鬼 新二.png", 9, TEX_SIZE_151_200);

	//主人公オブジェクト作成
//	CObjHero* obj = new CObjHero();		//オブジェクト作成
	//Objs::InsertObj(obj, OBJ_HERO, 1);	//マネージャに登録

	//アイテムオブジェクト作成
	CObjPeach* i = new CObjPeach();		//オブジェクト作成
	Objs::InsertObj(i, OBJ_PEACH, 1);	//マネージャに登録

	CObjYellowPeach* yp = new CObjYellowPeach();		//オブジェクト作成
	Objs::InsertObj(yp, OBJ_YELLOW_PEACH, 1);	//マネージャに登録

	CObjPlum* pl = new CObjPlum();		//オブジェクト作成
	Objs::InsertObj(pl, OBJ_PLUM, 1);	//マネージャに登録

	CObjHone* ho = new CObjHone();		//オブジェクト作成
	Objs::InsertObj(ho, OBJ_HONE, 1);	//マネージャに登録

	CObjGoldBullion* gb = new CObjGoldBullion();		//オブジェクト作成
	Objs::InsertObj(gb, OBJ_GOLD_BULLION, 1);	//マネージャに登録

	CObjSilverBullion* sb = new CObjSilverBullion();		//オブジェクト作成
	Objs::InsertObj(sb, OBJ_SILVER_BULLION, 1);	//マネージャに登録

	CObjClub* cl = new CObjClub();		//オブジェクト作成
	Objs::InsertObj(cl, OBJ_CLUB, 1);	//マネージャに登録

	//犬オブジェクト作成
	CObjDog* D = new CObjDog();			//オブジェクト作成
	Objs::InsertObj(D, OBJ_DOG, 2);		//マネージャに登録
	
	//サルオブジェクト作成
	CObjMonke* M = new CObjMonke();			//オブジェクト作成
	Objs::InsertObj(M, OBJ_MONKE, 2);		//マネージャに登録
	
	//キジオブジェクト作成
	CObjPheasant* P = new CObjPheasant();			//オブジェクト作成
	Objs::InsertObj(P, OBJ_PHEASANT, 2);		//マネージャに登録

	//青鬼オブジェクト作成
	CObjEnemy* e = new CObjEnemy();
	Objs::InsertObj(e, OBJ_ENEMY, 1);

	//黄鬼オブジェクト作成
	CObjEnemy2* e2 = new CObjEnemy2();
	Objs::InsertObj(e2, OBJ_ENEMY2, 1);

	//緑鬼オブジェクト作成
	CObjEnemy3* e3 = new CObjEnemy3();
	Objs::InsertObj(e3, OBJ_ENEMY3, 1);

	//イベントオブジェクト作成
	CObjEveDog* eve = new CObjEveDog();
	Objs::InsertObj(eve, OBJ_TALK, 3);

	//階層1オブジェクト作成
	CObjMap1* objb = new CObjMap1(map);
	Objs::InsertObj(objb, OBJ_MAP1, 1);

	//ボス敵機オブジェクト
	CObjBoss*obj_boss_enemy = new CObjBoss(300, 300);
	Objs::InsertObj(obj_boss_enemy, OBJ_BOSS,2);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}