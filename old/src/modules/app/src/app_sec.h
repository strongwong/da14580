/**
 ****************************************************************************************
 *
 * @file app_sec.h
 *
 * @brief Application Security Entry Point
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APP_SEC
 * @{
 ****************************************************************************************
 */

#ifndef APP_SEC_H_
#define APP_SEC_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"

#if (BLE_APP_SEC)

#include "co_bt.h"
#include "gap.h"

/*
 * DEFINES
 ****************************************************************************************
 */

#if (NVDS_SUPPORT)

// Buffer Size - BD Address / EDIV / RANDNB / LTK / IRK
#define NVDS_BUFFER_SIZE        (NVDS_LEN_BLE_LINK_KEY)
// NVDS_BD ADDRESS Offset
#define NVDS_BD_ADDR_OFFSET     (0)
// NVDS EIDV Offset
#define NVDS_EIDV_OFFSET        (NVDS_BD_ADDR_OFFSET + BD_ADDR_LEN)
// NVDS RANDNB Offset
#define NVDS_RANDNB_OFFSET      (NVDS_EIDV_OFFSET + sizeof(uint16_t))
// NVDS LTK Offset
#define NVDS_LTK_OFFSET         (NVDS_RANDNB_OFFSET + RAND_NB_LEN)
// NVDS IRK Offset
#define NVDS_IRK_OFFSET         (NVDS_LTK_OFFSET + 16)
// IRK Flag
#define APP_SEC_IRK_FLAG        (NVDS_TAG_BLE_LINK_KEY_FIRST)

#else

#define APP_SEC_IRK_FLAG        (0)

#endif //(NVDS_SUPPORT)

/*
 * STRUCTURES DEFINITIONS
 ****************************************************************************************
 */

struct app_sec_env_tag
{
    // LTK
    struct gap_sec_key ltk;
    // Random Number
    struct rand_nb rand_nb;
    // EDIV
    uint16_t ediv;
    // LTK key size
    uint8_t key_size;
    
    // Last paired peer address type 
    uint8_t peer_addr_type;
    // Last paired peer address 
    struct bd_addr peer_addr;
    
    // authentication level
    uint8_t auth;

    // Current Peer Device NVDS Tag
    uint8_t nvds_tag;
};

/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */

/// Application Security Environment
extern struct app_sec_env_tag app_sec_env;




/*
 * GLOBAL FUNCTIONS DECLARATIONS
 ****************************************************************************************
 */

void app_sec_init(void);


void app_sec_pairing_cmp_evt_send(uint8_t);


/**
 ****************************************************************************************
 * @brief Generate pin code
 *
 * @return Pin code
 ****************************************************************************************
 */
uint32_t app_sec_gen_tk(void);

/**
 * @brief Generate a LTK
 */
void app_sec_gen_ltk(uint8_t key_size);

#endif //(BLE_APP_SEC)

#endif // APP_SEC_H_

/// @} APP_SEC
