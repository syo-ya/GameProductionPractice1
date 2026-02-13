#include "DXLib.h"
#include "GameSetting/GameSetting.h"
#include "Input/Input.h"
#include "Scene/SceneManager.h"
#include "FPS/FPS.h"
#include "Sound/Sound.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_DEPTH);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	SetTransColor(TRANS_COLOR_R, TRANS_COLOR_G, TRANS_COLOR_B);

	SetDrawScreen(DX_SCREEN_BACK);

	SetBackgroundColor(BACK_GROUND_COLOR_R, BACK_GROUND_COLOR_G, BACK_GROUND_COLOR_B);

	SetFontSize(20);

	InitFPS();

	InitInput();

	while (ProcessMessage() >= 0)
	{
		Sleep(1);

		ClearDrawScreen();

		UpdateInput();

		//SceneManagerUpdate();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		UpdateFPS();

		DrawFPS();

		FPSWait();

		ScreenFlip();
	}

	FinInput();

	DxLib_End();

	return 0;

}