#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../GameSetting/GameSetting.h"
#include "../Collision/Collision.h"
#include "../Camera/Camera.h"
#include "../Scene/SceneManager.h"
#include "../FPS/FPS.h"
#include "../Sound/Sound.h"
#include "../Map/Map.h"
#include "math.h"

PlayerData g_PlayerData = { 0 };
PlayerData g_PrevPlayerData = { 0 };

int TotalGetCoin = 0;
int StageGetCoin = 0;

float pFPS = rFPS();

float effectTime = 0.0f;

bool SECooltime = true;

bool JumpInput = true;

bool gameOver = false;
bool gameClear = false;
int StopCount = 0;
bool gameSceneChangeSE = false;

bool MoveNow = false;

float PLAYER_MOVE_MAX = 6.5;
float PLAYER_JUMP_MAX = 12.0;

struct PlayerAnimationParam
{
	int interval;
	int frameNum;
	int width;
	int height;
};
const PlayerAnimationParam PLAYER_ANIM_PARAM[PLAYER_ANIM_MAX] =
{
	8, 4, 72, 72,
	5, 8, 72, 72,
	8, 2, 72, 72,
	8, 2, 72, 72,
	8, 1, 72, 72,
};

void StartPlayerAnimation(PlayerAnimationType anim);
void UpdatePlayerAnimation();

void InitPlayer()
{
	gameOver = false;
	gameClear = false;
	SECooltime = true;
	StopCount = 0;
	gameSceneChangeSE = false;
	
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;
	g_PlayerData.playAnim = PLAYER_ANIM_NONE;

	for (int i = 0; i < PLAYER_ANIM_MAX; i++)
	{
		InitAnimation(&g_PlayerData.animation[i]);
	}
}

void LoadPlayer()
{
	g_PlayerData.animation[PLAYER_ANIM_IDLE].handle = LoadGraph("Data/Player/PlayerIdle.png");
	g_PlayerData.animation[PLAYER_ANIM_RUN].handle = LoadGraph("Data/Player/PlayerRun.png");
	g_PlayerData.animation[PLAYER_ANIM_JUMP].handle = LoadGraph("Data/Player/PlayerJump.png");
	g_PlayerData.animation[PLAYER_ANIM_FALL].handle = LoadGraph("Data/Player/PlayerFall.png");
	g_PlayerData.animation[PLAYER_ANIM_LANDING].handle = LoadGraph("Data/Player/PlayerLanding.png");
}

void StartPlayer()
{
	StartPlayerAnimation(PLAYER_ANIM_IDLE);
}

void StepPlayer()
{
	if (!gameOver && !gameClear)
	{
		g_PrevPlayerData = g_PlayerData;

		if (IsInputKey(KEY_X))
		{
			PLAYER_MOVE_MAX = 6.5f;
			PLAYER_JUMP_MAX = 12.0f;

		}
		else
		{
			PLAYER_MOVE_MAX = 3.5f;
			PLAYER_JUMP_MAX = 10.0f;
		}

		if (g_PlayerData.move.x)

			if (g_PlayerData.move.x > PLAYER_MOVE_MAX)
			{
				g_PlayerData.move.x = PLAYER_MOVE_MAX;
			}
		if (g_PlayerData.move.x < -PLAYER_MOVE_MAX)
		{
			g_PlayerData.move.x = -PLAYER_MOVE_MAX;
		}
		if (g_PlayerData.move.y > PLAYER_GRAVITY_MAX)
		{
			g_PlayerData.move.y = PLAYER_GRAVITY_MAX;
		}
		if (IsInputKey(KEY_LEFT) && !g_PlayerData.isAir)
		{
			g_PlayerData.move.x += -PLAYER_MOVE_POWER;
			g_PlayerData.isTurn = true;
			MoveNow = true;
		}
		else if (IsInputKey(KEY_RIGHT) && !g_PlayerData.isAir)
		{
			g_PlayerData.move.x += PLAYER_MOVE_POWER;
			g_PlayerData.isTurn = false;
			MoveNow = true;
		}
		else if (IsInputKey(KEY_LEFT) && g_PlayerData.isAir)
		{
			g_PlayerData.move.x += -PLAYER_MOVE_POWER;
			g_PlayerData.isTurn = true;
			MoveNow = true;
		}
		else if (IsInputKey(KEY_RIGHT) && g_PlayerData.isAir)
		{
			g_PlayerData.move.x += PLAYER_MOVE_POWER;
			g_PlayerData.isTurn = false;
			MoveNow = true;
		}
		else
		{
			if (g_PlayerData.move.x < 0)
			{
				g_PlayerData.move.x += PLAYER_MOVE_POWER;
			}
			else if (g_PlayerData.move.x > 0)
			{
				g_PlayerData.move.x -= PLAYER_MOVE_POWER;
			}
			MoveNow = false;
		}
		if (IsTriggerKey(KEY_Z) && !g_PrevPlayerData.jumpPow && !JumpInput)
		{
			JumpInput = true;
		}
		if (IsInputKey(KEY_Z) && !g_PlayerData.jumpPow && JumpInput)
		{
			g_PlayerData.move.y += -PLAYER_JUMP_POWER;

			if (SECooltime)
			{
				//PlaySE(SE_JUMP);
			}
			SECooltime = false;
		}
		g_PlayerData.move.y += PLAYER_GRAVITY;
	}
}

