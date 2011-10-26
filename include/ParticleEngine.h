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
#include <map>

class Particle;
class ParticleEmitter;

/******************************************************************************
 *********************************** DEFINE  **********************************
 ******************************************************************************/

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/
typedef std::list<Particle*>::iterator							ParticleIter;
typedef std::map<std::string, ParticleEmitter*>::iterator		ParticleEmitterIter;

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
	* @brief Add a particle in the Managed Particles
	*
	* @param pParticle
	*		
	* @return void
	*/
	void addParticle(Particle* pParticle);

	/**
	* @brief Add a new Emitter to the Engine
	*
	* @param pID			Name of the Emitter
	* @param pEmitter		Reference on the Emitter
	*		
	* @return void
	*/
	void addEmitter(std::string pID, ParticleEmitter* pEmitter);

	/**
	* @brief Return the "asked by ID" emitter
	*
	* @param pID		Name of the Emitter
	*		
	* @return ParticleEmitter*
	*/
	ParticleEmitter* getEmitter(const std::string& pID);

	/**
	* @brief Remove the Emitter from the Engine
	*
	* @param pID		Name of the Emitter
	*		
	* @return void
	*/
	void removeEmitter(const std::string& pID);

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
	std::list<Particle*>						mParticles;

	/**
	* Map of all Emitters  
	*/
	std::map<std::string, ParticleEmitter*>		mEmitters;

	/**
	* Perlin Kernel generating a Perlin noise signal 
	*/
	ci::Perlin									mPerlin;

	/******************************** METHODS *********************************/


};
