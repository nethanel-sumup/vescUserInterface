#include <gui/containers/Speed.hpp>

Speed::Speed()
{

}

void Speed::initialize()
{
  SpeedBase::initialize();
}

void Speed::SetValue(int value)
{
  Unicode::snprintf(speedTextBuffer, SPEEDTEXT_SIZE, "%d", value);
}
