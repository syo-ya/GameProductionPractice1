#include "DxLib.h"
#include "ClearScene.h"
//#include "../../BackGround/BackGround.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"
#include <stdio.h>

// 背景のスクロール速度
#define BACK_GROUND_SPEED (-1.5)

void InitGameClearScene()
{
	// 背景初期化
	//InitBackGround();
}

void LoadGameClearScene()
{
	// 背景ロード
	//LoadBackGround("Data/GameClear/clear.PNG", BACK_GROUND_LAYER_1);
	// 背景スクロール
	//SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);
}

void StartGameClearScene()
{

}

void StepGameClearScene()
{
	// 背景ステップ
	//StepBackGround();

	// Zキーでタイトルに戻る
	if (IsTriggerKey(KEY_SPACE))
	{
		ChangeScene(SCENE_TITLE);
	}
}

void UpdateGameClearScene()
{
	// 背景更新
	//UpdateBackGround();
}

void DrawGameClearScene()
{
	// 背景描画
	//DrawBackGround();
}

void FinGameClearScene()
{
	// 背景終了
	//FinBackGround();
}
