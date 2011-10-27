/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			SimpleParticle.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/25
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "SimpleParticle.h"
#include "cinder/app/App.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
SimpleParticle::SimpleParticle(ParticleEngine* pEngine)
	: Particle(pEngine)
{
	//Initialize graphics variables
	mRadius = 4.0f;
	mInitialSize  = ci::Vec2i(4,4);
	mColor = ci::Color(1.0f, 1.0f, 1.0f);

	//Initialize behavior variables
	mDecay = ci::Rand::randFloat(0.95f, 0.99f);
	mShrinkingRatio = 0.0f;
}
//-----------------------------------------------------------------------------
SimpleParticle::~SimpleParticle()
{

}
//-----------------------------------------------------------------------------
void SimpleParticle::doUpdate()
{
	//Update the ShrinkingRatio
	mShrinkingRatio = mAge / (float)mLifespan;

	//Update the Velocity
	float lNoise = mEngine->getPerlinKernel().fBm(ci::Vec3f(mLoc * 0.005f, ci::app::getElapsedSeconds() * 0.1f));
	float lAngle = lNoise * 15.0f;
	ci::Vec2f lNoiseVector =  ci::Vec2f(cos(lAngle), sin(lAngle));
	mVel += lNoiseVector * 0.2f * mShrinkingRatio;
	mVel *= mDecay;

	//Update the Position
	mLoc += mVel;

	//Update the Radius
	mRadius = mInitialSize.x * (1 - mShrinkingRatio);
}
//-----------------------------------------------------------------------------
void SimpleParticle::doDraw()
{
	ci::gl::color(mColor);
	ci::gl::drawSolidCircle(mLoc, mRadius * mScale);
}
//-----------------------------------------------------------------------------