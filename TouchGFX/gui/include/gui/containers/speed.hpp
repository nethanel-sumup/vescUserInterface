#ifndef SPEED_HPP
#define SPEED_HPP

#include <gui_generated/containers/speedBase.hpp>

class speed : public speedBase
{
public:
    speed();
    virtual ~speed() {}

    virtual void initialize();

    virtual void SetValue(int32_t value);
protected:
};

#endif // SPEED_HPP
