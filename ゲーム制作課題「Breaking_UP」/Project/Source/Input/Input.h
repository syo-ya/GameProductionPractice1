#pragma once

void InitInput();
void UpdateInput();
void DrawInput();
void FinInput();

enum InputKey
{
    KEY_Z = 1 << 0,
    KEY_SPACE = 1 << 1,
    KEY_A = 1 << 2,
    KEY_W = 1 << 3,
    KEY_D = 1 << 4,
    KEY_S = 1 << 5,
    KEY_X = 1 << 6,
    KEY_P = 1 << 7,
    KEY_O = 1 << 8,
    KEY_UP = 1 << 9,
    KEY_DOWN = 1 << 10,
    KEY_RIGHT = 1 << 11,
    KEY_LEFT = 1 << 12,
    KEY_L = 1 << 13,
    KEY_R = 1 << 14,
    KEY_Z2 = 1 << 15,
    KEY_SPACE2 = 1 << 16,
    KEY_X2 = 1 << 17,
    KEY_P2 = 1 << 18,
    KEY_O2 = 1 << 19,
    KEY_UP2 = 1 << 20,
    KEY_DOWN2 = 1 << 21,
    KEY_RIGHT2 = 1 << 22,
    KEY_LEFT2 = 1 << 23
};

bool IsInputKey(InputKey key);
bool IsTriggerKey(InputKey key);
bool IsReleaseKey(InputKey key);