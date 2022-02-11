#include <gui/containers/Battery.hpp>
#include <touchgfx/Color.hpp>

Battery::Battery()
{

}

void Battery::initialize()
{
  BatteryBase::initialize();
}

void Battery::SetValue(float value)
{
  Unicode::snprintfFloat(batteryTextBuffer, BATTERYTEXT_SIZE, "%.1f", value);
  int16_t height = (kMaxFillerHeight * (((value - kMinLevel) * 100) / kWorkRange)) / 100;
  int16_t posY = kMaxFillerHeight + kMinPositionY - (height);

  if (height > kGreenZoneStart)
  {
    // Green zone
    filler.setColor(touchgfx::Color::getColorFromRGB(0x00, 0xFF, 0x6A));
  }
  else if (height > kYellowZoneStart)
  {
    // Yellow zone
    filler.setColor(touchgfx::Color::getColorFromRGB(0xFF, 0xFF, 0x00));
  }
  else if (height > kOrangeZoneStart)
  {
    // Orange zone
    filler.setColor(touchgfx::Color::getColorFromRGB(0xFF, 0x7F, 0x00));
  }
  else
  {
    // Red zone
    filler.setColor(touchgfx::Color::getColorFromRGB(0xFF, 0x00, 0x00));
  }
  filler.setY(posY);
  filler.setHeight(height);
}
