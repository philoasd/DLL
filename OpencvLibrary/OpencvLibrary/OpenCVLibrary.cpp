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
	if (roiImage.empty()) {
		return adaptiveThresholdImage;
	}
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

cv::Mat OpenCVLibrary::Dilate(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat dilated;
	cv::dilate(roiImage, dilated, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return dilated;
	}

	// 将膨胀后的图像拷贝到原图中
	dilated.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Erode(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat eroded;
	cv::erode(roiImage, eroded, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return eroded;
	}

	// 将腐蚀后的图像拷贝到原图中
	eroded.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Open(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat opened;
	cv::morphologyEx(roiImage, opened, cv::MORPH_OPEN, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return opened;
	}

	// 将开运算后的图像拷贝到原图中
	opened.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Close(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat closed;
	cv::morphologyEx(roiImage, closed, cv::MORPH_CLOSE, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return closed;
	}

	// 将闭运算后的图像拷贝到原图中
	closed.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Gradient(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat gradiented;
	cv::morphologyEx(roiImage, gradiented, cv::MORPH_GRADIENT, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return gradiented;
	}

	// 将形态学梯度后的图像拷贝到原图中
	gradiented.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::TopHat(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat topHated;
	cv::morphologyEx(roiImage, topHated, cv::MORPH_TOPHAT, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return topHated;
	}

	// 将顶帽后的图像拷贝到原图中
	topHated.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::BlackHat(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat blackHated;
	cv::morphologyEx(roiImage, blackHated, cv::MORPH_BLACKHAT, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return blackHated;
	}

	// 将黑帽后的图像拷贝到原图中
	blackHated.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Hitmiss(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat hitmissed;
	cv::morphologyEx(roiImage, hitmissed, cv::MORPH_HITMISS, cv::getStructuringElement(morphShape, cv::Size(kernelSize, kernelSize)));

	if (rect.empty()) {
		return hitmissed;
	}

	// 将Hitmiss后的图像拷贝到原图中
	hitmissed.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Rotate(cv::Mat inputImage, double angle, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat rotated;
	cv::Point2f center(static_cast<float>(roiImage.cols) / 2, static_cast<float>(roiImage.rows) / 2);
	cv::Mat rotateMatrix = cv::getRotationMatrix2D(center, angle, 1.0);
	cv::warpAffine(roiImage, rotated, rotateMatrix, inputImage.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT);

	if (rect.empty()) {
		return rotated;
	}

	// 将旋转后的图像拷贝到原图中
	rotated.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::EqualizeHist(cv::Mat inputImage, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat equalizeHisted;
	if (roiImage.channels() == 3) { // 彩色图像
		cv::Mat rgbImage[3];
		cv::split(roiImage, rgbImage);
		for (int i = 0; i < 3; i++) { // 对每个通道进行直方图均衡化
			cv::equalizeHist(rgbImage[i], rgbImage[i]);
		}
		cv::merge(rgbImage, 3, equalizeHisted); // 合并通道
	}
	else { // 灰度图像
		cv::equalizeHist(roiImage, equalizeHisted);
	}

	if (rect.empty()) {
		return equalizeHisted;
	}

	// 将直方图均衡化后的图像拷贝到原图中
	equalizeHisted.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::CLAHE(cv::Mat inputImage, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat claheed;
	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(2.0, cv::Size(8, 8));
	clahe->apply(roiImage, claheed);

	if (rect.empty()) {
		return claheed;
	}

	// 将CLAHE后的图像拷贝到原图中
	claheed.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Laplace(cv::Mat inputImage, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat laplaced;
	cv::Mat kenerl = (cv::Mat_<float>(3, 3) << 0, 1, 0, 1, -4, 1, 0, 1, 0);
	cv::filter2D(roiImage, laplaced, roiImage.type(), kenerl);

	if (rect.empty()) {
		return laplaced;
	}

	// 将Laplace后的图像拷贝到原图中
	laplaced.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Log(cv::Mat inputImage, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat loged(roiImage.size(), roiImage.type());
	// log变换
	cv::logPolar(roiImage, loged, cv::Point2f(static_cast<float>(roiImage.cols) / 2, static_cast<float>(roiImage.rows) / 2), 40, cv::INTER_LINEAR + cv::WARP_FILL_OUTLIERS);
	cv::normalize(loged, loged, 0, 255, cv::NORM_MINMAX); // 归一化到0~255
	cv::convertScaleAbs(loged, loged); // 转换为8bit图像

	if (rect.empty()) {
		return loged;
	}

	// 将Log后的图像拷贝到原图中
	loged.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Gamma(cv::Mat inputImage, double gamma, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat gammaed(roiImage.size(), roiImage.type());
	// gamma变换
	for (int i = 0; i < roiImage.rows; i++) {
		for (int j = 0; j < roiImage.cols; j++) {
			if (roiImage.channels() == 1) { // 灰度图像
				gammaed.at<uchar>(i, j) = cv::saturate_cast<uchar>(pow((double)roiImage.at<uchar>(i, j) / 255.0, gamma) * 255.0);
			}
			else
			{ // 彩色图像
				gammaed.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(pow((double)roiImage.at<cv::Vec3b>(i, j)[0] / 255.0, gamma) * 255.0);
				gammaed.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(pow((double)roiImage.at<cv::Vec3b>(i, j)[1] / 255.0, gamma) * 255.0);
				gammaed.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(pow((double)roiImage.at<cv::Vec3b>(i, j)[2] / 255.0, gamma) * 255.0);
			}
		}
	}

	cv::normalize(gammaed, gammaed, 0, 255, cv::NORM_MINMAX); // 归一化到0~255
	cv::convertScaleAbs(gammaed, gammaed); // 转换为8bit图像

	if (rect.empty()) {
		return gammaed;
	}

	// 将Gamma后的图像拷贝到原图中
	gammaed.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Sobel(cv::Mat inputImage, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat sobeled;
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;
	cv::Sobel(roiImage, grad_x, CV_16S, 1, 0, 3, 1, 1, cv::BORDER_DEFAULT);
	cv::Sobel(roiImage, grad_y, CV_16S, 0, 1, 3, 1, 1, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_x, abs_grad_x);
	cv::convertScaleAbs(grad_y, abs_grad_y);
	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, sobeled);

	if (rect.empty()) {
		return sobeled;
	}

	// 将Sobel后的图像拷贝到原图中
	sobeled.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::Blur(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat blured;
	cv::blur(roiImage, blured, cv::Size(kernelSize, kernelSize));

	if (rect.empty()) {
		return blured;
	}

	// 将均值滤波后的图像拷贝到原图中
	blured.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::BoxFilter(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat boxFiltered;
	cv::boxFilter(roiImage, boxFiltered, -1, cv::Size(kernelSize, kernelSize));

	if (rect.empty()) {
		return boxFiltered;
	}

	// 将方框滤波后的图像拷贝到原图中
	boxFiltered.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::MedianBlur(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat medianBlured;
	cv::medianBlur(roiImage, medianBlured, kernelSize);

	if (rect.empty()) {
		return medianBlured;
	}

	// 将中值滤波后的图像拷贝到原图中
	medianBlured.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::GaussianBlur(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	// 高斯滤波
	cv::Mat gaussianBlured;
	cv::GaussianBlur(roiImage, gaussianBlured, cv::Size(kernelSize, kernelSize), 0, 0);

	if (rect.empty()) {
		return gaussianBlured;
	}

	// 将高斯滤波后的图像拷贝到原图中
	gaussianBlured.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::BilateralFilter(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat bilateralFiltered;
	cv::bilateralFilter(roiImage, bilateralFiltered, 21, 10, 10);

	if (rect.empty()) {
		return bilateralFiltered;
	}

	// 将双边滤波后的图像拷贝到原图中
	bilateralFiltered.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::NLMeanFilter(cv::Mat inputImage, int kernelSize, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect, false)) { return inputImage; }

	cv::Mat nLMeanFiltered;
	cv::fastNlMeansDenoising(roiImage, nLMeanFiltered, kernelSize);

	if (rect.empty()) {
		return nLMeanFiltered;
	}

	// 将非局部均值滤波后的图像拷贝到原图中
	nLMeanFiltered.copyTo(inputImage(rect));
	return inputImage;
}

cv::Mat OpenCVLibrary::MatchTemplate(cv::Mat inputImage, cv::Mat templateImage, cv::Rect rect)
{
	// 提取ROI区域
	cv::Mat roiImage;
	if (!CheckROI(inputImage, roiImage, rect)) { return inputImage; }

	cv::Mat matched;
	// 如果模板图像是彩色图像，则转换为灰度图像
	if (templateImage.channels() > 1)
	{
		cv::cvtColor(templateImage, templateImage, cv::COLOR_BGR2GRAY);
	}

	// 定义旋转角度范围和步长
	double minAngle = -5.0;
	double maxAngle = 5.0;
	double angleStep = 1.0;
	for (double angle = minAngle; angle <= maxAngle; angle += angleStep) {
		// 旋转模板图像
		cv::Mat rotatedTemplate = Rotate(templateImage, angle);
		// 模板匹配
		cv::matchTemplate(roiImage, rotatedTemplate, matched, cv::TM_CCOEFF_NORMED);

		// 绘制单个矩形框
		//double maxVal;
		//cv::Point maxLoc;
		//cv::minMaxLoc(matched, NULL, &maxVal, NULL, &maxLoc); // 寻找结果矩阵中的最大值
		//cv::cvtColor(roiImage, roiImage, cv::COLOR_GRAY2BGR); // 转换为彩色图像,为了显示绘制的矩形框颜色
		//cv::rectangle(roiImage, cv::Rect(maxLoc.x, maxLoc.y, templateImage.cols, templateImage.rows), cv::Scalar(0, 255, 0), 1);

		// 绘制多个矩形框
		double threshold = 0.8; // 识别阈值
		for (int i = 0; i < matched.rows; i++) {
			for (int j = 0; j < matched.cols; j++) {
				if (matched.at<float>(i, j) >= threshold) {
					// 绘制带有角度的矩形框
					cv::Rect matchRect(j, i, templateImage.cols, templateImage.rows);
					//cv::Mat imgWithMatch = roiImage.clone();
					roiImage = Rotate(roiImage, angle);
					cv::rectangle(roiImage, matchRect, cv::Scalar(0, 255, 0), 1);
					//cv::rectangle(roiImage, cv::Point(j, i), cv::Point(j + templateImage.cols, i + templateImage.rows), cv::Scalar(0, 255, 0), 1);
				}
			}
		}
	}

	cv::imshow("matched", roiImage);
	cv::waitKey(0);
	if (rect.empty()) {

		return roiImage;
	}

	// 将模板匹配后的图像拷贝到原图中
	roiImage.copyTo(inputImage(rect));
	//cv::cvtColor(inputImage, inputImage, cv::COLOR_BGR2RGB);
	return inputImage;
}

bool OpenCVLibrary::CheckROI(cv::Mat& inputImage, cv::Mat& roiImage, cv::Rect& rect, bool convert)
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
		cv::cvtColor(roiImage, roiImage, cv::COLOR_RGB2BGR);
		if (convert) {
			cv::cvtColor(roiImage, roiImage, cv::COLOR_BGR2GRAY);
		}
	}

	return true;
}
