#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：剣
class CObjSword :public CObj
{
public:				//コンストラクタ
	CObjSword(float x, float y,int m_pos);
	~CObjSword() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;		//位置
	float m_y;
	int pos;		//主人公の向き(m_posture)
	int px, py;		//向きによる位置変更用x,y
};