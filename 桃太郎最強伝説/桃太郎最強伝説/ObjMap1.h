#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjMap1 :public CObj
{
	public:
		CObjMap1(int map[56][56]);
		~CObjMap1() {};
		void Init();	//イニシャル
		void Action();	//アクション
		void Draw();	//ドロー

		//左右スクロール用
		void SetScroll(float s) { m_scroll = s; }
		float GetScroll() { return m_scroll; }
		//上下スクロール用
		void SetScrolly(float s) { m_scrolly = s; }
		float GetScrolly() { return m_scrolly; }

		int x, y;	//初期位置設定用変数

		//ブロックとの当たり判定
		void Map1Hit(
			float *x, float *y, bool scroll_on,
			bool*up, bool* down, bool*left, bool*right,

			float*vx, float*vy, int*bt
		);
	private:
		void BlockDraw(float x, float y, RECT_F* dst, float c[]);
		int m_map[56][56];//マップ情報

		float m_scroll;		//左右スクロール用
		float m_scrolly;	//上下スクロール用

		float Dot(float ax, float ay, float bx, float by);	//内積
		float Cross(float ax, float ay, float bx, float by);//外積
};
