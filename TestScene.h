#pragma once
#include "Engine/GameObject.h"

class Sprite;

class TestScene :
    public GameObject
{
    Sprite* q;
    public:
        //コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
        TestScene(GameObject * parent);
        void Initialize() override;
        void Update() override;
        void Draw() override;
        void Release() override;
};

