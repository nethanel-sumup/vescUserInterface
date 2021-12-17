#include <gui/screen_screen/screenView.hpp>
#include <gui/screen_screen/screenPresenter.hpp>

screenPresenter::screenPresenter(screenView& v)
    : view(v)
{

}

void screenPresenter::activate()
{

}

void screenPresenter::deactivate()
{

}

void screenPresenter::NotifyBatteryLevelChanged(float level)
{
	view.SetBatteryLevel(level);
}

void screenPresenter::NotifySpeedChanged(int speed)
{
	view.SetSpeed(speed);
}
