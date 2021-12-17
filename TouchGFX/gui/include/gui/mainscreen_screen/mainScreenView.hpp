#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP

#include <gui/mainscreen_screen/mainScreenPresenter.hpp>
#include <gui_generated/mainscreen_screen/mainScreenViewBase.hpp>

class mainScreenView : public mainScreenViewBase
{
public:
    mainScreenView();
    virtual ~mainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void SetBatteryLevel(float level)
    {
    	battery1.SetValue(level);
    	this->invalidate();
    }
    virtual void SetSpeed(int speed)
    {
    	speed1.SetValue(speed);
    	this->invalidate();
    }
protected:

};

#endif // SCREENVIEW_HPP
