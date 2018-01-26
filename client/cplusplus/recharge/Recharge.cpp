//
//  Recharge.cpp
//  tsDemo
//
//  Created by jie on 13-8-26.
//
//

#include "Recharge.h"
#include "GoldRecharge.h"
#include "EnergyRecharge.h"

bool Recharge::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite *rechargeBkg=CCSprite::create("friendmain_bkg.png");
    rechargeBkg->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(rechargeBkg);
    CCMenuItemImage*energyItem=CCMenuItemImage::create("GoldRecharge-01.png",
        "GoldRecharge-02.png",this,menu_selector(Recharge::callRechargeGold));
    CCMenuItemImage *goldItem=CCMenuItemImage::create("EnergyRecharge-01.png", "EnergyRecharge-02.png",this,menu_selector(Recharge::callRechargeEnergy));
    CCMenu *rechargeMenu=CCMenu::create(energyItem,goldItem,NULL);
    rechargeMenu->setPosition(ccp(size.width/2, size.height/2-5));
    rechargeMenu->alignItemsVerticallyWithPadding(90);
    rechargeBkg->addChild(rechargeMenu);
    
    return true;
}

void Recharge::callRechargeEnergy()
{
    EnergyRecharge *energy=EnergyRecharge::create();
    this->addChild(energy);
}

void Recharge::callRechargeGold()
{
    GoldRecharge *gold=GoldRecharge::create();
    this->addChild(gold);
}

