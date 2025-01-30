#include "PlayScene.h"
#include "Engine/Fbx.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "Engine/Input.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	//Player* pPlayer;
	//pPlayer = new Player(this);//プレイヤーの親は、自分（PlayScene)
	//pPlayer->Initialize();
	//childList_.push_back(pPlayer);//PlaySceneの子として、プレイヤーを登録
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	if (Input::IsKey(DIK_B))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{

}
