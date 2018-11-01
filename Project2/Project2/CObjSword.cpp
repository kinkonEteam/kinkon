//使用するヘッダーファイル
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"
#include "UtilityModule.h"

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
	px = 0;
	py = 0;
}

//アクション
void CObjSword::Action()
{

}

//ドロー
void CObjSword::Draw()
{
	int AniData[4] = { 0,1,2,3, };
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置
				//切り取り位置の設定

	//主人公向きで切り取り位置変更と表示位置の変更
	if (pos == 0)     //↓
	{
		py = 1;
	}
	else if (pos == 1)//←
	{
		px = -1;
	}
	else if (pos == 2)//→
	{
		px = 1;
	}
	else			  //↑
	{
		py = -1;
	}

	src.m_top	= 0.0f;
	src.m_left	= 0.0f;
	src.m_right =32.0f;
	src.m_bottom=40.0f;

	//表示位置の設定
	dst.m_top	=(  0.0f + m_y) + (32 * py);
	dst.m_left	=(  0.0f + m_x) + (32 * px);
	dst.m_right =( 32.0f + m_x) + (32 * px);
	dst.m_bottom=( 32.0f + m_y) + (32 * py);
		
	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
}