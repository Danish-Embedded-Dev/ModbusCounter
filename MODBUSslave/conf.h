//use this file for project configuration and defination
#ifndef CONF_H_
#define CONF_H_

/*-----------BLOCK CONTROL-----------*/

#define DEBUGOUT          //use for debug msg on USB serial port
//#define Serial Serialx  //use Serialx to replicate debug to any serial port like Serial1,Serial2
#define USE_MODBUS          //use modbus protocol
#define ModSerial Serial1   //serial port selection for rs-485 module

#define WATCHDOG_ENABLE     //Enable watchdog for software reset
#define I2C_ENABLE          //Enable I2C protocol
#define USE_I2C2            //I2C Peripherals selection uncomment will automatically shift to I2C_1
#define ExEEPROM_ENABLE     //Enable external eeprom  depedent on I2C communication
#define RTC_ENABLE          //Enable RTC module depedent on I2C communication 


//------------MODULE-Selection----------
#define MODBUS_COUNTER


/*--------------GLOBAL_VAR--------------*/


//-----------BLINK_STATUS-----------
#define Network_LED PB1     //Network and MQtt
#define MQTT_PUSH_LED PB0   //packet send to cloud  


//------------EEPROM Block----------
#ifdef  ExEEPROM_ENABLE

#define EE_ADDR 0x57        //EEPROM PHYSICAL ADDRESS ON I2C COMMUNICATION LAYER 
#define EEPROM_Lenght 4095  //EEPROM max length
//#define Reserved_pvt_bytes 160
//#define PAGE_BASE_ADDR 160

//structure variable
//struct Byte_type {
//  uint32_t unix_time;
//}; Byte_type EEPROM_DATA;

struct  Default_variable {
  byte device_id = 1;       //modbus device ID 0-255
  int mod_config = SERIAL_8N1;//default is SERIAL_8N1 from core
  int mod_baud    = 9600;     //default baudrate is 9600
  int net_timeout = 60;       //60 second network timeout for event update 
  uint32_t lst_epoch_c1 = 0 ; //last event epoch time for counter 1 
  uint32_t lst_epoch_c2 = 0 ; //last event epoch time for counter 2 
  uint16_t count_1a = 0;      //use for shift A counter_1
  uint16_t count_2a = 0;      //use for shift A counter_2
  uint16_t count_1b = 0;      //use for shift B counter_2
  uint16_t count_2b = 0;      //use for shift B counter_2
  uint16_t count_1c = 0;      //use for shift C counter_2
  uint16_t count_2c = 0;      //use for shift C  counter_2
} default_val, running_val;

enum EepromPrivateAddress { 
  _ADDR_DeviceId     = 10,                    //5bytes reserved for DeviceAddres 
  _ADDR_Mod_Config     = _ADDR_DeviceId + 5,  //5bytes reserved for modbus serial mode
  _ADDR_Mod_Baud       = _ADDR_Mod_Config + 5,  //5bytes reserved for modbus serial baudrate 
  _ADDR_Net_tmout      = _ADDR_Mod_Baud   + 5,  //5bytes reserved for network timeout  
  _ADDR_L_epoch_c1     = _ADDR_Net_tmout  + 5,  //5bytes reserved for last event epoch counter 1  
  _ADDR_L_epoch_c2     = _ADDR_L_epoch_c1 + 5,  //5bytes reserved for last event epoch counter 2
  _ADDR_count_1a       = _ADDR_L_epoch_c2 + 5,  //5bytes reserved for counter_1 for shift A 
  _ADDR_count_2a       = _ADDR_count_1a   + 5,  //5bytes reserved for counter_2 for shift A
  _ADDR_count_1b       = _ADDR_count_2a   + 5,  //5bytes reserved for counter_1 for shift B 
  _ADDR_count_2b       = _ADDR_count_1b   + 5,  //5bytes reserved for counter_2 for shift B 
  _ADDR_count_1c       = _ADDR_count_2b   + 5,  //5bytes reserved for counter_1 for shift C 
  _ADDR_count_2c       = _ADDR_count_1c   + 5,  //5bytes reserved for counter_2 for shift C 
};


#endif//ExEEPROM_ENABLE


//------------------RTC-Block---------
#ifdef RTC_ENABLE
#define DS3231_I2C_ADDRESS 0x68
typedef struct  { //unix conversion parameters
  uint8_t Second;
  uint8_t Minute;
  uint8_t Hour;
  uint8_t Wday;   // day of week, sunday is day 1
  uint8_t DayOfmonth;
  uint8_t Month;
  uint8_t Year;   // offset from 1970;
} tmElements_t ;
#endif//RTC_ENABLE


//---------------SERIAL-COMMUNICATION-----------
//  SERIAL_8N1  0B00000000 || 0 //modbus Serial config mode of operation
//  SERIAL_8N2  0B00100000 || 32
//  SERIAL_9N1  0B00001000 || 8
//  SERIAL_9N2  0B00101000 || 40  
//
//  SERIAL_8E1  0B00001010 || 10
//  SERIAL_8E2  0B00101010 || 42
//  SERIAL_8O1  0B00001011 || 11
//  SERIAL_8O2  0B00101011 || 43



#ifdef DEBUGOUT    //Use USB_Serial for debug communication
#define DEBUG_BAUD 9600
#define DEBUG_PRINT_F(...)    Serial.print(F(__VA_ARGS__))
#define DEBUG_PRINTLN_F(...)  Serial.println(F(__VA_ARGS__))
#define DEBUG_PRINT(...)    Serial.print(__VA_ARGS__)
#define DEBUG_PRINTLN(...)  Serial.println(__VA_ARGS__)
#else
#define DEBUG_PRINT_F(...) //else remove the debug  feature
#define DEBUG_PRINTLN_F(...)
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#endif //DEBUGOUT  

//------------------MODULE_SLAVE-----------
#ifdef USE_MODBUS
byte *_msg,
        _len;

word _baud,
       _crc,
       _frameDelay;

#endif//USE_MODBUS

//------------------MODULE_MODBUS_COUNTER-----------
#ifdef USE_MODBUS 
//-----------INPUT Button---------
  #define INPUT_1 PA0 
  #define INPUT_2 PA1 
  #define Run_LED PC13

#endif//USE_MODBUS


//----------------------reset-status--------
uint32_t reset_cnt __attribute__ ((section (".noinit"))); //Preserve A Variable in RAM between Software Resets

#endif // CONF_H_  
