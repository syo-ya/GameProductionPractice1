#include "DxLib.h"
#include "GameOverScene.h"
//#include "../../BackGround/BackGround.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"
//#include "../../Sound/SoundManager.h"

// 自動遷移までの待機時間
#define WAIT_TIMER		(300)

// 待機時間タイマー
int g_WaitTimer = 0;

int g_GameOverHandle = 0;

void InitGameOverScene()
{
	// 背景初期化
	//InitBackGround();

	// タイマー初期化
	g_WaitTimer = 0;

	int g_GameOverHandle = 0;
}

void LoadGameOverScene()
{
	// 背景ロード
	//LoadBackGround("Data/GameOver/gameover.PNG", BACK_GROUND_LAYER_1);
	// 背景スクロール
	//SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);

	g_GameOverHandle = LoadGraph("Data/Logo/GameOver.png");
}

void StartGameOverScene()
{
	// 待機タイマーをセット
	g_WaitTimer = WAIT_TIMER;
}

void StepGameOverScene()
{
	// 背景ステップ
	//StepBackGround();
	// タイマーをカウントダウン
	g_WaitTimer--;
}

void UpdateGameOverScene()
{
    // Zキーでタイトルに戻る
    if (IsTriggerKey(KEY_SPACE))
    {
        ChangeScene(SCENE_TITLE);
    }
	// 背景更新
	//UpdateBackGround();

	// タイマーが0もしくはZキーでタイトルに戻る
	if (g_WaitTimer <= 0 || IsTriggerKey(KEY_SPACE))
	{
		ChangeScene(SCENE_TITLE);
	}
}

void DrawGameOverScene()
{
	// 背景描画
	//DrawBackGround();

	DrawGraph(0, 0, g_GameOverHandle, TRUE);
}

void FinGameOverScene()
{
	// 背景終了
	//FinBackGround();

	DeleteGraph(g_GameOverHandle);
}
