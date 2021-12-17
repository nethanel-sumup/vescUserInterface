#include <gui/containers/speed.hpp>

speed::speed()
{

}

void speed::initialize()
{
  speedBase::initialize();
}

void speed::SetValue(int32_t value)
{
  Unicode::snprintf(speedTextBuffer, SPEEDTEXT_SIZE, "%d", value);
}
