#pragma once
#include "Engine/GameObject.h"

class Sprite;

class GameOverScene :
    public GameObject
{
    int count; //�J�E���g
    Sprite* q;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    GameOverScene(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};


