#include "MapManager.h"
#include "MapParameter.h"
#include "MapChip.h"
#include "Map.h"
#include "../Player/Player.h"

#define CHECK_ROUND_NUM (2)

void InitMap()
{
	InitMapData();
}

void LoadMap()
{
	LoadMapChipData();
	LoadMapData();
}

void StartMap()
{
	CreateMap();
}

void StepMap()
{
	StepMapData();
}

void UpdateMap()
{
	UpdateMapData();
}

void DrawMap()
{
	DrawMapData();
}

void FinMap()
{
	FinMapData();
	ResetMap();

}