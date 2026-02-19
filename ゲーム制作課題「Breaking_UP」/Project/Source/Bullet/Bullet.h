#pragma once

#define BULLET_MOVE_SPEED (20.0f)

#define BULLET_NUM (100)

#define BULLET_COOLTIME_MAX (10)

#define BULLET_WIDTH	(16)
#define BULLET_HEIGHT	(16)

struct BulletData
{
	int handle;
	VECTOR pos;
	VECTOR move;
	bool active;
	bool Hit;
};

void InitBullet();
void UpdateBullet();
void DrawBullet();
void FinBullet();

BulletData* GetBullet(int num);

void FireBullet(float posX, float posY);
