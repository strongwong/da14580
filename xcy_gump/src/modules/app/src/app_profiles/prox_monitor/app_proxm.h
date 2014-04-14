/**
****************************************************************************************
*
* @file app_proxr.h
*
* @brief Proximity Reporter application.
*
* Copyright (C) 2012. Dialog Semiconductor Ltd, unpublished work. This computer 
 * program includes Confidential, Proprietary Information and is a Trade Secret of 
 * Dialog Semiconductor Ltd.  All use, disclosure, and/or reproduction is prohibited 
 * unless authorized in writing. All Rights Reserved.
*
* <bluetooth.support@diasemi.com> and contributors.
*
****************************************************************************************
*/

#ifndef APP_PROXM_H_
#define APP_PROXM_H_

/**
 ****************************************************************************************
 * @addtogroup APP
 * @ingroup RICOW
 *
 * @brief Proximity Reporter Application entry point.
 *
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwble_config.h"
#include "gpio.h"

#if BLE_PROX_MONITOR
#include "proxm.h"

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */
typedef struct
{
uint32_t blink_timeout;
	
uint8_t blink_toggle;
	
uint8_t lvl;
	
uint8_t ll_alert_lvl;
	
int8_t  txp_lvl;
    
GPIO_PORT port;

GPIO_PIN pin;

}app_alert_state;

extern app_alert_state alert_state;

/*
 * DEFINES
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initialize Proximity Application
 ****************************************************************************************
 */
void app_proxm_init(GPIO_PORT port, GPIO_PIN pin);

/**
 ****************************************************************************************
 *
 * Proximity Application Functions
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Enable the proximity profile
 *
 ****************************************************************************************
 */
void app_proxm_enable(void);

/**
 ****************************************************************************************
 * @brief Start proximity Alert
 *
 ****************************************************************************************
 */
void app_proxm_alert_start(uint8_t lvl);

/**
 ****************************************************************************************
 * @brief Stop proximity Alert.
 *
 ****************************************************************************************
 */
void app_proxm_alert_stop(void);


/**
 ****************************************************************************************
 * @brief Read Tx Power Level.
 *
 ****************************************************************************************
 */
void app_proxm_rd_tx_pwr(void);

/**
 ****************************************************************************************
 * @brief Create proximity reporter Database
 *
 ****************************************************************************************
 */

void app_proxm_create_db_send(void);

void app_proxm_port_reinit(GPIO_PORT port, GPIO_PIN pin);

#if 0
#define XCY_BUZZER_GPIO	GPIO_PORT_0,GPIO_PIN_7
#define XCY_LED0_GPIO	GPIO_PORT_1,GPIO_PIN_0
#define XCY_LED1_GPIO	GPIO_PORT_1,GPIO_PIN_1
#define XCY_LED2_GPIO	GPIO_PORT_1,GPIO_PIN_2
#define XCY_LED3_GPIO	GPIO_PORT_1,GPIO_PIN_3
#define XCY_KB_ON		GPIO_PORT_2,GPIO_PIN_3
#define XCY_KB_JL		GPIO_PORT_2,GPIO_PIN_6
#define XCY_KB_SCH		GPIO_PORT_2,GPIO_PIN_9
#endif
#endif //BLE_PROX_MONTIOR

/// @} APP

#endif // APP_H_