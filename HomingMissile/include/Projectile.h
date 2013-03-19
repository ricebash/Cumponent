#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"

#include <vector>

using namespace ci;
using namespace std;

class Projectile
{
public:
	Projectile();
	Projectile(Vec2f iv,Vec2f id,float im);
	~Projectile(void);
	void draw();
	void update( float timeQ);
	void launch( Vec2f initV, Vec2f initPos, Vec2f chase);
	void goUp(float timeQ);
	void goDown(float timeQ);
	void goLeft(float timeQ);
	void goRight(float timeQ);

	float m;
	float maxV, maxA, maxF;
	Vec2f f,a,v,d,hw,hh;
	Vec2f follow;
	vector<Vec2f> points;
};

