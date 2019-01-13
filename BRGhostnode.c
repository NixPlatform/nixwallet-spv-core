//
//  BRGhostnode.c
//  nixwallet
//
//  Created by Matthew T on 1/12/19.
//  Copyright © 2019 Nix Platform. All rights reserved.
//

#include "BRGhostnode.h"
#include "BRPeer.h"

int GhostnodeInit(BRGhostnode ghostnode){
    int r = 0;
    BRPeer *peer;
    UInt256 hash[1];
    BRPeerSendGhostnode(peer, hash, 1);

    return r;
}
