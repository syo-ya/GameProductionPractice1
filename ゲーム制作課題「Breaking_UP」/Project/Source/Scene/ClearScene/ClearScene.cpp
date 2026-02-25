#include "DxLib.h"
#include "ClearScene.h"
//#include "../../BackGround/BackGround.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"
#include <stdio.h>

 int g_ClearHandle = 0;

void InitGameClearScene()
{
	// îwåièâä˙âª
	//InitBackGround();

	g_ClearHandle = 0;
}

void LoadGameClearScene()
{
	// îwåiÉçÅ[Éh
	//LoadBackGround("Data/GameClear/clear.PNG", BACK_GROUND_LAYER_1);
	// îwåiÉXÉNÉçÅ[Éã
	//SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);

	g_ClearHandle = LoadGraph("Data/Logo/GameClear.png");
}

void StartGameClearScene()
{

}

void StepGameClearScene()
{
	// îwåiÉXÉeÉbÉv
	//StepBackGround();

	// ZÉLÅ[Ç≈É^ÉCÉgÉãÇ…ñﬂÇÈ
	if (IsTriggerKey(KEY_SPACE))
	{
		ChangeScene(SCENE_TITLE);
	}
}

void UpdateGameClearScene()
{
	// îwåiçXêV
	//UpdateBackGround();
}

void DrawGameClearScene()
{
	// îwåiï`âÊ
	//DrawBackGround();

	DrawGraph(0, 0, g_ClearHandle, TRUE);
}

void FinGameClearScene()
{
	// îwåièIóπ
	//FinBackGround();

	DeleteGraph(g_ClearHandle);
}
