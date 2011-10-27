/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			StarParticle.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/26
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "StarParticle.h"
#include "cinder/ImageIo.h"
#include "cinder/app/App.h"

#include "Resources.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
StarParticle::StarParticle(ParticleEngine* pEngine)
	: Particle(pEngine)
{
	//Initialize graphics variables
	mSprite = ci::gl::Texture(ci::loadImage(ci::app::loadResource(RES_STAR_ID, "IMAGE")));
	mColor = ci::Color(1.0f,1.0f,1.0f);
	mInitialSize = mSprite.getSize();

	//Initialize behavior variables
	mDecay = ci::Rand::randFloat(0.95f, 0.99f);
	mShrinkingRatio = 0.0f;
}
//-----------------------------------------------------------------------------
StarParticle::~StarParticle()
{

}
//-----------------------------------------------------------------------------
void StarParticle::doUpdate()
{
	//Update the ShrinkingRatio
	mShrinkingRatio = mAge / (float)mLifespan;

	//Update the Velocity
	float lNoise = mEngine->getPerlinKernel().fBm(ci::Vec3f(mLoc * 0.005f, ci::app::getElapsedSeconds() * 0.1f));
	float lAngle = lNoise * 15.0f;
	ci::Vec2f lNoiseVector =  ci::Vec2f(cos(lAngle), sin(lAngle));
	mVel += lNoiseVector * 0.2f * mShrinkingRatio;
	mVel *= mDecay;

	//Update the Color
	double lTime = ci::app::getElapsedSeconds();
	float lRed = 0.5f* abs(cos(lTime)) + 0.5f * abs(cos(mLoc.x));
	float lGreen = 0.5f * abs(sin(lTime)) + 0.5f * abs(sin(mLoc.y)) ;
	float lBlue = abs(0.5f * cos(lTime) + 0.5f * sin(lTime));
	mColor = ci::Color(lRed, lGreen, lBlue);

	//Update the Position
	mLoc += mVel;

	//Update the Rotation
	mRot += mRotVel;
}
//-----------------------------------------------------------------------------
void StarParticle::doDraw()
{
	ci::gl::color(mColor);

	ci::gl::pushMatrices();

	ci::gl::translate(mLoc);
	ci::gl::rotate(mRot);
	ci::gl::scale(1 - mShrinkingRatio, 1 - mShrinkingRatio);

	ci::gl::enableAlphaBlending();
	ci::gl::draw(mSprite);
	ci::gl::disableAlphaBlending();

	ci::gl::popMatrices();
}
//-----------------------------------------------------------------------------