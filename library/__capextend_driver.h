/*
    __capextend_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __capextend_driver.h
@brief    Cap_Extend Driver
@mainpage Cap_Extend Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   CAPEXTEND
@brief      Cap_Extend Click Driver
@{

| Global Library Prefix | **CAPEXTEND** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **feb 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _CAPEXTEND_H_
#define _CAPEXTEND_H_

/** 
 * @macro T_CAPEXTEND_P
 * @brief Driver Abstract type 
 */
#define T_CAPEXTEND_P    const uint8_t*

/** @defgroup CAPEXTEND_COMPILE Compilation Config */              /** @{ */

//  #define   __CAPEXTEND_DRV_SPI__                            /**<     @macro __CAPEXTEND_DRV_SPI__  @brief SPI driver selector */
   #define   __CAPEXTEND_DRV_I2C__                            /**<     @macro __CAPEXTEND_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __CAPEXTEND_DRV_UART__                           /**<     @macro __CAPEXTEND_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup CAPEXTEND_VAR Variables */                           /** @{ */
//SPM Registers
extern const uint8_t _CAPEXTEND_SPM_CFG           ;
extern const uint8_t _CAPEXTEND_SPM_BASE_ADDR     ;
extern const uint8_t _CAPEXTEND_SPM_KEY_MSB       ;
extern const uint8_t _CAPEXTEND_SPM_KEY_LSB       ;
    //Blocks for SPM
extern const uint8_t _CAPEXTEND_BLOCK_1                ;
extern const uint8_t _CAPEXTEND_BLOCK_2                ;
extern const uint8_t _CAPEXTEND_BLOCK_3                ;
extern const uint8_t _CAPEXTEND_BLOCK_4                ;
extern const uint8_t _CAPEXTEND_BLOCK_5                ;
extern const uint8_t _CAPEXTEND_BLOCK_6                ;
extern const uint8_t _CAPEXTEND_BLOCK_7                ;
extern const uint8_t _CAPEXTEND_BLOCK_8                ;
extern const uint8_t _CAPEXTEND_BLOCK_9                ;
extern const uint8_t _CAPEXTEND_BLOCK_10               ;
extern const uint8_t _CAPEXTEND_BLOCK_11               ;
extern const uint8_t _CAPEXTEND_BLOCK_12               ;
extern const uint8_t _CAPEXTEND_BLOCK_13               ;
extern const uint8_t _CAPEXTEND_BLOCK_14               ;
extern const uint8_t _CAPEXTEND_BLOCK_15               ;

//I2C Registers
extern const uint8_t _CAPEXTEND_IRQ_SRC         ;
extern const uint8_t _CAPEXTEND_CAP_STAT_MSB    ;
extern const uint8_t _CAPEXTEND_CAP_STAT_LSB    ;
extern const uint8_t _CAPEXTEND_GPI_STAT        ;
extern const uint8_t _CAPEXTEND_SPM_STAT        ;
extern const uint8_t _CAPEXTEND_COMP_OP_MODE    ;
extern const uint8_t _CAPEXTEND_GPO_CTRL        ;
extern const uint8_t _CAPEXTEND_GPP_PIN_ID      ;
extern const uint8_t _CAPEXTEND_GPP_INTENSITY   ;
extern const uint8_t _CAPEXTEND_SOFT_RESET      ;
extern const uint8_t _CAPEXTEND_MON_SCAN_PER    ;

//Real Time Monitoring addresses
extern const uint8_t _CAPEXTEND_CAP_DIFF_BA     ;
extern const uint8_t _CAPEXTEND_CAP_RAW_BA      ;
extern const uint8_t _CAPEXTEND_CAP_AVG_BA      ;

//Real Time Monitoring Blocks
extern const uint8_t _CAPEXTEND_CAP_DIFF_BLK_1   ;
extern const uint8_t _CAPEXTEND_CAP_DIFF_BLK_2   ;
extern const uint8_t _CAPEXTEND_CAP_DIFF_BLK_3   ;

extern const uint8_t _CAPEXTEND_CAP_AVG_BLK_1    ;
extern const uint8_t _CAPEXTEND_CAP_AVG_BLK_2    ;
extern const uint8_t _CAPEXTEND_CAP_AVG_BLK_3    ;

