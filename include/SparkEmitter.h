/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			SparkEmitter.h
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/26
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
* @class SparkEmitter
* 
* @brief The SparkEmitter class provides an Emitter for Spark particle
*
* @see
*/
class SparkEmitter : public ParticleEmitter
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
	SparkEmitter(ParticleEngine* pEngine);

	/**
	* @brief Default Destructor
	*/
	~SparkEmitter();


/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	/**
	* @brief Emit quick Spark particles within a cone
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