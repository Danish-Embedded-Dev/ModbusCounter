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
  regBank.set(40005, running_val.debounce_tm);
  regBank.set(40006, 0); //zero for normal and 1 for restart
  unsigned long rtc_time = getEpoch();
  regBank.set(40007, int((rtc_time)&0xFFFF));     //put Epoch LSB 
  regBank.set(40008, int((rtc_time>>16)&0xFFFF)); //put Epoch MSB
  
  //adding input register
  regBank.set(30011, running_val.count_1a);
  regBank.set(30012, running_val.count_1b);
  regBank.set(30013, running_val.count_1c);
  regBank.set(30014, int((running_val.lst_epoch_c1)&0xFFFF));  //put last event c_1 Epoch LSB 
  regBank.set(30015, int((running_val.lst_epoch_c1>>16)&0xFFFF));  //put last event c_1 Epoch MSB 

  regBank.set(30021, running_val.count_2a);
  regBank.set(30022, running_val.count_2b);
  regBank.set(30023, running_val.count_2c);
  regBank.set(30014, int((running_val.lst_epoch_c2)&0xFFFF));    //put last event c_2 Epoch LSB 
  regBank.set(30015, int((running_val.lst_epoch_c2>>16)&0xFFFF));  //put last event c_2 Epoch MSB 

}

/**
    Sets up input/output digital pin
*/
void Config_IO(void) {
  pinMode(INPUT_1, INPUT_PULLUP);
  pinMode(INPUT_2, INPUT_PULLUP);
  pinMode(Run_LED, OUTPUT);
  //  pinMode(O1, OUTPUT);
}

/*
   Setup timer for non blocking mqtt lost status
   interupt generate for every define tm_interval(param) ms
*/
void Enable_Timer_Interrupt(int tm_interval) {
  Timer2.setChannel1Mode(TIMER_OUTPUTCOMPARE); // setting Mode as Compare...
  Timer2.setPeriod(tm_interval * 1000); // in microseconds, after this period one Tick/Count generates...
  Timer2.setCompare1(1);                       // when value of Counter equals this value, an Interrupt is generated...
  Timer2.attachCompare1Interrupt(input_handler); // On interrupt, this fn gets called...
}

/*
 * input button state and take action on button pressed 
 * @param trigger_mode can be LOW/HIGH   
 */
void input_handler(bool trigger_mode ) {

  val_s1 = digitalRead(INPUT_1);//read input state of button_1
  val_s2 = digitalRead(INPUT_2);//read input state of button_2

 

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch_1 changed, due to noise or pressing:
  if (val_s1 != last_state_s1) {
    // reset the debouncing timer
    lastDebounceTime_1 = millis();
  }

   // If the switch_2 changed, due to noise or pressing:
  if (val_s2 != last_state_s2) {
    // reset the debouncing timer
    lastDebounceTime_2 = millis();
  }

  //switch_1 case
  if ((millis() - lastDebounceTime_1) > running_val.debounce_tm) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (val_s1 != state_s1) {
      state_s1 = val_s1;

      // only activate the function if the new button state is LOW/HIGH
      if (state_s1 == trigger_mode) {
        running_val.count_1a++;
        //        running_val.Count_1b++;
        regBank.set(30011, running_val.count_1a); //update modbus counter 1 shift A register

      }
    }
  }

  //switch_2 case
  if ((millis() - lastDebounceTime_2) > running_val.debounce_tm) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (val_s2 != state_s2) {
      state_s2 = val_s2;

      // only activate the function if the new button state is LOW/HIGH
      if (state_s2 == trigger_mode) {
        running_val.count_2a++;
        //        running_val.Count_2b++;
        regBank.set(30021, running_val.count_2a); //update modbus counter 2 shift A register


      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState of switch_2:
  last_state_s1 = val_s1;
  // save the reading. Next time through the loop, it'll be the lastButtonState of switch_2:
  last_state_s2 = val_s2; 
       
      
}

/**
    if user modify the configuration variable then save value to EEPROM
    @Returns: if eeprom update then true else false
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

  //update debouncing time if change by modbus master
  if (running_val.debounce_tm != _device->get(40005)) {
    running_val.debounce_tm = _device->get(40005);
    EE.eeprom_write_Int(_ADDR_Debounce_tm, running_val.debounce_tm);
    _update = true;
  }
 

  return _update;
}

/**
    if user modify the configuration to take action
*/
void response_holdingReg() {

  //restart the device if user input 1
  if (_device->get(40006) == 1  ) {
#ifdef  WATCHDOG_ENABLE
    iwdg_init(IWDG_PRE_256, 250 ); //watch-dog 250*0.0064 = 1600 ms
#endif//WATCH_ENABLE   

    while (1); //stuct here watchdog will get out of here from restart
  }

  
  //get current time 
  if (_device->get(40007) == 1  ) { 
    unsigned long rtc_time = getEpoch();
    regBank.set(40007, int((rtc_time)&0xFFFF));     //put Epoch LSB 
    regBank.set(40008, int((rtc_time>>16)&0xFFFF)); //put Epoch MSB
  }
  

}





#endif//MODBUS_COUNTER
