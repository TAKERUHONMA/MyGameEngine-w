#include "GameClearScene.h"
#include "SceneManager.h"
#include "Engine/Input.h"
#include "Player.h"

GameClearScene::GameClearScene(GameObject* parent)
	:GameObject(parent, "GameClear")
{
}

void GameClearScene::Initialize()
{
	Instantiate<Player>(this);
}

void GameClearScene::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void GameClearScene::Draw()
{
}

void GameClearScene::Release()
{
}
