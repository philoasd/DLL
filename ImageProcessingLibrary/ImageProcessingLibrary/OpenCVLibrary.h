#pragma once

#include <opencv2/opencv.hpp>

class _declspec(dllexport) OpenCVLibrary
{
public:
	/// <summary>
	/// 二值化图像
	/// </summary>
	/// <param name="input">输入图像</param>
	/// <param name="leftThresholdValue">左阈值</param>
	/// <param name="rightThresholdValue">右阈值</param>
	/// <param name="rect">ROI区域,默认为空</param>
	cv::Mat Threshold(cv::Mat inputImage, int leftThresholdValue, int rightThresholdValue, cv::Rect rect = cv::Rect());

	/// <summary>
	/// 自动二值化图像
	/// </summary>
	/// <param name="inputImage">输入图像</param>
	/// <param name="rect">ROI区域,默认为空</param>
	/// <returns></returns>
	cv::Mat AutoThreshold(cv::Mat inputImage, cv::Rect rect = cv::Rect());

private:
	// 检查是否有ROI区域
	bool CheckROI(cv::Mat& inputImage, cv::Mat& roiImage, cv::Rect& rect);
};

