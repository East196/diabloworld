//
//  RechargeList.cpp
//  tsDemo
//
//  Created by jie on 13-9-5.
//
//

#include "RechargeList.h"

static RechargeList *rl=NULL;

RechargeList *RechargeList::getInstance()
{
    if(!rl)
    {
        rl=new RechargeList();
    }
    return rl;
}

RechargeList::~RechargeList()
{
    delete rl;
}








