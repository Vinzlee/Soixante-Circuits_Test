/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			HaarHandDetector.h
 * @author			Vinz
 * @version			1.0
 * @date			2011/10/24
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "HandDetector.h"

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
* @class HaarHandDetector
* 
* @brief The HaarHandDetector class provides the Detector for Closed Hands captured by the Camera.
* In order to guarantee a better detection, the closed hands must face the camera and stand just 
* like the "A-Letter" in the American Manual Alphabet features (http://en.wikipedia.org/wiki/American_Manual_Alphabet).
*
* @see HandDetector.h
*/
class HaarHandDetector : public HandDetector
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
	HaarHandDetector();

	/**
	* @brief Default Destructor
	*/
	~HaarHandDetector();


/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	/**
	* @brief Detect the Closed Hands through the Viola and Jones algorithm.
	* This algorithm mainly uses the Haar-XML file featured in the resources repository and
	* built from more than one hundred shots of Closed Hands. 
	* More info on : http://en.wikipedia.org/wiki/Viola%E2%80%93Jones_object_detection_framework
	*
	* @param pSurface		Input Cinder Surface featured by the Camera Capture 
	*		
	* @return void
	*/
	void doUpdateDetection(ci::Surface pSurface);


/*******************************************************************************
 ******************************** PRIVATE SECTION ******************************
 ******************************************************************************/
private:

	/******************************* ATTRIBUTES *******************************/

	/**
	*  Binary Object created from the XML Haar-Cascade File, featured in the resources repository
	*/
	cv::CascadeClassifier		mClosedHandCascade;

	/******************************** METHODS *********************************/


};