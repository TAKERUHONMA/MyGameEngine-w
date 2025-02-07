#pragma once
#include "Engine/GameObject.h"
class GameOverScene :
    public GameObject
{
    int count; //カウント
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    GameOverScene(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};


