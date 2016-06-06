/****************************************************************************
* Title                 :   CapExtend CLICK
* Filename              :   capextend_hw.h
* Author                :   CAL
* Origin Date           :   04/25/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials      Description
* 04/25/2016   XXXXXXXXXXX         CAL      Interface Created.
*
*****************************************************************************/
/**
 * @file capextend_hw.h
 * @brief <h3> Hardware Layer </h3>
 *
 * @par
 * Low level functions for
 * <a href="http://www.mikroe.com">MikroElektronika's</a> CapExtend click
 * board.
 */

/**
 * @page LIB_INFO Library Info
 * @date 25 April 2016
 * @author Corey Lakey
 * @copyright GNU Public License
 * @version 1.0.0 - Initial testing and verification
 */

/**
 * @page TEST_CFG Test Configurations
 * <h3> Test configuration 1 : </h3>
 * @par
 * <ul>
 * <li><b>MCU</b> :             STM32F107VC</li>
 * <li><b>Dev. Board</b> :      EasyMx Pro v7</li>
 * <li><b>Oscillator</b> :      72 Mhz internal</li>
 * <li><b>Ext. Modules</b> :    Cap Extend Click</li>
 * <li><b>SW</b> :              MikroC PRO for ARM 4.7.1</li>
 * </ul>
 *
 * <h3> Test configuration 2 : </h3>
 * @par
 * <ul>
 * <li><b>MCU</b> :             PIC32MX795F512L</li>
 * <li><b>Dev. Board</b> :      EasyPic Fusion v7</li>
 * <li><b>Oscillator</b> :      80 Mhz internal</li>
 * <li><b>Ext. Modules</b> :    Cap Extend Click</li>
 * <li><b>SW</b> :              MikroC PRO for PIC 6.6.2</li>
 * </ul>
 *
 * <h3> Test configuration 3 : </h3>
 * @par
 * <ul>
 * <li><b>MCU</b> :             FT900Q</li>
 * <li><b>Dev. Board</b> :      EasyFT90x v7</li>
 * <li><b>Oscillator</b> :      100 Mhz internal</li>
 * <li><b>Ext. Modules</b> :    Cap Extend Click</li>
 * <li><b>SW</b> :              MikroC PRO for FT90x 1.2.1</li>
 * </ul>
 */

/**
 * @mainpage
 * <h3> General Description </h3>
 * @par Cap Extend Click by MikroElektronika library for interfacing with click board.
 *
 *
 *
 */
#ifndef CAPEXTEND_HW_H
#define CAPEXTEND_HW_H
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
 
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

//SPM Registers
#define SPM_CFG         0x0D
#define SPM_BASE_ADDR   0x0E
#define SPM_KEY_MSB     0xAC
#define SPM_KEY_LSB     0xAD
    //Blocks for SPM
#define BLOCK_1         0x00
#define BLOCK_2         0x08
#define BLOCK_3         0x10
#define BLOCK_4         0x20
#define BLOCK_5         0x28
#define BLOCK_6         0x30
#define BLOCK_7         0x38
#define BLOCK_8         0x40
#define BLOCK_9         0x48
#define BLOCK_10        0x50
#define BLOCK_11        0x58
#define BLOCK_12        0x60
#define BLOCK_13        0x68
#define BLOCK_14        0x70
#define BLOCK_15        0x78

//I2C Registers
#define IRQ_SRC         0x00
#define CAP_STAT_MSB    0x01
#define CAP_STAT_LSB    0x02
#define GPI_STAT        0x07
#define SPM_STAT        0x08
#define COMP_OP_MODE    0x09
#define GPO_CTRL        0x0A
#define GPP_PIN_ID      0x0B
#define GPP_INTENSITY   0x0C
#define SOFT_RESET      0xB1
#define MON_SCAN_PER    0xF9

//Real Time Monitoring addresses
#define CAP_DIFF_BA     0xB4
#define CAP_RAW_BA      0x80
#define CAP_AVG_BA      0x9A

//Real Time Monitoring Blocks
#define CAP_DIFF_BLK_1  0xB4
#define CAP_DIFF_BLK_2  0xBC
#define CAP_DIFF_BLK_3  0xC4

