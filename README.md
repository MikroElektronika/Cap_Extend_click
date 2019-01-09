![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Cap_Extend Click

- **CIC Prefix**  : CAPEXTEND
- **Author**      : MikroE Team
- **Verison**     : 1.0.0
- **Date**        : feb 2018.

---

### Software Support

We provide a library for the Cap_Extend Click on our [LibStock](https://libstock.mikroe.com/projects/view/1804/cap-extend-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library cover all functionalities of the module. It carries specific functions for each important feature of the click board.

Key functions :

- ``` int8_t capextend_is_button_pressed(uint8_t button) ``` - Check is button pressed
- ``` int8_t capextend_set_spm_cap_threshold( uint8_t cap, uint8_t threshold ) ``` - Cap Extend SPM CAP Threshold
- ``` int8_t capextend_set_spm_cap_sensitivity( uint8_t cap, uint8_t sensitivity ) ``` - Cap Extend SPM CAP Sensitivity

**Examples Description**


The application is composed of three sections :

- System Initialization - GPIO and I2C module initialization
- Application Initialization - Click driver initialization
- Application Task - Detects the state of all 12 capacitive buttons and displays their state via UART.
Operation is repeated each one second.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1804/cap-extend-click) page.

mikroE Libraries used in the example:

- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
