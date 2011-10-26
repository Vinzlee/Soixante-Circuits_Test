/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			SparkEmitter.cpp
 * @author			Vinz
 * @version			1.0
 * @date			2011/10/26
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "SparkEmitter.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
SparkEmitter::SparkEmitter(ParticleEngine* pEngine)
	: ParticleEmitter(pEngine)
{
	mConeAngle = 3.1415f / 4.0f;
	mParticleType = ParticleType::SPARK_PARTICLE;
}
//-----------------------------------------------------------------------------
SparkEmitter::~SparkEmitter()
{

}
//-----------------------------------------------------------------------------
void SparkEmitter::doEmit(int pNum)
{
	float lDeltaAngle = (mConeAngle * 2) / (float)pNum;
	float lAngleCount = (3.1415f / 2.0f + mConeAngle);
	float lConeRadius = mScale.y;

	for (int i = 0; i < pNum; i++)
	{
		//Evaluate the Cone Direction of the Particle
		ci::Vec2f lDir = - ci::Vec2f(cos(lAngleCount), sin(lAngleCount));
		
		//Evaluate the Position of the Particle
		ci::Vec2f lLoc = mLoc + lConeRadius * lDir;

		//Evaluate the Speed of the the Particle
		ci::Vec2f lVel = mVel + ci::Rand::randFloat(10.0f, 20.0f) * lDir;

		//Create the Particle
		Particle* lParticle = this->createParticle();
		lParticle->setPosition(lLoc);
		lParticle->setVelocity(lVel);
		lParticle->setRotation(lAngleCount);

		//Add the particle
		mEngine->addParticle(lParticle);

		//Decrement the Angle Counter
		lAngleCount -= lDeltaAngle;
	}
}
//-----------------------------------------------------------------------------
