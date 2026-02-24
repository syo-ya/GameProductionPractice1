#include "Map.h"
#include "../GameSetting/GameSetting.h"
#include "MapParameter.h"
#include "../Camera/Camera.h"
#include "../Enemy/Enemy.h"


MapData g_Maps[BLOCK_MAX] = { 0 };
int g_MapHandle[BLOCK_TYPE_MAX] = { 0 };

void InitMapData()
{
	MapData* Map = g_Maps;
	for (int i = 0; i < BLOCK_MAX; i++, Map++)
	{
		Map->active = false;
		Map->pos = VGet(0.0f, 0.0f, 0.0f);
		Map->type = MAP_CHIP_NONE;
	}
}

void LoadMapData()
{
	g_MapHandle[NORMAL_BLOCK] = LoadGraph("Data/Map/Normal_Block.png");
	g_MapHandle[DESTROY_BLOCK] = LoadGraph("Data/Map/Destroy_Block/Block.png");
	g_MapHandle[ONE_WAY_BLOCK] = LoadGraph("Data/Map/One_Way_Block.png");
	g_MapHandle[NEEDLE_BLOCK] = LoadGraph("Data/Map/Needle_Block.png");
	g_MapHandle[COIN] = LoadGraph("Data/Map/Coin/Coin.png");
	g_MapHandle[GOAL] = LoadGraph("Data/Map/Goal.png");
}

void DrawMapData()
{
	CameraData camera = GetCamera();
	MapData* Map = g_Maps;
	for (int i = 0; i < BLOCK_MAX; i++, Map++)
	{
		if (Map->active)
		{
			DrawGraph((int)(Map->pos.x - camera.pos.x), (int)(Map->pos.y - ((MAP_CHIP_Y_NUM * MAP_CHIP_HEIGHT) - SCREEN_HEIGHT) - camera.pos.y), Map->handle, TRUE);
		}
	}
}

void FinMapData()
{
	ResetEnemy();
	MapData* Map = g_Maps;
	for (int i = 0; i < BLOCK_MAX; i++, Map++)
	{
		if (Map->active)
		{
			DeleteGraph(Map->handle);
		}
	}
}

MapData* CreateMap(MapChipType type, VECTOR pos)
{
	MapData* Map = g_Maps;
	for (int i = 0; i < BLOCK_MAX; i++, Map++)
	{
		if (!Map->active)
		{
			Map->active = true;
			Map->handle = g_MapHandle[type];
			Map->pos = pos;
			Map->type = type;
			Map->BreakFlg = -1;
			Map->BreakTime = 0.0f;
			return Map;
		}
	}

	return nullptr;
}

MapData* GetMaps()
{
	return g_Maps;
}