#include "DxLib.h"
#include "Enemy.h"
#include "../Map/Map.h"
#include "../Map//MapChip.h"
#include "../FPS/FPS.h"
#include "../Map/MapManager.h"
#include "../Player/Player.h"
#include "../Scene/SceneManager.h"
#include "../GameSetting/GameSetting.h"
#include "../Sound/Sound.h"

bool EnemyWalk = true;

float FPS = rFPS();

float time = 0.0f;

MapData* Map = GetMaps();

EnemyData g_EnemyData[BLOCK_MAX] = { 0 };

int EnemyGHandleA = -1;
int EnemyGHandleB = -1;
int EnemyGKillHandle1 = -1;
int EnemyGKillHandle2 = -1;
int EnemyGKillHandle3 = -1;
int EnemyGKillHandle4 = -1;
int EnemyGKillHandle5 = -1;
int EnemyGKillHandle6 = -1;

int EnemyRHandleA = -1;
int EnemyRHandleB = -1;
int EnemyRKillHandle1 = -1;
int EnemyRKillHandle2 = -1;
int EnemyRKillHandle3 = -1;
int EnemyRKillHandle4 = -1;
int EnemyRKillHandle5 = -1;
int EnemyRKillHandle6 = -1;


int EnemyBHandleA = -1;
int EnemyBHandleB = -1;
int EnemyBKillHandle1 = -1;
int EnemyBKillHandle2 = -1;
int EnemyBKillHandle3 = -1;
int EnemyBKillHandle4 = -1;
int EnemyBKillHandle5 = -1;
int EnemyBKillHandle6 = -1;

void InitEnemy()
{
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		g_EnemyData[i].move.x = ENEMY_MOVE_SPEED;
	}

	EnemyGHandleA = LoadGraph("Data/Enemy/G/Balloon_Enemy_1.png");
	EnemyGHandleB = LoadGraph("Data/Enemy/G/Balloon_Enemy_2.png");
	EnemyGKillHandle1 = LoadGraph("Data/Enemy/G/Balloon_Enemy_Kill_1.png");
	EnemyGKillHandle2 = LoadGraph("Data/Enemy/G/Balloon_Enemy_Kill_2.png");
	EnemyGKillHandle3 = LoadGraph("Data/Enemy/G/Balloon_Enemy_Kill_3.png");
	EnemyGKillHandle4 = LoadGraph("Data/Enemy/G/Balloon_Enemy_Kill_4.png");
	EnemyGKillHandle5 = LoadGraph("Data/Enemy/G/Balloon_Enemy_Kill_5.png");
	EnemyGKillHandle6 = LoadGraph("Data/Enemy/G/Balloon_Enemy_Kill_6.png");

	EnemyRHandleA = LoadGraph("Data/Enemy/R/Balloon_Enemy_1.png");
	EnemyRHandleB = LoadGraph("Data/Enemy/R/Balloon_Enemy_2.png");
	EnemyRKillHandle1 = LoadGraph("Data/Enemy/R/Balloon_Enemy_Kill_1.png");
	EnemyRKillHandle2 = LoadGraph("Data/Enemy/R/Balloon_Enemy_Kill_2.png");
	EnemyRKillHandle3 = LoadGraph("Data/Enemy/R/Balloon_Enemy_Kill_3.png");
	EnemyRKillHandle4 = LoadGraph("Data/Enemy/R/Balloon_Enemy_Kill_4.png");
	EnemyRKillHandle5 = LoadGraph("Data/Enemy/R/Balloon_Enemy_Kill_5.png");
	EnemyRKillHandle6 = LoadGraph("Data/Enemy/R/Balloon_Enemy_Kill_6.png");

	EnemyBHandleA = LoadGraph("Data/Enemy/B/Balloon_Enemy_1.png");
	EnemyBHandleB = LoadGraph("Data/Enemy/B/Balloon_Enemy_2.png");
	EnemyBKillHandle1 = LoadGraph("Data/Enemy/B/Balloon_Enemy_Kill_1.png");
	EnemyBKillHandle2 = LoadGraph("Data/Enemy/B/Balloon_Enemy_Kill_2.png");
	EnemyBKillHandle3 = LoadGraph("Data/Enemy/B/Balloon_Enemy_Kill_3.png");
	EnemyBKillHandle4 = LoadGraph("Data/Enemy/B/Balloon_Enemy_Kill_4.png");
	EnemyBKillHandle5 = LoadGraph("Data/Enemy/B/Balloon_Enemy_Kill_5.png");
	EnemyBKillHandle6 = LoadGraph("Data/Enemy/B/Balloon_Enemy_Kill_6.png");
}

