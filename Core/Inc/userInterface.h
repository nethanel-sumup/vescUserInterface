#pragma once

#include <vescLib/datatypes.h>

#ifdef __cplusplus
extern "C" {
#endif

  int ui_initialize(void);
  void ui_print_esc_values(mc_values *val);
  void ui_fill_battery(int stateOfCharge);
  void signal_vsync(void);

#ifdef __cplusplus
}
#endif
