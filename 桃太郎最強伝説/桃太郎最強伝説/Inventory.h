#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;


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
	int m_id;	//アイテムID
	int pb;		//確率用変数
	bool m_del;	//削除チェック


};





