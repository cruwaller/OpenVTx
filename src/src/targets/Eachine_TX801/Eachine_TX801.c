#include "targets.h"
#include "common.h"
#include "openVTxEEPROM.h"
#include "rtc6705.h"
#include <Arduino.h>

void rfPowerAmpPinSetup(void)
{
  // pinMode(POWER_AMP_1, INPUT);
  // pinMode(POWER_AMP_2, INPUT);
  // pinMode(POWER_AMP_3, INPUT);
  // pinMode(POWER_AMP_4, INPUT);
  // pinMode(POWER_AMP_5, INPUT);

  // pinMode(POWER_AMP_1, OUTPUT);
  // pinMode(POWER_AMP_2, OUTPUT);
  // pinMode(POWER_AMP_3, OUTPUT);
  // pinMode(POWER_AMP_4, OUTPUT);
  // pinMode(POWER_AMP_5, OUTPUT);
  // pinMode(POWER_AMP_6, OUTPUT);
}

uint8_t powerValuesGet(uint8_t * const list)
{
  uint8_t cnt = 0;
  if (list) {
    list[cnt++] = 0;
    list[cnt++] = 14; // 25mW
    list[cnt++] = 20; // 100mW
    list[cnt++] = 23; // 200mW
  }
  return cnt;
}

void setPowermW(uint16_t power)
{
  uint8_t pinOutput = 0;

  switch (power)
  {
  case 0:
    pinOutput = 1; // Setting to 0 does not reduce power for some reason :|
    myEEPROM.currPowerIndex = 0;
    myEEPROM.currPowermW = 0;
    myEEPROM.currPowerdB = 0;
    break;
  case 25:
    pinOutput = 18;
    myEEPROM.currPowerIndex = 1;
    myEEPROM.currPowermW = 25;
    myEEPROM.currPowerdB = 14;
    break;
  case 100:
    pinOutput = 50;
    myEEPROM.currPowerIndex = 2;
    myEEPROM.currPowermW = 100;
    myEEPROM.currPowerdB = 20;
    break;
  case 200:
    pinOutput = 63;
    myEEPROM.currPowerIndex = 3;
    myEEPROM.currPowermW = 200;
    myEEPROM.currPowerdB = 23;
    break;
  default:
    return; // power value not recognised and no change
    break;
  }

  if (pitMode)
  {
    pinOutput = 1; // Setting to 0 does not reduce power for some reason :|
    rtc6705PowerAmpOff();
  }
  else
  {
    rtc6705PowerAmpOn();
  }

  // digitalWrite(POWER_AMP_1, pinOutput & 0b000001);
  // digitalWrite(POWER_AMP_2, pinOutput & 0b000010);
  // digitalWrite(POWER_AMP_3, pinOutput & 0b000100);
  // digitalWrite(POWER_AMP_4, pinOutput & 0b001000);
  // digitalWrite(POWER_AMP_5, pinOutput & 0b010000);
  // digitalWrite(POWER_AMP_6, pinOutput & 0b100000);

}


void taget_setup(void)
{
}


void taget_loop(void)
{
}
