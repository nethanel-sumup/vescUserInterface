#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <gui_generated/containers/lightBase.hpp>

class light : public lightBase
{
public:
    /** Light On */
    static constexpr const int kStateOn = 0;
    /** Light Off */
    static constexpr const int kStateOff = 1;
    /** Light auto */
    static constexpr const int kStateAuto = 2;

    light();
    virtual ~light() {}

    virtual void initialize();
    virtual void SetState(int value);

protected:
    int currentState;
};

#endif // LIGHT_HPP