#define CAP_AVG_BLK_1   0x80
#define CAP_AVG_BLK_2   0x88
#define CAP_AVG_BLK_3   0x90

#define CAP_RAW_BLK_1   0x9A
#define CAP_RAW_BLK_2   0xA2
#define CAP_RAW_BLK_3   0xAA

/****************************
 * CAP Diff Data
 * CAP0DIFF_MSB 0xB4    //block 1
 * CAP0DIFF_LSB 0xB5
 * CAP1DIFF_MSB 0xB6
 * CAP1DIFF_LSB 0xB7
 * CAP2DIFF_MSB 0xB8
 * CAP2DIFF_LSB 0xB9
 * CAP3DIFF_MSB 0xBA
 * CAP3DIFF_LSB 0xBB
 * CAP4DIFF_MSB 0xBC    //block 2
 * CAP4DIFF_LSB 0xBD
 * CAP5DIFF_MSB 0xBE
 * CAP5DIFF_LSB 0xBF
 * CAP6DIFF_MSB 0xC0
 * CAP6DIFF_LSB 0xC1
 * CAP7DIFF_MSB 0xC2
 * CAP7DIFF_LSB 0xC3
 * CAP8DIFF_MSB 0xC4    //block 3
 * CAP8DIFF_LSB 0xC5
 * CAP9DIFF_MSB 0xC6
 * CAP9DIFF_LSB 0xC7
 * CAP10DIFF_MSB 0xC8
 * CAP10DIFF_LSB 0xC9
 * CAP11DIFF_MSB 0xCA
 * CAP11DIFF_LSB 0xCB
 *
 * CAP Raw Data
 * CAP0RAW_MSB 0x80     //block 1
 * CAP0RAW_LSB 0x81
 * CAP1RAW_MSB 0x82
 * CAP1RAW_LSB 0x83
 * CAP2RAW_MSB 0x84
 * CAP2RAW_LSB 0x85
 * CAP3RAW_MSB 0x86
 * CAP3RAW_LSB 0x87
 * CAP4RAW_MSB 0x88     //block 2
 * CAP4RAW_LSB 0x89
 * CAP5RAW_MSB 0x8A
 * CAP5RAW_LSB 0x8B
 * CAP6RAW_MSB 0x8C
 * CAP6RAW_LSB 0x8D
 * CAP7RAW_MSB 0x8E
 * CAP7RAW_LSB 0x8F
 * CAP8RAW_MSB 0x90     //block 3
 * CAP8RAW_LSB 0x91
 * CAP9RAW_MSB 0x92
 * CAP9RAW_LSB 0x93
 * CAP10RAW_MSB 0x94
 * CAP10RAW_LSB 0x95
 * CAP11RAW_MSB 0x96
 * CAP11RAW_LSB 0x97
 *
 * CAP Avg Data
 * CAP0AVG_MSB 0x9A     //block 1
 * CAP0AVG_LSB 0x9B
 * CAP1AVG_MSB 0x9C
 * CAP1AVG_LSB 0x9D
 * CAP2AVG_MSB 0x9E
 * CAP2AVG_LSB 0x9F
 * CAP3AVG_MSB 0xA0
 * CAP3AVG_LSB 0xA1
 * CAP4AVG_MSB 0xA2     //block 2
 * CAP4AVG_LSB 0xA3
 * CAP5AVG_MSB 0xA4
 * CAP5AVG_LSB 0xA5
 * CAP6AVG_MSB 0xA6
 * CAP6AVG_LSB 0xA7
 * CAP7AVG_MSB 0xA8
 * CAP7AVG_LSB 0xA9
 * CAP8AVG_MSB 0xAA     //block 3
 * CAP8AVG_LSB 0xAB
 * CAP9AVG_MSB 0xAC
 * CAP9AVG_LSB 0xAD
 * CAP10AVG_MSB 0xAE
 * CAP10AVG_LSB 0xAF
 * CAP11AVG_MSB 0xB0
 * CAP11AVG_LSB 0xB1

 *************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef enum
{
    GPIO_0 = 0,
    GPIO_1,
    GPIO_2,
    GPIO_3,
    GPIO_4,
    GPIO_5,
    GPIO_6,
    GPIO_7,
    GPIO_ALL
}gpio_t;

typedef enum
{
    COMMON_SETTINGS = 1,
    INDIVIDUAL_SETTINGS = 4
}cap_sett_t;

typedef enum
{
    DISABLED = 0,
    BUTTON
}cap_mode_t;

typedef enum
{
    MULTI_TOUCH = 0,
    SINGLE_TOUCH
}btn_report_t;

typedef enum
{
    INT_MASKED = 0,
    INT_TOUCH,
    INT_RELEASE,
    INT_BOTH_TR
}int_trigger_t;

typedef enum
{
    SMPL_0 = 0,
    SMPL_2,
    SMPL_3,
    SMPL_4
}btn_smpl_t;

typedef enum
{
    BTN_0 = 0,
    BTN_1,
    BTN_2,
    BTN_3,
    BTN_4,
    BTN_5,
    BTN_6,
    BTN_7,
    BTN_8,
    BTN_9,
    BTN_10,
    BTN_11,
    GROUP_0,
    GROUP_1
}btn_map_t;

typedef enum
{
    GPO = 0,
    GPP,
    GPI
}gpio_mode_t;

typedef enum
{
    LOG = 0,
    LIN
}pwm_func_t;

typedef enum
{
    EVERY_TIME = 0,
    EVERY_16
}fade_factor_t;

typedef enum
{
    NONE = 0,
    PULLUP,
    PULLDOWN
}pullup_down_t;

typedef enum
{
    NO_INT =0,
    RISING,
    FALLING,
    BOTH
}int_edge_t;

typedef enum
{
    OP_MODE_INT = 1,
    COMP_INT = 2,
    BUTTON_INT = 4,
    GPI_INT = 16,
    SPM_INT = 32,
    NVM_INT = 64
}int_src_t;

typedef enum
{
    ACTIVE_MODE = 0,
    DOZE_MODE,
    SLEEP_MODE
}op_mode_t;

typedef enum
{
    RAW = 0,
    AVG,
    DIFF
}monitor_data_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h3> HW Layer Initialization </h3>
 *
 * @par
 * Prepares library for usage and sets needed values to default.
 *
 * @note
 * This function must be called first.
 *
 */
