#include "GameOverScene.h"
#include "SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Sprite.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOver"),count(0)
{
}

void GameOverScene::Initialize()
{
	q = new Sprite();
	q->Load("Assets\\odenover.png");
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
	q->Draw(transform_);
}

void GameOverScene::Release()
{
}
