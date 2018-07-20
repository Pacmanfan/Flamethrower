#ifndef SETTINGS
#define SETTINGS
/*
  A structure to hold application variables, and to make it easier to save and load them from EEPROM
*/

struct AppVars
{
  int burst_duration; // how long to make a fireball burst last (milliseconds)
  int ignition_duration; // how long should the ignition happen for
  int burst_delay; // how long to wait between bursts
  int solenoid_pot_min; // this min value of the pot (0-1023)
  int solenoid_pot_max; // this max value of the pot (0-1023)
  int solenoid_PWM_min; // the minimum value at which the PWM will trip the solenoid (0-255)
  int solenoid_Initial_Duration; // the initial time to hold the solenoid open to make sure the valve opens prior to the rest of the PWM control
  int solenoid_acceleration; // the acceleration value of the gas flow per second (16 bit) Max change of 32.768/mS
  int maxLED; // max brightness for RGB LEDs
  int validkey; // is this valid data
};

extern AppVars pVars; // global application variables

void DefVals();
void SaveVars();
void LoadVars();
#endif