int capextend_init( uint8_t address );

/**
 * @brief <h3> Cap Extend is Button Pressed </h3>
 *
 * @param button    -   Button to be checked
 *
 * @retval uint8_t  -   -1: Button pressed 0: Button not pressed
 */
uint8_t capextend_is_button_pressed( uint8_t button );

/**
 * @brief <h3> Cap Extend Read MSB Buttons </h3>
 * Buttons 8-12
 *
 * @retval uint8_t  -   Buttons Pressed
 */
uint8_t capextend_read_msb_buttons( void );

/**
 * @brief <h3> Cap Extend Read LSB Buttons </h3>
 * Buttons 0-7
 *
 * @retval uint8_t  -   Buttons Pressed
 */
uint8_t capextend_read_lsb_buttons( void );

/**
 * @brief <h3> Cap Extend SPM GPIO Polarity </h3>
 *
 * @param gpio      -   GPIO to be changed
 * @param polarity  -   Polarity
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_polarity( gpio_t gpio, uint8_t polarity );

/**
 * @brief <h3> Cap Extend SPM Read Enable </h3>
 *  Enables reading of SPM memory regions
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_spm_read_enable(void );

/**
 * @brief <h3> Cap Extend SPM Write Enable </h3>
 *  Enables writing of SPM memory regions
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_spm_write_enable(void );

/**
 * @brief <h3> Cap Extend SPM Disable </h3>
 *  Disables use of SPM memory regions
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_spm_disable( void );

/**
 * @brief <h3> Cap Extend SPM Read Block </h3>
 *
 * @param block       -   Block buffer to read from
 * @param start_addr  -   Start address of block in spm
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_spm_read_block(uint8_t *block , uint8_t *start_addr);

/**
 * @brief <h3> Cap Extend SPM Write Block </h3>
 *
 * @param block       -   Block buffer to write from
 * @param start_addr  -   Start address of block in spm
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_spm_write_block(uint8_t *block , uint8_t *start_addr);

/**
 * @brief <h3> Cap Extend SPM Get I2C address </h3>
 *  Gets the I2C slave address
 *
 * @retval uint8_t  -   I2C Address
 */
