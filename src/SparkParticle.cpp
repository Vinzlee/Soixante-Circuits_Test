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
SparkParticle::SparkParticle(ParticleEngine* pEngine)
	: Particle(pEngine)
{
	//Initialize graphics variables
	mSprite = ci::gl::Texture(ci::loadImage(ci::app::loadResource(RES_SPARK_ID, "IMAGE")));
	mColor = ci::Color(1.0f,1.0f,1.0f);
	mInitialSize = mSprite.getSize();
	mScale = 0.5f;

	//Initialize behavior variables
	mDecay = ci::Rand::randFloat(0.95f, 0.96f);
	mShrinkingRatio = 0.0f;
	mLifespan = ci::Rand::randInt(5, 10);
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
	mVel *= mDecay;

	//Update the Position
	mLoc += mVel;

	//Update the color
	mColor = ci::Color(1.0f, 1.0f * (1- mShrinkingRatio), 0.0f );
}
//-----------------------------------------------------------------------------
void SparkParticle::doDraw()
{
	ci::gl::color(mColor);

	ci::gl::pushMatrices();

	ci::gl::translate(mLoc);
	ci::gl::rotate( mRot * 360.0f / 3.1415f + 180.0f);
	ci::gl::scale((1 - mShrinkingRatio) * mScale, (1 - mShrinkingRatio) * mScale );

	ci::gl::enableAlphaBlending();
	ci::gl::draw(mSprite);
	ci::gl::disableAlphaBlending();

	ci::gl::popMatrices();

}
//-----------------------------------------------------------------------------