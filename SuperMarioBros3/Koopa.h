#pragma once
#include "GameObject.h"

#define KOOPA_GRAVITY 0.002f
#define KOOPA_WALKING_SPEED 0.03f
#define KOOPA_SPINNING_SPEED	0.3f

#define KOOPA_ACCEL_SPIN_X 0.12f

#define KOOPA_BOUNCING_SPEED_X 0.7f
#define KOOPA_BOUNCING_SPEED_Y	0.8f

#define KOOPA_BBOX_WIDTH 16
#define KOOPA_BBOX_HEIGHT 20

#define KOOPA_SHAKING_WIDTH	10

#define KOOPA_LEVEL_NORMAL 30000
#define KOOPA_LEVEL_WINGS	30001

#define KOOPA_COLOR_GREEN	39998
#define KOOPA_COLOR_RED 39999

#define KOOPA_INACTIVE_DURATION 5000
#define KOOPA_WAKING_UP_DURATION	1000

#define KOOPA_STATE_WALKING	100

#define KOOPA_STATE_BOUNCING_RIGHT 201
#define KOOPA_STATE_BOUNCING_LEFT 200

#define	KOOPA_STATE_SKIPPING_RIGHT	211
#define	KOOPA_STATE_SKIPPING_LEFT	210

#define KOOPA_STATE_SPINNING_RIGHT 301
#define	KOOPA_STATE_SPINNING_LEFT 300

#define KOOPA_STATE_HIDING 400
#define KOOPA_STATE_UPSIDE_DOWN 500

#define KOOPA_STATE_SHAKING	600
#define	KOOPA_STATE_SHAKING_UPSIDE_DOWN 601

#define KOOPA_STATE_KNOCKED_OUT	700

#define KOOPA_DIE_TIMEOUT 2000

#define ID_ANI_KOOPA_GREEN_WALKING_RIGHT	4101
#define ID_ANI_KOOPA_GREEN_WALKING_LEFT	4100

#define ID_ANI_KOOPA_GREEN_JUMPING_RIGHT	4301
#define ID_ANI_KOOPA_GREEN_JUMPING_LEFT	4300

#define ID_ANI_KOOPA_GREEN_SPINNING_RIGHT	4121
#define ID_ANI_KOOPA_GREEN_SPINNING_LEFT	4120

#define ID_ANI_KOOPA_GREEN_FLYING_LEFT	4310
#define ID_ANI_KOOPA_GREEN_FLYING_RIGHT 4311

#define ID_ANI_KOOPA_GREEN_SHAKING	4400
#define ID_ANI_KOOPA_GREEN_SHAKING_UPSIDE_DOWN	4401

#define ID_ANI_KOOPA_GREEN_SHELL	4170
#define ID_ANI_KOOPA_GREEN_SHELL_UPSIDE_DOWN	4320

#define ID_ANI_KOOPA_RED_WALKING_RIGHT	4601
#define ID_ANI_KOOPA_RED_WALKING_LEFT	4600

#define ID_ANI_KOOPA_RED_JUMPING_RIGHT	4801
#define ID_ANI_KOOPA_RED_JUMPING_LEFT	4800

#define ID_ANI_KOOPA_RED_SPINNING_RIGHT	4721
#define ID_ANI_KOOPA_RED_SPINNING_LEFT	4720

#define ID_ANI_KOOPA_RED_FLYING_LEFT	4810
#define ID_ANI_KOOPA_RED_FLYING_RIGHT 4811

#define ID_ANI_KOOPA_RED_SHAKING	4900
#define ID_ANI_KOOPA_RED_SHAKING_UPSIDE_DOWN	4901

#define ID_ANI_KOOPA_RED_SHELL	4670
#define ID_ANI_KOOPA_RED_SHELL_UPSIDE_DOWN	4820

class CKoopa : public CGameObject
{
protected:
	float ax;
	float ay;
	ULONGLONG inactive_start;
	ULONGLONG die_start;
	ULONGLONG wake_up_start;

	int level;
	int color;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	int IsCollidable() { return state != KOOPA_STATE_KNOCKED_OUT ; };
	int IsHiding() { return state == KOOPA_STATE_HIDING; };
	int IsBlocking() { return state != KOOPA_STATE_KNOCKED_OUT; };

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithQuestionBlock(LPCOLLISIONEVENT e);

	int GetAniIdRedKoopaNormal();
	int GetAniIdGreenKoopaNormal();
	int GetAniIdRedKoopaWings();
	int GetAniIdGreenKoopaWings();

public:
	CKoopa(float x, float y, int level, int color);

	int IsSpinning() { return state == KOOPA_STATE_SPINNING_LEFT || state == KOOPA_STATE_SPINNING_RIGHT; };

	void SetState(int state);
	void SetLevel(int l);
	int GetLevel() { return this->level; };
	BOOLEAN IsRedKoopa() { return color == KOOPA_COLOR_RED; };
};