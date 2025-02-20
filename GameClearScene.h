#pragma once
#include "Engine/GameObject.h"

class Sprite;

class GameClearScene :
    public GameObject
{
    int count; //カウント
    Sprite* q;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    GameClearScene(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

