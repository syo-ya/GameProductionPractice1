#include "DxLib.h"
#include "../../Player/Player.h"
//#include "../../BackGround/BackGround.h"
#include "../../Scene/SceneManager.h"
//#include "../../Bullet/BulletManager.h"
//#include "../../Enemy/EnemyManager.h"
#include "../../Collision/Collision.h"

// 背景のスピード
#define BACK_GROUND_SPEED (-1.5f)

void InitPlayScene()
{
	// 背景初期化
	//InitBackGround();

	// プレイヤー初期化
	//InitPlayer();

	// エネミー初期化
	//InitEnemy();

	// 弾を初期化
	//InitBullet();
}

void LoadPlayScene()
{
	// 背景ロード
	//LoadBackGround("Data/Play/play.PNG", BACK_GROUND_LAYER_1);
	// 背景スクロール
	//SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);

	// プレイヤーロード
	//LoadPlayer();

	// エネミーロード
	//LoadEnemy();

	// 弾ロード
	//LoadBullet();
}

void StartPlayScene()
{
	// プレイヤー開始
	//StartPlayer();

	//StepPlayer();
}

void StepPlayScene()
{
	//StepBackGround();
	//StepPlayer();

	// まず敵出現システム
	//StepEnemySpawnSystem();

	// 敵更新
	//StepEnemy();

	//StepBullet();
}


void UpdatePlayScene()
{
	// 背景更新
	//UpdateBackGround();

	// プレイヤー更新
	//UpdatePlayer();

	// エネミー更新
	//UpdateEnemy();

	// 弾更新
	//UpdateBullet();

	// 当たり判定
	//CheckCollision();

	// スコア更新
	//UpdateScore();

	// Kapuを２体撃破したらクリアシーンへ
	/*if (GetEnemyDestroyNum(ENEMY_TYPE_MOZU) >= 2)
	{
		ChangeScene(SCENE_GAME_CLEAR);
	}*/
}

void DrawPlayScene()
{
	// 背景描画
	//DrawBackGround();

	// 弾描画
	//DrawBullet();

	// エネミー描画
	//DrawEnemy();

	// プレイヤー描画
	//DrawPlayer();
}

void FinPlayScene()
{
	// 背景終了
	//FinBackGround();

	// プレイヤー終了
	//FinPlayer();

	// エネミー終了
	//FinEnemy();

	// 弾終了
	//FinBullet();
}
