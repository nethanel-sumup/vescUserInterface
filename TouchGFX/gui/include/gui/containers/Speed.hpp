#pragma once

#include <gui_generated/containers/SpeedBase.hpp>

class Speed : public SpeedBase
{
public:
    Speed();
    virtual ~Speed() {}

    virtual void initialize();

    virtual void SetValue(int value);
protected:
};
