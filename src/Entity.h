//
//  Entity.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__Entity__
#define __Project__Isolation__Entity__

class Entity
{
private:
	float x, y;
	float vx, vy;
	
public:
	Entity()
	{
		x = 0.0f;
		y = 0.0f;
		vx = 0.0f;
		vy = 0.0f;
	};
	Entity(float newX, float newY, float newVX, float newVY)
	{
		x = newX;
		y = newY;
		vx = newVX;
		vy = newVY;
	};
	~Entity() {};
	
	float GetX() { return x; };
	float GetY() { return y; };
	float GetVX() { return vx; };
	float GetVY() { return vy; };
	
	void SetX(float value) { x = value; };
	void SetY(float value) { y = value; };
	void OffsetX(float value) { x += value; };
	void OffsetY(float value) { y += value; };
	
	void SetVX(float value) { vx = value; };
	void SetVY(float value) { vy = value; };
	void OffsetVX(float value) { vx += value; };
	void OffsetVY(float value) { vy += value; };
};

#endif /* defined(__Project__Isolation__Entity__) */
