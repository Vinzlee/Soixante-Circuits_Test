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
#include <vector>

#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"
#include "cinder/Capture.h"	
#include "cinder/params/Params.h"

#include "HaarHandDetector.h"
#include "ParticleEngine.h"
#include "SparkEmitter.h"
#include "StarEmitter.h"
#include "FireEmitter.h"

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
	* Particle Engine 
	*/
	ParticleEngine*			mParticleEngine;

	/**
	* Haar Hand Detector 
	*/
	HaarHandDetector*		mHaarHandDetector;

	/**
	*  Graphic Interface
	*/
	ci::params::InterfaceGl	mGUI;

	/**
	* Camera Device
	*/
	Capture					mCapture;

	/**
	* Input texture grabbed from the Camera Device each frame 
	*/
	gl::Texture				mInputTexture;

	/**
	* Position of the Hand in the 2D screen space 
	*/
	ci::Vec2i				mHandPosition;

	/**
	* Velocity of the Hand in the 2D screen space 
	*/
	ci::Vec2i				mHandSpeed;

	/**
	* Flag to know if a robust Hand signal has been grabbed 
	*/
	bool					mIsHandDetected;

	/**
	* Number of frame Min, an Object is considered as a Detected Hand. 
	*/
	int						mDetectionAppearThreshold;

	/**
	*  Number of frame Max, a detected Object is considered as Lost.
	*/
	int						mDetectionDesappearThreshold;

	/**
	* Number of frame a Hand signal is appearing on screen
	*/
	int						mDetectionAppearCount;

	/**
	* Number of frame a Hand hasn't featured an affirmative appearing signal
	*/
	int						mDetectionDesappearCount;

	/**
	* Particles to render stated as an integer type (see ParticleType in Particle.h) 
	*/
	int						mRenderedParticles;

	/**
	* Debug mode to display the Detected Punches 
	*/
	int						mDebugMode;


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
	mIsHandDetected = false;

	//Build the Particle Engine
	mParticleEngine = new ParticleEngine();
	SparkEmitter* lSparkEmitter = new SparkEmitter(mParticleEngine);
	StarEmitter* lStarEmitter = new StarEmitter(mParticleEngine);
	FireEmitter* lFireEmitter = new FireEmitter(mParticleEngine);
	mParticleEngine->addEmitter("Spark", lSparkEmitter);
	mParticleEngine->addEmitter("Star", lStarEmitter);
	mParticleEngine->addEmitter("Fire", lFireEmitter);

	//Build the GUI
	mRenderedParticles = 0;
	mDebugMode = 0;
	mGUI = params::InterfaceGl("Parameters", Vec2i(250,50));

	std::vector<std::string> lDebugModeString;
	lDebugModeString.push_back("Off");
	lDebugModeString.push_back("On");
	mGUI.addParam("Debug Mode", lDebugModeString, &mDebugMode, "min=0 max=1");

	std::vector<std::string> lParticles; 
	//lParticles.push_back("Simple Particles");
	lParticles.push_back("Spark Particles");
	lParticles.push_back("Star Particles");
	lParticles.push_back("Fire Particles");
	mGUI.addParam("Particle Type", lParticles, &mRenderedParticles, "min=0 max=2");

	

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
		float lUpperPunch = 0.0f;

		//Update the Detector
		if (mHaarHandDetector->updateDetection(lSurface))
		{
			//Grab the old position
			Vec2i lOldPosition = mHandPosition;

			//Get the current Position
			vector<Rectf> lDetectedHands;
			mHaarHandDetector->getDetectedHands(lDetectedHands);
			mHandPosition = lDetectedHands[0].getCenter();
			lUpperPunch = lDetectedHands[0].getHeight();

			//Is this a new Detection ?
			if (!mIsHandDetected)
			{
				mHandSpeed = Vec2i::zero();
			}
			//Or a Continuous one ?
			else
			{
				mHandSpeed = mHandPosition - lOldPosition;
			}
			

			mIsHandDetected = true;
		}

		else
		{
			mIsHandDetected = false;
		}

		//Update the Particle Engine
		if (mIsHandDetected)
		{
			ParticleEmitter* lEmitter;

			switch (mRenderedParticles)
			{

			case 0:
				{
					lEmitter = mParticleEngine->getEmitter("Spark");
					lEmitter->setPosition(mHandPosition);
					lEmitter->setVelocity(mHandSpeed);
					lEmitter->setScale(ci::Vec2f(lUpperPunch / 2.0f, lUpperPunch / 2.0f));
					lEmitter->Emit(30);
				}
				break;

			case 1:
				{
					lEmitter = mParticleEngine->getEmitter("Star");
					lEmitter->setPosition(mHandPosition);
					lEmitter->setVelocity(mHandSpeed);
					lEmitter->setScale(ci::Vec2f(lUpperPunch / 2.0f, lUpperPunch / 2.0f));
					lEmitter->Emit(60);
				}
				break;

			case 2:
				{
					lEmitter = mParticleEngine->getEmitter("Fire");
					lEmitter->setPosition(mHandPosition);
					lEmitter->setVelocity(mHandSpeed);
					lEmitter->setScale(ci::Vec2f(lUpperPunch / 2.0f, lUpperPunch / 2.0f));
					lEmitter->Emit(40);
				}
				break;

			default:
				break;
			}
		}
		
		mParticleEngine->update();
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
	gl::color(Color(1.0f ,1.0f,1.0f));
	gl::draw(mInputTexture);
	mInputTexture.disable();

	//draw the detected closed hands
	gl::color(ColorA( 0, 0, 1.0f, 0.35f ));
	vector<Rectf> lDetectedHands;
	mHaarHandDetector->getDetectedHands(lDetectedHands);
	for (vector<Rectf>::iterator lIter = lDetectedHands.begin(); lIter != lDetectedHands.end(); lIter++)
	{
		if (mDebugMode)
		{
			gl::drawSolidCircle(lIter->getCenter(), lIter->getWidth() / 2);
		}	
	}

	//draw the GUI
	mGUI.draw();

	//draw the Particles
	mParticleEngine->draw();
	
}
//-----------------------------------------------------------------------------
CINDER_APP_BASIC( SoixanteCircuits_Test_Application, RendererGl )
