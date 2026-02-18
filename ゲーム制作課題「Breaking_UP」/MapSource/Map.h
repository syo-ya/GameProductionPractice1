#pragma once
#include "MapParameter.h"

void InitMapData();
void LoadMapData();
void StartMapData();
void StepMapData();
void UpdateMapData();
void DrawMapData();
void FinMapData();

MapData* CreateMap(MapChipType type, VECTOR pos);
MapData* GetMaps();