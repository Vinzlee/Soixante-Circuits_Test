/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			HandDetector.cpp
 * @author			Vinz
 * @version			0.1
 * @date			2011/10/24
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "HandDetector.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
HandDetector::HandDetector(DetectionType pType)
{
	mType = pType;
}
//-----------------------------------------------------------------------------
HandDetector::~HandDetector()
{

}
//-----------------------------------------------------------------------------
bool HandDetector::updateDetection(ci::Surface pSurface)
{
	return (this->doUpdateDetection(pSurface));
}
//-----------------------------------------------------------------------------
void HandDetector::getDetectedHands(std::vector<ci::Rectf>& pOutputDetectedHand)
{
	for (HandsIterator lIter = mClosedHands.begin(); lIter != mClosedHands.end(); lIter++)
	{
		pOutputDetectedHand.push_back(*lIter);
	}
}
//-----------------------------------------------------------------------------
