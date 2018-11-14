#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペースネームスペース
using namespace GameL;

//オブジェクト：クリア
class CObjClear : public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	bool m_key_flag;
};
