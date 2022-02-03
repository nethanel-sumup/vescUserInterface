#ifndef DISTANCECOUNTER_HPP
#define DISTANCECOUNTER_HPP

#include <gui_generated/containers/DistanceCounterBase.hpp>

class DistanceCounter : public DistanceCounterBase
{
  private:
    static constexpr const float kMaxValue = 9999.9;
public:
    DistanceCounter();
    virtual ~DistanceCounter() {}

    virtual void initialize();

    void SetValue(float value);
protected:
};

#endif // DISTANCECOUNTER_HPP
