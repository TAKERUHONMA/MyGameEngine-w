#include "SceneManager.h"
#include "TestScene.h"
#include "PlayScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"
#include "Engine/Direct3D.h"
#include "Model.h"

SceneManager::SceneManager(GameObject* parent)
    :GameObject(parent, "SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;
	nextSceneID_ = currentSceneID_;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
    //次のシーンが現在のシーンと違う ＝ シーンを切り替えなければならない
    if (currentSceneID_ != nextSceneID_)
    {
        //そのシーンのオブジェクトを全削除(子オブジェクトをすべて削除）

        auto delScene = childList_.begin();
        (*delScene)->ReleaseSub();
        SAFE_DELETE(*delScene);
        childList_.clear();
        Model::Release();

        //ロードしたデータを全削除


        //次のシーンを作成
        switch (nextSceneID_)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        case SCENE_ID_CLEAR: Instantiate<GameClearScene>(this); break;
        case SCENE_ID_OVER: Instantiate<GameOverScene>(this); break;
        }
        //無事シーンを生成出来たら、カレントシーンを更新
        currentSceneID_ = nextSceneID_;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
