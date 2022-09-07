#include "main.h"


void setup()
{
 
#ifdef  WATCHDOG_ENABLE
                            iwdg_init(IWDG_PRE_256, 3500);          //setup watch-dog to 5000*0.0064 = 32000 ms                       
#endif//WATCH_ENABLE
#ifdef I2C_ENABLE
                            Wire.begin();                           //start I2C wire protocol for EEPROM and RTC
#endif//I2C_ENABLE 
#ifdef  DEBUGOUT
                            Serial.begin(DEBUG_BAUD);               //start serial communication for debugging
                            while(!Serial);  
#endif//DEBUGOUT    
#ifdef  ExEEPROM_ENABLE
                            Init_EEPROM_Var();                      //get EEPROM store parameter
#endif//ExEEPROM_ENABLE 
#ifdef  USE_MODBUS  
                            Init_Modbus_Var();
#endif//USE_MODBUS 
#ifdef  MODBUS_COUNTER
                            update_counter();
                            Config_IO();    
//                            Enable_Timer_Interrupt(running_val.debounce_tm); //Activate Timer interupt for routine task   
#endif//MODBUS_COUNTER 

}

void loop()
{
#ifdef  WATCHDOG_ENABLE
    iwdg_feed(); //Feeding watch dog
#endif//WATCH_ENABLE   
//    //put a random number into registers 1, 10001, 30001 and 40001
//    regBank.set(1, (byte) random(0, 2));
//    regBank.set(10001, (byte) random(0, 2));
//    regBank.set(30001, (word) random(0, 32767));
//    regBank.set(40001, (word) random(0, 32767));
//
//    regBank.set(2, (byte) random(0, 2));
//    regBank.set(10002, (byte) random(0, 2));
//    regBank.set(30002, (word) random(0, 32767));
//    regBank.set(40002, (word) random(0, 32767));
    input_handler(LOW);
    update_holdingReg();
    response_holdingReg();
    modSlave_run();

//long t_1 = millis();
//Serial.println(getEpoch());
//Serial.println(millis()-t_1);

}
