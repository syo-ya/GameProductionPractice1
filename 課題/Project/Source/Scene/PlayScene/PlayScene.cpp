#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"

// ƒOƒ[ƒoƒ‹•Ï”éŒ¾
int g_BGHandle;
int g_PlayerHandle;
int g_EnemyDragonFlyHandle;
int g_EnemyFliesHandle;

void InitPlayScene()
{
	// ”wŒi‰æ‘œ‚Ì“Ç‚İ‚İ
	g_BGHandle = LoadGraph("Data/Play/BG.png");

	// ƒvƒŒƒCƒ„[‰æ‘œ‚Ì“Ç‚İ‚İ
	g_PlayerHandle = LoadGraph("Data/Player/Player.png");

	// “G‰æ‘œ‚Ì“Ç‚İ‚İ
	g_EnemyDragonFlyHandle = LoadGraph("Data/Enemy/DragonFly.png");
	g_EnemyFliesHandle = LoadGraph("Data/Enemy/Flies.png");
}

void UpdatePlayScene()
{
	if (IsTriggerKey(KEY_C))
	{
		// ƒV[ƒ“‚ÌØ‚è‘Ö‚¦ˆ—
		ChangeScene(SCENE_TITLE);
	}
}

void DrawPlayScene()
{
	// ”wŒi‰æ‘œ‚Ì•`‰æ
	DrawGraph(0, 0, g_BGHandle, TRUE);

	// ƒvƒŒƒCƒ„[‰æ‘œ‚Ì•`‰æ
	DrawGraph(400, 300, g_PlayerHandle, TRUE);

	// “G‰æ‘œ‚Ì•`‰æ
	DrawGraph(600, 400, g_EnemyDragonFlyHandle, TRUE);
	DrawGraph(200, 500, g_EnemyFliesHandle, TRUE);
}

void FinPlayScene()
{
	// ”wŒi‰æ‘œ‚Ì‰ğ•ú
	DeleteGraph(g_BGHandle);

	// ƒvƒŒƒCƒ„[‰æ‘œ‚Ì‰ğ•ú
	DeleteGraph(g_PlayerHandle);

	// “G‰æ‘œ‚Ì‰ğ•ú
	DeleteGraph(g_EnemyDragonFlyHandle);
	DeleteGraph(g_EnemyFliesHandle);
}