void StepEnemy()
{
	FPS = rFPS();
	if (FPS > 0)
	{
		time += 1.00f / FPS;
	}
	else
	{
		time += 1.00f / 60.00f;
	}

	if (time >= 0.25f)
	{
		time = 0.0f;
		EnemyWalk = !EnemyWalk;
	}
	MapData* Map = GetMaps();
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if (Map[i].type == ENEMY || Map[i].type == FIRE_ENEMY || Map[i].type == SKY_ENEMY)
		{
			g_EnemyData[i].PrevPos = Map[i].pos;

			if (g_EnemyData[i].move.y > ENEMY_GRAVITY_MAX)
			{
				g_EnemyData[i].move.y = ENEMY_GRAVITY_MAX;
			}
			g_EnemyData[i].move.y += ENEMY_GRAVITY;
		}
	}

}

void UpdateEnemy()
{
	MapData* Block = GetMaps();
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if (!Map[i].active) continue;

		if (Map[i].type == ENEMY || Map[i].type == FIRE_ENEMY || Map[i].type == SKY_ENEMY)
		{
			if (!Map[i].EnemyKill)
			{
				if (g_EnemyData[i].dirRight)
				{
					Map[i].pos.x += g_EnemyData[i].move.x;
				}
				if (!g_EnemyData[i].dirRight)
				{
					Map[i].pos.x -= g_EnemyData[i].move.x;
				}

				if (Map[i].type != SKY_ENEMY)
				{
					Map[i].pos.y += g_EnemyData[i].move.y;
				}
				if (Map[i].type != SKY_ENEMY)
				{
					bool groundAhead = false;

					float footY = Map[i].pos.y + MAP_CHIP_HEIGHT + 1;
					float checkX;

					if (g_EnemyData[i].dirRight)
					{
						checkX = Map[i].pos.x + MAP_CHIP_WIDTH + 1;
					}
					else
					{
						checkX = Map[i].pos.x - 1;
					}
					for (int j = 0; j < BLOCK_MAX; j++)
					{
						if (!Block[j].active) continue;

						if (Block[j].type == NORMAL_BLOCK || Block[j].type == ONE_WAY_BLOCK || Block[j].type == DESTROY_BLOCK || Block[j].type == DESTROY_BLOCK_2)
						{
							if (CheckSquareSquare(
								checkX, footY,
								1, 1,
								Block[j].pos.x, Block[j].pos.y,
								MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
							{
								groundAhead = true;
								break;
							}
						}
					}
					if (!groundAhead)
					{
						g_EnemyData[i].dirRight = !g_EnemyData[i].dirRight;
					}
				}
			}

			for (int j = 0; j < BLOCK_MAX; j++)
			{
				if (!Block[j].active) continue;

				if (Block[j].type == NORMAL_BLOCK || Block[j].type == ONE_WAY_BLOCK || Block[j].type == NEEDLE_BLOCK || Block[j].type == DESTROY_BLOCK || Block[j].type == DESTROY_BLOCK_2 || Block[j].type == ENEMY || Block[j].type == FIRE_ENEMY || Block[j].type == SKY_ENEMY)
				{
					float prevBottom = g_EnemyData[i].PrevPos.y + MAP_CHIP_HEIGHT;
					float prevTop = g_EnemyData[i].PrevPos.y;
					float prevRight = g_EnemyData[i].PrevPos.x + MAP_CHIP_WIDTH;
					float prevLeft = g_EnemyData[i].PrevPos.x;

					float blockTop = Block[j].pos.y;
					float blockBottom = Block[j].pos.y + MAP_CHIP_HEIGHT;
					float blockLeft = Block[j].pos.x;
					float blockRight = Block[j].pos.x + MAP_CHIP_WIDTH;

					if (!CheckSquareSquare(Map[i].pos.x, Map[i].pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT,
						Block[j].pos.x, Block[j].pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
					{
						continue;
					}

					// ã‚©‚ç—Ž‚¿‚Ä‚«‚½
					if (prevBottom <= blockTop)
					{
						if (Block[j].type != ENEMY && Block[j].type != FIRE_ENEMY && Block[j].type != SKY_ENEMY)
						{
							Map[i].pos.y = blockTop - MAP_CHIP_HEIGHT;
							g_EnemyData[i].move.y = 0.0f;
						}
					}
					// ¶‚©‚ç‚Ô‚Â‚©‚Á‚½
					else if (prevRight <= blockLeft && Block[j].type != ONE_WAY_BLOCK)
					{
						g_EnemyData[i].dirRight = false;
					}
					// ‰E‚©‚ç‚Ô‚Â‚©‚Á‚½
					else if (prevLeft >= blockRight && Block[j].type != ONE_WAY_BLOCK)
					{
						g_EnemyData[i].dirRight = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if (Map[i].type == ENEMY)
		{
			if (!Map[i].EnemyKill)
			{
				if (EnemyWalk)
				{
					Map[i].handle = EnemyGHandleA;
				}
				else
				{
					Map[i].handle = EnemyGHandleB;
				}
			}
			else if (Map[i].active)
			{
				if (FPS > 0)
				{
					Map[i].EffectTime += 1.00f / FPS;
				}
				else
				{
					Map[i].EffectTime += 1.00f / 60.00f;
				}

				if (Map[i].EffectTime >= 0.0f && Map[i].EffectTime < 0.03f)
				{
					Map[i].handle = EnemyGKillHandle1;
				}
				else if (Map[i].EffectTime >= 0.03f && Map[i].EffectTime < 0.06f)
				{
					Map[i].handle = EnemyGKillHandle2;
				}
				else if (Map[i].EffectTime >= 0.06f && Map[i].EffectTime < 0.09f)
				{
					Map[i].handle = EnemyGKillHandle3;
				}
				else if (Map[i].EffectTime >= 0.09f && Map[i].EffectTime < 0.12f)
				{
					Map[i].handle = EnemyGKillHandle4;
				}
				else if (Map[i].EffectTime >= 0.12f && Map[i].EffectTime < 0.15f)
				{
					Map[i].handle = EnemyGKillHandle5;
				}
				else if (Map[i].EffectTime >= 0.15f && Map[i].EffectTime < 0.3f)
				{
					Map[i].handle = EnemyGKillHandle6;
				}
				else if (Map[i].EffectTime >= 0.3f)
				{
					Map[i].active = false;
					Map[i].EffectTime = 0.0f;
				}
			}
		}
		if (Map[i].type == FIRE_ENEMY)
		{
			if (!Map[i].EnemyKill)
			{
				if (EnemyWalk)
				{
					Map[i].handle = EnemyRHandleA;
				}
				else
				{
					Map[i].handle = EnemyRHandleB;
				}
			}
			else if (Map[i].active)
			{
				if (FPS > 0)
				{
					Map[i].EffectTime += 1.00f / FPS;
				}
				else
				{
					Map[i].EffectTime += 1.00f / 60.00f;
				}

				if (Map[i].EffectTime >= 0.0f && Map[i].EffectTime < 0.03f)
				{
					Map[i].handle = EnemyRKillHandle1;
				}
				else if (Map[i].EffectTime >= 0.03f && Map[i].EffectTime < 0.06f)
				{
					Map[i].handle = EnemyRKillHandle2;
				}
				else if (Map[i].EffectTime >= 0.06f && Map[i].EffectTime < 0.09f)
				{
					Map[i].handle = EnemyRKillHandle3;
				}
				else if (Map[i].EffectTime >= 0.09f && Map[i].EffectTime < 0.12f)
				{
					Map[i].handle = EnemyRKillHandle4;
				}
				else if (Map[i].EffectTime >= 0.12f && Map[i].EffectTime < 0.15f)
				{
					Map[i].handle = EnemyRKillHandle5;
				}
				else if (Map[i].EffectTime >= 0.15f && Map[i].EffectTime < 0.3f)
				{
					Map[i].handle = EnemyRKillHandle6;
				}
				else if (Map[i].EffectTime >= 0.3f)
				{
					Map[i].active = false;
					Map[i].EffectTime = 0.0f;
				}
			}
		}
		if (Map[i].type == SKY_ENEMY)
		{
			if (!Map[i].EnemyKill)
			{
				if (EnemyWalk)
				{
					Map[i].handle = EnemyBHandleA;
				}
				else
				{
					Map[i].handle = EnemyBHandleB;
				}
			}
			else if (Map[i].active)
			{
				if (FPS > 0)
				{
					Map[i].EffectTime += 1.00f / FPS;
				}
				else
				{
					Map[i].EffectTime += 1.00f / 60.00f;
				}

				if (Map[i].EffectTime >= 0.0f && Map[i].EffectTime < 0.03f)
				{
					Map[i].handle = EnemyBKillHandle1;
				}
				else if (Map[i].EffectTime >= 0.03f && Map[i].EffectTime < 0.06f)
				{
					Map[i].handle = EnemyBKillHandle2;
				}
				else if (Map[i].EffectTime >= 0.06f && Map[i].EffectTime < 0.09f)
				{
					Map[i].handle = EnemyBKillHandle3;
				}
				else if (Map[i].EffectTime >= 0.09f && Map[i].EffectTime < 0.12f)
				{
					Map[i].handle = EnemyBKillHandle4;
				}
				else if (Map[i].EffectTime >= 0.12f && Map[i].EffectTime < 0.15f)
				{
					Map[i].handle = EnemyBKillHandle5;
				}
				else if (Map[i].EffectTime >= 0.15f && Map[i].EffectTime < 0.3f)
				{
					Map[i].handle = EnemyBKillHandle6;
				}
				else if (Map[i].EffectTime >= 0.3f)
				{
					Map[i].active = false;
					Map[i].EffectTime = 0.0f;
				}
			}
		}
	}
}


void EnemyKill(int i)
{
	if (!Map[i].EnemyKill)
	{
		Map[i].EnemyKill = true;
		//PlaySE(SE_ENEMY_KILL);
		Map[i].EffectTime = 0.0f;
	}
}

void ResetEnemy()
{
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if (Map[i].type == ENEMY || Map[i].type == FIRE_ENEMY || Map[i].type == SKY_ENEMY)
		{
			Map[i].EnemyKill = false;
			DeleteGraph(Map[i].handle);
			g_EnemyData[i].dirRight = false;
		}
	}
}
