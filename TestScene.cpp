#include "TestScene.h"
#include "SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Sprite.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

void TestScene::Initialize()
{
	q = new Sprite();
	q->Load("Assets\\ss.png");
}

void TestScene::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

	if (Input::IsKey(DIK_BACK))
	{
		exit(0);
	}

}

void TestScene::Draw()
{
	q->Draw(transform_);
}

void TestScene::Release()
{
}
