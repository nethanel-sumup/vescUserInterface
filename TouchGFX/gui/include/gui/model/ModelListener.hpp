#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void NotifyBatteryLevelChanged(float level) {}
    virtual void NotifySpeedChanged(int speed) {}
    virtual void NotifyLightStateChanged(int state) {}
    virtual void NotifyMotorCurrentChanged(float current) {}
    virtual void NotifyDistanceChanged(float distance) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
