#include "DxLib.h"
#include "Bullet.h"
#include "../Input/Input.h"
#include "../Sound/Sound.h"
#include "../Camera/Camera.h"

BulletData g_BulletData[BULLET_NUM] = { 0 };

int BULLET_TRUE_NUM = 0;
float BULLET_COOLTIME = 0.0f;

void InitBullet()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		g_BulletData[i].handle = LoadGraph("Data/Bullet/Bullet.png");
		g_BulletData[i].active = false;
		g_BulletData[i].move.y = BULLET_MOVE_SPEED;
	}
}

void UpdateBullet()
{
	BULLET_COOLTIME--;

	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (g_BulletData[i].active)
		{
			g_BulletData[i].pos.y -= g_BulletData[i].move.y;
		}
	}
}

void DrawBullet()
{
	CameraData camera = GetCamera();

	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (g_BulletData[i].active)
		{
			DrawGraph((int)g_BulletData[i].pos.x - camera.pos.x, (int)g_BulletData[i].pos.y - camera.pos.y, g_BulletData[i].handle, TRUE);
		}
	}
}

void FinBullet()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		DeleteGraph(g_BulletData[i].handle);
	}
}

BulletData* GetBullet(int num)
{
	return &g_BulletData[num];
}


void FireBullet(float posX, float posY)
{
	if (!g_BulletData[BULLET_TRUE_NUM].active && BULLET_COOLTIME <= 0)
	{
		DrawGraph((int)posX, (int)posY, g_BulletData[BULLET_TRUE_NUM].handle, TRUE);
		g_BulletData[BULLET_TRUE_NUM].pos.x = posX;
		g_BulletData[BULLET_TRUE_NUM].pos.y = posY;
		g_BulletData[BULLET_TRUE_NUM].active = true;
		BULLET_TRUE_NUM++;
		BULLET_COOLTIME = BULLET_COOLTIME_MAX;

		//PlaySE(SE_SHOT);
	}

	if (BULLET_TRUE_NUM >= BULLET_NUM)
	{
		BULLET_TRUE_NUM = 0;
	}

}
