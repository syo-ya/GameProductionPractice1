#include "DxLib.h"
#include "GameOverScene.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"
#include "../../Sound/Sound.h"

int g_GameOverBG = 0;
int g_GameOverHandle = 0;

void InitGameOverScene()
{
	int g_BackGround = 0;
	int g_GameOverHandle = 0;
	StopBGM(BGM_PLAY_SCENE);
	PlayBGM(BGM_GAME_OVER);
}

void LoadGameOverScene()
{
	g_GameOverBG = LoadGraph("Data/Logo/Sky.jpg");
	g_GameOverHandle = LoadGraph("Data/Logo/GameOver.png");
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
		PlaySE(SE_ENTER);
		StopBGM(BGM_GAME_OVER);
    }
}

void DrawGameOverScene()
{
	DrawGraph(0, 0, g_GameOverBG, TRUE);
	DrawGraph(0, 0, g_GameOverHandle, TRUE);
}

void FinGameOverScene()
{
	DeleteGraph(g_GameOverBG);
	DeleteGraph(g_GameOverHandle);
}
