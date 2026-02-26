#pragma once

#define BULLET_MOVE_SPEED (15.0f)

#define BULLET_NUM (50)

#define BULLET_COOLTIME_MAX (10)

#define BULLET_WIDTH	(16)
#define BULLET_HEIGHT	(16)
#define BULLET_RADIUS	(8)

#define BULLET_OFFSET	(3)

#define ARROW_RADIUS	(12.5f)
#define ARROW_SIZE	(25.0f)

struct BulletData
{
	int handle;
	VECTOR pos;
	VECTOR prevPos;
	VECTOR move;
	bool active;
	bool Hit;
	bool Fire;
	float LifeTime;
	float EffectTime;
};

struct ArrowData
{
	int handle;
	VECTOR pos;
};

void InitBullet();
void UpdateBullet();
void DrawBullet();
void FinBullet();

BulletData* GetBullet(int num);

void FireBullet(float posX, float posY);
