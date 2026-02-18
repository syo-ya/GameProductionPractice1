#pragma once
#include "DxLib.h"

#define BLOCK_MAX 3072
#define MAP_CHIP_X_NUM (32)
#define MAP_CHIP_Y_NUM (180)
#define MAP_CHIP_WIDTH (50.0f)
#define MAP_CHIP_HEIGHT (50.0f)

enum MapChipType
{
	MAP_CHIP_NONE,
	NORMAL_BLOCK,
	ONE_WAY_BLOCK,
	NEEDLE_BLOCK,
	COIN,
	GOAL,
	GOAL_POINT,
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
	bool coinGet = false;
	bool coinGetClear = false;
};

struct MapChipData
{
	int mapChip;
	MapData* data;
};