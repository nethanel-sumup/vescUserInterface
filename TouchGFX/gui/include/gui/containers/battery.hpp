#ifndef BATTERY_HPP
#define BATTERY_HPP

#include <gui_generated/containers/batteryBase.hpp>

class battery : public batteryBase
{
public:
    battery();
    virtual ~battery() {}

    virtual void initialize();
protected:
};

#endif // BATTERY_HPP
