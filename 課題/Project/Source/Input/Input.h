#pragma once

void InitInput();
void UpdateInput();
void DrawInput();
void FinInput();

enum InputKey
{
	KEY_Z = (1 << 0),
	KEY_X = (1 << 1),
	KEY_C = (1 << 2)
};

bool IsInputKey(InputKey key);
bool IsTriggerKey(InputKey key);