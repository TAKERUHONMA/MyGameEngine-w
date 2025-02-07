#include "GameOverScene.h"
#include "SceneManager.h"
#include "Engine/Input.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOver"),count(0)
{
}

void GameOverScene::Initialize()
{
}

void GameOverScene::Update()
{
	count--;
	if (Input::IsKey(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

	if (Input::IsKey(DIK_BACK))
	{
		count = 10;
	}

	if (count == 0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void GameOverScene::Draw()
{
}

void GameOverScene::Release()
{
}
