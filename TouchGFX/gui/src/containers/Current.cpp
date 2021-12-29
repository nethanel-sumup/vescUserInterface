#include <gui/containers/Current.hpp>

Current::Current()
{

}

void Current::initialize()
{
  CurrentBase::initialize();
}

void Current::SetCurrent(float value)
{
  Unicode::snprintfFloat(currentTextBuffer, CURRENTTEXT_SIZE, "%.2f", value);
}
