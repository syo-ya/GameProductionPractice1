#pragma once
#include "DxLib.h"

#define BLOCK_MAX 8192
#define MAP_CHIP_X_NUM (32)
#define MAP_CHIP_Y_NUM (500)
#define MAP_CHIP_WIDTH (50.0f)
#define MAP_CHIP_HEIGHT (50.0f)

enum MapChipType
{
	MAP_CHIP_NONE,
	NORMAL_BLOCK,
	DESTROY_BLOCK,
	ONE_WAY_BLOCK,
	NEEDLE_BLOCK,
	GOAL,
	GOAL_POINT,
	COIN,
	ENEMY,
	FIRE_ENEMY,
	SKY_ENEMY,
	BLOCK_TYPE_MAX
};

struct MapData
{
	bool active;
	int handle;
	MapChipType type;
	VECTOR pos;
	bool EnemyKill = false;
	bool coinEffect = false;
	float BreakFlg = -1;
	float EffectTime = 0.0f;
};

struct MapChipData
{
	int mapChip;
	MapData* data;
};