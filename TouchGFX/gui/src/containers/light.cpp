#include <gui/containers/light.hpp>

light::light() : currentState(kStateAuto)
{
}

void light::initialize()
{
  lightBase::initialize();
}

void light::SetState(int value)
{
  // Nothing to do if current state is already up-to-date
  if (value == currentState)
  {
    return;
  }

  switch (value)
  {
    case kStateOn:
      lightImage.setVisible(true);
      lightText.setVisible(false);
      break;

    case kStateOff:
      lightImage.setVisible(false);
      lightText.setVisible(false);
      break;

    case kStateAuto:
      lightImage.setVisible(true);
      lightText.setVisible(true);
      break;

    default:
      return;
  }

  currentState = value;
}
