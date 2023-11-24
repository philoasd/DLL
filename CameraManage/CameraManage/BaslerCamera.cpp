#include "pch.h"
#include "BaslerCamera.h"

BaslerCamera::BaslerCamera()
{
	PylonInitialize();
}

vector<string> BaslerCamera::GetCameraDevices()
{
	vector<string> devicesInfo;
	if (CTlFactory::GetInstance().EnumerateDevices(Devices) > 0)
	{
		for (int index = 0; index < Devices.size(); index++)
		{
			Camera.Attach(CTlFactory::GetInstance().CreateDevice(Devices[index]));
			string serialNumber = (string)Camera.GetDeviceInfo().GetSerialNumber();
			devicesInfo.push_back((string)Camera.GetDeviceInfo().GetModelName() + "(" + serialNumber + ")");
		}
	}
	return devicesInfo;
}

bool BaslerCamera::ConnectedCamera(int serialNumber)
{
	if (serialNumber >= 0 && Devices.size() > 0)
	{
		// 连接相机
		Camera.Attach(CTlFactory::GetInstance().CreateDevice(Devices[serialNumber]));
		IsInitCamera = true;
		return true;
	}
	else
	{
		IsInitCamera = false;
		return false;
	}
}

void BaslerCamera::RegisterImageEvent(ImageEventHandler* imageEventHandler)
{
	if (!IsInitCamera)
	{
		return;
	}
	Camera.RegisterImageEventHandler(imageEventHandler, RegistrationMode_Append, Cleanup_Delete);
	Camera.GrabCameraEvents = true;
	if (!Camera.IsOpen())
	{
		Camera.Open();
		LoadParameter();
	}
}

void BaslerCamera::DeregisterImageEvent(ImageEventHandler* imageEventHandler)
{
	if (!IsInitCamera)
	{
		return;
	}
	Camera.DeregisterImageEventHandler(imageEventHandler);
}

bool BaslerCamera::DisConnectedCamera()
{
	if (!IsInitCamera)
	{
		return false;
	}
	if (Camera.IsGrabbing())
	{
		Camera.StopGrabbing();
	}
	if (Camera.IsOpen())
	{
		SaveParameter();
		Camera.Close();
	}
	IsInitCamera = false;
	return true;
}

void BaslerCamera::StartCapture(int flag)
{
	if (!IsInitCamera)
	{
		return;
	}
	//if (!Camera.IsOpen())
	//{
	//	Camera.Open();
	//}
	if (Camera.IsGrabbing())
	{
		Camera.StopGrabbing();
	}

	if (flag)
	{
		Camera.StartGrabbing(GrabStrategy_LatestImageOnly, GrabLoop_ProvidedByInstantCamera);
	}
	else
	{
		Camera.StartGrabbing(1, GrabStrategy_LatestImageOnly, GrabLoop_ProvidedByInstantCamera);
	}
}

void BaslerCamera::StopCapture()
{
	if (!IsInitCamera)
	{
		return;
	}
	Camera.StopGrabbing();
}

void BaslerCamera::SaveImage(const string& path, const CGrabResultPtr& ptrGrabResult)
{
	if (!IsInitCamera)
	{
		return;
	}
	CImagePersistence::Save(ImageFileFormat_Bmp, path.c_str(), ptrGrabResult);
}

double BaslerCamera::GetExposureTime()
{
	if (!IsInitCamera)
	{
		return 0;
	}
	return CFloatParameter(Camera.GetNodeMap(), "ExposureTime").GetValue();
}

void BaslerCamera::SetExposureTime(double exposureTime)
{
	if (!IsInitCamera)
	{
		return;
	}
	if (exposureTime < 100) { return; } // 最小曝光时间为100us
	CEnumParameter(Camera.GetNodeMap(), "ExposureAuto").SetValue("Off"); // 关闭自动曝光
	CFloatParameter(Camera.GetNodeMap(), "ExposureTime").SetValue(exposureTime); // 设置曝光时间
}

void BaslerCamera::SetAutoExposure(bool flag)
{
	if (!IsInitCamera)
	{
		return;
	}
	CEnumParameter(Camera.GetNodeMap(), "ExposureAuto").SetValue(flag ? "Continuous" : "Off");
}

double BaslerCamera::GetFrameRate()
{
	if (!IsInitCamera)
	{
		return 0.0;
	}
	return CFloatParameter(Camera.GetNodeMap(), "ResultingFrameRate").GetValue();
}

void BaslerCamera::SaveParameter()
{
	if (!IsInitCamera)
	{
		return;
	}
	CEnumParameter(Camera.GetNodeMap(), "UserSetSelector").SetValue("UserSet1");
	CCommandParameter(Camera.GetNodeMap(), "UserSetSave").Execute();
}

void BaslerCamera::LoadParameter()
{
	if (!IsInitCamera)
	{
		return;
	}
	CEnumParameter(Camera.GetNodeMap(), "UserSetSelector").SetValue("UserSet1");
	CCommandParameter(Camera.GetNodeMap(), "UserSetLoad").Execute();
}

void BaslerCamera::LoadDefaultParameter()
{
	if (!IsInitCamera)
	{
		return;
	}
	CEnumParameter(Camera.GetNodeMap(), "UserSetSelector").SetValue("Default");
	CCommandParameter(Camera.GetNodeMap(), "UserSetLoad").Execute();
}
