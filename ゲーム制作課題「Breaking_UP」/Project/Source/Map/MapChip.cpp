#include "MapChip.h"
#include "DxLib.h"
#include "../GameSetting/GameSetting.h"
#include "MapParameter.h"
#include "Map.h"

MapChipData g_MapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };

void LoadMapChipData(int stage)
{
	FILE* fp;
	char mapPath[64];
	sprintf_s(mapPath, sizeof(mapPath), "Data/Map/StageData/stage%d.bin", stage);
	if (fopen_s(&fp, mapPath, "rb") != 0) return;

	for (int i = 0; i < MAP_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < MAP_CHIP_X_NUM; j++)
		{
			int map = fgetc(fp);
			g_MapChip[i][j].mapChip = map;
		}
	}
}

void CreateMap()
{
	for (int i = 0; i < MAP_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < MAP_CHIP_X_NUM; j++)
		{
			MapChipType type = (MapChipType)g_MapChip[i][j].mapChip;

			if (type == MAP_CHIP_NONE) continue;

			VECTOR pos = VGet(j * MAP_CHIP_WIDTH, i * MAP_CHIP_HEIGHT, 0.0f);
			g_MapChip[i][j].data = CreateMap(type, pos);
		}
	}
}

void ResetMap()
{
	for (int i = 0; i < MAP_CHIP_Y_NUM; i++)
	{
		for (int j = 0; j < MAP_CHIP_X_NUM; j++)
		{
			g_MapChip[i][j].data = NULL;
			g_MapChip[i][j].mapChip = NULL;
		}
	}
}

MapChipData GetMapChipData(int x, int y)
{
	return g_MapChip[y][x];
}