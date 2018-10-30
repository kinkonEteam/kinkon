//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
}

//アクション
void CObjHero::Action()
{
	//ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//主人公機の移動にベクトルを入れる
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 1.0f;
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 1.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 1.0f;
	}

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//移動ベクトルを座標に加算する
	m_px += m_vx * 5.0f;
	m_py += m_vy * 5.0f;
}

//ドロー
void CObjHero::Draw()
{
	//描画カラー情報　R=RED　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				//切り取り位置の設定
	src.m_top	= 0.0f;
	src.m_left	= 48.0f;
	src.m_right	=96.0f;
	src.m_bottom=50.0f;


				//表示位置の設定
	dst.m_top	= 0.0f +m_py;
	dst.m_left	= 0.0f +m_px;
	dst.m_right =32.0f +m_px;
	dst.m_bottom=32.0f +m_py;


	Draw::Draw(0, &src, &dst, c, 0.0f);

}