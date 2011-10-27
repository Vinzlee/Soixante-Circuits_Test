/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			ParticleEmitter.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/26
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "ParticleEmitter.h"
#include "SimpleParticle.h"
#include "StarParticle.h"
#include "SparkParticle.h"
#include "FireParticle.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
ParticleEmitter::ParticleEmitter(ParticleEngine* pEngine)
{
	//Initialize the Engine
	mEngine = pEngine;

	//Initialize spatial variables
	mLoc = ci::Vec2f::zero();
	mScale = ci::Vec2f::zero();
	mRot = 0.0f;
	mVel = ci::Vec2f::zero();

	//Initialize the Type of particles as default
	mParticleType = ParticleType::DEFAULT_PARTICLE;
}
//-----------------------------------------------------------------------------
ParticleEmitter::~ParticleEmitter()
{

}
//-----------------------------------------------------------------------------
void ParticleEmitter::Emit(int pNum)
{
	this->doEmit(pNum);
}
//-----------------------------------------------------------------------------
Particle* ParticleEmitter::createParticle()
{
	Particle* lParticle = NULL;

	switch (mParticleType)
	{
	case ParticleType::DEFAULT_PARTICLE :
		lParticle = new SimpleParticle(mEngine);
		break;
	case ParticleType::SPARK_PARTICLE :
		lParticle = new SparkParticle(mEngine);
		break;
	case ParticleType::STAR_PARTICLE :
		lParticle = new StarParticle(mEngine);
		break;
		break;
	case ParticleType::FIRE_PARTICLE:
		lParticle = new FireParticle(mEngine);
		break;
	default:
		break;
	}

	return lParticle;
}
//-----------------------------------------------------------------------------
ci::Vec2f ParticleEmitter::getPositon() const
{
	return mLoc;
}
//-----------------------------------------------------------------------------
void ParticleEmitter::setPosition(const ci::Vec2f& pPosition)
{
	mLoc = pPosition;
}
//-----------------------------------------------------------------------------
float ParticleEmitter::getRotation() const
{
	return mRot;
}
//-----------------------------------------------------------------------------
void ParticleEmitter::setRotation(const float pRotation)
{
	mRot = pRotation;
}
//-----------------------------------------------------------------------------
ci::Vec2f ParticleEmitter::getScale() const
{
	return mScale;
}
//-----------------------------------------------------------------------------
void ParticleEmitter::setScale(const ci::Vec2f& pScale)
{
	mScale = pScale;
}
//-----------------------------------------------------------------------------
ci::Vec2f ParticleEmitter::getVelocity() const
{
	return mVel;
}
//-----------------------------------------------------------------------------
void ParticleEmitter::setVelocity(const ci::Vec2f& pVelocity)
{
	mVel = pVelocity;
}
//-----------------------------------------------------------------------------
ParticleType ParticleEmitter::getParticleType() const
{
	return mParticleType;
}
//-----------------------------------------------------------------------------
