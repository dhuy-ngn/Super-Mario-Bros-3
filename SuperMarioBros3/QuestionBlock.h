#pragma once
#include "Platform.h"

#define QUESTION_BLOCK_BBOX_WIDTH	15
#define	QUESTION_BLOCK_BBOX_HEIGHT 15

#define ID_ANI_QUESTION_BLOCK_ACTIVE  7001
#define ID_ANI_QUESTION_BLOCK_INACTIVE  7000 

#define QUESTION_BLOCK_STATE_ACTIVE	100
#define	QUESTION_BLOCK_STATE_INACTIVE	-100

#define	QUESTION_BLOCK_DEFLECT_SPEED 0.05f
#define QUESTION_BLOCK_DEFLECT_DURATION 50

class CQuestionBlock : public CGameObject
{
protected:
	BOOLEAN isContainingPowerup;
	BOOLEAN isExhausted;

	ULONGLONG deflect_start;
	ULONGLONG deflect_end;

	float start_y;
	float vy;

public:
	CQuestionBlock(float x, float y, int isContainingPowerup) : CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->start_y = y;
		this->isContainingPowerup = isContainingPowerup;
		this->isExhausted = false;
		this->deflect_start = -1;
		this->deflect_end = -1;
		this->vy = 0;
	}
	int IsContainingPowerup() { return isContainingPowerup; };
	int IsExhausted() { return isExhausted; };

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void SetState(int state);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};