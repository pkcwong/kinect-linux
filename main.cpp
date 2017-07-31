#include "pk_kinect.h"

int main()
{
	std::vector<std::string> serials = Kinect::initialize();
	Kinect kinect(serials[0]);
	while (true)
	{
		kinect.fetch();
		cv::imshow("Kinect", kinect.getRgbaMat());
		cv::waitKey(30);
	}
}
