#include "Projectile.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include <math.h>
#include "cinder\CinderMath.h"
using namespace ci;

Projectile::Projectile()
{
}

Projectile::Projectile(Vec2f iv,Vec2f id,float im)
{
	f = Vec2f(0,0);
	d = id;
	v = iv;
	m = im;
	a = Vec2f(0,0);

	hw = Vec2f(4.0f,0.0f);
	hh = Vec2f(0.0f,4.0f);
	points.push_back(d-hw+hh);
	points.push_back(d+hw+hh);
	points.push_back(d-hw-hh);
	points.push_back(d+hw-hh);
	maxV = 20;
	maxA = 10;
	maxF = 5;
}


Projectile::~Projectile(void)
{


}

void Projectile::draw()
{
	gl::drawSolidCircle(follow,10);
	gl::drawSolidCircle(d,4.0f);
	gl::color(0,1,0);
	gl::drawLine(v,v*2);
	gl::color(1,0,0);
	gl::drawLine(a + Vec2f(100,0),a*2+ Vec2f(100,0));
	gl::color(0,0,1);
	gl::drawLine(f + Vec2f(200,0),f*2+ Vec2f(200,0));
}

void Projectile::launch(Vec2f initV, Vec2f initD, Vec2f chase)
{
	follow = chase;
	d = initD;
	v = initV;
	Vec2f dif = follow - d;
	Vec2f dir = dif/dif.length();
	a = dif*5;
	//v = dif;
}

void Projectile::update(float timeQ)
{
	v = v + a*timeQ;
	d = d + (v/v.length()*100)*timeQ;

	//Vec2f dif = follow - d;
	//Vec2f dir = dif/dif.length();
	//a = dir;	

	
}

void Projectile::goUp(float timeQ)
{
	Vec2f temp = f - Vec2f(0,3)*timeQ;
	if( abs(temp.y) < maxF)
		f = temp;
	
	
}


void Projectile::goDown(float timeQ)
{
	Vec2f temp = f + Vec2f(0,3)*timeQ;
	if( abs(temp.y) < maxF)
		f = temp;
}

void Projectile::goLeft(float timeQ)
{
	Vec2f temp = f - Vec2f(3,0)*timeQ;
	if( abs(temp.x) < maxF)
		f = temp;
}

void Projectile::goRight(float timeQ)
{
	Vec2f temp = f + Vec2f(3,0)*timeQ;
	if( abs(temp.x) < maxF)
		f = temp;
}
