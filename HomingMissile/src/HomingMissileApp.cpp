#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Projectile.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HomingMissileApp : public AppBasic {
  public:
	void setup();
	void mouseMove( MouseEvent event );	
	void update();
	void draw();
	Vec2f mLoc;
	Projectile p;
};

void HomingMissileApp::setup()
{
	p = Projectile(Vec2f(10,10),Vec2f(200,200),10);
	p.launch(Vec2f(0,100),Vec2f(0,0),Vec2f(400,200));
}

void HomingMissileApp::update()
{
	p.update(0.01f);

}

void HomingMissileApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
	console() << "Pos:" <<p.d  << endl;
	console() << "Vel:" <<p.v << endl;
	console() << "Acc:" <<p.a << endl;
	console() << "Frc:" <<p.f << endl;
	//gl::drawSolidCircle(Vec2f(400,0),10);
	p.draw();
	
}

void HomingMissileApp::mouseMove( MouseEvent event ) {
    mLoc = event.getPos();
}

CINDER_APP_BASIC( HomingMissileApp, RendererGl )
