#ifndef MODEL_HPP
#define MODEL_HPP

//#include <vescLib/datatypes.h>

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
    //static mc_values controllerValues;
    float currentBatteryLevel;
    float motorCurrent;
    int currentSpeed;
    int currentLightState;
};

#endif // MODEL_HPP
