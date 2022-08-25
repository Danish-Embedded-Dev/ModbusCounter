#ifdef MODBUS_COUNTER

/**
    update modbus holding and input register with eeprom store variable
*/

void update_counter(void) {
  //put some data into the registers

  //add coil register
  //  regBank.set(1, 1);           //no coil status used in this module
  //  regBank.set(2, 1);

  //input status register
  //  regBank.set(10001, 1);      //no input status used in this module
  //  regBank.set(10002, 1);


  //adding holding register
  regBank.set(40001, running_val.device_id);
  regBank.set(40002, running_val.mod_config);
  regBank.set(40003, running_val.mod_baud);
  regBank.set(40004, running_val.net_timeout);

  //adding input register
  regBank.set(30011, running_val.count_1a);
  regBank.set(30012, running_val.count_1b);
  regBank.set(30013, running_val.count_1c);
  regBank.set(30014, 4);
  regBank.set(30015, 5);

  regBank.set(30021, running_val.count_2a);
  regBank.set(30022, running_val.count_2b);
  regBank.set(30023, running_val.count_2c);
  regBank.set(30024, 4);
  regBank.set(30025, 5);

}

/**
    Sets up input/output digital pin
*/
void Config_IO(void) {
  pinMode(INPUT_1, INPUT_PULLUP);
  pinMode(INPUT_2, INPUT_PULLUP);
  pinMode(Run_LED, OUTPUT);
}

/**
    if user modify the configuration variable then save value to EEPROM
    @Returns if eeprom update then true else false
*/
bool update_holdingReg() {
  bool _update = false ;

  //update device id if change by  modbus master
  if (running_val.device_id != _device->get(40001)) {
    running_val.device_id = _device->get(40001);
    EE.eeprom_write_Int(_ADDR_DeviceId, int(running_val.device_id));
    _update = true;
  }

  //update modbus configuration if change by  modbus master
  if (running_val.mod_config != _device->get(40002)) {
    switch (_device->get(40002)) {
      case 0:
        // set to SERIAL wordlenght = 8 parity = none stop bits = 1
        running_val.mod_config = SERIAL_8N1;
        regBank.set(40002, SERIAL_8N1);
        break;
      case 32:
        // set to SERIAL wordlenght = 8 parity = none stop bits = 2
        running_val.mod_config = SERIAL_8N2;
        regBank.set(40002, SERIAL_8N2);
        break;
      case 8:
        // set to SERIAL wordlenght = 9 parity = none stop bits = 1
        running_val.mod_config = SERIAL_9N1;
        regBank.set(40002, SERIAL_9N1);
        break;
      case 40:
        // set to SERIAL wordlenght = 9 parity = none stop bits = 2
        running_val.mod_config = SERIAL_9N2;
        regBank.set(40002, SERIAL_9N2);
        break;
      case 10:
        // set to SERIAL wordlenght = 8 parity = even stop bits = 1
        running_val.mod_config = SERIAL_8E1;
        regBank.set(40002, SERIAL_8E1);
        break;
      case 42:
        // set to SERIAL wordlenght = 8 parity = even stop bits = 2
        running_val.mod_config = SERIAL_8E2;
        regBank.set(40002, SERIAL_8E2);
        break;
      case 11:
        // set to SERIAL wordlenght = 8 parity = old stop bits = 1
        running_val.mod_config = SERIAL_8O1;
        regBank.set(40002, SERIAL_8O1);
        break;
      case 43:
        // set to SERIAL wordlenght = 8 parity = old stop bits = 2
        running_val.mod_config = SERIAL_8O2;
        regBank.set(40002, SERIAL_8O2);
        break;  
      default: //use if master modbus enter wrong data
        // set to SERIAL wordlenght = 8 parity = none stop bits = 1
        regBank.set(40002, SERIAL_8N1);
    }

    EE.eeprom_write_Int(_ADDR_Mod_Config, running_val.mod_config);
    _update = true;
  }

  //update modbus baud rate if change by  modbus master
  if (running_val.mod_baud != _device->get(40003)) {
    switch (_device->get(40003)) {
      case 1:
        // set to 2400 baud
        running_val.mod_baud = 2400;
        regBank.set(40003, 2400);
        break;
      case 2:
        // set to 4800 baud
        running_val.mod_baud = 4800;
        regBank.set(40003, 4800);
        break;
      case 3:
        // set to 9600 baud
        running_val.mod_baud = 9600;
        regBank.set(40003, 9600);
        break;
      case 4:
        // set to 19200 baud
        running_val.mod_baud = 19200;
        regBank.set(40003, 19200);
        break;
      case 5:
        // set to 38400 baud
        running_val.mod_baud = 38400;
        regBank.set(40003, 38400);
        break;
    }

    EE.eeprom_write_Int(_ADDR_Mod_Baud, running_val.mod_baud);
    _update = true;
  }

  //update network timeout if change by modbus master
  if (running_val.net_timeout != _device->get(40004)) {
    running_val.net_timeout = _device->get(40004);
    EE.eeprom_write_Int(_ADDR_Net_tmout, running_val.net_timeout);
    _update = true;
  }

  return _update;
}






#endif//MODBUS_COUNTER