extern const uint8_t _CAPEXTEND_CAP_RAW_BLK_1    ;
extern const uint8_t _CAPEXTEND_CAP_RAW_BLK_2    ;
extern const uint8_t _CAPEXTEND_CAP_RAW_BLK_3    ;


extern const uint8_t _CAPEXTEND_GPIO_0            ;
extern const uint8_t _CAPEXTEND_GPIO_1            ;
extern const uint8_t _CAPEXTEND_GPIO_2            ;
extern const uint8_t _CAPEXTEND_GPIO_3            ;
extern const uint8_t _CAPEXTEND_GPIO_4            ;
extern const uint8_t _CAPEXTEND_GPIO_5            ;
extern const uint8_t _CAPEXTEND_GPIO_6            ;
extern const uint8_t _CAPEXTEND_GPIO_7            ;
extern const uint8_t _CAPEXTEND_GPIO_ALL          ;
extern const uint8_t _CAPEXTEND_COMMON_SETTINGS   ;
extern const uint8_t _CAPEXTEND_INDIVIDUAL_SETTING;
extern const uint8_t _CAPEXTEND_DISABLED          ;
extern const uint8_t _CAPEXTEND_BUTTON            ;
extern const uint8_t _CAPEXTEND_MULTI_TOUCH       ;
extern const uint8_t _CAPEXTEND_SINGLE_TOUCH      ;
extern const uint8_t _CAPEXTEND_INT_MASKED        ;
extern const uint8_t _CAPEXTEND_INT_TOUCH         ;
extern const uint8_t _CAPEXTEND_INT_RELEASE       ;    
extern const uint8_t _CAPEXTEND_INT_BOTH_TR       ;
extern const uint8_t _CAPEXTEND_SMPL_0            ;
extern const uint8_t _CAPEXTEND_SMPL_2            ;
extern const uint8_t _CAPEXTEND_SMPL_3            ;      
extern const uint8_t _CAPEXTEND_SMPL_4            ;
extern const uint8_t _CAPEXTEND_BTN_0             ;
extern const uint8_t _CAPEXTEND_BTN_1             ;              
extern const uint8_t _CAPEXTEND_BTN_2             ;              
extern const uint8_t _CAPEXTEND_BTN_3             ;              
extern const uint8_t _CAPEXTEND_BTN_4             ;              
extern const uint8_t _CAPEXTEND_BTN_5             ;              
extern const uint8_t _CAPEXTEND_BTN_6             ;              
extern const uint8_t _CAPEXTEND_BTN_7             ;              
extern const uint8_t _CAPEXTEND_BTN_8             ;              
extern const uint8_t _CAPEXTEND_BTN_9             ;              
extern const uint8_t _CAPEXTEND_BTN_10            ;
extern const uint8_t _CAPEXTEND_BTN_11            ;
extern const uint8_t _CAPEXTEND_GROUP_0           ;
extern const uint8_t _CAPEXTEND_GROUP_1           ;
extern const uint8_t _CAPEXTEND_GPO               ;
extern const uint8_t _CAPEXTEND_GPP               ;   
extern const uint8_t _CAPEXTEND_GPI               ;
extern const uint8_t _CAPEXTEND_LOG               ;
extern const uint8_t _CAPEXTEND_LIN               ;
extern const uint8_t _CAPEXTEND_EVERY_TIME        ;
extern const uint8_t _CAPEXTEND_EVERY_16          ;
extern const uint8_t _CAPEXTEND_NONE              ;
extern const uint8_t _CAPEXTEND_PULLUP            ;
extern const uint8_t _CAPEXTEND_PULLDOWN          ;
extern const uint8_t _CAPEXTEND_NO_INT            ;
extern const uint8_t _CAPEXTEND_RISING            ;
extern const uint8_t _CAPEXTEND_FALLING           ;
extern const uint8_t _CAPEXTEND_BOTH              ;
extern const uint8_t _CAPEXTEND_OP_MODE_INT       ;
extern const uint8_t _CAPEXTEND_COMP_INT          ;
extern const uint8_t _CAPEXTEND_BUTTON_INT        ;
extern const uint8_t _CAPEXTEND_GPI_INT           ;
extern const uint8_t _CAPEXTEND_SPM_INT           ;
extern const uint8_t _CAPEXTEND_NVM_INT           ;
extern const uint8_t _CAPEXTEND_ACTIVE_MODE       ; 
extern const uint8_t _CAPEXTEND_DOZE_MODE         ;
extern const uint8_t _CAPEXTEND_SLEEP_MODE        ;
extern const uint8_t _CAPEXTEND_RAW               ;
extern const uint8_t _CAPEXTEND_AVG               ;
extern const uint8_t _CAPEXTEND_DIFF              ;


                                                                       /** @} */
