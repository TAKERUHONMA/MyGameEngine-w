#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
    int hModel;
    bool isAlive;
    //int count;
public:
    Enemy();
    Enemy(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    XMFLOAT3 GetPosition()
    { return (transform_.position_); }

    void OnCollision(GameObject* pTarget) override;

    void DeActivateMe() { isAlive = false; }
    void ActivateMe() { isAlive = true; }

    void EnemyCount(int _count);
};

