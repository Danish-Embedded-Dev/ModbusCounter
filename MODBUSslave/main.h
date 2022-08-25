// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions

#ifndef _MODBUS_COUNTER_H
#define _MODBUS_COUNTER_H
#include "Arduino.h"
#include "conf.h"


//--------------------------------------------------
//--include watchdog Rogarclark core library--------
//--------------------------------------------------
#ifdef  WATCHDOG_ENABLE
  #include <libmaple/iwdg.h>
#endif//WATCHDOG_ENABLE




//--------------------------------------------------
//--include I2C Rogarclark core library-------------
//--------------------------------------------------
#ifdef I2C_ENABLE 
  #include <Wire.h>
  
  #ifdef USE_I2C2  //if want to use I2C2 as alternate pins for I2C communication
    TwoWire WIRE2 (2,I2C_FAST_MODE);
    #define Wire WIRE2
  #endif//USE_I2C2
  
#endif//I2C_ENABLE


//-----------------------------------------
//--include RTC Rogarclark core library-------------
//-----------------------------------------
#ifdef RTC_ENABLE
    #include <RTClock.h> 
#endif//IN_RTC_ENABLE



//-------------------------------------------------
//--include eeprom library file--------------------
//--------------------------------------------------
#ifdef  ExEEPROM_ENABLE
    #include "ExEEPROM_lib/EE_lib.h"  
    ExEEPROM EE(EE_ADDR); //eeprom instance creation
#endif//ExEEPROM_ENABLE



//----------------------------------------------------
//--include library or file related to current project
//--------------------------------------------------
#ifdef  MODBUS_COUNTER 
  #include "MB_library/modbus.h"
  #include "MB_library/modbusDevice.h"
  #include "MB_library/modbusRegBank.h" 
  //Setup the brewtrollers register bank
  //All of the data accumulated will be stored here
  modbusDevice regBank; 
  //Create the modbus slave pointer
  modbusDevice *_device;
#endif//MODBUS_COUNTER


#endif//_MODBUS_COUNTER_H
