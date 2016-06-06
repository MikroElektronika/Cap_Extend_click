/****************************************************************************
* Title                 :   Cap Extend CLICK
* Filename              :   capextend_hw.h
* Author                :   CAL
* Origin Date           :   06/06/2016
* Notes                 :   Hardware layer
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date       Software Version    Initials      Description
*  06/06/2016        .1                CAL     Interface Created.
*
*****************************************************************************/
/**
 * @file capextend_hw.c
 * @brief <h3> Hardware Layer </h3>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "capextend_hw.h"
#include "capextend_hal.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/
int capextend_init( uint8_t address )
{
    if(capextend_hal_init( address ))
        return -1;
    else
        return 0;
}

uint8_t capextend_is_button_pressed( uint8_t button )
{
    uint8_t reg     = 0x01;
    uint8_t reg_2   = 0x02;
    uint8_t buffer  = 0;


    if( button >= 8 )
    {
        capextend_hal_read( &reg, &buffer, 1 );

        buffer &= ( 1 << ( button - 8) );
        if( buffer > 0 )
            return -1;
        else return 0;

    }
    else if( button > 0 && button < 8 )
    {
        capextend_hal_read( &reg_2, &buffer, 1 );

        buffer &= ( 1 << button );
        if( buffer > 0 )
            return -1;
        else return 0;

    }
    else return 0;

}

uint8_t capextend_read_msb_buttons( void )
{
    uint8_t reg = 0x01;
    uint8_t buffer = 0;

    capextend_hal_read( &reg, &buffer, 1 );

    return buffer;
}

uint8_t capextend_read_lsb_buttons( void )
{
    uint8_t reg = 0x02;
    uint8_t buffer = 0;

    capextend_hal_read( &reg, &buffer, 1 );

    return buffer;
}

uint8_t capextend_set_spm_gpio_polarity( gpio_t gpio, uint8_t polarity )
{
    uint8_t reg = BLOCK_8;
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

uint8_t capextend_spm_read_enable( void )
{
    uint8_t cfg     = SPM_CFG;
    uint8_t buffer  = 0;

    buffer = 0x18;
    capextend_hal_write( &cfg, &buffer, 1 );

    return -1;
}

uint8_t capextend_spm_write_enable( void )
{
    uint8_t cfg     = SPM_CFG;
    uint8_t buffer  = 0;

    buffer = 0x10;
    capextend_hal_write( &cfg, &buffer, 1 );

    return -1;
}

uint8_t capextend_spm_disable( void )
{
    uint8_t cfg     = SPM_CFG;
    uint8_t buffer  = 0;

    capextend_hal_write( &cfg, &buffer, 1 );

    return -1;
}

uint8_t capextend_spm_read_block( uint8_t *block, uint8_t *start_addr )
{
    uint8_t spm_add = SPM_BASE_ADDR;
         uint8_t i = 0x00;

    if( ( *start_addr % 8 ) > 0 )
        return 0;

    capextend_hal_write( &spm_add, start_addr, 1 );
        
        for( i = 0; i < 8; i++ )
            capextend_hal_read( &i, block++, 1 );

    return -1;
}

uint8_t capextend_spm_write_block( uint8_t *block , uint8_t *start_addr )
{
    uint8_t spm_add = SPM_BASE_ADDR;
         uint8_t i = 0x00;

    if( ( *start_addr % 8 ) > 0 )
        return 0;

    capextend_hal_write( &spm_add, start_addr, 1 );

    for( i = 0; i < 8; i++ )
        capextend_hal_write( &i, block++, 1 );

    return -1;
}

uint8_t capextend_spm_get_i2c_address( void )
{
    uint8_t reg = BLOCK_1;
    uint8_t block[8] = { 0 };

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    return block[4];
}

uint8_t capextend_set_spm_active_scan_period( uint8_t period )
{
    uint8_t reg = BLOCK_1;
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


uint8_t capextend_set_spm_doze_scan_period( uint8_t period )
{
    uint8_t reg = BLOCK_1;
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


uint8_t capextend_set_spm_passive_timer( uint8_t time )
{
    uint8_t reg = BLOCK_1;
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


uint8_t capextend_set_spm_cap_mode_setting( cap_sett_t setting )
{
    uint8_t reg = BLOCK_2;
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


uint8_t capextend_set_spm_cap_pin_mode( uint8_t cap, cap_mode_t mode )
{
    uint8_t reg = BLOCK_2;
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


uint8_t capextend_set_spm_cap_sensitivity( uint8_t cap, uint8_t sensitivity )
{
    uint8_t reg_1 = BLOCK_2;
    uint8_t reg_2 = BLOCK_3;
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


uint8_t capextend_set_spm_cap_threshold( uint8_t cap, uint8_t threshold )
{
    uint8_t reg_1 = BLOCK_3;
    uint8_t reg_2 = BLOCK_4;
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


uint8_t capextend_set_spm_cap_period_offset( uint8_t offset )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_cap_prox_enable( bool enable )
{
    uint8_t reg = BLOCK_14;
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


uint8_t capextend_set_spm_btn_report_cfg( btn_report_t config )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_btn_int_trigger( int_trigger_t trigger )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_btn_release_samples( btn_smpl_t samples )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_btn_touch_samples( btn_smpl_t samples )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_btn_avg_thresh( uint8_t thresh )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_btn_neg_offset_thresh( uint8_t thresh )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_smp_btn_neg_count_max( uint8_t max )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_btn_hysteresis( uint8_t hysteresis )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_btn_stuck_timeout( uint8_t timeout )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_wakeup_map_size( uint8_t size )
{
    uint8_t reg = BLOCK_6;
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


uint8_t capextend_set_spm_wakeup_value_0( uint8_t btn_1, uint8_t btn_2 )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_wakeup_value_1( uint8_t btn_1, uint8_t btn_2 )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_wakeup_value_2( uint8_t btn_1, uint8_t btn_2 )
{
    uint8_t reg = BLOCK_4;
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


uint8_t capextend_set_spm_autolight( uint8_t gpio, btn_map_t btn )
{
    uint8_t reg_1 = BLOCK_6;
    uint8_t reg_2 = BLOCK_7;
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


uint8_t capextend_set_spm_map_group_0( uint8_t btn, bool enable )
{
    uint8_t reg = BLOCK_7;
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


uint8_t capextend_set_spm_map_group_1( uint8_t btn, bool enable )
{
    uint8_t reg = BLOCK_7;
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


uint8_t capextend_set_spm_gpio_mode( uint8_t gpio, gpio_mode_t mode )
{
    uint8_t reg = BLOCK_8;
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


uint8_t capextend_set_spm_gpio_pwr_up_val( gpio_t gpio, uint8_t mode )
{
    uint8_t reg = BLOCK_8;
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


uint8_t capextend_set_spm_gpio_autolight_enable( gpio_t gpio, bool enable )
{
    uint8_t reg = BLOCK_8;
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


uint8_t capextend_set_spm_gpio_on_intensity( gpio_t gpio, uint8_t intensity )
{
    uint8_t reg_1 = BLOCK_8;
    uint8_t reg_2 = BLOCK_9;
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


uint8_t capextend_set_spm_gpio_off_intensity( gpio_t gpio, uint8_t intensity )
{
    uint8_t reg_1 = BLOCK_9;
    uint8_t reg_2 = BLOCK_10;
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


uint8_t capextend_set_spm_pwm_function( gpio_t gpio, pwm_func_t pwm )
{
    uint8_t reg = BLOCK_10;
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


uint8_t capextend_set_spm_gpio_fade_inc_factor( gpio_t gpio, fade_factor_t fade )
{
    uint8_t reg = BLOCK_10;
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


uint8_t capextend_set_spm_gpio_fade_dec_factor( gpio_t gpio, fade_factor_t fade )
{
    uint8_t reg = BLOCK_11;
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


uint8_t capextend_set_spm_gpio_fade_inc_time( uint8_t gpio, uint8_t time )
{
    uint8_t reg = BLOCK_11;
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


uint8_t capextend_set_spm_gpio_fade_dec_time( uint8_t gpio, uint8_t time )
{
    uint8_t reg_1 = BLOCK_11;
    uint8_t reg_2 = BLOCK_12;
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


uint8_t capextend_set_spm_fade_off_delay( uint8_t gpio, uint8_t delay )
{
    uint8_t reg = BLOCK_12;
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


uint8_t capextend_set_spm_pullup_pulldown( uint8_t gpio, pullup_down_t setting )
{
    uint8_t reg = BLOCK_12;
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


uint8_t capextend_set_spm_int_edge_trigger( uint8_t gpio, int_edge_t edge )
{
    uint8_t reg_1 = BLOCK_12;
    uint8_t reg_2 = BLOCK_13;
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


uint8_t capextend_set_spm_gpi_debounce_enable( gpio_t gpio, bool enable )
{
    uint8_t reg = BLOCK_13;
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


int_src_t capextend_get_int_src( void )
{
    uint8_t reg = IRQ_SRC;
    uint8_t buffer = 0;

    capextend_hal_read( &reg, &buffer, 1 );

    return buffer;
}


uint8_t capextend_get_gpio_status( gpio_t gpio )
{
    uint8_t reg = GPI_STAT;
    uint8_t buffer = 0;

    capextend_hal_read( &reg, &buffer, 1 );

    buffer &= gpio;

    if( buffer > 0 )
        return -1;
    else return 0;
}


uint8_t capextend_is_nvm_used( void )
{
    uint8_t reg = SPM_STAT;
    uint8_t buffer = 0;
    uint8_t mask = 8;

    capextend_hal_read( &reg, &buffer, 1 );

    buffer &= mask;

    if( buffer > 0 )
        return -1;
    else return 0;
}


uint8_t capextend_get_nvm_uses_count( void )
{
    uint8_t reg = SPM_STAT;
    uint8_t buffer = 0;
    uint8_t mask = 0x07;

    capextend_hal_read( &reg, &buffer, 1 );

    buffer &= mask;

    return buffer;
}


uint8_t capextend_get_comp_mode( void )
{
    uint8_t reg = COMP_OP_MODE;
    uint8_t buffer = 0;
    uint8_t mask = 4;

    capextend_hal_read( &reg, &buffer, 1 );

    buffer &= mask;

    if( buffer > 0 )
        return -1;
    else return 0;
}


op_mode_t capextend_get_op_mode( void )
{
    uint8_t reg = COMP_OP_MODE;
    int buffer = 0;
    uint8_t mask = 3;

    capextend_hal_read( &reg, &buffer, 1 );

    buffer &= mask;

    return buffer;
}


uint8_t capextend_set_gpo_pwr_autolight_off( gpio_t gpio, bool on )
{
    uint8_t reg = GPO_CTRL;
    uint8_t buffer = 0;
    uint8_t choice = 0;

    if( on )
        choice = 1;
    else choice = 0;

    capextend_hal_read( &reg, &buffer, 1 );

    buffer |= ( choice << gpio );

    capextend_hal_write( &reg, &buffer, 1 );

    return -1;
}


uint8_t capextend_set_gpp_intensity( uint8_t gpio, uint8_t intensity )
{
    uint8_t reg_1 = GPP_PIN_ID;
    uint8_t reg_2 = GPP_INTENSITY;
    uint8_t buffer = 0;

    if( gpio > 7 )
        return 0;

    buffer = gpio;
    capextend_hal_write( &reg_1, &buffer, 1 );

    buffer = intensity;
    capextend_hal_write( &reg_2, &buffer, 1 );

    return -1;
}


uint8_t capextend_software_reset( void )
{
    uint8_t reg = SOFT_RESET;
    uint8_t buffer = 0;

    buffer = 0xDE;
    capextend_hal_write( &reg, &buffer, 1 );
    buffer = 0x00;
    capextend_hal_write( &reg, &buffer, 1 );

    return -1;
}

uint8_t capextend_set_monitor_scan_period( uint8_t period )
{
    uint8_t reg = MON_SCAN_PER;
    uint8_t buffer = 0;

    buffer = period;

    capextend_spm_write_enable();
    capextend_hal_write( &reg, &buffer, 1 );
    capextend_spm_disable();

    return -1;

}

uint16_t capextend_get_real_time_data( uint8_t cap, monitor_data_t m_data )
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
            ba = CAP_RAW_BA;
            break;
        case 1:
            ba = CAP_AVG_BA;
            break;
        case 2:
            ba = CAP_DIFF_BA;
            break;
        default:
            return 0;
    }

    ba += ( cap * 2 );

    if( m_data == DIFF )
    {
        if( ba < CAP_DIFF_BLK_2 )
            reg = CAP_DIFF_BLK_1;
        else if( ba < CAP_DIFF_BLK_3 )
            reg = CAP_DIFF_BLK_2;
        else
            reg = CAP_DIFF_BLK_3;
    }
    else if( m_data == AVG )
    {
        if( ba < CAP_AVG_BLK_2 )
            reg = CAP_AVG_BLK_1;
        else if( ba < CAP_AVG_BLK_3 )
            reg = CAP_AVG_BLK_2;
        else
            reg = CAP_AVG_BLK_3;
    }
    else if( m_data == RAW )
    {
        if( ba < CAP_RAW_BLK_2 )
            reg = CAP_RAW_BLK_1;
        else if( ba < CAP_RAW_BLK_3 )
            reg = CAP_RAW_BLK_2;
        else
            reg = CAP_RAW_BLK_3;
    }

    capextend_spm_read_enable();
    capextend_spm_read_block( block, &reg );
    capextend_spm_disable();

    index = ba - reg;
    retval = ( (uint16_t)block[ index ] << 8 );
    retval |= block[ index + 1 ];

    return retval;
}

/*************** END OF FUNCTIONS *********************************************/