#ifndef DISTANCECOUNTER_HPP
#define DISTANCECOUNTER_HPP

#include <gui_generated/containers/DistanceCounterBase.hpp>

class DistanceCounter : public DistanceCounterBase
{
public:
    DistanceCounter();
    virtual ~DistanceCounter() {}

    virtual void initialize();
protected:
};

#endif // DISTANCECOUNTER_HPP
