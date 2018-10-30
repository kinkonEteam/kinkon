#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class  CSceneTitle : public CScene
{
public:
	 CSceneTitle() {};
	~CSceneTitle() {};
	void Init();
	void Action();
	void Draw();
private:
	void InitScene();
	void Scene();
};