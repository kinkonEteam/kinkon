#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define ITEM_TOP	(111.0f)
#define ITEM_LEFT	(256.0f)

//オブジェクト：キャラクターブロック
class CObjSilverBullion : public CObj
{
public:
	CObjSilverBullion() {};
	~CObjSilverBullion() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//アイテムヒットボックス用
	float m_y;	//アイテムヒットボックス用
	bool m_del;	//削除チェック


};





