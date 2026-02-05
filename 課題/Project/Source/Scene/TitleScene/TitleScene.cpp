#include "DxLib.h"
#include "TitleScene.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"

int g_TitleBGHandle = -1;
int g_TitleLogoHandle = -1;

void InitTitleScene()
{
	g_TitleBGHandle = LoadGraph("Data/Title/BG.png");
	g_TitleLogoHandle = LoadGraph("Data/Title/TitleText.png");
}

void UpdateTitleScene()
{
	if (IsTriggerKey(KEY_Z))
	{
		ChangeScene(SCENE_PLAY);
	}
	else if (IsTriggerKey(KEY_X))
	{
		ChangeScene(SCENE_OPTION);
	}
}

void DrawTitleScene()
{
	DrawGraph(0, 0, g_TitleBGHandle, TRUE);
	DrawGraph(200, 200, g_TitleLogoHandle, TRUE);
}

void FinTitleScene()
{
	DeleteGraph(g_TitleBGHandle);
	DeleteGraph(g_TitleLogoHandle);
}