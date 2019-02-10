//
//  BRGhostnode.h
//  nixwallet
//
//  Created by Matthew T on 1/12/19.
//  Copyright © 2019 Nix Platform. All rights reserved.
//

#ifndef BRGhostnode_h
#define BRGhostnode_h

#include <stdio.h>
#include "BRKey.h"
#include "BRInt.h"
#include "BRTransaction.h"
#include "BRPeer.h"
#include <stddef.h>
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif
   
enum state {
    GHOSTNODE_PRE_ENABLED,
    GHOSTNODE_ENABLED,
    GHOSTNODE_EXPIRED,
    GHOSTNODE_OUTPOINT_SPENT,
    GHOSTNODE_UPDATE_REQUIRED,
    GHOSTNODE_WATCHDOG_EXPIRED,
    GHOSTNODE_NEW_START_REQUIRED,
    GHOSTNODE_POSE_BAN
};
typedef struct dynamic_array_struct
{
    unsigned char* data;
    size_t capacity; /* total capacity */
    size_t size; /* number of elements in vector */
} vector;
    
typedef struct {
    char *alias;
    
    vector vchSig;

    UInt256 txHash;
    BRTxInput *vin;
    uint32_t lockTime;
    uint32_t blockHeight;
    uint32_t timestamp; // time interval since unix epoch
    
    BRPeer addr;
    BRKey pubKeyCollateralAddress;
    
    int64_t sigTime; //mnb message time
    int64_t nLastDsq; //the dsq count from the last dsq broadcast of this node
    int64_t nTimeLastChecked;
    int64_t nTimeLastPaid;
    int64_t nTimeLastWatchdogVote;
    
    int nActiveState;
    int nCacheCollateralBlock;
    int nBlockLastPaid;
    int nProtocolVersion;
    
} BRGhostnode;

BRGhostnode GhostnodeCreate(BRGhostnode ghostnode);

//int GhostnodeInit(const char *alias, const char *ip, const char *privKey, const char *txHash, const char *outputIndex);
    
    
#ifdef __cplusplus
    }
#endif

#endif /* BRGhostnode_h */