uint8_t capextend_spm_get_i2c_address( void );

/**
 * @brief <h3> Cap Extend SPM Active Scan Period </h3>
 *
 * @param period    -   Active Scan Period
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_active_scan_period( uint8_t period );

/**
 * @brief <h3> Cap Extend SPM Doze Scan Period </h3>
 *
 * @param period    -   Doze Scan Period
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_doze_scan_period( uint8_t period );

/**
 * @brief <h3> Cap Extend SPM Passive Timer </h3>
 *
 * @param time  -   Passive Timer on Button Information
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_passive_timer( uint8_t time );

/**
 * @brief <h3> Cap Extend SPM CAP Mode Setting </h3>
 *
 * @param setting   -   Common setting, or Individual settings for each CAP
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_cap_mode_setting( cap_sett_t setting );

/**
 * @brief <h3> Cap Extend SPM CAP Pin Mode </h3>
 *
 * @param cap       -   CAP pin
 * @param mode      -   CAP Mode, disabled or button
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_cap_pin_mode( uint8_t cap, cap_mode_t mode );

/**
 * @brief <h3> Cap Extend SPM CAP Sensitivity </h3>
 *
 * @param cap           -   CAP pin
 * @param sensitivity   -   Sensitivity of CAP pin
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_cap_sensitivity( uint8_t cap, uint8_t sensitivity );

/**
 * @brief <h3> Cap Extend SPM CAP Threshold </h3>
 *
 * @param cap           -   CAP pin
 * @param threshold     -   Touch Threshold ticks
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_cap_threshold( uint8_t cap, uint8_t threshold );

/**
 * @brief <h3> Cap Extend SPM CAP Period Offset </h3>
 *
 * @param offset    -   Periodic Offset Compensation
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_cap_period_offset( uint8_t offset );

/**
 * @brief <h3> Cap Extend SPM Proximity Enable </h3>
 *
 * @param enable    -   Enables / Disables Proximity Sensing
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_cap_prox_enable( bool enable );

/**
 * @brief <h3> Cap Extend SPM Button Reporting Config </h3>
 *
 * @param config    -   Multiple report of touches or Single reporting
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_report_cfg( btn_report_t config );

/**
 * @brief <h3> Cap Extend SPM Button Interrupt Trigger </h3>
 *
 * @param trigger   -   Interrupt trigger on touch, release, both, or masked
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_int_trigger( int_trigger_t trigger );

/**
 * @brief <h3> Cap Extend SPM Button Release Samples </h3>
 *
 * @param samples   -   Samples at a scan period for determining release
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_release_samples( btn_smpl_t samples );

/**
 * @brief <h3> Cap Extend SPM Button Touch Samples </h3>
 *
 * @param samples   -   Samples at a scan period for determining touch
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_touch_samples( btn_smpl_t samples );

/**
 * @brief <h3> Cap Extend SPM Button Average Threshold </h3>
 *
 * @param thresh    -   Positive threshold for disabling the processing
 *                      filter averaging
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_avg_thresh( uint8_t thresh );

/**
 * @brief <h3> Cap Extend SPM Button Negative Offset Threshold </h3>
 *
 * @param thresh    -   Negative offset compensation threshold
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_neg_offset_thresh( uint8_t thresh );

/**
 * @brief <h3> Cap Extend SPM Button Negative Count Maximum </h3>
 *
 * @param max   -   Number of ticks until offset compensation
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_smp_btn_neg_count_max( uint8_t max );

/**
 * @brief <h3> Cap Extend SPM Button Hysteresis </h3>
 *
 * @param hysteresis    -   Button hysteresis corresponding to % of CAP threshold
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_hysteresis( uint8_t hysteresis );

/**
 * @brief <h3> Cap Extend SPM Button Stuck Timeout </h3>
 *
 * @param timeout   -   Defines time stuck at timeout
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_btn_stuck_timeout( uint8_t timeout );

/**
 * @brief <h3> Cap Extend SPM Map Wakeup Size </h3>
 *
 * @param size  -   Size of key sequence size for Doze->Active sequence
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_wakeup_map_size( uint8_t size );

/**
 * @brief <h3> Cap Extend SPM Wakeup Value 0 </h3>
 *
 * @param btn_1     -   Key 5
 * @param btn_2     -   Key 4
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_wakeup_value_0( uint8_t btn_1, uint8_t btn_2 );

/**
 * @brief <h3> Cap Extend SPM Wakeup Value 1 </h3>
 *
 * @param btn_1     -   Key 3
 * @param btn_2     -   Key 2
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_wakeup_value_1( uint8_t btn_1, uint8_t btn_2 );

/**
 * @brief <h3> Cap Extend SPM Wakeup Value 2 </h3>
 *
 * @param btn_1     -   Key 1
 * @param btn_2     -   Key 0
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_wakeup_value_2( uint8_t btn_1, uint8_t btn_2 );

/**
 * @brief <h3> Cap Extend SPM Autolight </h3>
 *
 * @param gpio      -   GPIO pin
 * @param btn       -   Sensor to be mapped to gpio
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_autolight( uint8_t gpio, btn_map_t btn );

/**
 * @brief <h3> Cap Extend SPM Map Group 0 </h3>
 *
 * @param btn       -   Sensor to be mapped
 * @param enable    -   Enable / Disable mapping to Group 0
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_map_group_0( uint8_t btn, bool enable );

/**
 * @brief <h3> Cap Extend SPM Map Group 1 </h3>
 *
 * @param btn       -   Sensor to be mapped
 * @param enable    -   Enable / Disable mapping to Group 1
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_map_group_1( uint8_t btn, bool enable );

/**
 * @brief <h3> Cap Extend SPM GPIO Mode </h3>
 *
 * @param gpio      -   GPIO pin
 * @param mode      -   Mode of gpio, ( GPO, GPP, GPI )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_mode( uint8_t gpio, gpio_mode_t mode );

/**
 * @brief <h3> Cap Extend SPM GPIO Power Up Value </h3>
 *
 * @param gpio      -   GPIO pin
 * @param mode      -   Mode of gpio, ( ON, OFF )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_pwr_up_val( gpio_t gpio, uint8_t mode );

/**
 * @brief <h3> Cap Extend SPM GPIO Autolight Enable </h3>
 *
 * @param gpio      -   GPIO pin
 * @param enable    -   Enable / Disable autolight
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_autolight_enable( gpio_t gpio, bool enable );

/**
 * @brief <h3> Cap Extend SPM GPIO On Intensity </h3>
 *
 * @param gpio          -   GPIO pin
 * @param intensity     -   ON intensity index
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_on_intensity( gpio_t gpio, uint8_t intensity );

/**
 * @brief <h3> Cap Extend SPM GPIO Off Intensity </h3>
 *
 * @param gpio          -   GPIO pin
 * @param intensity     -   OFF intensity index
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_off_intensity( gpio_t gpio, uint8_t intensity );

/**
 * @brief <h3> Cap Extend SPM PWM Function </h3>
 *
 * @param gpio          -   GPIO pin
 * @param pwm           -   PWM Function ( Linear, Logarithmic )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_pwm_function( gpio_t gpio, pwm_func_t pwm );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Increment Factor </h3>
 *
 * @param gpio          -   GPIO pin
 * @param fade          -   Fading increment factor
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_fade_inc_factor( gpio_t gpio, fade_factor_t fade );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Decrement Factor </h3>
 *
 * @param gpio          -   GPIO pin
 * @param fade          -   Fading Decrement factor
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_fade_dec_factor( gpio_t gpio, fade_factor_t fade );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Increment Time </h3>
 *
 * @param gpio          -   GPIO pin
 * @param time          -   Fading increment time
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_fade_inc_time( uint8_t gpio, uint8_t time );

/**
 * @brief <h3> Cap Extend SPM GPIO Fade Decrement Time </h3>
 *
 * @param gpio          -   GPIO pin
 * @param time          -   Fading decrement time
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpio_fade_dec_time( uint8_t gpio, uint8_t time );

/**
 * @brief <h3> Cap Extend SPM Fade Off Delay </h3>
 *
 * @param gpio          -   GPIO pin
 * @param delay         -   Delay after GPO OFF trigger before fading out starts
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_fade_off_delay( uint8_t gpio, uint8_t delay );

/**
 * @brief <h3> Cap Extend SPM Pullup Pulldown </h3>
 *
 * @param gpio          -   GPIO pin
 * @param setting       -   Pullup/Pulldown resistor setting for GPI pins
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_pullup_pulldown( uint8_t gpio, pullup_down_t setting );

/**
 * @brief <h3> Cap Extend SPM Interrupt Edge Trigger </h3>
 *
 * @param gpio          -   GPIO pin
 * @param edge          -   Interrupt trigger ( none, rising, falling, both )
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_int_edge_trigger( uint8_t gpio, int_edge_t edge );

/**
 * @brief <h3> Cap Extend SPM GPIO Debounce Enable </h3>
 *
 * @param gpio          -   GPIO pin
 * @param enable        -   Enables / Disables GPI debounce
 *
 * @retval uint8_t  -   -1: Success 0: Failure
 */
