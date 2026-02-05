#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"

// グローバル変数宣言
int g_BGHandle;

void InitPlayScene()
{
	// 背景画像の読み込み
	g_BGHandle = LoadGraph("Data/Play/BG.png");
}

void UpdatePlayScene()
{
	if (IsTriggerKey(KEY_C))
	{
		// シーンの切り替え処理　チェンジシーン（タイトルシーン）；
		ChangeScene(SCENE_TITLE);
	}
}

void DrawPlayScene()
{
	// 背景画像の描画
	DrawGraph(0, 0, g_BGHandle, TRUE);
	// テキストの描画
	DrawString(100, 100, "ゲームシーンです。Cキーでタイトルシーンに戻れます。", GetColor(255, 255, 255));
}

void FinPlayScene()
{
	// 背景画像の解放
	DeleteGraph(g_BGHandle);
}