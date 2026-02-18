#include "DxLib.h"
#include "Camera.h"
#include "../Input/Input.h"
#include "../Player/Player.h"
#include "../Map/MapParameter.h"
#include "../GameSetting/GameSetting.h"

#define SCROLL_CAMERA_SPEED (1.0f)
#define CAMERA_SCROLL_START_Y (500.0f)

float CAMERA_Y_MAX;

CameraData g_CameraData = { 0 };

int Timer = 0;

bool Scroll = false;

void InitCamera()
{
	CAMERA_Y_MAX = (MAP_CHIP_Y_NUM * MAP_CHIP_HEIGHT - SCREEN_HEIGHT) * -1;
	g_CameraData.pos.y = 0.0f;
	Timer = 0;
}

void StepCamera()
{
	if (!Scroll)
	{
		if (!GameOverbool())
		{
			// プレイヤー取得
			PlayerData player = GetPlayer();

			// プレイヤーがスクロールラインを超えたらカメラ移動する
			if (player.pos.y <= CAMERA_SCROLL_START_Y && player.pos.y > CAMERA_Y_MAX + CAMERA_SCROLL_START_Y)
			{
				// ラインを超えている分だけ移動する
				g_CameraData.pos.y = player.pos.y - CAMERA_SCROLL_START_Y;
			}
			else if (player.pos.y <= CAMERA_Y_MAX + CAMERA_SCROLL_START_Y)
			{
				g_CameraData.pos.y = CAMERA_Y_MAX;
			}
			else
			{
				// 超えていなければ定位置
				g_CameraData.pos.y = 0.0f;
			}
		}
	}
	else if (Scroll && !GamePlayBool())
	{
		if (Timer >= 120)
		{
			if (g_CameraData.pos.y > CAMERA_Y_MAX)
			{
				g_CameraData.pos.y -= SCROLL_CAMERA_SPEED;
			}
			else
			{
				g_CameraData.pos.y = CAMERA_Y_MAX;
			}
		}
		else
		{
			Timer++;
		}
	}
}

void DrawCamera()
{

}

CameraData GetCamera()
{
	return g_CameraData;
}