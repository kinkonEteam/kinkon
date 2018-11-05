//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include"UtilityModule.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;
//位置変更用
void CObjHero::SetX(float x)
{
	m_px = x;
}
void CObjHero::SetY(float y)
{
	m_py = y;
}
//位置取得用
float CObjHero::GetX()
{
	return m_px;
}
float CObjHero::GetY()
{
	return m_py;
}


//イニシャライズ
void CObjHero::Init()
{
	m_px = 368.0f;		//初期位置(ここで変更出来る)
	m_py = 268.0f;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;


	m_hp = 5;			//初期HP５

	m_posture = 0.0f;	//正面(0.0f) 左(1.0f) 右(2.0f) 背面(3.0f)
	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレーム
	m_f = true;			//攻撃制御

			//HitBox作成座標x,yとサイズx,y、エレメントとオブジェクトを設定
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//攻撃の入力判定、押しっぱなし制御
	if (Input::GetVKey('A') == true){
		if (m_f == true) {
			//剣オブジェクト作成		 //ここで剣に座標と向きを渡す
			CObjSword* swd = new CObjSword(m_px, m_py, m_posture);	//剣オブジェクト作成
			Objs::InsertObj(swd, OBJ_SWORD, 3);	//マネージャーに登録

			m_f = false;
		}
	}
	else
		m_f = true;

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

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

	//弾丸と接触したらHPを減らす
	if (0/*hit->CheckObjNameHit(OBJ_BULLET) != nullptr*/)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//クリアシーンに移動
		//Scene::SetScene(new CSceneClear());
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
	src.m_top   =50.0f *  m_posture - 1;		//微調整-1
	src.m_left  = 0.0f + (AniData[m_ani_frame] * 48);
	src.m_right	=48.0f + (AniData[m_ani_frame] * 48);
	src.m_bottom=50.0f * (m_posture + 1) - 3;	//微調整-3

				//表示位置の設定
	dst.m_top   = 0.0f + m_py;
	dst.m_left	= 0.0f + m_px;
	dst.m_right =32.0f + m_px;
	dst.m_bottom=32.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}