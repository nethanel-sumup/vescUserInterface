#include <userInterface.h>
#include <stdio.h>

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/hal/OSWrappers.hpp>

#ifdef __cplusplus
extern "C" {
#endif

int ui_initialize(void)
{
  return 0;
}

void signal_vsync(void)
{
	touchgfx::OSWrappers::signalVSync();
}

#ifdef __cplusplus
}
#endif
