#include "pk_kinect.h"
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>

int main()
{
	cv::Ptr<cv::BackgroundSubtractor> mog2 = cv::createBackgroundSubtractorMOG2();
	std::vector<std::string> serials = Kinect::initialize();
	Kinect kinect(serials[0]);
	while (true)
	{
		kinect.fetch();
		cv::Mat frame = kinect.getRgbaMat();
		cv::Mat mask;
		mog2->apply(frame, mask, 0.1);
		cv::imshow("Kinect", mask);
		cv::waitKey(30);
	}
}
