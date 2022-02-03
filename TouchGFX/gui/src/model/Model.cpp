#include <gui/containers/Light.hpp>
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern "C" {
#include <vescLib/bldc_interface.h>
}

#include <cmsis_os2.h>
#include <string.h>
#include <math.h>

extern osMessageQueueId_t ESCRealTimeDataQHandle;
extern osMessageQueueId_t ESCMotorConfigQHandle;


Model::Model() : modelListener(0), speedFactor_(0.0), currentBatteryLevel(36.0), motorCurrent(0.0),
                 currentSpeed(0), currentLightState(Light::kStateAuto), currentDistance(0), initialized_(false)
{
}

void Model::tick()
{
  osStatus_t rv;

  if (!initialized_)
  {
    rv = osMessageQueueGet(ESCMotorConfigQHandle, &controllerMotorConfig_, 0, 0);
    if (osOK != rv)
    {
      bldc_interface_get_mcconf();
      return;
    }
    speedFactor_ = (((controllerMotorConfig_.si_motor_poles / 2.0) * 60.0 * controllerMotorConfig_.si_gear_ratio) / (controllerMotorConfig_.si_wheel_diameter * M_PI)) / 3.6;
    initialized_ = true;
  }

  rv = osMessageQueueGet(ESCRealTimeDataQHandle, &controllerValues_, 0, 0);
  if (osOK != rv)
  {
    return;
  }

  // New values received
  if (modelListener)
  {
    modelListener->NotifyBatteryLevelChanged(controllerValues_.v_in);
    modelListener->NotifyDistanceChanged(controllerValues_.tachometer / 100 / speedFactor_);
    modelListener->NotifySpeedChanged(controllerValues_.rpm / speedFactor_);
    modelListener->NotifyMotorCurrentChanged(controllerValues_.current_motor);
  }



#ifdef DEMO
	currentBatteryLevel += 0.1;
	if (currentBatteryLevel > 43)
	{
	  currentBatteryLevel = 36;
	  if (modelListener)
    {
      currentLightState++;
      if (currentLightState > Light::kStateAuto)
      {
        currentLightState = Light::kStateOn;
      }
      modelListener->NotifyLightStateChanged(currentLightState);
    }
	}
	if (modelListener)
	{
		modelListener->NotifyBatteryLevelChanged(currentBatteryLevel);
	}

	motorCurrent += 0.6;
	if (motorCurrent > 30)
	{
	  motorCurrent = 0;
	}
	if (modelListener)
	{
	  modelListener->NotifyMotorCurrentChanged(motorCurrent);
	}

	if (++currentSpeed > 99)
	{
	  currentSpeed = 0;
	}
	if (modelListener)
	{
		modelListener->NotifySpeedChanged(currentSpeed);
	}

	currentDistance += 10.1;
	if (currentDistance > 9999.9)
	{
	  currentDistance = 0;
	}
	if (modelListener)
	{
	  modelListener->NotifyDistanceChanged(currentDistance);
	}

#endif // DEMO

}
