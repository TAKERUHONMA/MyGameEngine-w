#pragma once
#include "Engine/GameObject.h"

class Sprite;

class GameOverScene :
    public GameObject
{
    int count; //カウント
    Sprite* q;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    GameOverScene(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};


