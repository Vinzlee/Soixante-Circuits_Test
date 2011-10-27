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
#include "Particle.h"
#include "ParticleEmitter.h"

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
void ParticleEngine::addParticle(Particle* pParticle)
{
	mParticles.push_back(pParticle);
}
//-----------------------------------------------------------------------------
ci::Perlin& ParticleEngine::getPerlinKernel()
{
	return mPerlin;
}
//-----------------------------------------------------------------------------
void ParticleEngine::addEmitter(std::string pID, ParticleEmitter* pEmitter)
{
	mEmitters[pID] = pEmitter;
}
//-----------------------------------------------------------------------------
ParticleEmitter* ParticleEngine::getEmitter(const std::string& pID)
{
	return mEmitters[pID];
}
//-----------------------------------------------------------------------------
void ParticleEngine::removeEmitter(const std::string& pID)
{
	mEmitters.erase(pID);
}
//-----------------------------------------------------------------------------