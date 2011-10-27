/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			StarEmitter.cpp
 * @author			Vinz
 * @version			1.0
 * @date			2011/10/27
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "StarEmitter.h"
#include "cinder/app/App.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
StarEmitter::StarEmitter(ParticleEngine* pEngine)
	: ParticleEmitter(pEngine)
{
	mConeAngle = 3.1415f / 3.0f;
	mParticleType = ParticleType::STAR_PARTICLE;
}
//-----------------------------------------------------------------------------
StarEmitter::~StarEmitter()
{

}
//-----------------------------------------------------------------------------
void StarEmitter::doEmit(int pNum)
{
	float lDeltaAngle = (mConeAngle * 2) / (float)pNum;
	float lAngleCount = (3.1415f / 2.0f + mConeAngle);
	float lConeRadius = mScale.y;

	for (int i = 0; i < pNum; i++)
	{

		//Create the Particle
		Particle* lParticle = this->createParticle();

		//Evaluate the Cone Direction of the Particle
		ci::Vec2f lDir = - ci::Vec2f(cos(lAngleCount), sin(lAngleCount));
		//ci::Vec2f lDir2 = ci::Vec2f(- lDir.x, lDir.y);

		//Evaluate the Position of the Particle
		ci::Vec2f lLoc = mLoc + (lConeRadius + lParticle->getInitialSize().y * lParticle->getScale()) * lDir;

		//Evaluate the Speed of the the Particle
		ci::Vec2f lVel = mVel + ci::Rand::randFloat(5.0f, 15.0f) * lDir;

		//Evaluate the LifeSpan depending on the Angle in the Cone
		float lAngleRatio = (1 - ((abs (lAngleCount - 3.1415f / 2.0f )) / mConeAngle)); //Ratio evaluating the distance between AngleCount and the y-axis
		int lLifespan = 20 + (int) lAngleRatio * 220;

		//Set the Particle
		lParticle->setPosition(lLoc);
		lParticle->setVelocity(lVel);
		lParticle->setLifespan(lLifespan);

		//Add the particle
		mEngine->addParticle(lParticle);

		//Decrement the Angle Counter
		lAngleCount -= lDeltaAngle;
	}
}
//-----------------------------------------------------------------------------