/**
 ****************************************************************************************
 *
 * @file co_version.h
 *
 * @brief Version definitions for BT4.0
 *
 * Copyright (C) RivieraWaves 2009-2013
 *
 *
 ****************************************************************************************
 */

#ifndef _CO_VERSION_H_
#define _CO_VERSION_H_
/**
 ****************************************************************************************
 * @defgroup CO_VERSION Version Defines
 * @ingroup COMMON
 *
 * @brief Bluetooth Controller Version definitions.
 *
 * @{
 ****************************************************************************************
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "rwip_config.h"        // SW configuration options

/// RWBT SW Major Version
#if (BLE_EMB_PRESENT)
#define RWBT_SW_VERSION_MAJOR                   6
#else //BLE_EMB_PRESENT
#define RWBT_SW_VERSION_MAJOR                   5
#endif //BLE_EMB_PRESENT

#if (BT_EMB_PRESENT)
/// RWBT SW Minor Version
#define RWBT_SW_VERSION_MINOR                   7
/// RWBT SW Build Version
#define RWBT_SW_VERSION_BUILD                   1
#else //BT_EMB_PRESENT
/// RWBT SW Minor Version
#define RWBT_SW_VERSION_MINOR                   7
/// RWBT SW Build Version
#define RWBT_SW_VERSION_BUILD                   1
#endif //BT_EMB_PRESENT

/// RWBT SW Major Version
#define RWBT_SW_VERSION_SUB_BUILD               0


/// RiCow ROM SW Major Version
#define RICOW_ROM_SW_VERSION_MAJOR              2
/// RiCow ROM SW Minor Version
#define RICOW_ROM_SW_VERSION_MINOR              2
/// RiCow ROM SW Build Version
#define RICOW_ROM_SW_VERSION_BUILD              2
/// RiCow ROM SW Major Version
#define RICOW_ROM_SW_VERSION_SUB_BUILD          0


/// @} CO_VERSION


#endif // _CO_VERSION_H_
