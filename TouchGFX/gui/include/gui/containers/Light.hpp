#pragma once

#include <gui_generated/containers/LightBase.hpp>

class Light : public LightBase
{
public:
    /** Light On */
    static constexpr const int kStateOn = 0;
    /** Light Off */
    static constexpr const int kStateOff = 1;
    /** Light auto */
    static constexpr const int kStateAuto = 2;

    Light();
    virtual ~Light() {}

    virtual void initialize();
    virtual void SetState(int value);

protected:
    int currentState;
};
