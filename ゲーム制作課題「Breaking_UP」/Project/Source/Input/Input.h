#pragma once

void InitInput();
void UpdateInput();
void DrawInput();
void FinInput();

enum InputKey
{
	KEY_Z = (1 << 0),
	KEY_SPACE = (1 << 1),
	KEY_A = (1 << 2),
	KEY_W = (1 << 3),
	KEY_D = (1 << 4),
	KEY_RIGHT = (1 << 5),
	KEY_LEFT = (1 << 6)
};

bool IsInputKey(InputKey key);
bool IsTriggerKey(InputKey key);