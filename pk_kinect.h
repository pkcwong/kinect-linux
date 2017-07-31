#ifndef _PK_KINECT
#define _PK_KINECT

#include <vector>

#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/logger.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Kinect
{

private:
	const unsigned int config = libfreenect2::Frame::Color | libfreenect2::Frame::Ir | libfreenect2::Frame::Depth;
	libfreenect2::Freenect2Device* device = NULL;
	libfreenect2::SyncMultiFrameListener* listener;
	libfreenect2::FrameMap frames;
	libfreenect2::Frame* rgba;
	libfreenect2::Frame* ir;
	libfreenect2::Frame* depth;

public:
	static std::vector<std::string> initialize();
	Kinect(std::string serial);
	bool fetch();
	libfreenect2::Frame* getRgba();
	cv::Mat getRgbaMat();

};

#endif
