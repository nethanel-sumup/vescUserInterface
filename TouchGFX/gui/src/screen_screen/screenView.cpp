#include <gui/screen_screen/screenView.hpp>

screenView::screenView() : counter(0)
{

}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}

void screenView::IncreaseValue()
{
	counter++;
	Unicode::snprintf(speedTextBuffer, SPEEDTEXT_SIZE, "%d", counter);
	speedText.invalidate();
}
