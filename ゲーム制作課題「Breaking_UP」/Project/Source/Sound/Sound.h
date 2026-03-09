#pragma once

enum BGMType
{
	BGM_TITLE,
	BGM_PLAY_SCENE,
	BGM_GAME_OVER,
	BGM_GAME_CLEAR,
	BGM_TYPE_MAX
};

void LoadBGM();
void PlayBGM(BGMType type);
void StopBGM(BGMType type);
void FinBGM();

enum SEType
{
	SE_ENTER,
	SE_JUMP,
	SE_COIN,
	SE_ENEMY_KILL,
	SE_GAME_OVER,
	SE_CLEAR,
	SE_BULLET,
	SE_HIT,
	SE_DESTROY,
	SE_TYPE_MAX
};

void LoadSE();
void PlaySE(SEType type);
void FinSE();
