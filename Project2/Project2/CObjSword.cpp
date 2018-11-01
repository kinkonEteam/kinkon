//使用するヘッダーファイル
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSword::CObjSword(float x, float y, int m_pos)//渡されるだけの変数
{//渡された位置と向きデータをDrawで使える変数に代入
	m_x = x;
	m_y = y;
	pos = m_pos;
}

//イニシャライズ
void CObjSword::Init()
{

}

//アクション
void CObjSword::Action()
{

}

//ドロー
void CObjSword::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


				//切り取り位置の設定
	src.m_top	= 0.0f;
	src.m_left	= 0.0f;
	src.m_right =32.0f;
	src.m_bottom=40.0f;

	//表示位置の設定
	dst.m_top	= 0.0f + m_y;
	dst.m_left	= 0.0f + m_x;
	dst.m_right =32.0f + m_x;
	dst.m_bottom=40.0f + m_y;

	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
}