/****************************************************************************
* Title                 :   CapExtend click
* Filename              :   capextend_hal.h
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
 * @file capextend_hal.h
 * @brief <h2> HAL layer </h2>
 *
 * @par
 * HAL layer for <a href="http://www.mikroe.com">MikroElektronika's</a>
 * CapExtend click board.
 */
#ifndef CAPEXTEND_HAL_H_
#define CAPEXTEND_HAL_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include "stdint.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define CMD_SIZE                1                  // COMMAND OR REGISTER ADDRESS SIZE
#define BUFF_SIZE               256                // BUFFER SIZE
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
        
/******************************************************************************
* Typedefs
*******************************************************************************/

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
 * @brief <h3>HAL Initialization</h3>
 *
 * @par
 * Initialization of HAL layer used to initialize I2C bus and pins needed
 * for proper usage of click board.
 *
 * @param[in] address_id - hardware address
 */
int capextend_hal_init( uint8_t address_id );

/**
 * @brief <h3>HAL Reset</h3>
 *
 * @par
 * Resets the module using
 * @link CAPEXTEND_RST @endlink .
 */
void capextend_hal_reset( void );


/**
 * @brief <h3>HAL Write</h3>
 *
 * @par
 * Generic write function adapted for I2C bus.
 *
 * @param[in] command - register address
 * @param[in] buffer - data buffer
 * @param[in] count - data size in bytes
 */
void capextend_hal_write( uint8_t *command,
                              uint8_t *buffer,
                              uint16_t count );

/**
 * @brief <h3>HAL Read</h3>
 *
 * @par
 * Generic read function adapted for SHT click.
 *
 * @param[in] command - register address
 * @param[out] buffer - data buffer
 * @param[in] count - data size in bytes
 */
void capextend_hal_read( uint8_t *command,
                                    uint8_t *buffer,
                                    uint16_t count );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CAPEXTEND_HAL_H_ */

/*** End of File **************************************************************/