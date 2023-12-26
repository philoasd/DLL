#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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

	// 内核形状,默认为矩形
	cv::MorphShapes morphShape = cv::MORPH_RECT;

	// 膨胀图像，用于填充空洞
	cv::Mat Dilate(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 腐蚀图像，用于去除噪点
	cv::Mat Erode(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 开运算，先腐蚀后膨胀，可以去掉图像上一些小的对象
	cv::Mat Open(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 闭运算，先膨胀后腐蚀，可以填充小洞，填充小的噪点
	cv::Mat Close(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 形态学梯度，膨胀图像减去腐蚀图像,可以得到物体的轮廓
	cv::Mat Gradient(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 顶帽，原图像减去开运算图像,可以得到噪点
	cv::Mat TopHat(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 黑帽，闭运算图像减去原图像,可以得到小的物体
	cv::Mat BlackHat(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// Hitmiss，用于检测图像中的特定形状
	cv::Mat Hitmiss(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 旋转图像
	cv::Mat Rotate(cv::Mat inputImage, double angle, cv::Rect rect = cv::Rect());

	// 直方图均衡化,增强图像对比度
	cv::Mat EqualizeHist(cv::Mat inputImage, cv::Rect rect = cv::Rect());

	// CLAHE变换，限制对比度的增强，避免过度增强对比度导致的噪点增加
	cv::Mat CLAHE(cv::Mat inputImage, cv::Rect rect = cv::Rect());

	// Laplace变换，增强图像边缘，从而提高图像的对比度
	cv::Mat Laplace(cv::Mat inputImage, cv::Rect rect = cv::Rect());

	// 对数变换，扩大图像中暗区的对比度，使得暗区的细节更加清晰
	cv::Mat Log(cv::Mat inputImage, cv::Rect rect = cv::Rect());

	// Gamma变换，调整图像的亮度，使得图像在人眼感知上更加自然
	cv::Mat Gamma(cv::Mat inputImage, double gamma, cv::Rect rect = cv::Rect());

	// Sobel变换，增强图像边缘，从而提高图像的对比度
	cv::Mat Sobel(cv::Mat inputImage, cv::Rect rect = cv::Rect());

	// 均值滤波，去除图像中的噪点
	cv::Mat Blur(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 方框滤波，去除图像中的噪点
	cv::Mat BoxFilter(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 中值滤波，去除图像中的噪点
	cv::Mat MedianBlur(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 高斯滤波，去除图像中的噪点
	cv::Mat GaussianBlur(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 双边滤波，去除图像中的噪点
	cv::Mat BilateralFilter(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 非局部均值滤波，去除图像中的噪点
	cv::Mat NLMeanFilter(cv::Mat inputImage, int kernelSize, cv::Rect rect = cv::Rect());

	// 模板识别
	/* 模板匹配方法
	* 1.cv::TM_SQDIFF：平方差匹配方法。这种方法通过计算模板和图像间的每个像素的平方差来进行匹配。结果越小，匹配度越高。
	* 2.cv::TM_SQDIFF_NORMED：归一化平方差匹配方法。这种方法是对平方差匹配方法的结果进行归一化处理。
	* 3.cv::TM_CCORR：相关匹配方法。这种方法通过计算模板和图像间的每个像素的乘积来进行匹配。结果越大，匹配度越高。
	* 4.cv::TM_CCORR_NORMED：归一化相关匹配方法。这种方法是对相关匹配方法的结果进行归一化处理。
	* 5.cv::TM_CCOEFF：相关系数匹配方法。这种方法通过计算模板和图像间的每个像素的相关系数来进行匹配。结果越大，匹配度越高。
	* 6.cv::TM_CCOEFF_NORMED：归一化相关系数匹配方法。这种方法是对相关系数匹配方法的结果进行归一化处理。
	*/
	cv::Mat MatchTemplate(cv::Mat inputImage, cv::Mat templateImage, cv::Rect rect = cv::Rect());
private:
	/// <summary>
	/// 检查是否有ROI区域
	/// </summary>
	/// <param name="inputImage">输入图像</param>
	/// <param name="roiImage">roi区域图像</param>
	/// <param name="rect">roi区域</param>
	/// <param name="convert">是否转换为灰度图像,默认转灰度图</param>
	/// <returns></returns>
	bool CheckROI(cv::Mat& inputImage, cv::Mat& roiImage, cv::Rect& rect, bool convert = true);
};

