#include "DxLib.h"
#include "Input.h"

int g_InputState = 0;

int g_PrevInputState = 0;

void InitInput()
{
	g_InputState = 0;
	g_PrevInputState = 0;
}

void UpdateInput()
{
	g_PrevInputState = g_InputState;

	g_InputState = 0;

	if (CheckHitKey(KEY_INPUT_Z))
	{
		g_InputState |= KEY_Z;
	}
	if (CheckHitKey(KEY_INPUT_X))
	{
		g_InputState |= KEY_X;
	}
	if (CheckHitKey(KEY_INPUT_C))
	{
		g_InputState |= KEY_C;
	}
}
void DrawInput()
{
}
void FinInput()
{
}
bool IsInputKey(InputKey key)
{
	return g_InputState & key;
}

bool IsTriggerKey(InputKey key)
{
	return (g_InputState & key) && !(g_PrevInputState & key);
}