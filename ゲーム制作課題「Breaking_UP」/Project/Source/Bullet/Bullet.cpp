#include "DxLib.h"
#include "Bullet.h"
#include "../Input/Input.h"
#include "../Sound/Sound.h"
#include "../Camera/Camera.h"
#include "../Player/Player.h"
#include "../FPS/FPS.h"
#include "../Map/Map.h"
#include "../GameSetting/GameSetting.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

BulletData g_BulletData[BULLET_NUM] = { 0 };

ArrowData g_ArrowData = { 0 };

int BulletNormalHandle = -1;
int BulletHitHandle1 = -1;
int BulletHitHandle2 = -1;
int BulletHitHandle3 = -1;
int BulletHitHandle4 = -1;

int BULLET_TRUE_NUM = 0;
float BULLET_COOLTIME = 0.0f;

VECTOR BulletPos;

int BulletDir = 1;

int rx;
int ry;

float TurnBulletPos;

int BlockHandle0 = -1;
int BlockHandle1 = -1;
int BlockHandle2 = -1;
int BlockHandle3 = -1;
int BlockHandle4 = -1;
int BlockHandle5 = -1;
int BlockHandle6 = -1;
int BlockHandle7 = -1;
int BlockHandle8 = -1;
int BlockHandle9 = -1;
int BlockHandle10 = -1;
int BlockHandle11 = -1;

void InitBullet()
{
	BulletDir = 1;

	g_ArrowData.handle = LoadGraph("Data/Bullet/Arrow.png");

	for (int i = 0; i < BULLET_NUM; i++)
	{
		g_BulletData[i].active = false;
		g_BulletData[i].Hit = false;
		g_BulletData[i].Fire = false;
		g_BulletData[i].move.x = BULLET_MOVE_SPEED;
		g_BulletData[i].move.y = BULLET_MOVE_SPEED;
		g_BulletData[i].LifeTime = 0.0f;
	}

	BulletNormalHandle = LoadGraph("Data/Bullet/Bullet.png");
	BulletHitHandle1 = LoadGraph("Data/Bullet/Bullet_Hit_1.png");
	BulletHitHandle2 = LoadGraph("Data/Bullet/Bullet_Hit_2.png");
	BulletHitHandle3 = LoadGraph("Data/Bullet/Bullet_Hit_3.png");
	BulletHitHandle4 = LoadGraph("Data/Bullet/Bullet_Hit_4.png");

	BlockHandle0 = LoadGraph("Data/Map/Destroy_Block/Block.png");
	BlockHandle1 = LoadGraph("Data/Map/Destroy_Block/Block_Break_1.png");
	BlockHandle2 = LoadGraph("Data/Map/Destroy_Block/Block_Break_2.png");
	BlockHandle3 = LoadGraph("Data/Map/Destroy_Block/Block_Break_3.png");
	BlockHandle4 = LoadGraph("Data/Map/Destroy_Block/Block_Break_4.png");
	BlockHandle5 = LoadGraph("Data/Map/Destroy_Block/Block_Break_5.png");
	BlockHandle6 = LoadGraph("Data/Map/Destroy_Block/Block_Break_6.png");
	BlockHandle7 = LoadGraph("Data/Map/Destroy_Block/Block_Break_7.png");
	BlockHandle8 = LoadGraph("Data/Map/Destroy_Block/Block_Break_8.png");
	BlockHandle9 = LoadGraph("Data/Map/Destroy_Block/Block_Break_9.png");
	BlockHandle10 = LoadGraph("Data/Map/Destroy_Block/Block_Break_10.png");
	BlockHandle11 = -1;
}

