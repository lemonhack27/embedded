//###########################################################################
// Description:
//! \addtogroup f2833x_example_list
//! <h1>I2C EEPROM (i2c_eeprom)</h1>
//!
//!  This program requires an external I2C EEPROM connected to
//!  the I2C bus at address 0x50. \n
//!  This program will write 1-14 words to EEPROM and read them back.
//!  The data written and the EEPROM address written to are contained
//!  in the message structure, \b I2cMsgOut1. The data read back will be
//!  contained in the message structure \b I2cMsgIn1.
//!
//!  \b Watch \b Variables \n
//!  - I2cMsgIn1
//!  - I2cMsgOut1
//
//###########################################################################
// $TI Release: F2833x/F2823x Header Files and Peripheral Examples V142 $
// $Release Date: November  1, 2016 $
// $Copyright: Copyright (C) 2007-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "AVP33x_Project.h" // Device Headerfile and Examples Include File

// Note: I2C Macros used in this example can be found in the
// DSP2833x_I2C_defines.h file

// Prototype statements for functions found within this file.
void   InitEeprom(void);
void   Eepromtest(void);
void   I2CA_Init(void);
Uint16 I2CA_WriteData(struct I2CMSG *msg);
Uint16 I2CA_ReadData(struct I2CMSG *msg);
__interrupt void i2c_int1a_isr(void);


#define I2C_SLAVE_ADDR        0x50
#define I2C_NUMBYTES          4
#define I2C_EEPROM_HIGH_ADDR  0x00
#define I2C_EEPROM_LOW_ADDR   0x30

