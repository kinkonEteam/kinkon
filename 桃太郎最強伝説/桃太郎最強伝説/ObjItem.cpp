//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjItem.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

CObjItem::CObjItem(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjItem::Init()
{

	srand((unsigned)time(NULL)); // 乱数の初期化

	pb = rand() % 100;

	if (0 <= pb  && pb <= 50)
	{
		m_id = ITEM_CLUB;
	}
	else
	{
		m_id = ITEM_GOLD_BULLION;
	}

	//アイテムのヒットボックスを作成
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_ITEM, OBJ_ITEM, 1);


}

//アクション
void CObjItem::Action()
{
	switch (m_id)
	{
	case ITEM_PEACH:
				

		break;
	case ITEM_YELLOW_PEACH:

		break;
	case ITEM_PLUM:

		break;
	case ITEM_HORN:

		break;
	case ITEM_GOLD_BULLION:

		break;
	case ITEM_SILVER_BULLION:

		break;
	case ITEM_CLUB:

		break;
	}
}

void CObjItem::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	
	//切り取り位置の設定
	src.m_top = 31.0f;
	src.m_left = 0.0f;
	src.m_right = 0.0f;
	src.m_bottom = 31.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 50.0f	+ m_px;
	dst.m_bottom = 50.0f + m_py;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);

}