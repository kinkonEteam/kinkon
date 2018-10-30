//使用するヘッダー
#include <math.h>   //数学計算ヘッダー
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;
bool UnitVec(float* vx, float* vy)
{
	//ベクトルの長さを求める(三平方の定理)
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		//0なら計算失敗
		return false;
	}
	else
	{
		//正規化しvxとvyに格納
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}
	//計算成功
	return true;
}