#include "pk_kinect.h"

libfreenect2::Freenect2 freenect2;

std::vector<std::string> Kinect::initialize()
{
	std::vector<std::string> serial;
	int num = freenect2.enumerateDevices();
	for (int i = 0; i != num; i++)
	{
		serial.push_back(freenect2.getDeviceSerialNumber(i));
	}
	return serial;
}

Kinect::Kinect(std::string serial)
{
	this->device = freenect2.openDevice(serial);
	this->listener = new libfreenect2::SyncMultiFrameListener(Kinect::config);
	this->device->setColorFrameListener(this->listener);
	this->device->setIrAndDepthFrameListener(this->listener);
	this->device->start();
}

bool Kinect::fetch()
{
	this->listener->release(frames);
	this->listener->waitForNewFrame(this->frames);
	this->rgba = this->frames[libfreenect2::Frame::Color];
	this->ir = this->frames[libfreenect2::Frame::Ir];
	this->depth = this->frames[libfreenect2::Frame::Depth];
}

libfreenect2::Frame* Kinect::getRgba()
{
	return this->rgba;
}

cv::Mat Kinect::getRgbaMat()
{
	return cv::Mat(this->getRgba()->height, this->getRgba()->width, CV_8UC4, this->getRgba()->data).clone();
}
