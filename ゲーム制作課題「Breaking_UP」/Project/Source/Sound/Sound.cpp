#include "DxLib.h"
#include "Sound.h"

int g_BGMHandle[BGM_TYPE_MAX] = { 0 };
int g_SEHandle[SE_TYPE_MAX] = { 0 };

void LoadBGM()
{
	g_BGMHandle[BGM_TITLE] = LoadSoundMem("Data/Sound/BGM/title.mp3");
	g_BGMHandle[BGM_PLAY_SCENE] = LoadSoundMem("Data/Sound/BGM/play.mp3");
	g_BGMHandle[BGM_GAME_OVER] = LoadSoundMem("Data/Sound/BGM/gameover.mp3");
	g_BGMHandle[BGM_GAME_CLEAR] = LoadSoundMem("Data/Sound/BGM/gameclear.mp3");
}

void PlayBGM(BGMType type)
{
	//PlaySoundMem(g_BGMHandle[type], DX_PLAYTYPE_LOOP);
}

void StopBGM(BGMType type)
{
	StopSoundMem(g_BGMHandle[type]);
}

void FinBGM()
{
	for (int i = 0; i < BGM_TYPE_MAX; i++)
	{
		DeleteSoundMem(g_BGMHandle[i]);
	}
}


void LoadSE()
{
	g_SEHandle[SE_ENTER] = LoadSoundMem("Data/Sound/SE/enter.mp3");
	g_SEHandle[SE_JUMP] = LoadSoundMem("Data/Sound/SE/jump.mp3");
	g_SEHandle[SE_BULLET] = LoadSoundMem("Data/Sound/SE/shot.mp3");
	g_SEHandle[SE_HIT] = LoadSoundMem("Data/Sound/SE/hit.mp3");
	g_SEHandle[SE_DESTROY] = LoadSoundMem("Data/Sound/SE/destroy.mp3");
	g_SEHandle[SE_COIN] = LoadSoundMem("Data/Sound/SE/coin.mp3");
	g_SEHandle[SE_ENEMY_KILL] = LoadSoundMem("Data/Sound/SE/enemykill.mp3");
	g_SEHandle[SE_GAME_OVER] = LoadSoundMem("Data/Sound/SE/gameover.mp3");
	g_SEHandle[SE_CLEAR] = LoadSoundMem("Data/Sound/SE/clear.mp3");
}

void PlaySE(SEType type)
{
	PlaySoundMem(g_SEHandle[type], DX_PLAYTYPE_BACK);
}

void FinSE()
{
	for (int i = 0; i < SE_TYPE_MAX; i++)
	{
		DeleteSoundMem(g_SEHandle[i]);
	}
}
