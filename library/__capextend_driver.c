/*
    __capextend_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__capextend_driver.h"
#include "__capextend_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __CAPEXTEND_DRV_I2C__
static uint8_t _slaveAddress;
#endif


//SPM Registers
const uint8_t _CAPEXTEND_SPM_CFG            =  0x0D;
const uint8_t _CAPEXTEND_SPM_BASE_ADDR      =  0x0E;
const uint8_t _CAPEXTEND_SPM_KEY_MSB        =  0xAC;
const uint8_t _CAPEXTEND_SPM_KEY_LSB        =  0xAD;
    //Blocks for SPM
const uint8_t _CAPEXTEND_BLOCK_1                =  0x00;
const uint8_t _CAPEXTEND_BLOCK_2                =  0x08;
const uint8_t _CAPEXTEND_BLOCK_3                =  0x10;
const uint8_t _CAPEXTEND_BLOCK_4                =  0x20;
const uint8_t _CAPEXTEND_BLOCK_5                =  0x28;
const uint8_t _CAPEXTEND_BLOCK_6                =  0x30;
const uint8_t _CAPEXTEND_BLOCK_7                =  0x38;
const uint8_t _CAPEXTEND_BLOCK_8                =  0x40;
const uint8_t _CAPEXTEND_BLOCK_9                =  0x48;
const uint8_t _CAPEXTEND_BLOCK_10               =  0x50;
const uint8_t _CAPEXTEND_BLOCK_11               =  0x58;
const uint8_t _CAPEXTEND_BLOCK_12               =  0x60;
const uint8_t _CAPEXTEND_BLOCK_13               =  0x68;
const uint8_t _CAPEXTEND_BLOCK_14               =  0x70;
const uint8_t _CAPEXTEND_BLOCK_15               =  0x78;

//I2C Registers
const uint8_t _CAPEXTEND_IRQ_SRC            =   0x00;
const uint8_t _CAPEXTEND_CAP_STAT_MSB       =   0x01;
const uint8_t _CAPEXTEND_CAP_STAT_LSB       =   0x02;
const uint8_t _CAPEXTEND_GPI_STAT           =   0x07;
const uint8_t _CAPEXTEND_SPM_STAT           =   0x08;
const uint8_t _CAPEXTEND_COMP_OP_MODE       =   0x09;
const uint8_t _CAPEXTEND_GPO_CTRL           =   0x0A;
const uint8_t _CAPEXTEND_GPP_PIN_ID         =   0x0B;
const uint8_t _CAPEXTEND_GPP_INTENSITY      =   0x0C;
const uint8_t _CAPEXTEND_SOFT_RESET         =   0xB1;
const uint8_t _CAPEXTEND_MON_SCAN_PER       =   0xF9;

//Real Time Monitoring addresses
const uint8_t _CAPEXTEND_CAP_DIFF_BA        =   0xB4;
const uint8_t _CAPEXTEND_CAP_RAW_BA         =   0x80;
const uint8_t _CAPEXTEND_CAP_AVG_BA         =   0x9A;

//Real Time Monitoring Blocks
const uint8_t _CAPEXTEND_CAP_DIFF_BLK_1     =   0xB4;
const uint8_t _CAPEXTEND_CAP_DIFF_BLK_2     =   0xBC;
const uint8_t _CAPEXTEND_CAP_DIFF_BLK_3     =   0xC4;

const uint8_t _CAPEXTEND_CAP_AVG_BLK_1      =   0x80;
const uint8_t _CAPEXTEND_CAP_AVG_BLK_2      =   0x88;
const uint8_t _CAPEXTEND_CAP_AVG_BLK_3      =   0x90;

const uint8_t _CAPEXTEND_CAP_RAW_BLK_1      =   0x9A;
const uint8_t _CAPEXTEND_CAP_RAW_BLK_2      =   0xA2;
const uint8_t _CAPEXTEND_CAP_RAW_BLK_3      =   0xAA;


const uint8_t _CAPEXTEND_GPIO_0             =   0x00;
const uint8_t _CAPEXTEND_GPIO_1             =   0x01;
const uint8_t _CAPEXTEND_GPIO_2             =   0x02;
const uint8_t _CAPEXTEND_GPIO_3             =   0x03;
const uint8_t _CAPEXTEND_GPIO_4             =   0x04;
const uint8_t _CAPEXTEND_GPIO_5             =   0x05;
const uint8_t _CAPEXTEND_GPIO_6             =   0x06;
const uint8_t _CAPEXTEND_GPIO_7             =   0x07;
const uint8_t _CAPEXTEND_GPIO_ALL           =   0x08;
const uint8_t _CAPEXTEND_COMMON_SETTINGS    =   0x01;
const uint8_t _CAPEXTEND_INDIVIDUAL_SETTINGS =  0x04;
const uint8_t _CAPEXTEND_DISABLED           =   0x00;
const uint8_t _CAPEXTEND_BUTTON             =   0x01;
const uint8_t _CAPEXTEND_MULTI_TOUCH        =   0x00;
const uint8_t _CAPEXTEND_SINGLE_TOUCH       =   0x01;
const uint8_t _CAPEXTEND_INT_MASKED         =   0x00;
const uint8_t _CAPEXTEND_INT_TOUCH          =   0x01;
const uint8_t _CAPEXTEND_INT_RELEASE        =   0x02;    
const uint8_t _CAPEXTEND_INT_BOTH_TR        =   0x03;
const uint8_t _CAPEXTEND_SMPL_0             =   0x00;
const uint8_t _CAPEXTEND_SMPL_2             =   0x01;
const uint8_t _CAPEXTEND_SMPL_3             =   0x02;      
const uint8_t _CAPEXTEND_SMPL_4             =   0x03;
const uint8_t _CAPEXTEND_BTN_0              =   0x00;
const uint8_t _CAPEXTEND_BTN_1              =   0x01;              
const uint8_t _CAPEXTEND_BTN_2              =   0x02;              
const uint8_t _CAPEXTEND_BTN_3              =   0x03;              
const uint8_t _CAPEXTEND_BTN_4              =   0x04;              
const uint8_t _CAPEXTEND_BTN_5              =   0x05;              
const uint8_t _CAPEXTEND_BTN_6              =   0x06;              
const uint8_t _CAPEXTEND_BTN_7              =   0x07;              
const uint8_t _CAPEXTEND_BTN_8              =   0x08;              
const uint8_t _CAPEXTEND_BTN_9              =   0x09;              
const uint8_t _CAPEXTEND_BTN_10             =   0x0A;
const uint8_t _CAPEXTEND_BTN_11             =   0x0B;
const uint8_t _CAPEXTEND_GROUP_0            =   0x0C;
const uint8_t _CAPEXTEND_GROUP_1            =   0x0D;
const uint8_t _CAPEXTEND_GPO                =   0x00;
const uint8_t _CAPEXTEND_GPP                =   0x01;   
const uint8_t _CAPEXTEND_GPI                =   0x02;
const uint8_t _CAPEXTEND_LOG                =   0x00;
const uint8_t _CAPEXTEND_LIN                =   0x01;
const uint8_t _CAPEXTEND_EVERY_TIME         =   0x00;
const uint8_t _CAPEXTEND_EVERY_16           =   0x01;
const uint8_t _CAPEXTEND_NONE               =   0x00;
const uint8_t _CAPEXTEND_PULLUP             =   0x01;
const uint8_t _CAPEXTEND_PULLDOWN           =   0x02;
const uint8_t _CAPEXTEND_NO_INT             =   0x00;
const uint8_t _CAPEXTEND_RISING             =   0x01;
const uint8_t _CAPEXTEND_FALLING            =   0x02;
const uint8_t _CAPEXTEND_BOTH               =   0x03;
const uint8_t _CAPEXTEND_OP_MODE_INT        =   0x01;
const uint8_t _CAPEXTEND_COMP_INT           =   0x02;
const uint8_t _CAPEXTEND_BUTTON_INT         =   0x04;
const uint8_t _CAPEXTEND_GPI_INT            =   0x10;
const uint8_t _CAPEXTEND_SPM_INT            =   0x20;
const uint8_t _CAPEXTEND_NVM_INT            =   0x40;
const uint8_t _CAPEXTEND_ACTIVE_MODE        =   0x00; 
const uint8_t _CAPEXTEND_DOZE_MODE          =   0x01;
const uint8_t _CAPEXTEND_SLEEP_MODE         =   0x02;
const uint8_t _CAPEXTEND_RAW                =   0x00;
const uint8_t _CAPEXTEND_AVG                =   0x01;
const uint8_t _CAPEXTEND_DIFF               =   0x02;




/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

void capextend_hal_write( uint8_t *command, uint8_t *buffer,uint16_t count );
void capextend_hal_read( uint8_t *command,uint8_t *buffer,uint16_t count );


/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */
void capextend_hal_write( uint8_t command, uint8_t buffer,uint16_t count )
{
    uint8_t temp[2];

    temp[0] = command;
    temp[1] = buffer;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,temp,2,END_MODE_STOP);
}