uint8_t capextend_set_spm_gpi_debounce_enable( gpio_t gpio, bool enable );

/**
 * @brief <h3> Cap Extend Get Interrupt Source </h3>
 *  Gets the interrupt source from register
 *
 * @retval int_src_t    -   Interrupt Source
 */
int_src_t capextend_get_int_src( void );

/**
 * @brief <h3> Cap Extend Get GPIO Status </h3>
 *
 * @param gpio  -   GPIO pin
 *
 * @retval uint8_t  -   GPIO Status
 */
uint8_t capextend_get_gpio_status( gpio_t gpio );

/**
 * @brief <h3> Cap Extend Is NVM Used </h3>
 *
 * @retval uint8_t  -   1: NVM used 0: QSM used
 */
uint8_t capextend_is_nvm_used( void );

/**
 * @brief <h3> Cap Extend Get NVM Uses Count </h3>
 *
 * @retval uint8_t  -   NVM Usages, 0: None 1: Once 2: Twice
 *                      3: Three Times 4: More than three times
 */
uint8_t capextend_get_nvm_uses_count( void );

/**
 * @brief <h3> Cap Extend Get Compensation Mode </h3>
 *
 * @retval uint8_t  -   Compensation Mode 0: Compensation complete
 *                                        1: Read->Compensation running
 */
