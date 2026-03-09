#include "DxLib.h"
#include "ClearScene.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"
#include "../../Sound/Sound.h"
#include <stdio.h>

 int g_ClearHandle = 0;

void InitGameClearScene()
{
	g_ClearHandle = 0;
	StopBGM(BGM_PLAY_SCENE);
	PlayBGM(BGM_GAME_CLEAR);
}

void LoadGameClearScene()
{g_ClearHandle = LoadGraph("Data/Logo/GameClear.png");
}

void StartGameClearScene()
{

}

void StepGameClearScene()
{
	if (IsTriggerKey(KEY_SPACE))
	{
		ChangeScene(SCENE_TITLE);
		PlaySE(SE_ENTER);
		StopBGM(BGM_GAME_CLEAR);
	}
}

void UpdateGameClearScene()
{
	
}

void DrawGameClearScene()
{
	DrawGraph(0, 0, g_ClearHandle, TRUE);
}

void FinGameClearScene()
{
	DeleteGraph(g_ClearHandle);
}
