#ifndef MODEL_HPP
#define MODEL_HPP

#include <vescLib/datatypes.h>

class ModelListener;


class Model
{
  public:

    Model();

    void bind(ModelListener *listener)
    {
      modelListener = listener;
    }

    void tick();

    float GetCurrentBatteryLevel() const
    {
      return currentBatteryLevel;
    }

    int GetCurrentSpeed() const
    {
      return currentSpeed;
    }

    int GetCurrentLightState() const
    {
      return currentLightState;
    }

  protected:
    ModelListener *modelListener;
    mc_values controllerValues_;
    mc_configuration controllerMotorConfig_;
    float speedFactor_;
    float currentBatteryLevel;
    float motorCurrent;
    int currentSpeed;
    int currentLightState;
    float currentDistance;
    bool initialized_;
};

#endif // MODEL_HPP
