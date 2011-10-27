/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			FlareParticle.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/27
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "FireParticle.h"
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
FireParticle::FireParticle(ParticleEngine* pEngine)
	: Particle(pEngine)
{
	//Initialize graphics variables
	int lSpriteID = ci::Rand::randInt(132,135);
	mSprite = ci::gl::Texture(ci::loadImage(ci::app::loadResource(lSpriteID, "IMAGE")));
	mInitialColor = ci::Color(1.0f,1.0f,0.0f);
	mInitialSize = mSprite.getSize();
	mScale = ci::Rand::randFloat(0.2f, 0.4f);

	//Initialize behavior variables
	mDecay = ci::Rand::randFloat(0.95f, 0.97f);
	mShrinkingRatio = 0.0f;
}
//-----------------------------------------------------------------------------
FireParticle::~FireParticle()
{

}
//-----------------------------------------------------------------------------
void FireParticle::doUpdate()
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
	mColor = ci::Color(mInitialColor.r, mInitialColor.g * (1 - mShrinkingRatio), mInitialColor.b * (1 - mShrinkingRatio)  );

	//Update the Position
	mLoc += mVel;
}
//-----------------------------------------------------------------------------
void FireParticle::doDraw()
{
	ci::gl::color(mColor);

	ci::gl::pushMatrices();

	ci::gl::translate(mLoc);
	ci::gl::scale((1 - mShrinkingRatio) * mScale, (1 - mShrinkingRatio) * mScale );

	ci::gl::enableAlphaBlending();
	ci::gl::draw(mSprite);
	ci::gl::disableAlphaBlending();

	ci::gl::popMatrices();
}
//-----------------------------------------------------------------------------