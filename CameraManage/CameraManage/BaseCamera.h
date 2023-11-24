#pragma once
#include <vector>
#include <string>

using namespace std;

/// <summary>
/// 相机类的抽象类
/// </summary>
class BaseCmaera
{
public:
	/// <summary>
	/// 获取相机设备
	/// </summary>
	/// <returns></returns>
	virtual vector<string> GetCameraDevices() = 0;

	/// <summary>
	/// 连接相机
	/// </summary>
	/// <param name="serialNumber"></param>
	virtual bool ConnectedCamera(int serialNumber) = 0;

	/// <summary>
	/// 断开相机
	/// </summary>
	virtual bool DisConnectedCamera() = 0;

	/// <summary>
	/// 开始采集
	/// </summary>
	/// <param name="flag">0：单次；1：连续</param>
	virtual void StartCapture(int flag) = 0;

	/// <summary>
	/// 停止采集
	/// </summary>
	virtual void StopCapture() = 0;

	// 获取相机的曝光时间
	virtual double GetExposureTime() = 0;

	// 设置相机的曝光时间
	virtual void SetExposureTime(double exposureTime) = 0;

	virtual void SetAutoExposure(bool flag) = 0;

	// 获取相机的增益
	//virtual double GetGain() = 0;

	// 设置相机的增益
	//virtual double SetGain(float gain) = 0;

protected:
	// 获取帧率
	virtual double GetFrameRate() = 0;

	// 保存参数
	virtual void SaveParameter() = 0;

	// 加载参数
	virtual void LoadParameter() = 0;
};