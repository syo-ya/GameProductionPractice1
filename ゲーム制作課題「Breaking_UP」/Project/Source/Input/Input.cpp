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

	if (CheckHitKey(KEY_INPUT_Z) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) != 0)
	{
		g_InputState |= KEY_Z;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)
	{
		g_InputState |= KEY_SPACE;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		g_InputState |= KEY_A;
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		g_InputState |= KEY_W;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		g_InputState |= KEY_D;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		g_InputState |= KEY_S;
	}
	if (CheckHitKey(KEY_INPUT_X) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
	{
		g_InputState |= KEY_X;
	}
	if (CheckHitKey(KEY_INPUT_P) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_7) != 0)
	{
		g_InputState |= KEY_P;
	}
	if (CheckHitKey(KEY_INPUT_O) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_8) != 0)
	{
		g_InputState |= KEY_O;
	}
	if (CheckHitKey(KEY_INPUT_UP) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) != 0)
	{
		g_InputState |= KEY_UP;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0)
	{
		g_InputState |= KEY_DOWN;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
	{
		g_InputState |= KEY_RIGHT;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
	{
		g_InputState |= KEY_LEFT;
	}
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0)
	{
		g_InputState |= KEY_L;
	}
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0)
	{
		g_InputState |= KEY_R;
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

bool IsReleaseKey(InputKey key)
{
	return !(g_InputState & key) && (g_PrevInputState & key);
}