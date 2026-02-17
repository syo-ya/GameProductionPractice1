#include "DxLib.h"
#include "ClearScene.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"

void InitClearScene()
{
}

void LoadClearScene()
{
}

void StartClearScene()
{
}

void StepClearScene()
{
}

void UpdateClearScene()
{
	// Zキーでタイトルに戻る
    if (IsTriggerKey(KEY_SPACE))
    {
        ChangeScene(SCENE_TITLE);
    }
}

void DrawClearScene()
{
	// ゲームクリアのメッセージを描画
	DrawString(700, 400, "ゲームクリア！！", GetColor(255, 255, 0));
	DrawString(650, 500, "SPACEキーでタイトルへ戻る", GetColor(255, 255, 255));
}

void FinClearScene()
{
}
