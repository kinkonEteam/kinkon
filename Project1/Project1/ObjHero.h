#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	//主人公の方向移動用変数
	float m_x;//x方向移動用変数
	float m_y;//y方向移動用変数
	float m_vx;//x方向移動ベクトル用変数
	float m_vy;//y方向移動ベクトル用変数
};