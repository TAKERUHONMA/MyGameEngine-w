#include "Enemy.h"
#include "Model.h"
#include "ChildOden.h"
#include "Engine\SphereCollider.h"
#include "SceneManager.h"

Enemy::Enemy()
{
}

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel(-1), isAlive(true)
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("Assets/enemy.fbx");

	transform_.position_.y = 2.0f;
	transform_.scale_ = { 0.1f,0.1f,0.1f };

	SphereCollider* collision = new SphereCollider(100.0f);
	AddCollider(collision);
}

void Enemy::Update()
{
	static int dt;
	dt++;
	float nTime = dt / (10.0f * 10.0f) - 2.0f;
	transform_.position_.x = 4.0 * sin(nTime);
}

void Enemy::Draw()
{
	if (true)
	{
		Model::SetTransform(hModel, transform_);
		Model::Draw(hModel);
	}
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->FindChildObject("Bullet"))
	{
		this->KillMe();
	}
}

void Enemy::EnemyCount(int _count)
{
	if(_count == 0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}
