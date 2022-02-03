#include <gui/containers/DistanceCounter.hpp>

DistanceCounter::DistanceCounter()
{

}

void DistanceCounter::initialize()
{
    DistanceCounterBase::initialize();
}

void DistanceCounter::SetValue(float value)
{
  if (value < 0)
  {
    return;
  }
  if (value > kMaxValue)
  {
    value = kMaxValue;
  }
  Unicode::snprintfFloat(distanceTextBuffer, DISTANCETEXT_SIZE, "%.1f", value);
}