void UpdateBullet()
{
	BULLET_COOLTIME--;

	for (int i = 0; i < BULLET_NUM; i++)
	{
		g_BulletData[i].prevPos = g_BulletData[i].pos;

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

		if (g_BulletData[i].active && !g_BulletData[i].Hit)
		{
			g_BulletData[i].pos.x += g_BulletData[i].move.x;
			g_BulletData[i].pos.y += g_BulletData[i].move.y;
			if (rFPS() > 0)
			{
				g_BulletData[i].LifeTime += 1.00f / rFPS();
			}
			else
			{
				g_BulletData[i].LifeTime += 1.00f / 60.00f;
			}
			if (g_BulletData[i].LifeTime >= 3.0f)
			{
				g_BulletData[i].active = false;
			}
		}
		else if (g_BulletData[i].LifeTime > 0.0f || g_BulletData[i].Fire)
		{
			g_BulletData[i].LifeTime = 0.0f;
			g_BulletData[i].Fire = false;
		}

		if (g_BulletData[i].Hit)
		{
			if (rFPS() > 0)
			{
				g_BulletData[i].EffectTime += 1.00f / rFPS();
			}
			else
			{
				g_BulletData[i].EffectTime += 1.00f / 60.00f;
			}

			if (g_BulletData[i].EffectTime >= 0.0f && g_BulletData[i].EffectTime < 0.05f)
			{
				g_BulletData[i].handle = BulletHitHandle1;
			}
			else if (g_BulletData[i].EffectTime >= 0.05f && g_BulletData[i].EffectTime < 0.10f)
			{
				g_BulletData[i].handle = BulletHitHandle2;
			}
			else if (g_BulletData[i].EffectTime >= 0.10f && g_BulletData[i].EffectTime < 0.15f)
			{
				g_BulletData[i].handle = BulletHitHandle3;
			}
			else if (g_BulletData[i].EffectTime >= 0.15f && g_BulletData[i].EffectTime < 0.25f)
			{
				g_BulletData[i].handle = BulletHitHandle4;
			}
			else if (g_BulletData[i].EffectTime >= 0.25f)
			{
				g_BulletData[i].active = false;
			}

			if (g_BulletData[i].active == false)
			{
				g_BulletData[i].EffectTime = 0.0f;
				g_BulletData[i].Hit = false;
			}
		}

		MapData* Map = GetMaps();
		for (int j = 0; j < BLOCK_MAX; j++)
		{
			if (!Map[j].active)
			{
				continue;
			}
			float blockDrawY = Map[j].pos.y - ((MAP_CHIP_Y_NUM * MAP_CHIP_HEIGHT) - SCREEN_HEIGHT);

			if (!GamePlayBool() && g_BulletData[i].active && !g_BulletData[i].Hit)
			{
				if (!CheckSquareSquare(g_BulletData[i].pos.x + BULLET_OFFSET, g_BulletData[i].pos.y + BULLET_OFFSET, BULLET_WIDTH - BULLET_OFFSET * 2, BULLET_HEIGHT - BULLET_OFFSET * 2,
					Map[j].pos.x, blockDrawY, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
				{
					continue;
				}

				if (Map[j].type == NORMAL_BLOCK || Map[j].type == NEEDLE_BLOCK)
				{
					g_BulletData[i].Hit = true;
				}
				if (Map[j].type == DESTROY_BLOCK || Map[j].type == DESTROY_BLOCK_2)
				{
					if (Map[j].BreakFlg == -1)
					{
						Map[j].BreakFlg = 0;
						Map[j].EffectTime = 0.0f;
						g_BulletData[i].Hit = true;
					}
					else if (Map[j].BreakFlg == 1 || Map[j].BreakFlg == 0)
					{
						Map[j].BreakFlg = 2;
						Map[j].EffectTime = 0.0f;
						g_BulletData[i].Hit = true;
					}
				}
			}
		}
	}

	MapData* Map = GetMaps();
	for (int j = 0; j < BLOCK_MAX; j++)
	{

		if (Map[j].type == DESTROY_BLOCK || Map[j].type == DESTROY_BLOCK_2)
		{
			if (Map[j].BreakFlg == 0)
			{
				if (rFPS() > 0)
				{
					Map[j].EffectTime += 1.00f / rFPS();
				}
				else
				{
					Map[j].EffectTime += 1.00f / 60.00f;
				}

				if (Map[j].EffectTime >= 0.0f && Map[j].EffectTime < 0.04f)
				{
					Map[j].handle = BlockHandle1;
				}
				else if (Map[j].EffectTime >= 0.04f && Map[j].EffectTime < 0.08f)
				{
					Map[j].handle = BlockHandle2;
				}
				else if (Map[j].EffectTime >= 0.08f && Map[j].EffectTime < 0.12f)
				{
					Map[j].handle = BlockHandle3;
				}
				else if (Map[j].EffectTime >= 0.12f && Map[j].EffectTime < 0.16f)
				{
					Map[j].handle = BlockHandle4;
				}
				else if (Map[j].EffectTime >= 0.16f && Map[j].EffectTime < 0.20f)
				{
					Map[j].handle = BlockHandle5;
					Map[j].EffectTime = 0.0f;
					Map[j].BreakFlg = 1;
				}
			}

			if (Map[j].BreakFlg == 2)
			{
				for (int v = 0; v < BLOCK_MAX; v++)
				{
					if (Map[j].EffectTime > 0.05f)
					{
						if ((Map[j].ChipY == Map[v].ChipY) && (Map[j].ChipX - Map[v].ChipX == 1 || Map[v].ChipX - Map[j].ChipX == 1) && (Map[v].BreakFlg == 1 || Map[v].BreakFlg == 0))
						{
							Map[v].EffectTime = 0.0f;
							Map[v].BreakFlg = 2;
						}
						if ((Map[j].ChipX == Map[v].ChipX) && (Map[j].ChipY - Map[v].ChipY == 1 || Map[v].ChipY - Map[j].ChipY == 1) && (Map[v].BreakFlg == 1 || Map[v].BreakFlg == 0))
						{
							Map[v].EffectTime = 0.0f;
							Map[v].BreakFlg = 2;
						}
					}
				}

				if (rFPS() > 0)
				{
					Map[j].EffectTime += 1.00f / rFPS();
				}
				else
				{
					Map[j].EffectTime += 1.00f / 60.00f;
				}

				if (Map[j].EffectTime >= 0.0f && Map[j].EffectTime < 0.04f)
				{
					Map[j].handle = BlockHandle6;
				}
				else if (Map[j].EffectTime >= 0.04f && Map[j].EffectTime < 0.08f)
				{
					Map[j].handle = BlockHandle7;
				}
				else if (Map[j].EffectTime >= 0.08f && Map[j].EffectTime < 0.12f)
				{
					Map[j].handle = BlockHandle8;
				}
				else if (Map[j].EffectTime >= 0.12f && Map[j].EffectTime < 0.16f)
				{
					Map[j].handle = BlockHandle9;
				}
				else if (Map[j].EffectTime >= 0.16f && Map[j].EffectTime < 0.20f)
				{
					Map[j].handle = BlockHandle10;
				}
				else if (Map[j].EffectTime > 0.20f)
				{
					Map[j].handle = BlockHandle11;
					Map[j].EffectTime = 0.0f;
					Map[j].BreakFlg = -1;
					Map[j].active = false;
				}
			}
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

	BulletPos.x = PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - BULLET_RADIUS + TurnBulletPos;
	BulletPos.y = PLAYER_BOX_COLLISION_OFFSET_Y + (PLAYER_BOX_COLLISION_HEIGHT / 2) - BULLET_RADIUS;

	GetJoypadAnalogInputRight(&rx, &ry, DX_INPUT_PAD1);

	SetDrawMode(DX_DRAWMODE_BILINEAR);

	if ((IsInputKey(KEY_W) && IsInputKey(KEY_D)) || (rx > 200 && ry < -200))
	{
		BulletDir = 2;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + ARROW_RADIUS - camera.pos.y,
			1.0, 1.25 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if ((IsInputKey(KEY_D) && IsInputKey(KEY_S)) || (rx > 200 && ry > 200))
	{
		BulletDir = 4;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + ARROW_RADIUS - camera.pos.y,
			1.0, 1.75 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if ((IsInputKey(KEY_S) && IsInputKey(KEY_A)) || (rx < -200 && ry > 200))
	{
		BulletDir = 6;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + ARROW_RADIUS - camera.pos.y,
			1.0, 0.25 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if ((IsInputKey(KEY_A) && IsInputKey(KEY_W)) || (rx < -200 && ry < -200))
	{
		BulletDir = 8;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) - ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + ARROW_RADIUS - camera.pos.y,
			1.0, 0.75 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if (IsInputKey(KEY_W) || ry <= -1000)
	{
		BulletDir = 1;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + TurnBulletPos - camera.pos.x,
			player.pos.y - camera.pos.y,
			1.0, 1 * M_PI, g_ArrowData.handle, TRUE);

	}
	else if (IsInputKey(KEY_D) || rx >= 1000)
	{
		BulletDir = 3;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH)+ARROW_SIZE + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + (PLAYER_BOX_COLLISION_HEIGHT / 2) - camera.pos.y,
			1.0, 1.5 + M_PI, g_ArrowData.handle, TRUE);

	}
	else if (IsInputKey(KEY_S) || ry >= 1000)
	{
		BulletDir = 5;
		DrawRotaGraph(player.pos.x + PLAYER_BOX_COLLISION_OFFSET_X + (PLAYER_BOX_COLLISION_WIDTH / 2) + TurnBulletPos - camera.pos.x,
			player.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT + (ARROW_RADIUS * 2) - camera.pos.y,
			1.0, 0, g_ArrowData.handle, TRUE);
	}
	else if (IsInputKey(KEY_A) || rx <= -1000)
	{
		BulletDir = 7;
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
		g_BulletData[BULLET_TRUE_NUM].handle = BulletNormalHandle;
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
