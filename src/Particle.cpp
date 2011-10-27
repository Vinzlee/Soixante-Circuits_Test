/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			Particle.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/24
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "Particle.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
Particle::Particle(ParticleEngine* pEngine)
{
	//Set the Linked Engine
	mEngine = pEngine;

	//Set the spatial variables
	mLoc = ci::Vec2f::zero();
	mRot = 0.0f;
	mVel = ci::Vec2f::zero();
	mRotVel = 0.0f;
	mScale = 1.0f;
	mInitialSize = ci::Vec2i::zero();
	mInitialColor = ci::Color(1.0f, 1.0f, 1.0f);

	//Set the time variables
	mAge = 0;
	mLifespan = ci::Rand::randInt(50,250);
	mIsDead = false;
}
//-----------------------------------------------------------------------------
Particle::~Particle()
{

}
//-----------------------------------------------------------------------------
void Particle::update()
{
	//Update the Age
	mAge++;

	if (mAge > mLifespan)
	{
		mIsDead = true;
	}

	//Update the behavior
	this->doUpdate();
}
//-----------------------------------------------------------------------------
void Particle::draw()
{
	this->doDraw();
}
//-----------------------------------------------------------------------------
ci::Vec2f Particle::getPosition() const
{
	return mLoc;
}
//-----------------------------------------------------------------------------
void Particle::setPosition(const ci::Vec2f& pPosition)
{
	mLoc = pPosition;
}
//-----------------------------------------------------------------------------
float Particle::getRotation() const
{
	return mRot;
}
//-----------------------------------------------------------------------------
void Particle::setRotation(float pRotation)
{
	mRot = pRotation;
}
//-----------------------------------------------------------------------------
ci::Vec2f Particle::getVelocity() const
{
	return mVel;
}
//-----------------------------------------------------------------------------
void Particle::setVelocity(const ci::Vec2f& pVelocity)
{
	mVel = pVelocity;
}
//-----------------------------------------------------------------------------
float Particle::getRotationVelocity() const
{
	return mRotVel;
}
//-----------------------------------------------------------------------------
void Particle::setRotationVelocity(float pRotVel)
{
	mRotVel = pRotVel;
}
//-----------------------------------------------------------------------------
float Particle::getScale() const
{
	return mScale;
}
//-----------------------------------------------------------------------------
void Particle::setScale(const float pScale)
{
	mScale = pScale;
}
//-----------------------------------------------------------------------------
ci::Vec2i Particle::getInitialSize() const
{
	return mInitialSize;
}
//-----------------------------------------------------------------------------
ci::Color Particle::getInitialColor() const
{
	return mInitialColor;
}
//-----------------------------------------------------------------------------
void Particle::setInitialColor(const ci::Color& pColor)
{
	mInitialColor = pColor;
}
//-----------------------------------------------------------------------------
int Particle::getAge() const
{
	return mAge;
}
//-----------------------------------------------------------------------------
int Particle::getLifespan() const
{
	return mLifespan;
}
//-----------------------------------------------------------------------------
void Particle::setLifespan(const int pLifespan)
{
	mLifespan = pLifespan;
}
//-----------------------------------------------------------------------------
bool Particle::isDead()
{
	return mIsDead;
}
//-----------------------------------------------------------------------------

