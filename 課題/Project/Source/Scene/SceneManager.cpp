#include "DxLib.h"
#include "SceneManager.h"
#include "TitleScene/TitleScene.h"
#include "PlayScene/PlayScene.h"
#include "OptionScene/OptionScene.h"

Scene g_NowScene = SCENE_TITLE;

Scene g_NextScene = SCENE_TITLE;

SceneState g_SceneState = SCENE_STATE_INIT;

bool g_IsLoopEnd = false;

void SceneManagerUpdate()
{
	switch (g_SceneState)
	{
	case SCENE_STATE_INIT:
		InitScene();
		g_IsLoopEnd = false;
		g_SceneState = SCENE_STATE_LOOP;
		break;

	case SCENE_STATE_LOOP:
		UpdateScene();
		DrawScene();

		if (g_IsLoopEnd)
		{
			g_SceneState = SCENE_STATE_FIN;
		}
		break;

	case SCENE_STATE_FIN:
		FinScene();
		g_NowScene = g_NextScene;
		g_SceneState = SCENE_STATE_INIT;
		break;
	}
}

void InitScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		InitTitleScene();
		break;
	case SCENE_PLAY:
		InitPlayScene();
		break;
	case SCENE_OPTION:
		InitOptionScene();
		break;
	}
}

void UpdateScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		UpdateTitleScene();
		break;
	case SCENE_PLAY:
		UpdatePlayScene();
		break;
	case SCENE_OPTION:
		UpdateOptionScene();
		break;
	}
}

void DrawScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		DrawTitleScene();
		break;
	case SCENE_PLAY:
		DrawPlayScene();
		break;
	case SCENE_OPTION:
		DrawOptionScene();
		break;
	}
}

void FinScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		FinTitleScene();
		break;
	case SCENE_PLAY:
		FinPlayScene();
		break;
	case SCENE_OPTION:
		FinOptionScene();
		break;
	}
}

void ChangeScene(Scene scene)
{
	g_NextScene = scene;
	g_IsLoopEnd = true;
}