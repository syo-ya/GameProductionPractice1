#pragma once
#include "MapParameter.h"

void InitMapData();
void LoadMapData();
void DrawMapData();
void FinMapData();

MapData* CreateMap(MapChipType type, VECTOR pos, int chipX, int chipY);
MapData* GetMaps();