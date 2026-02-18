#include "DxLib.h"
#include "TitleScene.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
//#include "../../BackGround/BackGround.h"
#include <math.h>

#define BACK_GROUND_SPEED (-0.3f)

#define TITLE_POS_X (280)
#define TITLE_POS_Y (130)

#define PRESS_Z_KEY_POS_X (500)
#define PRESS_Z_KEY_POS_Y (530)

#define PRESS_Z_KEY_BLINK_SPEED (0.04f)

int g_BGHandle = 0;
int g_TitleHandle = 0;
int g_PressZKeyHandle = 0;

float g_PressZKeyAlpha = 0.0f;
float g_PressZKeyRadian = 0.0f;

void InitTitleScene()
{
	g_BGHandle = 0;
	g_TitleHandle = 0;
	g_PressZKeyHandle = 0;
	g_PressZKeyAlpha = 0.0f;
	g_PressZKeyRadian = 0.0f;

	//InitBackGround();
}

void LoadTitleScene()
{
	g_BGHandle = LoadGraph("Data/Title/title.PNG");
}

void StartTitleScene()
{

}


void StepTitleScene()
{
	if (IsTriggerKey(KEY_SPACE))
	{
		ChangeScene(SCENE_PLAY);
	}

	// îwåiÉXÉeÉbÉv
	//StepBackGround();
}

void UpdateTitleScene()
{
	// îwåiçXêV
	//UpdateBackGround();
}

void DrawTitleScene()
{
	// îwåiï`âÊ
	//DrawBackGround();

	DrawGraph(0, 0, g_BGHandle, TRUE);

}

void FinTitleScene()
{
	// îwåièIóπ
	//FinBackGround();

	// äeâÊëúÇçÌèú
	DeleteGraph(g_TitleHandle);
}