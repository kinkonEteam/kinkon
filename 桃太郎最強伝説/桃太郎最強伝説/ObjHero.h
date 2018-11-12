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
		void Init();	 //イニシャライズ
		void Action();	 //アクション
		void Draw();	 //ドロー

		float GetX() { return m_px; }
		float GetY() { return m_py; }
		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }

		void SetKf(float f) { m_Kf = f; }
	private:
	//主人公の位置と移動用
		int x, y;		//初期位置設定用変数
		float m_px;		 //位置
		float m_py;
		float m_vx;		 //移動ベクトル用変数
		float m_vy;

		float m_posture; //姿勢

		int m_hp;		 //HP
		int m_map[56][56];//マップ情報

		int m_ani_time;  //アニメーションフレーム動作間隔
		int m_ani_frame;	//描画フレーム
		bool m_Sf;			//ソード攻撃制御
		bool m_Kf;			//キジ攻撃制御
		//blockとの衝突状態確認用
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		int item_num[5];	//アイテムの所持数確認用
		//踏んでいるblockの種類を確認用
		int m_block_type;

};