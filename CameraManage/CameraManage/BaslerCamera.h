#pragma once
#include <pylon/PylonIncludes.h>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include "BaseCamera.h"

using namespace Pylon;
using namespace std;

/// <summary>
/// 相机回调函数
/// </summary>
class ImageEventHandler : public CImageEventHandler
{
public:
	using ImageCallback = function<void(const CGrabResultPtr&)>;
	ImageEventHandler(ImageCallback callback) : imageCallback(callback) {}

	/*virtual*/ void OnImageGrabbed(CInstantCamera& camera, const CGrabResultPtr& ptrGrabResult) override
	{
		if (ptrGrabResult->GrabSucceeded())
		{
			imageCallback(ptrGrabResult);
		}
	}

private:
	ImageCallback imageCallback;
};

/// <summary>
/// Basler相机类
/// </summary>
class __declspec(dllexport) BaslerCamera : public BaseCmaera
{
public:
	BaslerCamera();
	vector<string> GetCameraDevices() override;
	bool ConnectedCamera(int serialNumber) override;

	/// <summary>
	/// 注册相机回调函数
	/// </summary>
	/// <param name="imageEventHandler"></param>
	void RegisterImageEvent(ImageEventHandler* imageEventHandler);

	/// <summary>
	/// 注销相机回调函数
	/// </summary>
	/// <param name="imageEventHandler"></param>
	void DeregisterImageEvent(ImageEventHandler* imageEventHandler);

	// 断开相机
	bool DisConnectedCamera() override;

	/// <summary>
	/// 捕获图像
	/// </summary>
	/// <param name="flag">0:单次；1：连续</param>
	void StartCapture(int flag) override;
	void StopCapture() override;

	/// <summary>
	/// 保存图像
	/// </summary>
	/// <param name="path"></param>
	/// <param name="ptrGrabResult"></param>
	void SaveImage(const string& path, const CGrabResultPtr& ptrGrabResult);

	// 获取曝光时间
	double GetExposureTime() override;

	// 设置曝光时间
	void SetExposureTime(double exposureTime) override;

	// 设置自动曝光
	void SetAutoExposure(bool flag) override;

	// 获取帧率
	double GetFrameRate() override;

protected:
	// 保存参数
	void SaveParameter() override;
	// 加载参数
	void LoadParameter() override;
	// 加载默认参数
	void LoadDefaultParameter();

private:
	CInstantCamera Camera;	   // 相机对象
	DeviceInfoList_t Devices;  // 相机设备列表
	bool IsInitCamera = false; // 是否初始化相机
};