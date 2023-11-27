#include "pch.h"
#include "OpenCVLibrary.h"

cv::Mat OpenCVLibrary::Threshold(cv::Mat inputImage, int leftThresholdValue, int rightThresholdValue, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	// 二值化
	cv::Mat binaryRoi;
	cv::threshold(roiImage, binaryRoi, leftThresholdValue, rightThresholdValue, cv::THRESH_BINARY);

	if (inputImage(rect).channels() == 3) {
		cv::cvtColor(binaryRoi, binaryRoi, cv::COLOR_GRAY2BGR);
	}

	if (rect.empty()) {
		return binaryRoi;
	}

	// 将二值化后的图像拷贝到原图中
	binaryRoi.copyTo(inputImage(rect));

	return inputImage;
}

cv::Mat OpenCVLibrary::AutoThreshold(cv::Mat inputImage, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	// 自适应阈值处理
	cv::Mat adaptiveThresholdImage;
	adaptiveThreshold(roiImage, adaptiveThresholdImage, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);

	if (inputImage(rect).channels() == 3) {
		cv::cvtColor(adaptiveThresholdImage, adaptiveThresholdImage, cv::COLOR_GRAY2BGR);
	}

	if (rect.empty()) {
		return adaptiveThresholdImage;
	}

	// 将二值化后的图像拷贝到原图中
	adaptiveThresholdImage.copyTo(inputImage(rect));

	return inputImage;
}

bool OpenCVLibrary::CheckROI(cv::Mat& inputImage, cv::Mat& roiImage, cv::Rect& rect)
{
	if (inputImage.empty())
	{
		return false;
	}

	// 提取ROI区域
	if (rect.empty()) {
		roiImage = inputImage;
	}
	else {
		roiImage = inputImage(rect);
	}

	// 转换为灰度图
	if (roiImage.channels() == 3) {
		cv::cvtColor(roiImage, roiImage, cv::COLOR_BGR2GRAY);
	}

	return true;
}
