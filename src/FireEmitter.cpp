/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			FireEmitter.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/27
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "FireEmitter.h"
#include "cinder/app/App.h"
/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
FireEmitter::FireEmitter(ParticleEngine* pEngine)
	: ParticleEmitter(pEngine)
{
	mConeAngle = 3.1415f / 6.0f;
	mParticleType = ParticleType::FIRE_PARTICLE;
}
//-----------------------------------------------------------------------------
FireEmitter::~FireEmitter()
{

}
//-----------------------------------------------------------------------------
void FireEmitter::doEmit(int pNum)
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

		//Evaluate the Position of the Particle
		ci::Vec2f lLoc = mLoc + (lConeRadius + lParticle->getInitialSize().y * lParticle->getScale()) * lDir;

		//Evaluate the Speed of the the Particle
		ci::Vec2f lVel = mVel + ci::Rand::randFloat(10.0f, 20.0f) * ci::Vec2i(0,-1);

		//Evaluate the LifeSpan depending on the Angle in the Cone
		float lAngleRatio = (1 - ((abs (lAngleCount - 3.1415f / 2.0f )) / mConeAngle)); //Ratio evaluating the distance between AngleCount and the y-axis
		int lLifespan = 10 + (int) lAngleRatio * 200;

		//Evaluate the Initial Color depending on the Angle in the cone
		ci::Color lColor = ci::Color(1.0f, 1.0f * lAngleRatio,0.0f);

		//Set the Particle
		lParticle->setPosition(lLoc);
		lParticle->setVelocity(lVel);
		lParticle->setInitialColor(lColor);
		lParticle->setLifespan(lLifespan);

		//Add the particle
		mEngine->addParticle(lParticle);

		//Decrement the Angle Counter
		lAngleCount -= lDeltaAngle;
	}
}
//-----------------------------------------------------------------------------