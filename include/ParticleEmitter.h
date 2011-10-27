/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			ParticleEmmiter.h
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/26
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "ParticleEngine.h"
#include "Particle.h"

/******************************************************************************
 *********************************** DEFINE  **********************************
 ******************************************************************************/

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

/******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/

/**
* @class ParticleEmitter
* 
* @brief The ParticleEmitter class provides an abstract Emitter defining the initial 
* spatial conditions for the creation of particles.
*
* @see
*/
class ParticleEmitter
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
	ParticleEmitter(ParticleEngine* pEngine);

	/**
	* @brief Default Destructor
	*/
	virtual ~ParticleEmitter();

	/**
	* @brief Return the current Position of the Emitter
	*	
	* @return ci::Vec2f
	*/
	ci::Vec2f getPositon() const;

	/**
	* @brief Set the Position of the Emitter
	*
	* @param pPosition
	*		
	* @return void
	*/
	void setPosition(const ci::Vec2f& pPosition);

	/**
	* @brief Return the current Angular Position of the Emitter
	*	
	* @return float
	*/
	float getRotation() const;

	/**
	* @brief Set the Angular Position of the Emitter
	*
	* @param pRotation
	*		
	* @return void
	*/
	void setRotation(const float pRotation);

	/**
	* @brief Return the current Scale of the Emitter
	*	
	* @return ci::Vec2f
	*/
	ci::Vec2f getScale() const;

	/**
	* @brief Set the pScale of the Emitter
	*
	* @param pScale
	*		
	* @return void
	*/
	void setScale(const ci::Vec2f& pScale);

	/**
	* @brief Return the current Velocity of the Emitter
	*
	* @return ci::Vec2f
	*/
	ci::Vec2f getVelocity() const;

	/**
	* @brief Set the Velocity of the Emitter
	*
	* @param pVelocity
	*		
	* @return void
	*/
	void setVelocity(const ci::Vec2f& pVelocity);

	/**
	* @brief Return the Particle Type of the Emitter
	*	
	* @return ParticleType
	*/
	ParticleType getParticleType() const;

	/**
	* @brief Main function emitting a featuring number of Particles
	*
	* @param pNum
	*		
	* @return void
	*/
	void Emit(int pNum);


/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/**
	* Reference on the Particle Engine 
	*/
	ParticleEngine* mEngine;
	
	/**
	*  Position of the Emitter in the 2D space screen
	*/
	ci::Vec2f		mLoc;

	/**
	* Angle Position of the Emitter in the 2D space Screen 
	*/
	float			mRot;

	/**
	* Scale of the Emitter 
	*/
	ci::Vec2f		mScale;
	
	/**
	*  Velocity of the Emitter in the 2D space screen
	*/
	ci::Vec2f		mVel;

	/**
	* Type of particles emitted by the Emitter 
	*/
	ParticleType	mParticleType;

	/******************************** METHODS *********************************/

	/**
	* @brief Main method to be overridden in the child classes
	*
	* @param pNum
	*		
	* @return void
	*/
	virtual void doEmit(int pNum) = 0;

	/**
	* @brief Factory method to create Particles depending on the mParticleType
	*	
	* @return Particle*
	*/
	Particle* createParticle();

/*******************************************************************************
 ******************************** PRIVATE SECTION ******************************
 ******************************************************************************/
private:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/


};