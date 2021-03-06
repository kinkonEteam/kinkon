//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include"GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"Scenefloor1.h"
#include"GameHead.h"

//コンストラクタ
CScenefloor1::CScenefloor1()
{

}

//デストラクタ
CScenefloor1::~CScenefloor1()
{

}

//初期化メソッド
void CScenefloor1::InitScene()
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

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み
	//外部グラフィックを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"桃太郎.png", 0, TEX_SIZE_512);
	//外部グラフィックを読み込み1番に登録(141×47ピクセル)
	Draw::LoadImageW(L"マップチップ.png", 1, TEX_SIZE_141_47);
	//外部グラフィックを読み込み2番に登録(512×512ピクセル)
	Draw::LoadImage(L"OTOMO.GIF", 2, TEX_SIZE_512);
	//外部グラフィックを読み込み3番に登録(512×512ピクセル)
	Draw::LoadImage(L"Sword.png", 3, TEX_SIZE_512);
	//外部グラフィックを読み込み4番に登録(512×512ピクセル)
	Draw::LoadImage(L"アイテム.png", 4, TEX_SIZE_512);
	//外部グラフィックを読み込み5番に登録(151×200ピクセル)
	Draw::LoadImage(L"鬼原画 青鬼 新二.png", 5, TEX_SIZE_151_200);
	//外部グラフィックを読み込み6番に登録(151×200ピクセル)
	Draw::LoadImage(L"鬼原画 黄鬼 新二.png", 6, TEX_SIZE_151_200);
	//外部グラフィックを読み込み7番に登録(151×200ピクセル)
	Draw::LoadImage(L"鬼原画 緑鬼 新二.png", 7, TEX_SIZE_151_200);


	//階層1オブジェクト作成
	CObjMap1* objb = new CObjMap1(map);
	Objs::InsertObj(objb, OBJ_MAP1, 1);
}

//実行中メソッド
void CScenefloor1::Scene()
{

}