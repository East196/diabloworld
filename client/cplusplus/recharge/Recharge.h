//
//  Recharge.h
//  tsDemo
//
//  Created by jie on 13-8-26.
//
//

#ifndef __tsDemo__Recharge__
#define __tsDemo__Recharge__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recharge:public CCLayer
{
public:
    virtual bool init();
    void callRechargeGold();
    void callRechargeEnergy();
    CREATE_FUNC(Recharge);
};

#endif /* defined(__tsDemo__Recharge__) */