/** @defgroup CAPEXTEND_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup CAPEXTEND_INIT Driver Initialization */              /** @{ */

#ifdef   __CAPEXTEND_DRV_SPI__
void capextend_spiDriverInit(T_CAPEXTEND_P gpioObj, T_CAPEXTEND_P spiObj);
#endif
#ifdef   __CAPEXTEND_DRV_I2C__
void capextend_i2cDriverInit(T_CAPEXTEND_P gpioObj, T_CAPEXTEND_P i2cObj, uint8_t slave);
#endif
#ifdef   __CAPEXTEND_DRV_UART__
void capextend_uartDriverInit(T_CAPEXTEND_P gpioObj, T_CAPEXTEND_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void capextend_gpioDriverInit(T_CAPEXTEND_P gpioObj);
                                                                       /** @} */
/** @defgroup CAPEXTEND_FUNC Driver Functions */                   /** @{ */




/**
 * @brief <h3> Cap Extend is Button Pressed </h3>
 *
 * @param button    -   Button to be checked
 *
 * @retval uint8_t  -   -1: Button pressed 0: Button not pressed
 */
int8_t capextend_is_button_pressed( uint8_t button );

/**
 * @brief <h3> Cap Extend Read MSB Buttons </h3>
 * Buttons 8-12
 *
 * @retval uint8_t  -   Buttons Pressed
 */
int8_t capextend_read_msb_buttons( void );

/**
 * @brief <h3> Cap Extend Read LSB Buttons </h3>
 * Buttons 0-7
 *
 * @retval uint8_t  -   Buttons Pressed
 */
int8_t capextend_read_lsb_buttons( void );

/**
 * @brief <h3> Cap Extend SPM GPIO Polarity </h3>
 *
 * @param gpio      -   GPIO to be changed
 * @param polarity  -   Polarity
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_polarity( uint8_t gpio, uint8_t polarity );

/**
 * @brief <h3> Cap Extend SPM Read Enable </h3>
 *  Enables reading of SPM memory regions
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_spm_read_enable(void );

/**
 * @brief <h3> Cap Extend SPM Write Enable </h3>
 *  Enables writing of SPM memory regions
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_spm_write_enable(void );

/**
 * @brief <h3> Cap Extend SPM Disable </h3>
 *  Disables use of SPM memory regions
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_spm_disable( void );

/**
 * @brief <h3> Cap Extend SPM Read Block </h3>
 *
 * @param block       -   Block buffer to read from
 * @param start_addr  -   Start address of block in spm
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_spm_read_block(uint8_t *block , uint8_t *start_addr);

/**
 * @brief <h3> Cap Extend SPM Write Block </h3>
 *
 * @param block       -   Block buffer to write from
 * @param start_addr  -   Start address of block in spm
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_spm_write_block(uint8_t *block , uint8_t *start_addr);

/**
 * @brief <h3> Cap Extend SPM Get I2C address </h3>
 *  Gets the I2C slave address
 *
 * @retval uint8_t  -   I2C Address
 */
int8_t capextend_spm_get_i2c_address( void );

/**
 * @brief <h3> Cap Extend SPM Active Scan Period </h3>
 *
 * @param period    -   Active Scan Period
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_active_scan_period( uint8_t period );

/**
 * @brief <h3> Cap Extend SPM Doze Scan Period </h3>
 *
 * @param period    -   Doze Scan Period
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_doze_scan_period( uint8_t period );

/**
 * @brief <h3> Cap Extend SPM Passive Timer </h3>
 *
 * @param time  -   Passive Timer on Button Information
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_passive_timer( uint8_t time );

/**
 * @brief <h3> Cap Extend SPM CAP Mode Setting </h3>
 *
 * @param setting   -   Common setting, or Individual settings for each CAP
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_cap_mode_setting( uint8_t setting );

/**
 * @brief <h3> Cap Extend SPM CAP Pin Mode </h3>
 *
 * @param cap       -   CAP pin
 * @param mode      -   CAP Mode, disabled or button
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_cap_pin_mode( uint8_t cap, uint8_t mode );

/**
 * @brief <h3> Cap Extend SPM CAP Sensitivity </h3>
 *
 * @param cap           -   CAP pin
 * @param sensitivity   -   Sensitivity of CAP pin
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_cap_sensitivity( uint8_t cap, uint8_t sensitivity );

/**
 * @brief <h3> Cap Extend SPM CAP Threshold </h3>
 *
 * @param cap           -   CAP pin
 * @param threshold     -   Touch Threshold ticks
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_cap_threshold( uint8_t cap, uint8_t threshold );

/**
 * @brief <h3> Cap Extend SPM CAP Period Offset </h3>
 *
 * @param offset    -   Periodic Offset Compensation
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_cap_period_offset( uint8_t offset );

/**
 * @brief <h3> Cap Extend SPM Proximity Enable </h3>
 *
 * @param enable    -   Enables / Disables Proximity Sensing
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_cap_prox_enable( uint8_t enable );

/**
 * @brief <h3> Cap Extend SPM Button Reporting Config </h3>
 *
 * @param config    -   Multiple report of touches or Single reporting
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_report_cfg( uint8_t config );

/**
 * @brief <h3> Cap Extend SPM Button Interrupt Trigger </h3>
 *
 * @param trigger   -   Interrupt trigger on touch, release, both, or masked
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_int_trigger( uint8_t trigger );

/**
 * @brief <h3> Cap Extend SPM Button Release Samples </h3>
 *
 * @param samples   -   Samples at a scan period for determining release
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_release_samples( uint8_t samples );

/**
 * @brief <h3> Cap Extend SPM Button Touch Samples </h3>
 *
 * @param samples   -   Samples at a scan period for determining touch
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_touch_samples( uint8_t samples );

/**
 * @brief <h3> Cap Extend SPM Button Average Threshold </h3>
 *
 * @param thresh    -   Positive threshold for disabling the processing
 *                      filter averaging
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_avg_thresh( uint8_t thresh );

/**
 * @brief <h3> Cap Extend SPM Button Negative Offset Threshold </h3>
 *
 * @param thresh    -   Negative offset compensation threshold
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_neg_offset_thresh( uint8_t thresh );

/**
 * @brief <h3> Cap Extend SPM Button Negative Count Maximum </h3>
 *
 * @param max   -   Number of ticks until offset compensation
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_smp_btn_neg_count_max( uint8_t max );

/**
 * @brief <h3> Cap Extend SPM Button Hysteresis </h3>
 *
 * @param hysteresis    -   Button hysteresis corresponding to % of CAP threshold
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_hysteresis( uint8_t hysteresis );

/**
 * @brief <h3> Cap Extend SPM Button Stuck Timeout </h3>
 *
 * @param timeout   -   Defines time stuck at timeout
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_btn_stuck_timeout( uint8_t timeout );

/**
 * @brief <h3> Cap Extend SPM Map Wakeup Size </h3>
 *
 * @param size  -   Size of key sequence size for Doze->Active sequence
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_wakeup_map_size( uint8_t size );

/**
 * @brief <h3> Cap Extend SPM Wakeup Value 0 </h3>
 *
 * @param btn_1     -   Key 5
 * @param btn_2     -   Key 4
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_wakeup_value_0( uint8_t btn_1, uint8_t btn_2 );

/**
 * @brief <h3> Cap Extend SPM Wakeup Value 1 </h3>
 *
 * @param btn_1     -   Key 3
 * @param btn_2     -   Key 2
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_wakeup_value_1( uint8_t btn_1, uint8_t btn_2 );

/**
 * @brief <h3> Cap Extend SPM Wakeup Value 2 </h3>
 *
 * @param btn_1     -   Key 1
 * @param btn_2     -   Key 0
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_wakeup_value_2( uint8_t btn_1, uint8_t btn_2 );

/**
 * @brief <h3> Cap Extend SPM Autolight </h3>
 *
 * @param gpio      -   GPIO pin
 * @param btn       -   Sensor to be mapped to gpio
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_autolight( uint8_t gpio, uint8_t btn );

/**
 * @brief <h3> Cap Extend SPM Map Group 0 </h3>
 *
 * @param btn       -   Sensor to be mapped
 * @param enable    -   Enable / Disable mapping to Group 0
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_map_group_0( uint8_t btn, uint8_t enable );

/**
 * @brief <h3> Cap Extend SPM Map Group 1 </h3>
 *
 * @param btn       -   Sensor to be mapped
 * @param enable    -   Enable / Disable mapping to Group 1
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_map_group_1( uint8_t btn, uint8_t enable );

/**
 * @brief <h3> Cap Extend SPM GPIO Mode </h3>
 *
 * @param gpio      -   GPIO pin
 * @param mode      -   Mode of gpio, ( GPO, GPP, GPI )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_mode( uint8_t gpio, uint8_t mode );

/**
 * @brief <h3> Cap Extend SPM GPIO Power Up Value </h3>
 *
 * @param gpio      -   GPIO pin
 * @param mode      -   Mode of gpio, ( ON, OFF )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_pwr_up_val( uint8_t gpio, uint8_t mode );

/**
 * @brief <h3> Cap Extend SPM GPIO Autolight Enable </h3>
 *
 * @param gpio      -   GPIO pin
 * @param enable    -   Enable / Disable autolight
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_autolight_enable( uint8_t gpio, uint8_t enable );

/**
 * @brief <h3> Cap Extend SPM GPIO On Intensity </h3>
 *
 * @param gpio          -   GPIO pin
 * @param intensity     -   ON intensity index
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_on_intensity( uint8_t gpio, uint8_t intensity );

/**
 * @brief <h3> Cap Extend SPM GPIO Off Intensity </h3>
 *
 * @param gpio          -   GPIO pin
 * @param intensity     -   OFF intensity index
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_off_intensity( uint8_t gpio, uint8_t intensity );

/**
 * @brief <h3> Cap Extend SPM PWM Function </h3>
 *
 * @param gpio          -   GPIO pin
 * @param pwm           -   PWM Function ( Linear, Logarithmic )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_pwm_function( uint8_t gpio, uint8_t pwm );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Increment Factor </h3>
 *
 * @param gpio          -   GPIO pin
 * @param fade          -   Fading increment factor
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_fade_inc_factor( uint8_t gpio, uint8_t fade );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Decrement Factor </h3>
 *
 * @param gpio          -   GPIO pin
 * @param fade          -   Fading Decrement factor
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_fade_dec_factor( uint8_t gpio, uint8_t fade );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Increment Time </h3>
 *
 * @param gpio          -   GPIO pin
 * @param time          -   Fading increment time
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_fade_inc_time( uint8_t gpio, uint8_t time );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Decrement Time </h3>
 *
 * @param gpio          -   GPIO pin
 * @param time          -   Fading decrement time
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpio_fade_dec_time( uint8_t gpio, uint8_t time );

/**
 * @brief <h3> Cap Extend SPM Fade Off Delay </h3>
 *
 * @param gpio          -   GPIO pin
 * @param delay         -   Delay after GPO OFF trigger before fading out starts
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_fade_off_delay( uint8_t gpio, uint8_t delay );

/**
 * @brief <h3> Cap Extend SPM Pullup Pulldown </h3>
 *
 * @param gpio          -   GPIO pin
 * @param setting       -   Pullup/Pulldown resistor setting for GPI pins
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_pullup_pulldown( uint8_t gpio, uint8_t setting );

/**
 * @brief <h3> Cap Extend SPM Interrupt Edge Trigger </h3>
 *
 * @param gpio          -   GPIO pin
 * @param edge          -   Interrupt trigger ( none, rising, falling, both )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_int_edge_trigger( uint8_t gpio, uint8_t edge );

/**
 * @brief <h3> Cap Extend SPM GPIO Debounce Enable </h3>
 *
 * @param gpio          -   GPIO pin
 * @param enable        -   Enables / Disables GPI debounce
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
int8_t capextend_set_spm_gpi_debounce_enable( uint8_t gpio, uint8_t enable );

/**
 * @brief <h3> Cap Extend Get Interrupt Source </h3>
 *  Gets the interrupt source from register
 *
 * @retval int_src_t    -   Interrupt Source
 */
int8_t capextend_get_int_src( void );

/**
 * @brief <h3> Cap Extend Get GPIO Status </h3>
 *
 * @param gpio  -   GPIO pin
 *
 * @retval uint8_t  -   GPIO Status
 */
int8_t capextend_get_gpio_status( uint8_t gpio );

/**
 * @brief <h3> Cap Extend Is NVM Used </h3>
 *
 * @retval uint8_t  -   1: NVM used 0: QSM used
 */
int8_t capextend_is_nvm_used( void );

/**
 * @brief <h3> Cap Extend Get NVM Uses Count </h3>
 *
 * @retval uint8_t  -   NVM Usages, 0: None 1: Once 2: Twice
 *                      3: Three Times 4: More than three times
 */
int8_t capextend_get_nvm_uses_count( void );

/**
 * @brief <h3> Cap Extend Get Compensation Mode </h3>
 *
 * @retval uint8_t  -   Compensation Mode 0: Compensation complete
 *                                        1: Read->Compensation running
 */
int8_t capextend_get_comp_mode( void );

/**
 * @brief <h3> Cap Extend Get Operating Mode </h3>
 *
 * @retval uint8_t  -   Operation Mode 0: Active Mode 1: Doze Mode 2: Sleep Mode
 */
int8_t capextend_get_op_mode( void );

/**
 * @brief <h3> Cap Extend Set Power of GPOs while Autolight is OFF </h3>
 *
 * @param gpio  -   GPIO pin
 * @param on    -   ON / OFF state of GPOs when Autolight is off
 *
 * @retval uint8_t  -   -1: success 0: failure
 */
int8_t capextend_set_gpo_pwr_autolight_off( uint8_t gpio, uint8_t on );

/**
 * @brief <h3> Cap Extend Set GPP Intensity </h3>
 *
 * @param gpio      -   GPP pin
 * @param intensity -   Intensity index of GPP pin
 *
 * @retval uint8_t  -   GPIO Status
 */
int8_t capextend_set_gpp_intensity( uint8_t gpio, uint8_t intensity );

/**
 * @brief <h3> Cap Extend Software Reset </h3>
 *  Resets software on Cap Extend
 *
 * @retval uint8_t  -   -1: success 0: failure
 */
int8_t capextend_software_reset( void );

/**
 * @brief <h3> Cap Extend Set Monitor Scan Period </h3>
 *
 * @param period    -   Monitor Mode Scan Period ( period * 15 )ms
 *
 * @retval uint8_t  -   -1: success 0: failure
 */
int8_t capextend_set_monitor_scan_period( uint8_t period );

/**
 * @brief <h3> Cap Extend Get Real Time Data </h3>
 *
 * @param cap       -   CAP
 * @param data      -   Raw, Diff, or Avg
 *
 * @retval uint16_t     -   16 bit 2s complement format of data
 */
uint16_t capextend_get_real_time_data( uint8_t cap, uint8_t m_data );





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Cap_Extend_STM.c
    @example Click_Cap_Extend_TIVA.c
    @example Click_Cap_Extend_CEC.c
    @example Click_Cap_Extend_KINETIS.c
    @example Click_Cap_Extend_MSP.c
    @example Click_Cap_Extend_PIC.c
    @example Click_Cap_Extend_PIC32.c
    @example Click_Cap_Extend_DSPIC.c
    @example Click_Cap_Extend_AVR.c
    @example Click_Cap_Extend_FT90x.c
    @example Click_Cap_Extend_STM.mbas
    @example Click_Cap_Extend_TIVA.mbas
    @example Click_Cap_Extend_CEC.mbas
    @example Click_Cap_Extend_KINETIS.mbas
    @example Click_Cap_Extend_MSP.mbas
    @example Click_Cap_Extend_PIC.mbas
    @example Click_Cap_Extend_PIC32.mbas
    @example Click_Cap_Extend_DSPIC.mbas
    @example Click_Cap_Extend_AVR.mbas
    @example Click_Cap_Extend_FT90x.mbas
    @example Click_Cap_Extend_STM.mpas
    @example Click_Cap_Extend_TIVA.mpas
    @example Click_Cap_Extend_CEC.mpas
    @example Click_Cap_Extend_KINETIS.mpas
    @example Click_Cap_Extend_MSP.mpas
    @example Click_Cap_Extend_PIC.mpas
    @example Click_Cap_Extend_PIC32.mpas
    @example Click_Cap_Extend_DSPIC.mpas
    @example Click_Cap_Extend_AVR.mpas
    @example Click_Cap_Extend_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __capextend_driver.h

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