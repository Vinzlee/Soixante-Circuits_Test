/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			SparkParticle.cpp
 * @author			Vinz
 * @version			1.0
 * @date			2011/10/26
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "SparkParticle.h"
#include "cinder/app/App.h"
/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
SparkParticle::SparkParticle(ParticleEngine* pEngine)
	: Particle(pEngine)
{
	//Initialize graphics variables
	mWidth = 1.0f;
	mLength = 4.0f;
	mColor = ci::Color(1.0f, 1.0f, 0.0f);

	//Initialize behavior variables
	mDecay = ci::Rand::randFloat(0.95f, 0.96f);
	mShrinkingRatio = 0.0f;
	mLifespan = ci::Rand::randInt(5, 15);
}
//-----------------------------------------------------------------------------
SparkParticle::~SparkParticle()
{

}
//-----------------------------------------------------------------------------
void SparkParticle::doUpdate()
{
	//Update the ShrinkingRatio
	mShrinkingRatio = mAge / (float)mLifespan;

	//Update the Velocity
	//float lNoise = mEngine->getPerlinKernel().fBm(ci::Vec3f(mLoc * 0.005f, ci::app::getElapsedSeconds() * 0.1f));
	//float lAngle = lNoise * 15.0f;
	//ci::Vec2f lNoiseVector =  ci::Vec2f(cos(lAngle), sin(lAngle));
	//mVel += lNoiseVector * 0.2f * mShrinkingRatio;
	mVel *= mDecay;

	//Update the Position
	mLoc += mVel;

	//Update the Size
	mWidth = 4.0f * (1 - mShrinkingRatio);
	mLength = 8.0f * (1 - mShrinkingRatio);

	//Update the color
	mColor = ci::Color(1.0f, 1.0f * (1- mShrinkingRatio), 0.0f );
}
//-----------------------------------------------------------------------------
void SparkParticle::doDraw()
{
	ci::gl::color(mColor);

	//ci::gl::pushMatrices();

	//ci::gl::rotate(mRot);

	ci::gl::drawSolidRect(ci::Rectf(mLoc.x, mLoc.y, mLoc.x + mWidth, mLoc.y + mLength));
	//ci::gl::drawSolidCircle(mLoc, mLength);

	//ci::gl::popMatrices();
}
//-----------------------------------------------------------------------------