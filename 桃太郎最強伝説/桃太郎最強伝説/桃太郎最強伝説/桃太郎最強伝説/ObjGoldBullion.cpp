//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>
#include "ObjGoldBullion.h"
#include "GameHead.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGoldBullion::Init()
{
	m_x = 200.0f;
	m_y = 0.0f;

	//アイテムのヒットボックスを作成
	Hits::SetHitBox(this, m_x + 4, m_y , 24, 28, ELEMENT_ITEM, OBJ_GOLD_BULLION, 1);


}

//アクション
void CObjGoldBullion::Action()
{


	CHitBox* hit = Hits::GetHitBox(this);

	//主人公と接触しているかどうかを調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//アイテムが所有するHitBoxを削除する

	}
}

void CObjGoldBullion::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


				//切り取り位置の設定
	src.m_top = 134.0f;
	src.m_left = 134.0f;
	src.m_right = 158.0f;
	src.m_bottom = 158.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);

}