#pragma once
#include "GameObject.h"

#define KOOPA_GRAVITY 0.002f
#define KOOPA_WALKING_SPEED 0.03f

#define KOOPA_BBOX_WIDTH 16
#define KOOPA_BBOX_HEIGHT 16

#define KOOPA_COLOR_GREEN -999
#define	KOOPA_COLOR_RED 999

#define KOOPA_LEVEL_NORMAL 1
#define KOOPA_LEVEL_WINGS	2

#define KOOPA_BBOX_WIDTH 16
#define KOOPA_BBOX_HEIGHT 20

#define KOOPA_STATE_WALKING 100

#define KOOPA_STATE_BOUNCING 200
#define	KOOPA_STATE_SKIPPING	210

#define KOOPA_STATE_SPINNING 300

#define KOOPA_STATE_DIE -1

#define KOOPA_DIE_TIMEOUT 500

#define ID_ANI_KOOPA_WALKING_RIGHT	4101
#define ID_ANI_KOOPA_WALKING_LEFT	4100

#define ID_ANI_KOOPA_JUMPING_RIGHT	4301
#define ID_ANI_KOOPA_JUMPING_LEFT	4300

#define ID_ANI_KOOPA_SPINNING	4170

#define ID_ANI_KOOPA_DIE	4320

class CKoopa : public CGameObject
{
protected:
	float ax;
	float ay;
	ULONGLONG die_start;

	int level;
	int color;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	int IsCollidable() { return state != KOOPA_STATE_DIE; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);

	int GetAniIdKoopaNormal();
	int GetAniIdKoopaWings();

public:
	CKoopa(float x, float y);
	virtual void SetState(int state);
	virtual void SetLevel(int l);
};