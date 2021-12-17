#include <gui/containers/battery.hpp>
#include <touchgfx/Color.hpp>

battery::battery()
{

}

void battery::initialize()
{
    batteryBase::initialize();
}

void battery::SetValue(float value)
{
	Unicode::snprintfFloat(batteryTextBuffer, BATTERYTEXT_SIZE, "%.1f", value);
	int16_t height = (kMaxFillerHeight * (((value - kMinLevel) * 100) / kWorkRange)) / 100;
	int16_t posY = kMaxFillerHeight + kMinPositionY - (height);

	if (height > kGreenZoneStart)
	{
		filler.setColor(touchgfx::Color::getColorFromRGB(0x00, 0x6A, 0xFF));
	}
	else if (height > kYellowZoneStart)
	{
		filler.setColor(touchgfx::Color::getColorFromRGB(0xFF, 0xFF, 0x00));
	}
	else if (height > kOrangeZoneStart)
	{
		filler.setColor(touchgfx::Color::getColorFromRGB(0xFF, 0x7F, 0x00));
	}
	else
	{
		filler.setColor(touchgfx::Color::getColorFromRGB(0xFF, 0x00, 0x00));
	}
	filler.setY(posY);
	filler.setHeight(height);
}
