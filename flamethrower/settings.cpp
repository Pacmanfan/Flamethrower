#include <Arduino.h>
#include "settings.h"
#include <EEPROM.h>

#define EEPROM_KEY_VALUE 345 // change this when adding to the AppVars struct

//set default values
void DefVals()
{
  pVars.burst_duration = 250;
  pVars.ignition_duration = 200;
  pVars.burst_delay = 100; // 1/10 second between bursts
  pVars.solenoid_pot_min = 0; // this min value of the pot (0-1023)
  pVars.solenoid_pot_max = 1023; // this max value of the pot (0-1023)
  pVars.solenoid_PWM_min = 220; // the minimum value at which the PWM will trip the solenoid (0-255)
  pVars.solenoid_Initial_Duration = 50; // the initial time to hold the solenoid open to make sure the valve opens prior to the rest of the PWM control
  pVars.solenoid_acceleration = 1024; // can go from 0 to full range (255) in .25 seconds at 1024  
  pVars.maxLED = 64;
  pVars.validkey = 0;
}

void SaveVars()
{
  int eeAddress = 0;
  pVars.validkey = EEPROM_KEY_VALUE;
  EEPROM.put(eeAddress, pVars);
}

void LoadVars()
{
  int eeAddress = 0;
  EEPROM.get(eeAddress, pVars);
  if (pVars.validkey != EEPROM_KEY_VALUE)
  {
    DefVals();//no data, set default vals
  }
}

