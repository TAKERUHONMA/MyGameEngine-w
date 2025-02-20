#include "GameClearScene.h"
#include "SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Sprite.h"
#include "Player.h"

GameClearScene::GameClearScene(GameObject* parent)
	:GameObject(parent, "GameClear"),count(0)
{
}

void GameClearScene::Initialize()
{
	q = new Sprite();
	q->Load("Assets\\ss.png");

	Instantiate<Player>(this);
}

void GameClearScene::Update()
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

void GameClearScene::Draw()
{
	q->Draw(transform_);
}

void GameClearScene::Release()
{
}
