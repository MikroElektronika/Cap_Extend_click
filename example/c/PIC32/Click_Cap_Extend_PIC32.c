/*
Example for Cap_Extend Click

    Date          : feb 2018.
    Author        : MikroE Team

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---
Description :

The application is composed of three sections :

- System Initialization - GPIO and I2C module initialization
- Application Initialization - Click driver  initialization
- Application Task - Program detects the state of all 12 capacitive buttons
 and displays their state via UART


*/

#include "Click_Cap_Extend_types.h"
#include "Click_Cap_Extend_config.h"


uint8_t msb;
uint8_t lsb;
char text[20];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_CAPEXTEND_I2C_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_ms( 100 );
    
}

void applicationInit()
{
     capextend_i2cDriverInit( (T_CAPEXTEND_P)&_MIKROBUS1_GPIO, (T_CAPEXTEND_P)&_MIKROBUS1_I2C, 0x2B );
}

void applicationTask()
{
    msb = capextend_read_msb_buttons();
    lsb = capextend_read_lsb_buttons();
    ByteToHex(lsb,text);
    mikrobus_logWrite("Hex representation of lsb: ",_LOG_TEXT);
    mikrobus_logWrite(text,_LOG_LINE);
    ByteToHex(msb,text);
    mikrobus_logWrite("Hex representation of msb: ",_LOG_TEXT);
    mikrobus_logWrite(text,_LOG_LINE);
    Delay_ms(1000);
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
    	applicationTask();
    }
}