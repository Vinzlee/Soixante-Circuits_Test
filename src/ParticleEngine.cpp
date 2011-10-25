/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			ParticleEngine.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/24
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "ParticleEngine.h"
#include "SimpleParticle.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
ParticleEngine::ParticleEngine()
{
	mPerlin = ci::Perlin();
}
//-----------------------------------------------------------------------------
ParticleEngine::~ParticleEngine()
{

}
//-----------------------------------------------------------------------------
void ParticleEngine::update()
{
	for (ParticleIter lIter = mParticles.begin(); lIter != mParticles.end(); )
	{
		if ((*lIter)->isDead())
		{
			delete (*lIter);
			lIter = mParticles.erase(lIter);
		}

		else
		{
			(*lIter)->update();
			lIter++; 
		}
	}
}
//-----------------------------------------------------------------------------
void ParticleEngine::draw()
{
	for (ParticleIter lIter = mParticles.begin(); lIter != mParticles.end(); lIter++)
	{
		(*lIter)->draw();
	}
}
//-----------------------------------------------------------------------------
void ParticleEngine::addParticle(int pNumber /* = 1 */, const ci::Vec2i& pLoc /* = ci::Vec2i::zero */, const ci::Vec2f& pVel /* = ci::Vec2f::zero() */, const float pScale /* = 1.0f */)
{
	for (int i = 0; i < pNumber; i++)
	{
		//Warp the position
		ci::Vec2f lRandomLocOffset = ci::Rand::randVec2f() * 5.0f;
		ci::Vec2f lLoc = pLoc + lRandomLocOffset;


		//Warp the Velocity
		ci::Vec2f lRandomVelOffset = ci::Rand::randVec2f() * ci::Rand::randFloat(1.0f, 3.0f);
		ci::Vec2f lVel = pVel + lRandomVelOffset;

		//Create the Particle
		//SimpleParticle lParticle(this);
		SimpleParticle* lParticle = new SimpleParticle(this);
		lParticle->setPosition(lLoc);
		lParticle->setVelocity(lVel);

		//Add the particle
		mParticles.push_back(lParticle);
	}
}
//-----------------------------------------------------------------------------
ci::Perlin& ParticleEngine::getPerlinKernel()
{
	return mPerlin;
}
//-----------------------------------------------------------------------------