#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define ITEM_KIND (2)
#define ITEM_NUM (6)


//オブジェクト：キャラクターブロック
class CObjInventory : public CObj
{
public:
	CObjInventory() {};
	~CObjInventory() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//アイテムヒットボックス用
	float m_y;	//アイテムヒットボックス用
	bool item_id[ITEM_KIND][ITEM_NUM];//アイテム保存用:[種類][個数]

	
};





