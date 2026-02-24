#pragma once

void InitEnemy();
void StepEnemy();
void UpdateEnemy();
void EnemyKill(int i);
void ResetEnemy();

struct EnemyData
{
	VECTOR move;
	bool dirRight; // true=‰EŒü‚«, false=¶Œü‚«
};