
/* Table of CRC values for high–order byte */
const byte _auchCRCHi[] = {
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
        0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40};

/* Table of CRC values for low–order byte */
const byte _auchCRCLo[] = {
        0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
        0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
        0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
        0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
        0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
        0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
        0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
        0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
        0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
        0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
        0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
        0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
        0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
        0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
        0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
        0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
        0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
        0x40};

 
/*
Set the Serial Baud rate.
Reconfigure the UART for 8 data bits, no parity, and 1 stop bit.
and flush the serial port.
*/
void setBaud(word baud,byte SerialConfig)
{
  _baud = baud;
  //calculate the time perdiod for 3 characters for the given bps in ms.
  _frameDelay = 24000/_baud;
//  port = &Serial;
  ModSerial.begin(baud,SerialConfig);
  //ModSerial.begin(baud);
 
  ModSerial.flush();
  //ModSerial.flush();
  
}

/*
Retrieve the serial baud rate
*/
word getBaud(void)
{
  return(_baud);
}

/*
Generates the crc for the current message in the buffer.
*/

void calcCrc(void)
{
  byte  CRCHi = 0xFF,
      CRCLo = 0x0FF,
      Index,
      msgLen,
      *msgPtr;

  msgLen = _len-2;
  msgPtr = _msg;

  while(msgLen--)
  {
    Index = CRCHi ^ *msgPtr++;
    CRCHi = CRCLo ^ _auchCRCHi[Index];
    CRCLo = _auchCRCLo[Index];
  }
  _crc = (CRCHi << 8) | CRCLo;
}

/*
  Checks the UART for query data
*/
void checkSerial(void)
{
  //while there is more data in the UART than when last checked
  //while(ModSerial.available()> _len)
  while(ModSerial.available()> _len)
  {
//    Serial.println("yes");
    //update the incoming query message length
    _len = ModSerial.available();
    //Wait for 3 bytewidths of data (SOM/EOM)
//    delayMicroseconds(RTUFRAMETIME);
    delay(_frameDelay);
    //Check the UART again
  }
}

/*
Copies the contents of the UART to a buffer
*/
void serialRx(void)
{
  byte i;

  //allocate memory for the incoming query message
  _msg = (byte*) malloc(_len);

    //copy the query byte for byte to the new buffer
    for (i=0 ; i < _len ; i++)
      _msg[i] = ModSerial.read();
}

/*
Generates a query reply message for Digital In/Out status update queries.
*/
void getDigitalStatus(byte funcType, word startreg, word numregs)
{
  //initialize the bit counter to 0
  byte bitn =0;
  
  //if the function is to read digital inputs then add 10001 to the start register
  //else add 1 to the start register
  if(funcType == READ_DI)
    startreg += 10001;
  else
    startreg += 1;

  //determine the message length
  //for each group of 8 registers the message length increases by 1
  _len = numregs/8;
  //if there is at least one incomplete byte's worth of data
  //then add 1 to the message length for the partial byte.
  if(numregs%8)
    _len++;
  //allow room for the Device ID byte, Function type byte, data byte count byte, and crc word
  _len +=5;

  //allocate memory of the appropriate size for the message
  _msg = (byte *) malloc(_len);

  //write the slave device ID
  _msg[0] = _device->getId();
  //write the function type
  _msg[1] = funcType;
  //set the data byte count
  _msg[2] = _len-5;

  //For the quantity of registers queried
  while(numregs--)
  {
    //if a value is found for the current register, set bit number bitn of msg[3]
    //else clear it
    if(_device->get(startreg))
      bitSet(_msg[3], bitn);
    else
      bitClear(_msg[3], bitn);
    //increment the bit index
    bitn++;
    //increment the register
    startreg++;
  }
  
  //generate the crc for the query reply and append it
  calcCrc();
  _msg[_len - 2] = _crc >> 8;
  _msg[_len - 1] = _crc & 0xFF;
}

