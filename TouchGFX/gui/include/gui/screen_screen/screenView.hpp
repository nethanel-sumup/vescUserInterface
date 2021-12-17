#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP

#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <gui/screen_screen/screenPresenter.hpp>

class screenView : public screenViewBase
{
public:
    screenView();
    virtual ~screenView() {}
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