void UpdatePlayer()
{
	CameraData camera = GetCamera();
	if (camera.pos.y <= g_PlayerData.pos.y - SCREEN_HEIGHT - (SCREEN_HEIGHT / 3))
	{
		gameOver = true;
	}

	if (g_PlayerData.move.y < 0.0f || g_PlayerData.move.y > PLAYER_GRAVITY)
	{
		g_PlayerData.isAir = true;
	}
	if (g_PlayerData.move.y < -PLAYER_JUMP_MAX || g_PlayerData.move.y > g_PrevPlayerData.move.y)
	{
		g_PlayerData.jumpPow = true;
	}

	if (gameOver)
	{
		GameOverPlayer();
	}
	if (gameClear)
	{
		GameClearPlayer();
	}

	g_PlayerData.pos.x += g_PlayerData.move.x;
	g_PlayerData.pos.y += g_PlayerData.move.y;

	MapData* Map = GetMaps();
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if (Map[i].type == COIN)
		{
			if (Map[i].coinEffect)
			{
				if (pFPS > 0)
				{
					effectTime += 1.00f / pFPS;
				}
				else
				{
					effectTime += 1.00f / 60.00f;
				}

				if (effectTime >= 0.0f && effectTime < 0.05f)
				{
					Map[i].handle = LoadGraph("Data/Map/Coin/Coin.png");
				}
				else if (effectTime >= 0.05f && effectTime < 0.10f)
				{
					Map[i].handle = LoadGraph("Data/Map/Coin/GetCoin1.png");
				}
				else if (effectTime >= 0.10f && effectTime < 0.15f)
				{
					Map[i].handle = LoadGraph("Data/Map/Coin/GetCoin2.png");
				}
				else if (effectTime >= 0.15f && effectTime < 0.20f)
				{
					Map[i].handle = LoadGraph("Data/Map/Coin/GetCoin3.png");
				}
				else if (effectTime >= 0.20f && effectTime < 0.30f)
				{
					Map[i].handle = LoadGraph("Data/Map/Coin/GetCoin4.png");
				}
				else if (effectTime >= 0.30f)
				{
					Map[i].active = false;
					effectTime = 0.0f;
				}
			}
			if (!Map[i].active)
			{
				Map[i].coinEffect = false;
			}
		}
		if (!Map[i].active) continue;

		if (Map[i].type == COIN)
		{
			if (Map[i].coinGetClear)
			{
				Map[i].active = false;
			}
		}

		float blockDrawY = Map[i].pos.y - ((MAP_CHIP_Y_NUM * MAP_CHIP_HEIGHT) - SCREEN_HEIGHT);

		float playerHitX = g_PlayerData.pos.x + PLAYER_BOX_COLLISION_OFFSET_X;
		float playerHitY = g_PlayerData.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y;
		float playerHitW = PLAYER_BOX_COLLISION_WIDTH;
		float playerHitH = PLAYER_BOX_COLLISION_HEIGHT;

		if (!gameOver && !gameClear)
		{
			if (!CheckSquareSquare(playerHitX, playerHitY, playerHitW, playerHitH,
				Map[i].pos.x, blockDrawY, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
			{
				continue;
			}

			float prevHitX = g_PrevPlayerData.pos.x + PLAYER_BOX_COLLISION_OFFSET_X;
			float prevHitY = g_PrevPlayerData.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y;

			// 下方向
			if (g_PrevPlayerData.pos.y + PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT < blockDrawY)
			{
				if (!Map[i].EnemyKill)
				{
					if (Map[i].type == NORMAL_BLOCK || Map[i].type == ONE_WAY_BLOCK || Map[i].type == ENEMY || Map[i].type == SKY_ENEMY)
					{
						g_PlayerData.pos.y = blockDrawY - (PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_BOX_COLLISION_HEIGHT) - PLAYER_MAP_COLLISION_OFFSET;
						g_PlayerData.move.y = 0.0f;
						g_PlayerData.isAir = false;
						g_PlayerData.jumpPow = false;
						SECooltime = true;
						if (JumpInput && Map[i].type != ENEMY && Map[i].type != SKY_ENEMY)
						{
							JumpInput = false;
						}
					}
				}
				if (Map[i].type == COIN && !Map[i].coinGet)
				{
					//PlaySE(SE_COIN);
					TotalGetCoin++;
					StageGetCoin++;
					Map[i].coinGet = true;
					Map[i].coinEffect = true;
				}
				if (Map[i].type == ENEMY || Map[i].type == SKY_ENEMY)
				{
					JumpInput = true;
					//EnemyKill(i);
				}
				if (Map[i].type == NEEDLE_BLOCK)
				{
					gameOver = true;
				}
				if (Map[i].type == FIRE_ENEMY)
				{
					gameOver = true;
				}
				if (Map[i].type == GOAL || Map[i].type == GOAL_POINT)
				{
					gameClear = true;
				}
			}
			// 右方向（左の壁にぶつかる）
			else if (prevHitX + PLAYER_BOX_COLLISION_WIDTH < Map[i].pos.x && Map[i].type != ONE_WAY_BLOCK)
			{
				if (Map[i].type == COIN && !Map[i].coinGet)
				{
					//PlaySE(SE_COIN);
					TotalGetCoin++;
					StageGetCoin++;
					Map[i].coinGet = true;
					Map[i].coinEffect = true;
				}
				if (Map[i].type == NORMAL_BLOCK)
				{
					g_PlayerData.pos.x = Map[i].pos.x - (PLAYER_BOX_COLLISION_OFFSET_X + PLAYER_BOX_COLLISION_WIDTH) - PLAYER_MAP_COLLISION_OFFSET;
					g_PlayerData.move.x = 0.0f;
				}
				if (Map[i].type == NEEDLE_BLOCK)
				{
					gameOver = true;
				}
				if (Map[i].type == ENEMY || Map[i].type == FIRE_ENEMY || Map[i].type == SKY_ENEMY && !Map[i].EnemyKill)
				{
					gameOver = true;
				}
				if (Map[i].type == GOAL || Map[i].type == GOAL_POINT)
				{
					gameClear = true;
				}
			}
			// 【3】左方向（右の壁にぶつかる）
			else if (prevHitX > Map[i].pos.x + MAP_CHIP_WIDTH && Map[i].type != ONE_WAY_BLOCK)
			{
				if (Map[i].type == COIN && !Map[i].coinGet)
				{
					//PlaySE(SE_COIN);
					TotalGetCoin++;
					StageGetCoin++;
					Map[i].coinGet = true;
					Map[i].coinEffect = true;
				}
				if (Map[i].type == NORMAL_BLOCK)
				{
					g_PlayerData.pos.x = Map[i].pos.x + MAP_CHIP_WIDTH - PLAYER_BOX_COLLISION_OFFSET_X + PLAYER_MAP_COLLISION_OFFSET;
					g_PlayerData.move.x = 0.0f;
				}
				if (Map[i].type == NEEDLE_BLOCK)
				{
					gameOver = true;
				}
				if (Map[i].type == ENEMY || Map[i].type == FIRE_ENEMY || Map[i].type == SKY_ENEMY && !Map[i].EnemyKill)
				{
					gameOver = true;
				}
				if (Map[i].type == GOAL || Map[i].type == GOAL_POINT)
				{
					gameClear = true;
				}
			}
			// 【4】上方向（天井）
			else if (prevHitY > blockDrawY + MAP_CHIP_HEIGHT && Map[i].type != ONE_WAY_BLOCK && Map[i].type != DESTROY_BLOCK)
			{
				if (Map[i].type == COIN && !Map[i].coinGet)
				{
					//PlaySE(SE_COIN);
					TotalGetCoin++;
					StageGetCoin++;
					Map[i].coinGet = true;
					Map[i].coinEffect = true;
				}
				if (Map[i].type != COIN)
				{
					g_PlayerData.pos.y = blockDrawY + MAP_CHIP_HEIGHT - PLAYER_BOX_COLLISION_OFFSET_Y + PLAYER_MAP_COLLISION_OFFSET;
					g_PlayerData.move.y = 0.0f;
					g_PlayerData.jumpPow = true;
				}
				if (Map[i].type == NEEDLE_BLOCK)
				{
					gameOver = true;
				}
				if (Map[i].type == ENEMY || Map[i].type == FIRE_ENEMY || Map[i].type == SKY_ENEMY && !Map[i].EnemyKill)
				{
					gameOver = true;
				}
				if (Map[i].type == GOAL || Map[i].type == GOAL_POINT)
				{
					gameClear = true;
				}
			}
			else if ((Map[i].type == ENEMY || Map[i].type == FIRE_ENEMY || Map[i].type == SKY_ENEMY) && !Map[i].EnemyKill)
			{
				gameOver = true;
			}
		}
	}
	UpdatePlayerAnimation();
}

void DrawPlayer()
{
	CameraData camera = GetCamera();

	PlayerAnimationType animType = g_PlayerData.playAnim;
	AnimationData* animData = &g_PlayerData.animation[animType];
	DrawAnimation(animData, g_PlayerData.pos.x - camera.pos.x, g_PlayerData.pos.y - camera.pos.y, g_PlayerData.isTurn);

	DrawGraph((int)g_PlayerData.pos.x - camera.pos.x, (int)g_PlayerData.pos.y - camera.pos.y, g_PlayerData.handle, TRUE);
	DrawFormatString(0, 0, GetColor(0, 0, 0), "獲得コイン：%d / 5", TotalGetCoin);
}

void FinPlayer()
{
	for (int i = 0; i < PLAYER_ANIM_MAX; i++)
	{
		DeleteGraph(g_PlayerData.animation[i].handle);
	}
}

PlayerData GetPlayer()
{
	return g_PlayerData;
}

void StartPlayerAnimation(PlayerAnimationType anim)
{
	if (anim == g_PlayerData.playAnim) return;

	g_PlayerData.playAnim = anim;

	AnimationData* animData = &g_PlayerData.animation[anim];
	PlayerAnimationParam animParam = PLAYER_ANIM_PARAM[anim];

	StartAnimation(animData, g_PlayerData.pos.x, g_PlayerData.pos.y, animParam.interval, animParam.frameNum, animParam.width, animParam.height, true);
}

void UpdatePlayerAnimation()
{
	if (!gameOver && !gameClear)
	{
		if (!g_PlayerData.isAir)
		{
			if (g_PlayerData.move.x < 0.0f || g_PlayerData.move.x > 0.0f || MoveNow)
			{
				StartPlayerAnimation(PLAYER_ANIM_RUN);
			}
			else
			{
				StartPlayerAnimation(PLAYER_ANIM_IDLE);
			}
		}
		else
		{
			if (g_PlayerData.move.y < 0.0f)
			{
				StartPlayerAnimation(PLAYER_ANIM_JUMP);
			}
			else if (g_PlayerData.move.y > 0.0f)
			{
				StartPlayerAnimation(PLAYER_ANIM_FALL);
			}
		}
	}

	PlayerAnimationType animType = g_PlayerData.playAnim;
	AnimationData* animData = &g_PlayerData.animation[animType];
	UpdateAnimation(animData);
}

bool GameOverbool()
{
	return gameOver;
}

void GameClearPlayer()
{
	if (!gameSceneChangeSE)
	{
		//PlaySE(SE_CLEAR);
		g_PlayerData.move.x = 0.0f;
		g_PlayerData.move.y = 0.0f;
		gameSceneChangeSE = true;
	}
	StopCount++;
	if (StopCount >= 60)
	{
		ChangeScene(SCENE_GAME_CLEAR);
	}
}

void GameOverPlayer()
{
	if (!gameSceneChangeSE)
	{
		//PlaySE(SE_GAME_OVER);
		g_PlayerData.move.x = 0.0f;
		g_PlayerData.move.y = -0.00001f;
		gameSceneChangeSE = true;
	}
	StopCount++;
	if (StopCount >= 40)
	{
		StartPlayerAnimation(PLAYER_ANIM_FALL);
		g_PlayerData.move.y = 10.0f;
		if (g_PlayerData.pos.y >= g_PrevPlayerData.pos.y + 850.0f)
		{
			ChangeScene(SCENE_GAME_OVER);
		}
	}
}

bool GamePlayBool()
{
	if (gameClear || gameOver)
	{
		return true;
	}
	else
	{
		return false;
	}
}