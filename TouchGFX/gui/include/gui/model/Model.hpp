#ifndef MODEL_HPP
#define MODEL_HPP

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

  protected:
    ModelListener *modelListener;
    float currentBatteryLevel;
    int currentSpeed;
    int currentLightState;

};

#endif // MODEL_HPP
