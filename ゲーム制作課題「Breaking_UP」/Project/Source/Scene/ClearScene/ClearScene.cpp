#include "DxLib.h"
#include "ClearScene.h"
//#include "../../BackGround/BackGround.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"
#include <stdio.h>

void InitGameClearScene()
{
	// ”wŒi‰Šú‰»
	//InitBackGround();
}

void LoadGameClearScene()
{
	// ”wŒiƒ[ƒh
	//LoadBackGround("Data/GameClear/clear.PNG", BACK_GROUND_LAYER_1);
	// ”wŒiƒXƒNƒ[ƒ‹
	//SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);
}

void StartGameClearScene()
{

}

void StepGameClearScene()
{
	// ”wŒiƒXƒeƒbƒv
	//StepBackGround();

	// ZƒL[‚Åƒ^ƒCƒgƒ‹‚É–ß‚é
	if (IsTriggerKey(KEY_SPACE))
	{
		ChangeScene(SCENE_TITLE);
	}
}

void UpdateGameClearScene()
{
	// ”wŒiXV
	//UpdateBackGround();
}

void DrawGameClearScene()
{
	// ”wŒi•`‰æ
	//DrawBackGround();
}

void FinGameClearScene()
{
	// ”wŒiI—¹
	//FinBackGround();
}
