/**
 * This program belongs to Vincent Chollet : vinz_lee@hotmail.fr
 * It is considered a trade secret, and is not to be divulged or used 
 * by parties who have not received written authorization from the owner.
 *
 * @file			HaarHandDetector.cpp
 * @author			Vinz
 * @version			1.0
 * @date			2011/10/24
 */


/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/
#include "cinder/app/App.h"
#include "HaarHandDetector.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

//-----------------------------------------------------------------------------
HaarHandDetector::HaarHandDetector()
	: HandDetector(DetectionType::HAAR_STYLE)
{
	//Load the XML Cascade File for the Closed Hand Detection. 
	//WARNING : Only for WINDOWNS
	mClosedHandCascade.load(ci::app::getAppPath() + "../../resources/HaarClosedHand.xml");
}
//-----------------------------------------------------------------------------
HaarHandDetector::~HaarHandDetector()
{

}
//-----------------------------------------------------------------------------
void HaarHandDetector::doUpdateDetection(ci::Surface pSurface)
{
	//Set a Scale for the image to increase the processing time
	int lScale = 2;

	//Create a GrayScale copy of the input image
	cv::Mat	lGrayScaleImage(toOcv(pSurface, CV_8UC1));

	//Scale the GrayScaleImage
	cv::Mat lSmallGrayScaleImage(pSurface.getHeight() / lScale, pSurface.getWidth() / lScale, CV_8UC1);
	cv::resize(lGrayScaleImage, lSmallGrayScaleImage, lSmallGrayScaleImage.size(), 0,0,cv::INTER_LINEAR);

	//Equalize the Histogram to improve Edges Detection
	cv::equalizeHist(lSmallGrayScaleImage, lSmallGrayScaleImage);

	//Clear out the previous Detected Closed Hands
	mClosedHands.clear();

	//Start the Detection 
	std::vector<cv::Rect> lCVRectangles;
	mClosedHandCascade.detectMultiScale(lSmallGrayScaleImage, lCVRectangles, 1.2f, 2, CV_HAAR_FIND_BIGGEST_OBJECT, cv::Size(24,24));

	for (std::vector<cv::Rect>::iterator lIter = lCVRectangles.begin(); lIter != lCVRectangles.end(); lIter++)
	{
		ci::Rectf lClosedHand(ci::fromOcv(*lIter));
		lClosedHand *= lScale;
		mClosedHands.push_back(lClosedHand);
	}
}
//-----------------------------------------------------------------------------
