#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Scene/SceneManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Enemy/Enemy.h"
#include "../../Collision/Collision.h"
#include "../../Map/MapManager.h"
#include "../../Camera/Camera.h"
#include "../../Sound/Sound.h"

// îwåiÇÃÉXÉsÅ[Éh
#define BACK_GROUND_SPEED (-1.5f)
int g_PlayBG = NULL;
void InitPlayScene()
{
	g_PlayBG = LoadGraph("Data/Logo/Sky.jpg");
	InitMap();
	InitPlayer();
	InitCamera();
	InitBullet();
	InitEnemy();
	PlayBGM(BGM_PLAY_SCENE);
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
	DrawGraph(0, 0, g_PlayBG, TRUE);
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