uint8_t capextend_get_comp_mode( void );

/**
 * @brief <h3> Cap Extend Get Operating Mode </h3>
 *
 * @retval uint8_t  -   Operation Mode 0: Active Mode 1: Doze Mode 2: Sleep Mode
 */
op_mode_t capextend_get_op_mode( void );

/**
 * @brief <h3> Cap Extend Set Power of GPOs while Autolight is OFF </h3>
 *
 * @param gpio  -   GPIO pin
 * @param on    -   ON / OFF state of GPOs when Autolight is off
 *
 * @retval uint8_t  -   -1: success 0: failure
 */
uint8_t capextend_set_gpo_pwr_autolight_off( gpio_t gpio, bool on );

/**
 * @brief <h3> Cap Extend Set GPP Intensity </h3>
 *
 * @param gpio      -   GPP pin
 * @param intensity -   Intensity index of GPP pin
 *
 * @retval uint8_t  -   GPIO Status
 */
uint8_t capextend_set_gpp_intensity( uint8_t gpio, uint8_t intensity );

/**
 * @brief <h3> Cap Extend Software Reset </h3>
 *  Resets software on Cap Extend
 *
 * @retval uint8_t  -   -1: success 0: failure
 */
uint8_t capextend_software_reset( void );

/**
 * @brief <h3> Cap Extend Set Monitor Scan Period </h3>
 *
 * @param period    -   Monitor Mode Scan Period ( period * 15 )ms
 *
 * @retval uint8_t  -   -1: success 0: failure
 */
uint8_t capextend_set_monitor_scan_period( uint8_t period );

/**
 * @brief <h3> Cap Extend Get Real Time Data </h3>
 *
 * @param cap       -   CAP
 * @param data      -   Raw, Diff, or Avg
 *
 * @retval uint16_t     -   16 bit 2s complement format of data
 */
uint16_t capextend_get_real_time_data( uint8_t cap, monitor_data_t m_data );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CLICKNAME_HW_H */
/*** End of File **************************************************************/
