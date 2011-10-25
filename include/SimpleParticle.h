/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			SimpleParticle.h
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/25
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "Particle.h"
#include "cinder/Color.h"

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
* @class SimpleParticle
* 
* @brief The SimpleParticle class provides a basic round Particle with pseudo-random behavior.
*
* @see
*/
class SimpleParticle : public Particle
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
	SimpleParticle(ParticleEngine* pEngine);

	/**
	* @brief Default Destructor
	*/
	~SimpleParticle();


/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	/**
	* @brief Update the behavior of the particle as a pseudo-random move :
	* - The more the particle is closed to death, the more it moves quickly
	* - The more the particle is closed to death, the more its size decreases
	*	
	* @return void
	*/
	void doUpdate();

	/**
	* @brief Draw the particle like a little white solid disk
	*		
	* @return void
	*/
	void doDraw();


/*******************************************************************************
 ******************************** PRIVATE SECTION ******************************
 ******************************************************************************/
private:

	/******************************* ATTRIBUTES *******************************/

	/**
	* Vanishing factor of the particle in [0..1] 
	*/
	float			mDecay;

	/**
	* (mAge / mLifespan) Ratio  
	*/
	float			mShrinkingRatio;

	/**
	* Size of the particle 
	*/
	float			mRadius;

	/**
	* Color of the particle 
	*/
	ci::Color		mColor;

	/******************************** METHODS *********************************/


};
