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

void ui_print_esc_values(mc_values *val)
{
//  printf("Input voltage: %.2f V\r\n", val->v_in);
//  printf("Temp:          %.2f degC\r\n", val->temp_mos);
//  printf("Current motor: %.2f A\r\n", val->current_motor);
//  printf("Current in:    %.2f A\r\n", val->current_in);
//  printf("RPM:           %.1f RPM\r\n", val->rpm);
//  printf("Duty cycle:    %.1f %%\r\n", val->duty_now * 100.0);
//  printf("Ah Drawn:      %.4f Ah\r\n", val->amp_hours);
//  printf("Ah Regen:      %.4f Ah\r\n", val->amp_hours_charged);
//  printf("Wh Drawn:      %.4f Wh\r\n", val->watt_hours);
//  printf("Wh Regen:      %.4f Wh\r\n", val->watt_hours_charged);
//  printf("Tacho:         %i counts\r\n", val->tachometer);
//  printf("Tacho ABS:     %i counts\r\n", val->tachometer_abs);
//  printf("Fault Code:    %s\r\n", bldc_interface_fault_to_string(val->fault_code));
}

void signal_vsync(void)
{
	touchgfx::OSWrappers::signalVSync();
}

#ifdef __cplusplus
}
#endif
