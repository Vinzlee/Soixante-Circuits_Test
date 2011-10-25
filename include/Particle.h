/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			Particle.h
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/21
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "ParticleEngine.h"

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
* @class Particle
* 
* @brief The Particle class provides an abstract Particle managed by the Particle Engine.
* Child classes must implement :
* - Behavior through the doUpdate() method
* - Graphics through the doDraw() method
*
* @see
*/
class Particle
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
	Particle(ParticleEngine* pEngine);

	/**
	* @brief Default Destructor
	*/
	virtual ~Particle();

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
	* @brief Get the Position of the Particle in 2D space
	*		
	* @return ci::Vec2f
	*/
	ci::Vec2f getPosition() const;

	/**
	* @brief Set the Position of the Particle in 2D space
	*
	* @param pPosition	Position input
	*		
	* @return void
	*/
	void setPosition(const ci::Vec2f& pPosition);

	/**
	* @brief Get the Velocity of the Particle in 2D space
	*		
	* @return ci::Vec2f
	*/
	ci::Vec2f getVelocity() const;

	/**
	* @brief Set the Velocity of the Particle in 2D space
	*
	* @param pVelocity	Velocity input
	*		
	* @return void
	*/
	void setVelocity(const ci::Vec2f& pVelocity);

	/**
	* @brief Get the Scale of the Particle
	*	
	* @return float
	*/
	float getScale() const;

	/**
	* @brief Set the scale of the Particle
	*
	* @param pScale	Scale input
	*		
	* @return void
	*/
	void setScale(const float pScale);

	/**
	* @brief Get the Age of the particle in number of frames
	*	
	* @return int
	*/
	int getAge() const;

	/**
	* @brief Get the Lifespan of the particle in number of frames
	*
	* @return int
	*/
	int getLifespan() const;

	/**
	* @brief 
	*	
	* @return bool
	*/
	bool isDead();


/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/**
	* Reference on the Engine which has created this particle 
	*/
	ParticleEngine*	mEngine;

	/**
	* Location of the Particle in the 2D space 
	*/
	ci::Vec2f		mLoc;

	/**
	* Scale Factor cheating about the size of the particle to provide a depth effect
	*/
	float			mScale;

	/**
	* Velocity of the Particle in the 2D space 
	*/
	ci::Vec2f		mVel;

	/**
	* Age of the particle stated in number of frames 
	*/
	int				mAge;

	/**
	* Lifespan of the particle stated in number of frames 
	*/
	int				mLifespan;

	/**
	* Flag to know if the particle is dead 
	*/
	bool			mIsDead;

	/******************************** METHODS *********************************/

	/**
	* @brief Behavior method to be overridden in child classes
	*	
	* @return void
	*/
	virtual void doUpdate();

	/**
	* @brief Graphics method to be overridden in child classes
	*	
	* @return void
	*/
	virtual void doDraw();

/*******************************************************************************
 ******************************** PRIVATE SECTION ******************************
 ******************************************************************************/
private:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/


};