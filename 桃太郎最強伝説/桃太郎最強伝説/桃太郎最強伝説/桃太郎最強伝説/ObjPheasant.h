#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//オブジェクト：キャラクターブロック
class CObjPheasant : public CObj
{
public:
	CObjPheasant() {};
	~CObjPheasant() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//お供ヒットボックス用
	float m_y;	//お供ヒットボックス用

};

