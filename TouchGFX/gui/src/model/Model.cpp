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


Model::Model() : modelListener(0), speedFactor_(0.0), currentBatteryLevel(48.0), motorCurrent(0.0),
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
    modelListener->NotifyDistanceChanged(controllerValues_.tachometer / 400.0 / speedFactor_);
    modelListener->NotifySpeedChanged(controllerValues_.rpm / speedFactor_);
    modelListener->NotifyMotorCurrentChanged(controllerValues_.current_motor);
  }
}
