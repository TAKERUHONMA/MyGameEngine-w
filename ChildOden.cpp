#include "ChildOden.h"
#include "Engine/Fbx.h"
#include "Model.h"
#include "Enemy.h"
#include "SceneManager.h"

ChildOden::ChildOden(GameObject* parent)
    :GameObject(parent,"Bullet"),hModel(-1)
{
}

void ChildOden::Initialize()
{
    //pFbx = new Fbx;
    //pFbx->Load("Assets/oden.fbx");
    hModel = Model::Load("Assets/Bullet.fbx");
    transform_.scale_.x = 0.5f;
    transform_.scale_.y = 0.5f;
    transform_.scale_.z = 0.5f;
    transform_.position_.x = 2.0f;
    transform_.position_.y = 1.0f;
}

void ChildOden::Update()
{
    transform_.rotate_.y+=2.0;
    transform_.position_.y += 0.1;
    Enemy* enemy = (Enemy*)FindObject("Enemy");

    if (enemy)
    {
        float r1 = 0.1;
        float r2 = 0.5;
        XMFLOAT3 P1 = enemy->GetPosition();
        XMFLOAT3 P2 = transform_.position_;
        XMVECTOR Dist = XMVector3Length(
            XMVectorSet(P1.x, P1.y, P1.z, 1) - XMVectorSet(P2.x, P2.y, P2.z, 1));
        float d = XMVectorGetX(Dist);

        if (d <= r1 + r2)
        {
            enemy->EnemyCount(0);
            enemy->KillMe();
            KillMe();
        }
    }

    if (transform_.position_.y > 5.0)
    {
        KillMe();
    }
}

void ChildOden::Draw()
{
    //pFbx->Draw(transform_);
    Model::SetTransform(hModel, transform_);
    Model::Draw(hModel);
}

void ChildOden::Release()
{
    //���Ƃ�
}

void ChildOden::OnCollision(GameObject* pTarget)
{
}
