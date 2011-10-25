/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			HandDetector.h
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/21
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "CinderOpenCV.h"
#include "cinder/Rect.h"
#include <vector>

/******************************************************************************
 *********************************** DEFINE  **********************************
 ******************************************************************************/

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

typedef std::vector<ci::Rectf>::iterator	HandsIterator;

enum DetectionType
{
	HAAR_STYLE = 0,
	BLOB_STYLE,
	FBSEGMENTATION_STYLE
};

/******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/

/**
* @class HandDetector
* 
* @brief The HandDetector class provides an Interface to detect Closed Hands 
* on a featured Surface and return their positions and size in this Surface.
* Several Detection Methods should be available through child classes : 
* - Available :		 Viola and Jones algorithm (http://en.wikipedia.org/wiki/Viola%E2%80%93Jones_object_detection_framework) aka Haar-Cascade algorithm.	[HaarHandDetector class]
* - Soon available : Blob detection algorithm																												[BlobHandDetector class]
* - Soon available : Foreground/Background Segmentation algorithm																							[FGSegmentationHandDetector class]
*
* @see
*/
class HandDetector
{
		
/*******************************************************************************
 ******************************** PUBLIC SECTION *******************************
 ******************************************************************************/
public:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/
	
	/**
	* @brief Default Constructor
	*
	* @param pType		Detection Type -Haar, -Blob, -FGSegmentation
	*/
	HandDetector(DetectionType pType);

	/**
	* @brief Default Destructor
	*/
	virtual ~HandDetector();

	/**
	* @brief Main method called every frame to detect Closed Hands.
	* When detection is successfully processed, the result is stored in the
	* output vector mClosedHand.
	*
	* @param pSurface		Input Cinder Surface featured by the Camera Capture 
	*		
	* @return bool			Return true if one or several Hands are detected
	*/
	bool updateDetection(ci::Surface pSurface);

	/**
	* @brief Get the detected Hands as an output reference featured in parameter
	*
	* @param pDetectedHand		Output parameter to get the vector of detected hands
	*		
	* @return void
	*/
	void getDetectedHands(std::vector<ci::Rectf>& pOutputDetectedHand);


/*******************************************************************************
 ******************************* PROTECTED SECTION *****************************
 ******************************************************************************/
protected:

	/******************************* ATTRIBUTES *******************************/

	/**
	* Type of Detector [-Haar, -Blob, -FGSegmentation]
	*/
	DetectionType				mType;
	
	/**
	* Output vector of detected closed hands, stored as Rectangles
	*/
	std::vector<ci::Rectf>		mClosedHands;	

	/******************************** METHODS *********************************/

	/**
	* @brief Pure Virtual method to be updated in child class.
	* Here must the code be written to process the detection algorithm.
	*
	* @param pSurface		Input Cinder Surface featured by the Camera Capture
	*		
	* @return bool			Return true if one or several Hands are detected
	*/
	bool virtual doUpdateDetection(ci::Surface pSurface) = 0;


/*******************************************************************************
 ******************************** PRIVATE SECTION ******************************
 ******************************************************************************/
private:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/


};
