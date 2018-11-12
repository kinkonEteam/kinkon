#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define ITEM_TOP	(111.0f)
#define ITEM_LEFT	(256.0f)
#define ITEM_SIZE	(50.0f)

#define ITEM_LEFT_OFF_SET	(2)
#define ITEM_TOP_OFF_SET	(1)
#define ITEM_RESOURCE_TOP	(50.0f)
#define ITEM_RESOURCE_SIZE	(50.0f)

//オブジェクト：キャラクターブロック
class CObjItem : public CObj
{
	public:
		CObjItem(float x,float y);
		~CObjItem() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		//アイテムヒットボックス用
		float m_x;	
		float m_y;
		//マップ位置設定用
		float m_px;
		float m_py;

		int m_id;	//アイテムID
		int pb;
};




