//使用するヘッダーファイル
#include "GameHead.h"
#include "CObjSword.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSword::CObjSword(float x, float y, int pos)//渡されるだけの変数
{						//渡されたデータをDrawで使えるメンバ変数に代入
	m_x = x;
	m_y = y;
	m_pos = pos;
}

//イニシャライズ
void CObjSword::Init()
{
	m_sx = 0;
	m_sy = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_s = 1;
}

//アクション
void CObjSword::Action()
{
	//主人公の位置を常に取得し、代入
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_x = obj->GetX();
	m_y = obj->GetY();

	//主人公向きで表示位置の変更用py,px
	if (m_pos == 0)     //↓
	{
		m_sy = 1;
	}
	else if (m_pos == 1)//←
	{
		m_sx = -1;
	}
	else if (m_pos == 2)//→
	{
		m_sx = 1;
	}
	else			  //↑
	{
		m_sy = -1;
	}


	m_ani_time+=m_s;			//削除されるまで常に足し続ける
	if (m_ani_time > 5)		//アニメーション動作間隔(※ここでアニメーション速度変更出来る)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
		m_s++;
	}

	if (m_ani_frame == 4)
	{
		this->SetStatus(false);	//オブジェクト削除
		//Hits::DeleteHitBox;		//HitBox削除
	}
}

//ドロー
void CObjSword::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top	= 0.0f + (32.0f*m_pos);
	src.m_left	= 0.0f + (32.0f*m_ani_frame);
	src.m_right =32.0f + (32.0f*m_ani_frame);
	src.m_bottom=32.0f + (32.0f*m_pos);

	//表示位置の設定
	dst.m_top	=(  0.0f + m_y) + (32 * m_sy);
	dst.m_left	=(  0.0f + m_x) + (32 * m_sx);
	dst.m_right =( 32.0f + m_x) + (32 * m_sx);
	dst.m_bottom=( 32.0f + m_y) + (32 * m_sy);
		
	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
}