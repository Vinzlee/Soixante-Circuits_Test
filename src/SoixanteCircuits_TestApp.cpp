/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			SoixanteCircuits_TestApp.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/21
 */

#pragma once

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"
#include "cinder/Capture.h"	

#include "HaarHandDetector.h"

/******************************************************************************
 *********************************** DEFINE  **********************************
 ******************************************************************************/

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/
using namespace ci;
using namespace ci::app;
using namespace std;

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

/******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/


/**
* @class SoixanteCircuits_Test_Application
* 
* @brief The SoixanteCircuits_Test_Application class provides a program tracking 
* punches of the user via a webcam, and add on it some particles in order to create
* a spark effect around each punches if they are detected.
* The program is shared in 2 parts :
* - HandDetector : This class processes the Hand Detection via the WebCam
* - ParticleEngine : This class processes the behavior and graphical effects 
* of sparks during the video capture.
*
* @see HandDetector, ParticleEngine
*/
class SoixanteCircuits_Test_Application : public AppBasic
{
		
/*******************************************************************************
 ******************************** PUBLIC SECTION *******************************
 ******************************************************************************/
public:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	/**
	* @brief Set the size of the output window
	*
	* @param pSettings		Reference on the main output display
	*		
	* @return void
	*/
	void prepareSettings( Settings *pSettings );

	/**
	* @brief Initialize the Application
	*	
	* @return void
	*/
	void setup();

	/**
	* @brief Update the Application on every frames
	*		
	* @return void
	*/
	void update();

	/**
	* @brief Draw the Application on every frames
	*	
	* @return void
	*/
	void draw();


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
	* Haar Hand Detector 
	*/
	HaarHandDetector*		mHaarHandDetector;

	/**
	* Camera Device
	*/
	Capture					mCapture;

	/**
	* Input texture grabbed from the Camera Device each frame 
	*/
	gl::Texture				mInputTexture;


	/******************************** METHODS *********************************/


};


/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::prepareSettings( Settings *pSettings )
{
	//pSettings->setWindowSize(800,600);
}
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::setup()
{
	//Build the Hand Detector
	mHaarHandDetector = new HaarHandDetector();

	//Start the Capture
	mCapture = Capture(800, 600);
	mCapture.start();
}
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::update()
{
	if (mCapture.checkNewFrame())
	{
		//Capture the Texture
		Surface lSurface = mCapture.getSurface();
		mInputTexture = gl::Texture(lSurface);

		//Update the Detector
		mHaarHandDetector->updateDetection(lSurface);
	}
	
}
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::draw()
{
	//Exit if no frame has been grabbed from the Camera Device
	if (!mInputTexture)
	{
		return;
	}

	//Enable Alpha for transparency
	gl::enableAlphaBlending();

	//draw the Input Camera image
	gl::color(Color(1,1,1));
	gl::draw(mInputTexture);
	mInputTexture.disable();

	//draw the detected closed hands
	gl::color(ColorA( 0, 0, 1, 0.35f ));
	vector<Rectf> lDetectedHands;
	mHaarHandDetector->getDetectedHands(lDetectedHands);
	for (vector<Rectf>::iterator lIter = lDetectedHands.begin(); lIter != lDetectedHands.end(); lIter++)
	{
		gl::drawSolidCircle(lIter->getCenter(), lIter->getWidth() / 2);
	}
	
}
//-----------------------------------------------------------------------------
CINDER_APP_BASIC( SoixanteCircuits_Test_Application, RendererGl )
