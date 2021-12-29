#include <gui/containers/Light.hpp>
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
//#include <vescLib/bldc_interface.h>

Model::Model() : modelListener(0), currentBatteryLevel(36.0), motorCurrent(0.0), currentSpeed(0), currentLightState(Light::kStateAuto)
{
  // Give bldc_interface a function to call when values are received.
  //bldc_interface_set_rx_value_func(ui_print_esc_values);
}

void Model::tick()
{
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

}
