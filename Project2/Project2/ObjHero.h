#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
//m_はメンバ(クラス内の変数や関数)で、pxはプレイヤーのx座標
//メンバ関数は直接呼び出されるのでpublic、関数内で使われる変数はprivate
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();	 //イニシャライズ
	void Action();	 //アクション
	void Draw();	 //ドロー

	void SetX(float x);	//位置変更用
	void SetY(float y);
	float GetX();		//位置取得用
	float GetY();
private:
//主人公の位置と移動用
	float m_px;		 //位置
	float m_py;
	float m_vx;		 //移動ベクトル用変数
	float m_vy;
	float m_posture; //姿勢

	int m_ani_time;  //アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	bool m_f;		//攻撃制御用(trueかfalseだけ)

	int m_hp;		//HP
};