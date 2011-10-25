/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			ParticleEngine.h
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/21
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"

#include <list>

class Particle;

/******************************************************************************
 *********************************** DEFINE  **********************************
 ******************************************************************************/

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/
typedef std::list<Particle*>::iterator		ParticleIter;

/******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/

/**
* @class ParticleEngine
* 
* @brief The ParticleEngine class manages the creation, destruction and behavior of 
* all the particles of the simulation.
*
* @see Particle.h
*/
class ParticleEngine
{
		
/*******************************************************************************
 ******************************** PUBLIC SECTION *******************************
 ******************************************************************************/
public:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/
	
	/**
	* @brief Default Constructor
	*/
	ParticleEngine();

	/**
	* @brief Default Destructor
	*/
	~ParticleEngine();

	/**
	* @brief 
	*
	* @return void
	*/
	void update();

	/**
	* @brief 
	*		
	* @return void
	*/
	void draw();

	/**
	* @brief Add one or several particles in the 2D space system
	*
	* @param pNumber	Number of particles to add
	* @param pLoc		Position of the new particles
	* @param pVel		Velocity of the new particles
	* @param pScale		Scale of the new particles
	*		
	* @return void
	*/
	void addParticle(int pNumber = 1, const ci::Vec2i& pLoc = ci::Vec2i::zero(), const ci::Vec2f& pVel = ci::Vec2f::zero(), const float pScale = 1.0f);

	/**
	* @brief Return a reference on the Perlin Kernel
	*	
	* @return ci::Perlin&
	*/
	ci::Perlin& getPerlinKernel();

/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/



/*******************************************************************************
 ******************************** PRIVATE SECTION ******************************
 ******************************************************************************/
private:

	/******************************* ATTRIBUTES *******************************/

	/**
	* List of Particles created by the Engine 
	*/
	std::list<Particle*>	mParticles;

	/**
	* Perlin Kernel generating a Perlin noise signal 
	*/
	ci::Perlin				mPerlin;

	/******************************** METHODS *********************************/


};
