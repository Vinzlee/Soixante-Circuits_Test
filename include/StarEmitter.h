/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			StarEmitter.h
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/27
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "ParticleEmitter.h"

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
* @class StarEmitter
* 
* @brief The StarEmitter class provides an Emitter for Star particles
*
* @see
*/
class StarEmitter : public ParticleEmitter
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
	StarEmitter(ParticleEngine* pEngine);

	/**
	* @brief Default Destructor
	*/
	~StarEmitter();


/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	/**
	* @brief Emit star particles within a cone
	*
	* @param pNum
	*		
	* @return void
	*/
	void doEmit(int pNum);


/*******************************************************************************
 ******************************** PRIVATE SECTION ******************************
 ******************************************************************************/
private:

	/******************************* ATTRIBUTES *******************************/

	/**
	* Open angle of the Cone from where particles are emitted 
	*/
	float	mConeAngle;

	/******************************** METHODS *********************************/


};