void capextend_hal_read( uint8_t command,uint8_t *buffer,uint16_t count )
{    
    uint8_t temp[1];
    uint8_t *dataPtr;
    
    dataPtr = buffer;
    temp[0] = command;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,temp,1,END_MODE_RESTART);
    hal_i2cRead(_slaveAddress,dataPtr,1,END_MODE_STOP);

}
/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __CAPEXTEND_DRV_SPI__

void capextend_spiDriverInit(T_CAPEXTEND_P gpioObj, T_CAPEXTEND_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __CAPEXTEND_DRV_I2C__

void capextend_i2cDriverInit(T_CAPEXTEND_P gpioObj, T_CAPEXTEND_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_rstSet(0);
    Delay_100ms();
    hal_gpio_rstSet(1);
    Delay_100ms();

}

#endif
#ifdef   __CAPEXTEND_DRV_UART__

void capextend_uartDriverInit(T_CAPEXTEND_P gpioObj, T_CAPEXTEND_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void capextend_gpioDriverInit(T_CAPEXTEND_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */


int8_t capextend_spm_read_enable( void )
{
    uint8_t cfg     = _CAPEXTEND_SPM_CFG;
    uint8_t buffer  = 0;

    buffer = 0x18;
    capextend_hal_write( cfg, buffer, 1 );

    return -1;
}
int8_t capextend_spm_read_block( uint8_t *block, uint8_t *start_addr )
{
    uint8_t spm_add = _CAPEXTEND_SPM_BASE_ADDR;
         uint8_t i = 0x00;

    if( ( *start_addr % 8 ) > 0 )
        return 0;

    capextend_hal_write( spm_add, start_addr, 1 );

        for( i = 0; i < 8; i++ )
            capextend_hal_read( i, block++, 1 );

    return -1;
}

int8_t capextend_spm_disable( void )
{
    uint8_t cfg     = _CAPEXTEND_SPM_CFG;
    uint8_t buffer  = 0;

    capextend_hal_write( cfg, buffer, 1 );

    return -1;
}

int8_t capextend_spm_write_enable( void )
{
    uint8_t cfg     = _CAPEXTEND_SPM_CFG;
    uint8_t buffer  = 0;

    buffer = 0x10;
    capextend_hal_write( cfg, buffer, 1 );

    return -1;
}

int8_t capextend_spm_write_block( uint8_t *block , uint8_t *start_addr )
{
    uint8_t spm_add = _CAPEXTEND_SPM_BASE_ADDR;
         uint8_t i = 0x00;

    if( ( *start_addr % 8 ) > 0 )
        return 0;

    capextend_hal_write( spm_add, start_addr, 1 );

    for( i = 0; i < 8; i++ )
        capextend_hal_write( i, block++, 1 );

    return -1;
}

int8_t capextend_is_button_pressed( uint8_t button )
{
    uint8_t reg     = 0x01;
    uint8_t reg_2   = 0x02;
    uint8_t buffer  = 0;


    if( button >= 8 )
    {
        capextend_hal_read( reg, &buffer, 1 );

        buffer &= ( 1 << ( button - 8) );
        if( buffer > 0 )
            return -1;
        else return 0;

    }
    else if( button > 0 && button < 8 )
    {
        capextend_hal_read( reg_2, &buffer, 1 );

        buffer &= ( 1 << button );
        if( buffer > 0 )
            return -1;
        else return 0;

    }
    else return 0;

}

int8_t capextend_read_msb_buttons( void )
{
    uint8_t reg = 0x01;
    uint8_t buffer = 0;

    capextend_hal_read( reg, &buffer, 1 );

    return buffer;
}

int8_t capextend_read_lsb_buttons( void )
{
    uint8_t reg = 0x02;
    uint8_t buffer = 0;

    capextend_hal_read( reg, &buffer, 1 );

    return buffer;
}

int8_t capextend_set_spm_gpio_polarity( uint8_t gpio, uint8_t polarity )
{
    uint8_t reg = _CAPEXTEND_BLOCK_8;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    if( polarity > 1 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    if( gpio == 8 )
    {
        if( polarity == 0 )
            buffer = 0;
        else
            buffer = 0xFF;
    }
    else
        buffer |= ( polarity << gpio );

    block[4] = buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}




int8_t capextend_spm_get_i2c_address( void )
{
    uint8_t reg = _CAPEXTEND_BLOCK_1;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    return block[4];
}

int8_t capextend_set_spm_active_scan_period( uint8_t period )
{
    uint8_t reg = _CAPEXTEND_BLOCK_1;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    buffer = period;
    block[5] = buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_doze_scan_period( uint8_t period )
{
    uint8_t reg = _CAPEXTEND_BLOCK_1;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    buffer = period;
    block[6] = buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_passive_timer( uint8_t time )
{
    uint8_t reg = _CAPEXTEND_BLOCK_1;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    buffer = time;
    block[7] = buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_cap_mode_setting( uint8_t setting )
{
    uint8_t reg = _CAPEXTEND_BLOCK_2;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    buffer = setting;
    block[1] = buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_cap_pin_mode( uint8_t cap, uint8_t mode )
{
    uint8_t reg = _CAPEXTEND_BLOCK_2;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( cap )
    {
        case 0:
            buffer = mode;
            break;
        case 1:
            buffer = ( mode << 2 );
            break;
        case 2:
            buffer = ( mode << 4 );
            break;
        case 3:
            buffer = ( mode << 6 );
            break;
        case 4:
            buffer = mode;
            break;
        case 5:
            buffer = ( mode << 2 );
            break;
        case 6:
            buffer = ( mode << 4 );
            break;
        case 7:
            buffer = ( mode << 6 );
            break;
        case 8:
            buffer = mode;
            break;
        case 9:
            buffer = ( mode << 2 );
            break;
        case 10:
            buffer = ( mode << 4 );
            break;
        case 11:
            buffer = ( mode << 6 );
            break;
        default:
            return 0;
    }
    if( cap > 7 )
    {
        block[2] |= buffer;
    }
    else if( cap > 3 && cap < 8 )
    {
        block[3] |= buffer;
    }
    else if( cap < 4 )
    {
        block[4] |= buffer;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_cap_sensitivity( uint8_t cap, uint8_t sensitivity )
{
    uint8_t reg_1 = _CAPEXTEND_BLOCK_2;
    uint8_t reg_2 = _CAPEXTEND_BLOCK_3;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    if( cap > 7 )
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_2 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_1 );
        capextend_spm_disable();
    }

    if( sensitivity > 15 )
        return 0;

    switch( cap )
    {
        case 0:
            buffer = ( sensitivity << 4 );
            break;
        case 1:
            buffer = sensitivity;
            break;
        case 2:
            buffer = ( sensitivity << 4 );
            break;
        case 3:
            buffer = sensitivity;
            break;
        case 4:
            buffer = ( sensitivity << 4 );
            break;
        case 5:
            buffer = sensitivity;
            break;
        case 6:
            buffer = ( sensitivity << 4 );
            break;
        case 7:
            buffer = sensitivity;
            break;
        case 8:
            buffer = ( sensitivity << 4 );
            break;
        case 9:
            buffer = sensitivity;
            break;
        case 10:
            buffer = ( sensitivity << 4 );
            break;
        case 11:
            buffer = sensitivity;
            break;
        default:
            return 0;
    }

    if( cap > 9 )
    {
        block[2] |= buffer;
    }
    else if( cap > 7 )
    {
        block[1] |= buffer;
    }
    else if( cap > 5 )
    {
        block[0] |= buffer;
    }
    else if( cap > 3 )
    {
        block[7] |= buffer;
    }
    else if( cap > 1 )
    {
        block[6] |= buffer;
    }
    else
    {
        block[5] |= buffer;
    }

    if( cap > 7 )
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_2 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_1 );
        capextend_spm_disable();
    }

    return -1;
}


int8_t capextend_set_spm_cap_threshold( uint8_t cap, uint8_t threshold )
{
    uint8_t reg_1 = _CAPEXTEND_BLOCK_3;
    uint8_t reg_2 = _CAPEXTEND_BLOCK_4;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    if( cap < 5 )
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_2 );
        capextend_spm_disable();
    }

    buffer = threshold;

    switch( cap )
    {
        case 0:
            block[3] |= buffer;
            break;
        case 1:
            block[4] |= buffer;
            break;
        case 2:
            block[5] |= buffer;
            break;
        case 3:
            block[6] |= buffer;
            break;
        case 4:
            block[7] |= buffer;
            break;
        case 5:
            block[0] |= buffer;
            break;
        case 6:
            block[1] |= buffer;
            break;
        case 7:
            block[2] |= buffer;
            break;
        case 8:
            block[3] |= buffer;
            break;
        case 9:
            block[4] |= buffer;
            break;
        case 10:
            block[5] |= buffer;
            break;
        case 11:
            block[6] |= buffer;
            break;
        default:
            return 0;
    }

    if( cap < 5 )
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_2 );
        capextend_spm_disable();
    }

    return -1;
}


int8_t capextend_set_spm_cap_period_offset( uint8_t offset )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    if( offset > 15 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[7] = offset;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_cap_prox_enable( uint8_t enable )
{
    uint8_t reg = _CAPEXTEND_BLOCK_14;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    if( enable )
        block[1] = 0x74;
    else
        block[1] = 0x46;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_report_cfg( uint8_t config )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    buffer = ( config << 6 );
    block[1] |= buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_int_trigger( uint8_t trigger )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    buffer = ( trigger << 4 );
    block[1] |= buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_release_samples( uint8_t samples )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    buffer = ( samples << 2 );
    block[1] |= buffer;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_touch_samples( uint8_t samples )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[1] |= samples;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_avg_thresh( uint8_t thresh )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[2] |= thresh;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_neg_offset_thresh( uint8_t thresh )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[3] |= thresh;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_smp_btn_neg_count_max( uint8_t max )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    if( max == 0 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[4] |= max;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_hysteresis( uint8_t hysteresis )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    if( hysteresis > 0x64 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[5] |= hysteresis;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_btn_stuck_timeout( uint8_t timeout )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[6] |= timeout;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_wakeup_map_size( uint8_t size )
{
    uint8_t reg = _CAPEXTEND_BLOCK_6;
    uint8_t block[8] = { 0 };

    if( size > 7 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[3] |= size;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_wakeup_value_0( uint8_t btn_1, uint8_t btn_2 )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    if( btn_1 > 0x0C || btn_2 > 0x0C )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[4] = ( btn_1 << 4 );
    block[4] |= btn_2;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_wakeup_value_1( uint8_t btn_1, uint8_t btn_2 )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    if( btn_1 > 0x0C || btn_2 > 0x0C )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[5] = ( btn_1 << 4 );
    block[5] |= btn_2;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_wakeup_value_2( uint8_t btn_1, uint8_t btn_2 )
{
    uint8_t reg = _CAPEXTEND_BLOCK_4;
    uint8_t block[8] = { 0 };

    if( btn_1 > 0x0C || btn_2 > 0x0C )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    block[6] = ( btn_1 << 4 );
    block[6] |= btn_2;

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_autolight( uint8_t gpio, uint8_t btn )
{
    uint8_t reg_1 = _CAPEXTEND_BLOCK_6;
    uint8_t reg_2 = _CAPEXTEND_BLOCK_7;
    uint8_t buffer = 0;
    uint8_t block[8] = { 0 };

    if( gpio > 5 )
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_2 );
        capextend_spm_disable();
    }

    switch( gpio )
    {
        case 0:
            buffer = btn;
            block[2] |= buffer;
            break;
        case 1:
            buffer = ( btn << 4 );
            block[2] |= buffer;
            break;
        case 2:
            buffer = btn;
            block[1] |= buffer;
            break;
        case 3:
            buffer = ( btn << 4 );
            block[1] |= buffer;
            break;
        case 4:
            buffer = btn;
            block[0] |= buffer;
            break;
        case 5:
            buffer = ( btn << 4 );
            block[0] |= buffer;
            break;
        case 6:
            buffer = btn;
            block[7] |= buffer;
            break;
        case 7:
            buffer = ( btn << 4 );
            block[7] |= buffer;
            break;
        default:
            return 0;
    }

    if( gpio  > 5 )
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_2 );
        capextend_spm_disable();
    }

    return -1;
}


int8_t capextend_set_spm_map_group_0( uint8_t btn, uint8_t enable )
{
    uint8_t reg = _CAPEXTEND_BLOCK_7;
    uint8_t block[8] = { 0 };
    uint8_t choice = 0;

    if( btn > 11 )
        return 0;

    if( enable )
        choice = 1;
    else
        choice = 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( btn )
    {
        case 0:
            block[4] |= choice;
            break;
        case 1:
            block[4] |= ( choice << btn );
            break;
        case 2:
            block[4] |= ( choice << btn );
            break;
        case 3:
            block[4] |= ( choice << btn );
            break;
        case 4:
            block[4] |= ( choice << btn );
            break;
        case 5:
            block[4] |= ( choice << btn );
            break;
        case 6:
            block[4] |= ( choice << btn );
            break;
        case 7:
            block[4] |= ( choice << btn );
            break;
        case 8:
            block[3] |= choice;
            break;
        case 9:
            block[3] |= ( choice << 1 );
            break;
        case 10:
            block[3] |= ( choice << 2 );
            break;
        case 11:
            block[3] |= ( choice << 3 );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_map_group_1( uint8_t btn, uint8_t enable )
{
    uint8_t reg = _CAPEXTEND_BLOCK_7;
    uint8_t block[8] = { 0 };
    uint8_t choice = 0;

    if( btn > 11 )
        return 0;

    if( enable )
        choice = 1;
    else
        choice = 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( btn )
    {
        case 0:
            block[6] |= choice;
            break;
        case 1:
            block[6] |= ( choice << btn );
            break;
        case 2:
            block[6] |= ( choice << btn );
            break;
        case 3:
            block[6] |= ( choice << btn );
            break;
        case 4:
            block[6] |= ( choice << btn );
            break;
        case 5:
            block[6] |= ( choice << btn );
            break;
        case 6:
            block[6] |= ( choice << btn );
            break;
        case 7:
            block[6] |= ( choice << btn );
            break;
        case 8:
            block[5] |= choice;
            break;
        case 9:
            block[5] |= ( choice << 1 );
            break;
        case 10:
            block[5] |= ( choice << 2 );
            break;
        case 11:
            block[5] |= ( choice << 3 );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_mode( uint8_t gpio, uint8_t mode )
{
    uint8_t reg = _CAPEXTEND_BLOCK_8;
    uint8_t block[8] = { 0 };

    if( gpio > 7 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( gpio )
    {
        case 0:
            block[1] |= mode;
            break;
        case 1:
            block[1] |= ( mode << 2 );
            break;
        case 2:
            block[1] |= ( mode << 4 );
            break;
        case 3:
            block[1] |= ( mode << 6 );
            break;
        case 4:
            block[0] |= mode;
            break;
        case 5:
            block[0] |= ( mode << 2 );
            break;
        case 6:
            block[0] |= ( mode << 4 );
            break;
        case 7:
            block[0] |= ( mode << 6 );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_pwr_up_val( uint8_t gpio, uint8_t mode )
{
    uint8_t reg = _CAPEXTEND_BLOCK_8;
    uint8_t block[8] = { 0 };

    if( gpio > 7 || mode > 1 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( gpio )
    {
        case 0:
            block[2] |= mode;
            break;
        case 1:
            block[2] |= ( mode << gpio );
            break;
        case 2:
            block[2] |= ( mode << gpio );
            break;
        case 3:
            block[2] |= ( mode << gpio );
            break;
        case 4:
            block[2] |= ( mode << gpio );
            break;
        case 5:
            block[2] |= ( mode << gpio );
            break;
        case 6:
            block[2] |= ( mode << gpio );
            break;
        case 7:
            block[2] |= ( mode << gpio );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_autolight_enable( uint8_t gpio, uint8_t enable )
{
    uint8_t reg = _CAPEXTEND_BLOCK_8;
    uint8_t block[8] = { 0 };
    uint8_t choice = 0;

    if( gpio > 7 )
        return 0;

    if( enable )
        choice = 1;
    else
        choice = 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( gpio )
    {
        case 0:
            block[3] |= choice;
            break;
        case 1:
            block[3] |= ( choice << gpio );
            break;
        case 2:
            block[3] |= ( choice << gpio );
            break;
        case 3:
            block[3] |= ( choice << gpio );
            break;
        case 4:
            block[3] |= ( choice << gpio );
            break;
        case 5:
            block[3] |= ( choice << gpio );
            break;
        case 6:
            block[3] |= ( choice << gpio );
            break;
        case 7:
            block[3] |= ( choice << gpio );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_on_intensity( uint8_t gpio, uint8_t intensity )
{
    uint8_t reg_1 = _CAPEXTEND_BLOCK_8;
    uint8_t reg_2 = _CAPEXTEND_BLOCK_9;
    uint8_t block[8] = { 0 };

    if( gpio < 3 )
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_2 );
        capextend_spm_disable();
    }

    switch( gpio )
    {
        case 0:
            block[5] = intensity;
            break;
        case 1:
            block[6] = intensity;
            break;
        case 2:
            block[7] = intensity;
            break;
        case 3:
            block[0] = intensity;
            break;
        case 4:
            block[1] = intensity;
            break;
        case 5:
            block[2] = intensity;
            break;
        case 6:
            block[3] = intensity;
            break;
        case 7:
            block[4] = intensity;
            break;
        default:
            return 0;
    }

    if( gpio < 3 )
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_2 );
        capextend_spm_disable();
    }

    return -1;
}


int8_t capextend_set_spm_gpio_off_intensity( uint8_t gpio, uint8_t intensity )
{
    uint8_t reg_1 = _CAPEXTEND_BLOCK_9;
    uint8_t reg_2 = _CAPEXTEND_BLOCK_10;
    uint8_t block[8] = { 0 };

    if( gpio < 3 )
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_2 );
        capextend_spm_disable();
    }

    switch( gpio )
    {
        case 0:
            block[5] = intensity;
            break;
        case 1:
            block[6] = intensity;
            break;
        case 2:
            block[7] = intensity;
            break;
        case 3:
            block[0] = intensity;
            break;
        case 4:
            block[1] = intensity;
            break;
        case 5:
            block[2] = intensity;
            break;
        case 6:
            block[3] = intensity;
            break;
        case 7:
            block[4] = intensity;
            break;
        default:
            return 0;
    }

    if( gpio < 3 )
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_2 );
        capextend_spm_disable();
    }

    return -1;
}


int8_t capextend_set_spm_pwm_function( uint8_t gpio, uint8_t pwm )
{
    uint8_t reg = _CAPEXTEND_BLOCK_10;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( gpio )
    {
        case 0:
            block[6] |= pwm;
            break;
        case 1:
            block[6] |= ( pwm << gpio );
            break;
        case 2:
            block[6] |= ( pwm << gpio );
            break;
        case 3:
            block[6] |= ( pwm << gpio );
            break;
        case 4:
            block[6] |= ( pwm << gpio );
            break;
        case 5:
            block[6] |= ( pwm << gpio );
            break;
        case 6:
            block[6] |= ( pwm << gpio );
            break;
        case 7:
            block[6] |= ( pwm << gpio );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_fade_inc_factor( uint8_t gpio, uint8_t fade )
{
    uint8_t reg = _CAPEXTEND_BLOCK_10;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( gpio )
    {
        case 0:
            block[7] |= fade;
            break;
        case 1:
            block[7] |= ( fade << gpio );
            break;
        case 2:
            block[7] |= ( fade << gpio );
            break;
        case 3:
            block[7] |= ( fade << gpio );
            break;
        case 4:
            block[7] |= ( fade << gpio );
            break;
        case 5:
            block[7] |= ( fade << gpio );
            break;
        case 6:
            block[7] |= ( fade << gpio );
            break;
        case 7:
            block[7] |= ( fade << gpio );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_fade_dec_factor( uint8_t gpio, uint8_t fade )
{
    uint8_t reg = _CAPEXTEND_BLOCK_11;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( gpio )
    {
        case 0:
            block[0] |= fade;
            break;
        case 1:
            block[0] |= ( fade << gpio );
            break;
        case 2:
            block[0] |= ( fade << gpio );
            break;
        case 3:
            block[0] |= ( fade << gpio );
            break;
        case 4:
            block[0] |= ( fade << gpio );
            break;
        case 5:
            block[0] |= ( fade << gpio );
            break;
        case 6:
            block[0] |= ( fade << gpio );
            break;
        case 7:
            block[0] |= ( fade << gpio );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_fade_inc_time( uint8_t gpio, uint8_t time )
{
    uint8_t reg = _CAPEXTEND_BLOCK_11;
    uint8_t block[8] = { 0 };

    if( time > 15 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    switch( gpio )
    {
        case 0:
            block[4] |= time;
            break;
        case 1:
            block[4] |= ( time << 4 );
            break;
        case 2:
            block[3] |= time;
            break;
        case 3:
            block[3] |= ( time << 4 );
            break;
        case 4:
            block[2] |= time;
            break;
        case 5:
            block[2] |= ( time << 4 );
            break;
        case 6:
            block[1] |= time;
            break;
        case 7:
            block[1] |= ( time << 4 );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_gpio_fade_dec_time( uint8_t gpio, uint8_t time )
{
    uint8_t reg_1 = _CAPEXTEND_BLOCK_11;
    uint8_t reg_2 = _CAPEXTEND_BLOCK_12;
    uint8_t block[8] = { 0 };

    if( gpio > 7 || time > 15 )
        return 0;

    if( gpio > 1 )
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_2 );
        capextend_spm_disable();
    }

    switch( gpio )
    {
        case 0:
            block[0] |= time;
            break;
        case 1:
            block[0] |= ( time << 4 );
            break;
        case 2:
            block[7] |= time;
            break;
        case 3:
            block[7] |= ( time << 4 );
            break;
        case 4:
            block[6] |= time;
            break;
        case 5:
            block[6] |= ( time << 4 );
            break;
        case 6:
            block[5] |= time;
            break;
        case 7:
            block[5] |= ( time << 4 );
            break;
        default:
            return 0;
    }

    if( gpio > 1 )
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_2 );
        capextend_spm_disable();
    }

    return -1;
}


int8_t capextend_set_spm_fade_off_delay( uint8_t gpio, uint8_t delay )
{
    uint8_t reg = _CAPEXTEND_BLOCK_12;
    uint8_t block[8] = { 0 };

    if( gpio > 7 || delay > 15 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();


    switch( gpio )
    {
        case 0:
            block[4] |= delay;
            break;
        case 1:
            block[4] |= ( delay << 4 );
            break;
        case 2:
            block[3] |= delay;
            break;
        case 3:
            block[3] |= ( delay << 4 );
            break;
        case 4:
            block[2] |= delay;
            break;
        case 5:
            block[2] |= ( delay << 4 );
            break;
        case 6:
            block[1] |= delay;
            break;
        case 7:
            block[1] |= ( delay << 4 );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_pullup_pulldown( uint8_t gpio, uint8_t setting )
{
    uint8_t reg = _CAPEXTEND_BLOCK_12;
    uint8_t block[8] = { 0 };

    if( gpio > 7 )
        return 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();


    switch( gpio )
    {
        case 0:
            block[6] |= setting;
            break;
        case 1:
            block[6] |= ( setting << 2 );
            break;
        case 2:
            block[6] |= ( setting << 4 );
            break;
        case 3:
            block[6] |= ( setting << 6 );
            break;
        case 4:
            block[5] |= setting;
            break;
        case 5:
            block[5] |= ( setting << 2 );
            break;
        case 6:
            block[5] |= ( setting << 4 );
            break;
        case 7:
            block[5] |= ( setting << 6 );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_set_spm_int_edge_trigger( uint8_t gpio, uint8_t edge )
{
    uint8_t reg_1 = _CAPEXTEND_BLOCK_12;
    uint8_t reg_2 = _CAPEXTEND_BLOCK_13;
    uint8_t block[8] = { 0 };

    if( gpio > 7 )
        return 0;

    if( gpio > 3 )
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_read_enable();
        capextend_spm_read_block( block, &reg_2 );
        capextend_spm_disable();
    }

    switch( gpio )
    {
        case 0:
            block[0] |= edge;
            break;
        case 1:
            block[0] |= ( edge << 2 );
            break;
        case 2:
            block[0] |= ( edge << 4 );
            break;
        case 3:
            block[0] |= ( edge << 6 );
            break;
        case 4:
            block[7] |= edge;
            break;
        case 5:
            block[7] |= ( edge << 2 );
            break;
        case 6:
            block[7] |= ( edge << 4 );
            break;
        case 7:
            block[7] |= ( edge << 6 );
            break;
        default:
            return 0;
    }

    if( gpio > 3 )
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_1 );
        capextend_spm_disable();
    }
    else
    {
        capextend_spm_write_enable();
        capextend_spm_write_block( block, &reg_2 );
        capextend_spm_disable();
    }

    return -1;
}


int8_t capextend_set_spm_gpi_debounce_enable( uint8_t gpio, uint8_t enable )
{
    uint8_t reg = _CAPEXTEND_BLOCK_13;
    uint8_t block[8] = { 0 };
    uint8_t choice = 0;

    if( enable )
        choice = 1;
    else
        choice = 0;

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();


    switch( gpio )
    {
        case 0:
            block[1] |= choice;
            break;
        case 1:
            block[1] |= ( choice << gpio );
            break;
        case 2:
            block[1] |= ( choice << gpio );
            break;
        case 3:
            block[1] |= ( choice << gpio );
            break;
        case 4:
            block[1] |= ( choice << gpio );
            break;
        case 5:
            block[1] |= ( choice << gpio );
            break;
        case 6:
            block[1] |= ( choice << gpio );
            break;
        case 7:
            block[1] |= ( choice << gpio );
            break;
        default:
            return 0;
    }

    capextend_spm_write_enable();
    capextend_spm_write_block( block, &reg );
    capextend_spm_disable();

    return -1;
}


int8_t capextend_get_int_src( void )
{
    uint8_t reg = _CAPEXTEND_IRQ_SRC;
    uint8_t buffer = 0;

    capextend_hal_read( reg, &buffer, 1 );

    return buffer;
}


int8_t capextend_get_gpio_status( uint8_t gpio )
{
    uint8_t reg = _CAPEXTEND_GPI_STAT;
    uint8_t buffer = 0;

    capextend_hal_read( reg, &buffer, 1 );

    buffer &= gpio;

    if( buffer > 0 )
        return -1;
    else return 0;
}


int8_t capextend_is_nvm_used( void )
{
    uint8_t reg = _CAPEXTEND_SPM_STAT;
    uint8_t buffer = 0;
    uint8_t mask = 8;

    capextend_hal_read( reg, &buffer, 1 );

    buffer &= mask;

    if( buffer > 0 )
        return -1;
    else return 0;
}


int8_t capextend_get_nvm_uses_count( void )
{
    uint8_t reg = _CAPEXTEND_SPM_STAT;
    uint8_t buffer = 0;
    uint8_t mask = 0x07;

    capextend_hal_read( reg, &buffer, 1 );

    buffer &= mask;

    return buffer;
}


int8_t capextend_get_comp_mode( void )
{
    uint8_t reg = _CAPEXTEND_COMP_OP_MODE;
    uint8_t buffer = 0;
    uint8_t mask = 4;

    capextend_hal_read( reg, &buffer, 1 );

    buffer &= mask;

    if( buffer > 0 )
        return -1;
    else return 0;
}


int8_t capextend_get_op_mode( void )
{
    uint8_t reg = _CAPEXTEND_COMP_OP_MODE;
    int buffer = 0;
    uint8_t mask = 3;

    capextend_hal_read( reg, &buffer, 1 );

    buffer &= mask;

    return buffer;
}


int8_t capextend_set_gpo_pwr_autolight_off( uint8_t gpio, uint8_t on )
{
    uint8_t reg = _CAPEXTEND_GPO_CTRL;
    uint8_t buffer = 0;
    uint8_t choice = 0;

    if( on )
        choice = 1;
    else choice = 0;

    capextend_hal_read( reg, &buffer, 1 );

    buffer |= ( choice << gpio );

    capextend_hal_write( reg, buffer, 1 );

    return -1;
}


int8_t capextend_set_gpp_intensity( uint8_t gpio, uint8_t intensity )
{
    uint8_t reg_1 = _CAPEXTEND_GPP_PIN_ID;
    uint8_t reg_2 = _CAPEXTEND_GPP_INTENSITY;
    uint8_t buffer = 0;

    if( gpio > 7 )
        return 0;

    buffer = gpio;
    capextend_hal_write( reg_1, buffer, 1 );

    buffer = intensity;
    capextend_hal_write( reg_2, buffer, 1 );

    return -1;
}


int8_t capextend_software_reset( void )
{
    uint8_t reg = _CAPEXTEND_SOFT_RESET;
    uint8_t buffer = 0;

    buffer = 0xDE;
    capextend_hal_write( reg, buffer, 1 );
    buffer = 0x00;
    capextend_hal_write( reg, buffer, 1 );

    return -1;
}

int8_t capextend_set_monitor_scan_period( uint8_t period )
{
    uint8_t reg = _CAPEXTEND_MON_SCAN_PER;
    uint8_t buffer = 0;

    buffer = period;

    capextend_spm_write_enable();
    capextend_hal_write( reg, buffer, 1 );
    capextend_spm_disable();

    return -1;

}

uint16_t capextend_get_real_time_data( uint8_t cap, uint8_t m_data )
{
    uint8_t block[8]    = { 0 };    //Block to use for reading
    uint8_t ba          = 0;        //Base address
    uint8_t reg         = 0;        //Register to read ( block )
    uint8_t index       = 0;        //Index where MSB of cap data is
    uint16_t retval     = 0;        //Return value

    if( cap > 11 )
        return 0;

    switch( m_data )
    {
        case 0:
            ba = _CAPEXTEND_CAP_RAW_BA;
            break;
        case 1:
            ba = _CAPEXTEND_CAP_AVG_BA;
            break;
        case 2:
            ba = _CAPEXTEND_CAP_DIFF_BA;
            break;
        default:
            return 0;
    }

    ba += ( cap * 2 );

    if( m_data == _CAPEXTEND_DIFF )
    {
        if( ba < _CAPEXTEND_CAP_DIFF_BLK_2 )
            reg = _CAPEXTEND_CAP_DIFF_BLK_1;
        else if( ba < _CAPEXTEND_CAP_DIFF_BLK_3 )
            reg = _CAPEXTEND_CAP_DIFF_BLK_2;
        else
            reg = _CAPEXTEND_CAP_DIFF_BLK_3;
    }
    else if( m_data == _CAPEXTEND_AVG )
    {
        if( ba < _CAPEXTEND_CAP_AVG_BLK_2 )
            reg = _CAPEXTEND_CAP_AVG_BLK_1;
        else if( ba < _CAPEXTEND_CAP_AVG_BLK_3 )
            reg = _CAPEXTEND_CAP_AVG_BLK_2;
        else
            reg = _CAPEXTEND_CAP_AVG_BLK_3;
    }
    else if( m_data == _CAPEXTEND_RAW )
    {
        if( ba < _CAPEXTEND_CAP_RAW_BLK_2 )
            reg = _CAPEXTEND_CAP_RAW_BLK_1;
        else if( ba < _CAPEXTEND_CAP_RAW_BLK_3 )
            reg = _CAPEXTEND_CAP_RAW_BLK_2;
        else
            reg = _CAPEXTEND_CAP_RAW_BLK_3;
    }

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    index = ba - reg;
    retval = ( (uint16_t)block[ index ] << 8 );
    retval |= block[ index + 1 ];

    return retval;
}





/* -------------------------------------------------------------------------- */
/*
  __capextend_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */