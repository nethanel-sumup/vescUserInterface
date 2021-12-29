#pragma once

#include <gui_generated/containers/CurrentBase.hpp>

class Current : public CurrentBase
{
public:
    Current();
    virtual ~Current() {}

    virtual void initialize();

    virtual void SetCurrent(float value);
protected:
};
