#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Scene/SceneManager.h"
//#include "../../Bullet/BulletManager.h"
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
	// エネミー初期化
	//InitEnemy();

	// 弾を初期化
	//InitBullet();
}

void LoadPlayScene()
{
	LoadMap();
	LoadPlayer();

	// エネミーロード
	//LoadEnemy();

	// 弾ロード
	//LoadBullet();
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
	// まず敵出現システム
	//StepEnemySpawnSystem();

	// 敵更新
	//StepEnemy();

	//StepBullet();
}


void UpdatePlayScene()
{
	UpdateMap();
	UpdatePlayer();

	// エネミー更新
	//UpdateEnemy();

	// 弾更新
	//UpdateBullet();

	CheckCollision();
}

void DrawPlayScene()
{
	DrawGraph(0, 0, PlayBG, TRUE);
	DrawCamera();
	DrawMap();

	// 弾描画
	//DrawBullet();

	// エネミー描画
	//DrawEnemy();

	DrawPlayer();
}

void FinPlayScene()
{
	FinMap();
	FinPlayer();

	// エネミー終了
	//FinEnemy();

	// 弾終了
	//FinBullet();
}
