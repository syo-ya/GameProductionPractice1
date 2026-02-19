#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Scene/SceneManager.h"
#include "../../Bullet/Bullet.h"
//#include "../../Enemy/EnemyManager.h"
#include "../../Collision/Collision.h"
#include "../../Map/MapManager.h"
#include "../../Camera/Camera.h"

// 背景のスピード
#define BACK_GROUND_SPEED (-1.5f)
int PlayBG = NULL;
void InitPlayScene()
{
	PlayBG = LoadGraph("Data/BackGround/PlayBG.png");
	InitMap();
	InitPlayer();
	InitCamera();
	InitBullet();
	// エネミー初期化
	//InitEnemy();
}

void LoadPlayScene()
{
	LoadMap();
	LoadPlayer();
	// エネミーロード
	//LoadEnemy();
}

void StartPlayScene()
{
	StartMap();
	StartPlayer();

	//StepPlayer();
}

void StepPlayScene()
{
	StepMap();
	StepPlayer();
	StepCamera();
	
	// 敵更新
	//StepEnemy();
}


void UpdatePlayScene()
{
	UpdateMap();
	UpdatePlayer();
	UpdateBullet();

	// エネミー更新
	//UpdateEnemy();

	CheckCollision();
}

void DrawPlayScene()
{
	DrawGraph(0, 0, PlayBG, TRUE);
	DrawCamera();
	DrawMap();
	DrawBullet();

	// エネミー描画
	//DrawEnemy();

	DrawPlayer();
}

void FinPlayScene()
{
	FinMap();
	FinPlayer();
	FinBullet();

	// エネミー終了
	//FinEnemy();
}
