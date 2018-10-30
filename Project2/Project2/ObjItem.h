#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//オブジェクト：キャラクターブロック
class CObjItem : public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	

};




