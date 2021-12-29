#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/containers/light.hpp>

Model::Model() : modelListener(0), currentBatteryLevel(36.0), currentSpeed(0), currentLightState(light::kStateAuto)
{

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
      if (currentLightState > light::kStateAuto)
      {
        currentLightState = light::kStateOn;
      }
      modelListener->NotifyLightStateChanged(currentLightState);
    }
	}
	if (modelListener)
	{
		modelListener->NotifyBatteryLevelChanged(currentBatteryLevel);
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