void getAnalogStatus(byte funcType, word startreg, word numregs)
{
  word val;
  word i = 0;

  //if the function is to read analog inputs then add 30001 to the start register
  //else add 40001 to the start register
  if(funcType == READ_AI)
    startreg += 30001;
  else
    startreg += 40001;

  //calculate the query reply message length
  //for each register queried add 2 bytes
  _len = numregs * 2;
  //allow room for the Device ID byte, Function type byte, data byte count byte, and crc word
  _len += 5;

  //allocate memory for the query response
  _msg = (byte *) malloc(_len);

  //write the device ID
  _msg[0] = _device->getId();
  //write the function type
  _msg[1] = funcType;
  //set the data byte count
  _msg[2] = _len - 5;

  //for each register queried
  while(numregs--)
  {
    //retrieve the value from the register bank for the current register
    val = _device->get(startreg+i);
    //write the high byte of the register value
    _msg[3 + i * 2]  = val >> 8;
    //write the low byte of the register value
    _msg[4 + i * 2] = val & 0xFF;
    //increment the register
    i++;
  }

  //generate the crc for the query reply and append it
  calcCrc();
  _msg[_len - 2] = _crc >> 8;
  _msg[_len - 1] = _crc & 0xFF;
}

void setStatus(byte funcType, word reg, word val)
{
  //Set the query response message length
  //Device ID byte, Function byte, Register byte, Value byte, CRC word
  _len = 8;
  //allocate memory for the message buffer.
  _msg = (byte *) malloc(_len);


  //write the device ID
  _msg[0] = _device->getId();
  //if the function type is a digital write
  if(funcType == WRITE_DO)
  {
    //Add 1 to the register value and set it's value to val
    _device->set(reg + 1, val);
    //write the function type to the response message
    _msg[1] = WRITE_DO;
  }
  else
  {
    //else add 40001 to the register and set it's value to val
    _device->set(reg + 40001, val);

    //write the function type of the response message
    _msg[1] = WRITE_AO;
  }
  
  //write the register number high byte value
  _msg[2] = reg >> 8;
  //write the register number low byte value
  _msg[3] = reg & 0xFF;
  //write the control value's high byte
  _msg[4] = val >> 8;
  //write the control value's low byte
  _msg[5] = val & 0xFF;

  //calculate the crc for the query reply and append it.
  calcCrc();
  _msg[_len - 2]= _crc >> 8;
  _msg[_len - 1]= _crc & 0xFF;
}

void modSlave_run(void)
{
// Serial.println("in run");
  byte deviceId;
  byte funcType;
  word field1;
  word field2;
  
  int i;
  
  //initialize mesasge length
  _len = 0;

  //check for data in the recieve buffer
  checkSerial();

  //if there is nothing in the recieve buffer, bail.
  if(_len == 0)
  {
    return;
  }

  //retrieve the query message from the serial uart
  serialRx();
  
  //if the message id is not 255, and
  // and device id does not match bail
  if( (_msg[0] != 0xFF) && 
    (_msg[0] != _device->getId()) )
  {
    return;
  }
  //calculate the checksum of the query message minus the checksum it came with.
  calcCrc();

  //if the checksum does not match, ignore the message
  if ( _crc != ((_msg[_len - 2] << 8) + _msg[_len - 1]))
    return;
  
  //copy the function type from the incoming query
  funcType = _msg[1];

  //copy field 1 from the incoming query
  field1  = (_msg[2] << 8) | _msg[3];

  //copy field 2 from the incoming query
  field2  = (_msg[4] << 8) | _msg[5];
  
  //free the allocated memory for the query message
  free(_msg);
  //reset the message length;
  _len = 0;

  //generate query response based on function type
  switch(funcType)
  {
  case READ_DI:
    getDigitalStatus(funcType, field1, field2);
    break;
  case READ_DO:
    getDigitalStatus(funcType, field1, field2);
    break;
  case READ_AI:
    getAnalogStatus(funcType, field1, field2);
    break;
  case READ_AO:
    getAnalogStatus(funcType, field1, field2);
    break;
  case WRITE_DO:
    setStatus(funcType, field1, field2);
    break;
  case WRITE_AO:
    setStatus(funcType, field1, field2);
    break;
  default:
    return;
    break;
  }

  //if a reply was generated
  if(_len)
  {
    int i;
    //send the reply to the serial UART
    //Senguino doesn't support a bulk serial write command....
    for(i = 0 ; i < _len ; i++)
      ModSerial.write(_msg[i]);
    //free the allocated memory for the reply message
    free(_msg);
    //reset the message length
    _len = 0;
  }
}
