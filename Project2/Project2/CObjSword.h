#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：剣
class CObjSword :public CObj
{
public:
	CObjSword(float x, float y,int m_pos);//コンストラクタ
	~CObjSword() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;		//位置
	float m_y;
	int pos;
};