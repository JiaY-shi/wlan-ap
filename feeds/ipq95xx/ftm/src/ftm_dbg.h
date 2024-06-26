/*==========================================================================

                     FTM WLAN Source File

# Copyright (c) 2013-2014 by Qualcomm Technologies, Inc.  All Rights Reserved.
# Qualcomm Technologies Proprietary and Confidential.

===========================================================================*/
#ifndef _FTM_DBG_H_
#define _FTM_DBG_H_
#include <stdint.h>

#define FTM_DBG_ERROR   0x00000001
#define FTM_DBG_INFO    0x00000002
#define FTM_DBG_TRACE   0x00000004

#define FTM_DBG_DEFAULT (FTM_DBG_ERROR)

extern unsigned int g_dbg_level;

struct ftm_config
{
    int total_num_slots;
    uint32_t slot_id[4];
    uint32_t slot_size[4];
};
extern struct ftm_config ftm_cfg;

#ifdef DEBUG
void current_time();
#define DPRINTF(_level, _x...)\
    do {\
        if (g_dbg_level & (_level))\
        {\
            fprintf(stderr, _x);\
        }\
    } while (0);

#else
#define DPRINTF(_level, x...)  do { } while (0);
#endif

#endif /* _FTM_DBG_H_ */
