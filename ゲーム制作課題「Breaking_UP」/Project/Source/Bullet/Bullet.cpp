#include "DxLib.h"
#include "Bullet.h"
#include "../Input/Input.h"
#include "../Sound/Sound.h"
#include "../Camera/Camera.h"
#include "../Player/Player.h"
#include "../FPS/FPS.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

BulletData g_BulletData[BULLET_NUM] = { 0 };

ArrowData g_ArrowData = { 0 };

int BULLET_TRUE_NUM = 0;
float BULLET_COOLTIME = 0.0f;

VECTOR BulletPos;

int BulletDir = 1;

int rx;
int ry;

float TurnBulletPos;

void InitBullet()
{
	g_ArrowData.handle = LoadGraph("Data/Bullet/Arrow.png");

	for (int i = 0; i < BULLET_NUM; i++)
	{
		g_BulletData[i].handle = LoadGraph("Data/Bullet/Bullet.png");
		g_BulletData[i].active = false;
		g_BulletData[i].Fire = false;
		g_BulletData[i].move.x = BULLET_MOVE_SPEED;
		g_BulletData[i].move.y = BULLET_MOVE_SPEED;
		g_BulletData[i].LifeTime = 0.0f;
	}
}

void UpdateBullet()
{
	BULLET_COOLTIME--;

	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (!g_BulletData[i].Fire)
		{
			if (BulletDir == 1)
			{
				g_BulletData[i].move.y = -BULLET_MOVE_SPEED;
				g_BulletData[i].move.x = 0.0f;
			}
			else if (BulletDir == 2)
			{
				g_BulletData[i].move.y = -BULLET_MOVE_SPEED;
				g_BulletData[i].move.x = BULLET_MOVE_SPEED;
			}
			else if (BulletDir == 3)
			{
				g_BulletData[i].move.y = 0.0f;
				g_BulletData[i].move.x = BULLET_MOVE_SPEED;
			}
			else if (BulletDir == 4)
			{
				g_BulletData[i].move.y = BULLET_MOVE_SPEED;
				g_BulletData[i].move.x = BULLET_MOVE_SPEED;
			}
			else if (BulletDir == 5)
			{
				g_BulletData[i].move.y = BULLET_MOVE_SPEED;
				g_BulletData[i].move.x = 0.0f;
			}
			else if (BulletDir == 6)
			{
				g_BulletData[i].move.y = BULLET_MOVE_SPEED;
				g_BulletData[i].move.x = -BULLET_MOVE_SPEED;
			}
			else if (BulletDir == 7)
			{
				g_BulletData[i].move.y = 0.0f;
				g_BulletData[i].move.x = -BULLET_MOVE_SPEED;
			}
			else if (BulletDir == 8)
			{
				g_BulletData[i].move.y = -BULLET_MOVE_SPEED;
				g_BulletData[i].move.x = -BULLET_MOVE_SPEED;
			}
		}

		if (g_BulletData[i].active)
		{
			g_BulletData[i].pos.x += g_BulletData[i].move.x;
			g_BulletData[i].pos.y += g_BulletData[i].move.y;
			g_BulletData[i].LifeTime += 1 / rFPS();
			if (g_BulletData[i].LifeTime >= 3.0f)
			{
				g_BulletData[i].active = false;
			}
		}
		else if (g_BulletData[i].LifeTime > 0.0f)
		{
			g_BulletData[i].LifeTime = 0.0f;
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

	PlayerData player = GetPlayer();

	if (player.isTurn)
	{
		TurnBulletPos = PLAYER_BOX_COLLISION_WIDTH / 4;
	}
	else
	{
		TurnBulletPos = 0;
	}

	GetJoypadAnalogInputRight(&rx, &ry, DX_INPUT_PAD1);

	SetDrawMode(DX_DRAWMODE_BILINEAR);
	if ((IsInputKey(KEY_W) && IsInputKey(KEY_D)) || (rx > 200 && ry < -200))
	{
		BulletDir = 2;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + ARROW_SIZE - BULLET_WIDTH + TurnBulletPos;
		BulletPos.y = ARROW_RADIUS;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + ARROW_RADIUS - camera.pos.y,
			1.0, 1.25 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if ((IsInputKey(KEY_D) && IsInputKey(KEY_S)) || (rx > 200 && ry > 200))
	{
		BulletDir = 4;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + ARROW_SIZE - BULLET_WIDTH + TurnBulletPos;
		BulletPos.y = PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + ARROW_RADIUS - BULLET_HEIGHT;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + ARROW_RADIUS  - camera.pos.y,
			1.0, 1.75 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if ((IsInputKey(KEY_S) && IsInputKey(KEY_A)) || (rx < -200 && ry > 200))
	{
		BulletDir = 6;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - ARROW_SIZE + TurnBulletPos;
		BulletPos.y = PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + ARROW_RADIUS - BULLET_HEIGHT;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + ARROW_RADIUS - camera.pos.y,
			1.0, 0.25 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if ((IsInputKey(KEY_A) && IsInputKey(KEY_W)) || (rx < -200 && ry < -200))
	{
		BulletDir = 8;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - ARROW_SIZE + TurnBulletPos;
		BulletPos.y = ARROW_RADIUS;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + ARROW_RADIUS - camera.pos.y,
			1.0, 0.75 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if (IsInputKey(KEY_W) || ry <= -1000)
	{
		BulletDir = 1;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - BULLET_RADIUS + TurnBulletPos;
		BulletPos.y = NULL;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + TurnBulletPos - camera.pos.x,
			player.pos.y - camera.pos.y,
			1.0, 1 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if (IsInputKey(KEY_D) || rx >= 1000)
	{
		BulletDir = 3;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH)+ARROW_SIZE - (BULLET_WIDTH * 1.5f) + TurnBulletPos;
		BulletPos.y = PLAYER_BOX_COLLISION_OFFSET_Y + (PLAYER_BOX_COLLISION_HEIGHT / 2) - BULLET_RADIUS;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH) + ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + (PLAYER_BOX_COLLISION_HEIGHT / 2) - camera.pos.y,
			1.0, 1.5 + M_PI, g_ArrowData.handle, TRUE);

	}
	else if (IsInputKey(KEY_S) || ry >= 1000)
	{
		BulletDir = 5;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - BULLET_RADIUS + TurnBulletPos;
		BulletPos.y = PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + (ARROW_RADIUS * 2) - BULLET_HEIGHT;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + (ARROW_RADIUS * 2) - camera.pos.y, 
			1.0, 0, g_ArrowData.handle, TRUE);
	}
	else if (IsInputKey(KEY_A) || rx <= -1000)
	{
		BulletDir = 7;
		BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X - ARROW_SIZE + TurnBulletPos;
		BulletPos.y = PLAYER_BOX_COLLISION_OFFSET_Y + (PLAYER_BOX_COLLISION_HEIGHT / 2) - BULLET_RADIUS;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X - ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + (PLAYER_BOX_COLLISION_HEIGHT / 2) - camera.pos.y,
			1.0, 0.5 * M_PI, g_ArrowData.handle, TRUE);

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
	CameraData camera = GetCamera();

	if (!g_BulletData[BULLET_TRUE_NUM].active && BULLET_COOLTIME <= 0)
	{
		DrawGraph((int)posX + BulletPos.x - camera.pos.x, (int)posY + BulletPos.y - camera.pos.y, g_BulletData[BULLET_TRUE_NUM].handle, TRUE);
		g_BulletData[BULLET_TRUE_NUM].pos.x = posX + BulletPos.x;
		g_BulletData[BULLET_TRUE_NUM].pos.y = posY + BulletPos.y;
		g_BulletData[BULLET_TRUE_NUM].active = true;
		g_BulletData[BULLET_TRUE_NUM].Fire = true;
		BULLET_TRUE_NUM++;
		BULLET_COOLTIME = BULLET_COOLTIME_MAX;

		//PlaySE(SE_SHOT);
	}

	if (BULLET_TRUE_NUM >= BULLET_NUM)
	{
		BULLET_TRUE_NUM = 0;
	}

}
