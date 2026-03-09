#include "DxLib.h"
#include "TitleScene.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../Sound/Sound.h"
#include <math.h>

#define BACK_GROUND_SPEED (-0.3f)

#define TITLE_POS_X (280)
#define TITLE_POS_Y (130)

#define PRESS_Z_KEY_POS_X (500)
#define PRESS_Z_KEY_POS_Y (530)

#define PRESS_SPACE_KEY_BLINK_SPEED (0.04f)

int g_BGHandle = 0;
int g_TitleHandle = 0;
int g_PressSpaceKeyHandle = 0;

float g_PressSpaceKeyAlpha = 0.0f;
float g_PressSpaceKeyRadian = 0.0f;

void InitTitleScene()
{
	g_BGHandle = 0;
	g_TitleHandle = 0;
	g_PressSpaceKeyHandle = 0;
	g_PressSpaceKeyAlpha = 0.0f;
	g_PressSpaceKeyRadian = 0.0f;
	PlayBGM(BGM_TITLE);
}

void LoadTitleScene()
{
	g_BGHandle = LoadGraph("Data/Logo/TitleLogo.png");
	g_PressSpaceKeyHandle = LoadGraph("Data/Logo/PressSpaceKey.png");
}

void StartTitleScene()
{

}


void StepTitleScene()
{
	// sin波の値からPressZKeyのアルファ値（透明度）を計算する
	// sinfが-1～1の値を返却するので加工して0～1の値にしている
	g_PressSpaceKeyAlpha = (sinf(g_PressSpaceKeyRadian) + 1) / 2;

	// ラジアン値を点滅速度で加算
	g_PressSpaceKeyRadian += PRESS_SPACE_KEY_BLINK_SPEED;

	// ラジアン値は0～2πをループさせる
	if (g_PressSpaceKeyRadian > DX_TWO_PI_F)
	{
		g_PressSpaceKeyRadian -= DX_TWO_PI_F;
	}

	if (IsTriggerKey(KEY_SPACE))
	{
		ChangeScene(SCENE_PLAY);
		PlaySE(SE_ENTER);
		StopBGM(BGM_TITLE);
	}
}

void UpdateTitleScene()
{

}

void DrawTitleScene()
{
	DrawGraph(0, 0, g_BGHandle, TRUE);

	// 点滅のためにブレンドモードを設定する(DXLibの仕様が0～255で指定するので加工する)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(g_PressSpaceKeyAlpha * 255));

	// Press Space Key 描画
	DrawGraph(0, 0, g_PressSpaceKeyHandle, TRUE);

	// ブレンドモードを戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void FinTitleScene()
{
	DeleteGraph(g_TitleHandle);
	DeleteGraph(g_PressSpaceKeyHandle);
}