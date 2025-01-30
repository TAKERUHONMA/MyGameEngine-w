#include "EnemyBullet.h"
#include "Engine/Fbx.h"
#include "Model.h"
#include "Player.h"
#include "SceneManager.h"

EnemyBullet::EnemyBullet(GameObject* parent)
    :GameObject(parent, "eBullet"), hModel(-1)
{
}

void EnemyBullet::Initialize()
{
    hModel = Model::Load("Assets/Player.fbx");
    transform_.scale_.x = 0.5f;
    transform_.scale_.y = 0.5f;
    transform_.scale_.z = 0.5f;
    transform_.position_.x = 10.0f;
    transform_.position_.y = 10.0f;
}

void EnemyBullet::Update()
{
    transform_.rotate_.y -= 2.0;
    transform_.position_.y -= 0.1;
    Player* player = (Player*)FindObject("Player");

    if (player)
    {
        float r1 = 0.1;
        float r2 = 0.5;
        XMFLOAT3 P1 = player->GetPosition();
        XMFLOAT3 P2 = transform_.position_;
        XMVECTOR Dist = XMVector3Length(
            XMVectorSet(P1.x, P1.y, P1.z, 1) - XMVectorSet(P2.x, P2.y, P2.z, 1));
        float d = XMVectorGetX(Dist);

        if (d <= r1 + r2)
        {
            player->PlayerCount(0);
            player->KillMe();
            //KillMe();
        }
    }

    if (transform_.position_.y == 0.0)
    {
        KillMe();
    }
}

void EnemyBullet::Draw()
{
    Model::SetTransform(hModel, transform_);
    Model::Draw(hModel);
}

void EnemyBullet::Release()
{
}
