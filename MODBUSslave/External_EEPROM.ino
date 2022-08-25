 //---------------Setting EEPROM ----------------------
#ifdef ExEEPROM_ENABLE 

/*
 * setup the running variable from eeprom store configuation 
 */ 
void Init_EEPROM_Var() {

  EE.eeprom_connected();  //checking EEPROM is connected or not 
   


  int Temp_device_id = EE.eeprom_read_Int(_ADDR_DeviceId);
  if (Temp_device_id != -1 ) {
    running_val.device_id = byte(Temp_device_id);
  } else {
    EE.eeprom_write_Int(_ADDR_DeviceId, int(default_val.device_id));
    running_val.device_id = default_val.device_id;
  }

  int Temp_mod_config = EE.eeprom_read_Int(_ADDR_Mod_Config);
  if (Temp_mod_config != -1 ) {
    running_val.mod_config = Temp_mod_config;
  } else {
    EE.eeprom_write_Int(_ADDR_Mod_Config, default_val.mod_config);
    running_val.mod_config = default_val.mod_config;
  }

  int Temp_mod_baud = EE.eeprom_read_Int(_ADDR_Mod_Baud);
  if (Temp_mod_baud != -1 ) {
    running_val.mod_baud = Temp_mod_baud;
  } else {
    EE.eeprom_write_Int(_ADDR_Mod_Baud, default_val.mod_baud);
    running_val.mod_baud = default_val.mod_baud;
  }

  int Temp_net_timeout = EE.eeprom_read_Int(_ADDR_Net_tmout);
  if (Temp_net_timeout != -1 ) {
    running_val.net_timeout = Temp_net_timeout;
  } else {
    EE.eeprom_write_Int(_ADDR_Net_tmout, default_val.net_timeout);
    running_val.net_timeout = default_val.net_timeout;
  }

  uint32_t Temp_lst_epoch_c1 = EE.eeprom_read_Long(_ADDR_L_epoch_c1);
  if (Temp_lst_epoch_c1 != 65535 ) {
    running_val.lst_epoch_c1 = Temp_lst_epoch_c1;
  } else {
    EE.eeprom_write_Long(_ADDR_L_epoch_c1, default_val.lst_epoch_c1);
    running_val.lst_epoch_c1 = default_val.lst_epoch_c1;
  }

  uint32_t Temp_lst_epoch_c2 = EE.eeprom_read_Long(_ADDR_L_epoch_c2);
  if (Temp_lst_epoch_c2 != 65535 ) {
    running_val.lst_epoch_c2 = Temp_lst_epoch_c2;
  } else {
    EE.eeprom_write_Long(_ADDR_L_epoch_c2, default_val.lst_epoch_c2);
    running_val.lst_epoch_c2 = default_val.lst_epoch_c2;
  }

  uint16_t Temp_count_1a = EE.eeprom_read_Int(_ADDR_count_1a);
  if (Temp_count_1a != 65535 ) {
    running_val.count_1a = Temp_count_1a;
  } else {
    EE.eeprom_write_Int(_ADDR_count_1a, default_val.count_1a );
    running_val.count_1a = default_val.count_1a;
  }

  uint16_t Temp_count_2a = EE.eeprom_read_Int(_ADDR_count_2a);
  if (Temp_count_2a != 65535 ) {
    running_val.count_2a = Temp_count_2a;
  } else {
    EE.eeprom_write_Int(_ADDR_count_2a, default_val.count_2a );
    running_val.count_2a = default_val.count_2a;
  }

  uint16_t Temp_count_1b = EE.eeprom_read_Int(_ADDR_count_1b);
  if (Temp_count_1b != 65535 ) {
    running_val.count_1b = Temp_count_1b;
  } else {
    EE.eeprom_write_Int(_ADDR_count_1b, default_val.count_1b );
    running_val.count_1b = default_val.count_1b;
  }

  uint16_t Temp_count_2b = EE.eeprom_read_Int(_ADDR_count_2b);
  if (Temp_count_2b != 65535 ) {
    running_val.count_2b = Temp_count_2b;
  } else {
    EE.eeprom_write_Int(_ADDR_count_2b, default_val.count_2b );
    running_val.count_2b = default_val.count_2b;
  }

  uint16_t Temp_count_1c = EE.eeprom_read_Int(_ADDR_count_1c);
  if (Temp_count_1c != 65535 ) {
    running_val.count_1c = Temp_count_1c;
  } else {
    EE.eeprom_write_Int(_ADDR_count_1c, default_val.count_1c );
    running_val.count_1c = default_val.count_1c;
  }

  uint16_t Temp_count_2c = EE.eeprom_read_Int(_ADDR_count_2c);
  if (Temp_count_2c != 65535 ) {
    running_val.count_2c = Temp_count_2c;
  } else {
    EE.eeprom_write_Int(_ADDR_count_2c, default_val.count_2c );
    running_val.count_2c = default_val.count_2c;
  }


  //debugging window
  DEBUG_PRINTLN("------------EEPROM_Var--------------");
  DEBUG_PRINT("Device ID       :");  DEBUG_PRINTLN(Temp_device_id); 
  DEBUG_PRINT("Modbus Config   :");  DEBUG_PRINTLN(Temp_mod_config);
  DEBUG_PRINT("Modbus Baudrate :");  DEBUG_PRINTLN(Temp_mod_baud);
  DEBUG_PRINT("Network timeout :");  DEBUG_PRINTLN(Temp_net_timeout);
  DEBUG_PRINT("last epoch c_1  :");  DEBUG_PRINTLN(Temp_lst_epoch_c1);
  DEBUG_PRINT("last epoch c_2  :");  DEBUG_PRINTLN(Temp_lst_epoch_c2);
  DEBUG_PRINT("count_1a        :");  DEBUG_PRINTLN(Temp_count_1a);
  DEBUG_PRINT("count_2a        :");  DEBUG_PRINTLN(Temp_count_2a);
  DEBUG_PRINT("count_1b        :");  DEBUG_PRINTLN(Temp_count_1b);
  DEBUG_PRINT("count_2b        :");  DEBUG_PRINTLN(Temp_count_2b);
  DEBUG_PRINT("count_1c        :");  DEBUG_PRINTLN(Temp_count_1c);
  DEBUG_PRINT("count_2c        :");  DEBUG_PRINTLN(Temp_count_2c);
  delay(20); //using because data lost issue without delay
  DEBUG_PRINTLN("------------Running_Var--------------");
  DEBUG_PRINT("Device ID       :");  DEBUG_PRINTLN(running_val.device_id); 
  DEBUG_PRINT("Modbus Config   :");  DEBUG_PRINTLN(running_val.mod_config);
  DEBUG_PRINT("Modbus Baudrate :");  DEBUG_PRINTLN(running_val.mod_baud);
  DEBUG_PRINT("Network timeout :");  DEBUG_PRINTLN(running_val.net_timeout);
  DEBUG_PRINT("last epoch c_1  :");  DEBUG_PRINTLN(running_val.lst_epoch_c1);
  DEBUG_PRINT("last epoch c_2  :");  DEBUG_PRINTLN(running_val.lst_epoch_c2);
  DEBUG_PRINT("count_1a        :");  DEBUG_PRINTLN(running_val.count_1a);
  DEBUG_PRINT("count_2a        :");  DEBUG_PRINTLN(running_val.count_2a);
  DEBUG_PRINT("count_1b        :");  DEBUG_PRINTLN(running_val.count_1b);
  DEBUG_PRINT("count_2b        :");  DEBUG_PRINTLN(running_val.count_2b);
  DEBUG_PRINT("count_1c        :");  DEBUG_PRINTLN(running_val.count_1c);
  DEBUG_PRINT("count_2c        :");  DEBUG_PRINTLN(running_val.count_2c);
  delay(20);
  DEBUG_PRINTLN("------------Default_Var--------------");
  DEBUG_PRINT("Device ID       :");  DEBUG_PRINTLN(default_val.device_id); 
  DEBUG_PRINT("Modbus Config   :");  DEBUG_PRINTLN(default_val.mod_config);
  DEBUG_PRINT("Modbus Baudrate :");  DEBUG_PRINTLN(default_val.mod_baud);
  DEBUG_PRINT("Network timeout :");  DEBUG_PRINTLN(default_val.net_timeout);
  DEBUG_PRINT("last epoch c_1  :");  DEBUG_PRINTLN(default_val.lst_epoch_c1);
  DEBUG_PRINT("last epoch c_2  :");  DEBUG_PRINTLN(default_val.lst_epoch_c2);
  DEBUG_PRINT("count_1a        :");  DEBUG_PRINTLN(default_val.count_1a);
  DEBUG_PRINT("count_2a        :");  DEBUG_PRINTLN(default_val.count_2a);
  DEBUG_PRINT("count_1b        :");  DEBUG_PRINTLN(default_val.count_1b);
  DEBUG_PRINT("count_2b        :");  DEBUG_PRINTLN(default_val.count_2b);
  DEBUG_PRINT("count_1c        :");  DEBUG_PRINTLN(default_val.count_1c);
  DEBUG_PRINT("count_2c        :");  DEBUG_PRINTLN(default_val.count_2c);
  
  delay(20);
}




#endif//ExEEPROM_ENABLE
