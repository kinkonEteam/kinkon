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
		m_id = CLUB;
	}
	else
	{
		m_id = GOLD_BULLION;
	}

	//アイテムのヒットボックスを作成
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_ITEM, OBJ_ITEM, 1);


}

//アクション
void CObjItem::Action()
{


	CHitBox* hit = Hits::GetHitBox(this);

	//主人公と接触しているかどうかを調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//アイテムが所有するHitBoxを削除する

	}
}

void CObjItem::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	
	//切り取り位置の設定
	src.m_top =ITEM_RESOURCE_TOP;
	src.m_left = ITEM_RESOURCE_SIZE*(m_id-PEACH)+ITEM_LEFT_OFF_SET;
	src.m_right = src.m_left + ITEM_SIZE + ITEM_LEFT_OFF_SET;
	src.m_bottom = src.m_top + ITEM_SIZE - ITEM_TOP_OFF_SET;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 50.0f	+ m_px;
	dst.m_bottom = 50.0f + m_py;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);

}