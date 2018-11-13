//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "Inventory.h"
//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjHero::Init()
{
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;

	m_hp = 5;			//初期HP５

	m_posture = 0.0f;	//正面(0.0f) 左(1.0f) 右(2.0f) 背面(3.0f)
	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレーム
	m_Sf = true;			//攻撃制御
	m_Kf = true;			//キジ攻撃制御

	//HitBox作成座標とサイズx,y、エレメントとオブジェクトを設定
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//攻撃の入力判定、押しっぱなし制御
	if (Input::GetVKey('A') == true) 
	{
		if (m_Sf == true) 
		{
			//剣オブジェクト作成		ここで剣に座標と向きを渡す
			CObjSword* swd = new CObjSword(m_px, m_py, m_posture);//作成
			Objs::InsertObj(swd, OBJ_SWORD, 3);	//マネージャーに登録

			m_Sf = false;
		}
	}
	else//放している場合
		m_Sf = true;

	//キジ攻撃の入力判定、押しっぱなし制御
	if (Input::GetVKey('S') == true)
	{
		if (m_Kf == true)
		{
			//キジオブジェクト作成				キジに座標と向きを渡す
			CObjFlyKiji* kiji = new CObjFlyKiji(m_px, m_py, m_posture);//作成
			Objs::InsertObj(kiji, OBJ_FLYKIJI, 3);	//マネージャーに登録

			m_Kf = false;
		}
	}
	else //押してない場合
	{
		;//何もしない
	}

	//主人公の移動にベクトルを入れる
	if (Input::GetVKey(VK_RIGHT) == true)//→
	{
		m_vx += 1.0f;
		m_posture = 2.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_UP) == true)	//↑
	{
		m_vy -= 1.0f;
		m_posture = 3.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_DOWN) == true)//↓
	{
		m_vy += 1.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)//←
	{
		m_vx -= 1.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;	//キー入力がない場合は静止フレームにする
		m_ani_time = 0;		
	}

	if (m_ani_time > 6)		//アニメーション動作間隔(※ここでアニメーション速度変更出来る)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
		m_ani_frame = 0;	//フレーム4で0に戻す

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//移動ベクトルを座標に加算する(※ここで移動速度変更出来る)
	m_px += m_vx * 2.0f;			
	m_py += m_vy * 2.0f;

	//スクロール
	CObjMap1*b = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
		m_px = 400;
		b->SetScrollx(b->GetScrollx());
		m_py = 300;
		b->SetScrolly(b->GetScrolly());

	//ブロックとの当たり判定
	CObjMap1*pb = (CObjMap1*)Objs::GetObj(OBJ_MAP1);
	pb->Map1Hit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

	//ELEMENT_ENEMYを持つオブジェクトと接触したら
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//エレメント敵に当たるとHP-1
	if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
	{
		m_hp -= 1;
	}
	//アイテムに当たった場合以下の処理をする
	if (hit->CheckObjNameHit(ELEMENT_ITEM) != nullptr)
	{
		switch (ELEMENT_ITEM)
		{
		case PEACH:	
			m_hp += 1; //HPを1回復
		break;

		case YELLOW_PEACH: //HPを3回復
			;
		break;

		case PLUM: //インベントリに追加
			break;

		case CLUB: //移動速度を0.8倍する。
			break;
		}

		
	}
	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		/*Scene::SetScene(new CSceneGameOver());*/
	}
}

//ドロー
void CObjHero::Draw()
{
	int AniData[4] = { 0,1,2,1, };
	//描画カラー情報　R=RED　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top   =50.0f *  m_posture - 1;	 //微調整-1
	src.m_left  = 0.0f + (AniData[m_ani_frame] * 48);
	src.m_right =48.0f + (AniData[m_ani_frame] * 48);
	src.m_bottom=50.0f * (m_posture + 1) - 3;//微調整-3

	//表示位置の設定
	dst.m_top   = 0.0f + m_py;
	dst.m_left  = 0.0f + m_px;
	dst.m_right =50.0f + m_px;
	dst.m_bottom=50.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}