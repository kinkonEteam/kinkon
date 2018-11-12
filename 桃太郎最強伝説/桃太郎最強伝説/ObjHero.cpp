//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"

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

	m_hp = 5;				//初期HP

	m_posture = 0.0f;	//正面(0.0f)左(1.0f) 右(2.0f) 背面(3.0f)
	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレーム

	//HitBox作成とサイズ、エレメント、オブジェクトを設定
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	
	if (Input::GetVKey('A') == true) //攻撃
	{
		if (m_f == true)
		{
			//剣オブジェクト作成
			CObjSword* obj = new CObjSword(m_px, m_py, m_posture); //弾丸オブジェクト作成
			Objs::InsertObj(obj, OBJ_SWORD, 100);//弾丸オブジェクトをマネージャーに登録

			m_f = false;
		}
	}
	else
	{
		m_f = true;
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

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		/*Scene::SetScene(new CSceneClear());*/
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
	src.m_top	=50.0f *  m_posture-1;
	src.m_left  = 0.0f + (AniData[m_ani_frame] * 48);
	src.m_right	=48.0f + (AniData[m_ani_frame] * 48);
	src.m_bottom=50.0f * (m_posture + 1)-3;


	//表示位置の設定
	dst.m_top	= 0.0f +m_py;
	dst.m_left	= 0.0f +m_px;
	dst.m_right =50.0f +m_px;
	dst.m_bottom=50.0f +m_py;


	Draw::Draw(0, &src, &dst, c, 0.0f);

}