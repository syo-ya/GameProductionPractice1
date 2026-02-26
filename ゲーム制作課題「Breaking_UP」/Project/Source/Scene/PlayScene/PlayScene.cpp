#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Scene/SceneManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Enemy/Enemy.h"
#include "../../Collision/Collision.h"
#include "../../Map/MapManager.h"
#include "../../Camera/Camera.h"

// îwåiÇÃÉXÉsÅ[Éh
#define BACK_GROUND_SPEED (-1.5f)
int PlayBG = NULL;
void InitPlayScene()
{
	PlayBG = LoadGraph("Data/BackGround/PlayBG.png");
	InitMap();
	InitPlayer();
	InitCamera();
	InitBullet();
	InitEnemy();
}

void LoadPlayScene()
{
	LoadMap();
	LoadPlayer();
}

void StartPlayScene()
{
	StartMap();
	StartPlayer();
}

void StepPlayScene()
{
	StepPlayer();
	StepCamera();
	StepEnemy();
}


void UpdatePlayScene()
{
	UpdatePlayer();
	UpdateBullet();
	UpdateEnemy();
	CheckCollision();
}

void DrawPlayScene()
{
	DrawGraph(0, 0, PlayBG, TRUE);
	DrawCamera();
	DrawMap();
	DrawPlayer();
	DrawBullet();
}

void FinPlayScene()
{
	FinMap();
	FinPlayer();
	FinBullet();
}
