#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
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