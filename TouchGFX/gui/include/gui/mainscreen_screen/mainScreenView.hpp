#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP

#include <gui/mainscreen_screen/mainScreenPresenter.hpp>
#include <gui_generated/mainscreen_screen/mainScreenViewBase.hpp>
#include <BitmapDatabase.hpp>

class mainScreenView: public mainScreenViewBase
{
  public:
    mainScreenView();

    virtual ~mainScreenView()
    {
    }

    virtual void setupScreen();

    virtual void tearDownScreen();

    virtual void SetBatteryLevel(float level)
    {
      battery1.SetValue(level);

      // force screen refresh
      invalidate();
    }

    virtual void SetSpeed(int speed)
    {
      speed1.SetValue(speed);

      // force screen refresh
      invalidate();
    }

    virtual void SetLightState(int state)
    {
      light1.SetState(state);

      // force screen refresh
      invalidate();
    }
  protected:
};

#endif // SCREENVIEW_HPP
