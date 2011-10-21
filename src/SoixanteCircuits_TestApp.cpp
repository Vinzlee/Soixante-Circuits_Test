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

	/******************************** METHODS *********************************/


};


/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::prepareSettings( Settings *pSettings )
{

}
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::setup()
{
}
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::update()
{
}
//-----------------------------------------------------------------------------
void SoixanteCircuits_Test_Application::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}
//-----------------------------------------------------------------------------
CINDER_APP_BASIC( SoixanteCircuits_Test_Application, RendererGl )
