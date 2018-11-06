//使用するヘッダーファイル
#include <stdlib.h>
#include <time.h>
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjMap1.h"

//使用するネームスペース
using namespace GameL;

CObjMap1::CObjMap1(int map[56][56])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(56 * 56));
}

//イニシャライズ
void CObjMap1::Init()
{
	srand(time(NULL));
	x = -1800;
	y = -1300;
	m_scroll = 0.0f;
	m_scrolly = 0.0f;

	//階段出現位置の設定
	while (1)
	{
		for (int i = 0; i < 56; i++)
		{
			for (int j = 0; j < 56; j++)
			{
				//２を発見
				if (m_map[i][j] == 2)
				{
					//2の中から1つ階段を出現させる
					int stair = 0;

					stair = rand() % 3;
					if (stair == 1)
					{
						m_map[i][j] = 4;
						return;
					}
				}
			}
		}
	}
}
//アクション
void CObjMap1::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//左方スクロールライン
//	if (hx < 80)
	{
		hero->SetX(0);				//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_scrollに加える
	}
	//右方スクロールライン
//	if (hx > 300)
	{
		hero->SetX(400);				
		m_scroll -= hero->GetVX();		
	}
	//上方スクロールライン
	{
		hero->SetY(0);
		m_scrolly -= hero->GetVY();
	}
	//下方スクロールライン
	{
		hero->SetY(300);
		m_scrolly -= hero->GetVY();
	}


	/*//敵出現ライン
	//主人公の位置+500を敵出現ラインにする
	float line = hx + (-m_scroll) + 500;

	//敵出現ラインを要素番号化
	int ex = ((int)line) / 64;

	//敵出現ラインの列を検索
	for (int i = 0; i < 10; i++)
	{
		//列の中から4を探す
		if (m_map[i][ex] == 4)
		{

			//4があれば敵を出現
			CObjEnemy* obje = new CObjEnemy(ex*64.0f, i*64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY, 10);
			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}
	}*/
}
//ドロー
void CObjMap1::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//マップチップによるblock配置
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] >= 0)
			{
				//表示位置の設定
				dst.m_top = i*50.0f + m_scrolly + y;				//マップサイズ,初期位置
				dst.m_left = j*50.0f + m_scroll + x;
				dst.m_right = dst.m_left + 50.0;
				dst.m_bottom = dst.m_top + 50.0;
			}
			if (m_map[i][j] == 1 || m_map[i][j] == 2 || m_map[i][j] >= 5)
			{
				//床
				BlockDraw(0.0f, 0.0f, &dst, c);
			}
			else if (m_map[i][j] == 4)
			{
				BlockDraw(94.0f, 0.0f, &dst, c);
			}
			else if (m_map[i][j] == 0)
			{
				//壁
				BlockDraw(47.0f, 0.0f, &dst, c);
			}
		}
	}
}

//BlockDrawMethod関数
//引数１　float	x	:リソース切り取り位置X
//引数２　float	y	:リソース切り取り位置Y
//引数３　RECT_F* dst :描画位置
//引数４　float	c[]	:カラー情報
//ブロックを64*64限定描画用。リソース切り取り位置のみx,yで
//設定できる
void CObjMap1::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 47.0f;
	src.m_bottom = src.m_top + 47.0f;
	//描画
	Draw::Draw(1, &src, dst, c, 0.0f);
}

/*//BlockHit変数
//引数１　float* x			：判定を行うobjectのX位置
//引数２　float* y			：判定を行うobjectのY位置
//引数３　bool  scroll		：判定を行うobjectはスクロールの影響与えるかどうか（true=与える、false=与えない）
//引数４　bool* up			：上下左右判定の上部分に当たっているかどうかを返す
//引数５　bool* down		：上下左右判定の下部分に当たっているかどうかを返す
//引数６　bool*left			：上下左右判定の左部分に当たっているかどうかを返す
//引数７　bool*right		：上下左右判定の右部分に当たっているかどうかを返す
//引数８　float* vx			：左右判定時の反発による移動方向・力の値を変えて返す
//引数９　float* vy			：上下判定時による自由落下運動の移動方向・力の値を変えて返す
//引数10　int* bt			：下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック50*50限定で、当たり判定と上下左右判定を行う
//その結果は引数４～10に返す
void CObjMap1::Map1Hit
(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//主人公の衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 1)
			{
				//要素番号を座標に変更
				float bx = j*50.0f;
				float by = i*50.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 50.0f > bx) && (*x + (-scroll) < bx + 50.0f) && (*y + (-scrolly) + 50.0f > by) && (*y + (-scrolly) < by + 50.0f))
				{
					//上下左右判定

					//Vectorの作成
					float rvx = (*x + (-scroll)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							*right = true;//オブジェクトの左部分が衝突している
							*x = bx + 50.0f + (scroll);//ブロックの位置+オブジェクトの幅
							*vx = -(*vx)*0.1f;//-VX*反発係数
						}

						if (r > 45 && r < 135)
						{
							//上
							*down = true;//オブジェクトの下の部分が衝突している
							*y = by - 50.0f + (scrolly);//ブロックの位置-オブジェクトの幅
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;//オブジェクトの右部分が衝突している
							*x = bx - 50.0f + (scroll);//ブロックの位置-オブジェクトの幅
							*vx = -(*vx)*0.1f;//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							*up = true;//オブジェクトの上の部分が衝突している
							*y = by + 50.0f + (scrolly);//ブロックの位置+オブジェクトの幅
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}
*/
