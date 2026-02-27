#pragma once

#define ENEMY_MOVE_SPEED (1.0f)
#define ENEMY_GRAVITY (0.40f)
#define ENEMY_GRAVITY_MAX (30.0f)

void InitEnemy();
void StepEnemy();
void UpdateEnemy();
void EnemyKill(int i);
void ResetEnemy();

struct EnemyData
{
	VECTOR move;
	bool dirRight; // true=‰EŒü‚«, false=¶Œü‚«
	VECTOR PrevPos;
	bool isGround;
};