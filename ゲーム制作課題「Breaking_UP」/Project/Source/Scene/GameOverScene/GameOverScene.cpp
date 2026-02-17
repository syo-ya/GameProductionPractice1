#include "DxLib.h"
#include "GameOverScene.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"

void InitGameOverScene()
{
}

void LoadGameOverScene()
{
}

void StartGameOverScene()
{
}

void StepGameOverScene()
{
}

void UpdateGameOverScene()
{
    // Zキーでタイトルに戻る
    if (IsTriggerKey(KEY_SPACE))
    {
        ChangeScene(SCENE_TITLE);
    }
}

void DrawGameOverScene()
{
	// ゲームオーバーのメッセージを描画
    DrawString(700, 400, "ゲームオーバー", GetColor(255, 0, 0));
    DrawString(660, 500, "SPACEキーでタイトルへ戻る", GetColor(255, 255, 255));
}

void FinGameOverScene()
{
}
