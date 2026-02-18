#pragma once
#include "DxLib.h"
#include "../Animation/Animation.h"
#include "../Collision/Collision.h"

#define PLAYER_DEFAULT_POS_X (150.0f)
#define PLAYER_DEFAULT_POS_Y (785.0f)
#define PLAYER_MOVE_POWER (0.5f)
#define PLAYER_MOVE_MAX (6.5)

#define PLAYER_WIDTH	(72.0f)
#define PLAYER_HEIGHT	(72.0f)
#define PLAYER_RADIUS	(36.0f)

#define PLAYER_JUMP_POWER (2.0f)
#define PLAYER_JUMP_MAX (12.0f)
#define PLAYER_GRAVITY (0.45f)
#define PLAYER_GRAVITY_MAX (30.0f)

#define PLAYER_MAP_COLLISION_OFFSET (0.05f)
#define PLAYER_BOX_COLLISION_OFFSET_X (24)
#define PLAYER_BOX_COLLISION_OFFSET_Y (20)
#define PLAYER_BOX_COLLISION_WIDTH (20)
#define PLAYER_BOX_COLLISION_HEIGHT (44)

enum PlayerAnimationType
{
	PLAYER_ANIM_IDLE,
	PLAYER_ANIM_RUN,
	PLAYER_ANIM_JUMP,
	PLAYER_ANIM_FALL,
	PLAYER_ANIM_LANDING,
	PLAYER_ANIM_MAX,
	PLAYER_ANIM_NONE = -1
};

struct PlayerData
{
	VECTOR pos;
	VECTOR move;
	int handle;
	bool isTurn;
	bool isAir;
	bool jumpPow;
	bool enemyHit;
	AnimationData animation[PLAYER_ANIM_MAX];
	PlayerAnimationType playAnim;
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData GetPlayer();
