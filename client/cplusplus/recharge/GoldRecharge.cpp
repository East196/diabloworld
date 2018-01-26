//
//  GoldRecharge.cpp
//  tsDemo
//
//  Created by jie on 13-8-27.
//
//

#include "GoldRecharge.h"
#include "CustomPop.h"

bool GoldRecharge::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    rl=RechargeList::getInstance();
    path = CCFileUtils::sharedFileUtils()->fullPathForFilename("list.json");
    str = CCString::createWithContentsOfFile(path.c_str());
    read.parse(str->getCString(), root);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite* recharge_bkg = CCSprite::create("Recharge_bkg.png");
    recharge_bkg->setPosition(ccp(size.width/2, size.height/2-5));
    this->addChild(recharge_bkg);
    lColor=ccc3(217,195,118);
    tableView=CCTableView::create(this, CCSizeMake(420, 490));
    tableView->setAnchorPoint(ccp(0, 0));
    tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setPosition(ccp(37, 140));
    tableView->setDelegate(this);
    this->addChild(tableView);
    //tableView->reloadData();
    
    return true;
}

void GoldRecharge::scrollViewDidScroll(CCScrollView *view)
{
    
}

void GoldRecharge::scrollViewDidZoom(CCScrollView *view)
{
    
}

void GoldRecharge::tableCellTouched(CCTableView *table,CCTableViewCell *cell)
{
    CCLog("you have clicked %d",cell->getIdx());
    //CustomPop::show("Waitting for recharging link!");
    //CCMessageBox("Waitting for recharging link!", "Notice");
}

CCSize GoldRecharge::cellSizeForTable(CCTableView *table)
{
    return CCSizeMake(420, 91);
}

CCTableViewCell* GoldRecharge::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    //if(read.parse(str->getCString(), root))
    //{
        gold=root["gold"];
        CCLog("%d",idx);
        rl->rid=gold[idx]["id"].asInt();
        CCLog("%d",rl->rid);
        //CCLog("%d",idx);
        rl->rmb=gold[idx]["rmb"].asInt();
        //CCLog("%d",rl->rmb);
        //CCLog("%d",idx);
        rl->obtain=gold[idx]["obtain"].asInt();
        //CCLog("%d",rl->obtain);
        rl->present=gold[idx]["present"].asString();
         //CCLog("%s",rl->present.c_str());
    //}
    CCTableViewCell *tableViewCell;//=table->dequeueCell();
    //if (!tableViewCell)
    //{
        tableViewCell=new CCTableViewCell();
        tableViewCell->autorelease();
        CCScale9Sprite *cellSprite=CCScale9Sprite::create("Recharge_item.png");
        cellSprite->setAnchorPoint(CCPointZero);
        cellSprite->setPosition(CCPointZero);
        
        sprintf(mstring, "%d",rl->rmb);
        //CCLog("%s",mstring);
        //CCLog("%s",moneyDesc.c_str());
        CCLabelTTF *rmbText=CCLabelTTF::create(mstring, "hycc.ttf", 20);
        rmbText->setAnchorPoint(CCPointZero);
        rmbText->setPosition(ccp(cellSprite->getContentSize().width/2-75,cellSprite->getContentSize().height/2-15));
        rmbText->setColor(lColor);
        cellSprite->addChild(rmbText);
        
        sprintf(ostring, "%d",rl->obtain);
        //CCLog("%s",sObtain.c_str());
        CCLabelTTF *obtainText=CCLabelTTF::create(ostring, "hycc.ttf", 20);
        obtainText->setAnchorPoint(CCPointZero);
        obtainText->setPosition(ccp(cellSprite->getContentSize().width/2+100,cellSprite->getContentSize().height/2+3));
        obtainText->setColor(lColor);
        cellSprite->addChild(obtainText);
        
        CCLabelTTF *presentText=CCLabelTTF::create(rl->present.c_str(), "hycc.ttf", 20);
        //CCLog("%s",rl->present.c_str());
        presentText->setAnchorPoint(CCPointZero);
        presentText->setPosition(ccp(cellSprite->getContentSize().width/2+100,cellSprite->getContentSize().height/2-32));
        presentText->setColor(lColor);
        cellSprite->addChild(presentText);
        
        tableViewCell->addChild(cellSprite);
    //}
//    else
//    {
//        CCScale9Sprite *cellSprite=CCScale9Sprite::create("Recharge_item.png");
//        cellSprite->setAnchorPoint(CCPointZero);
//        cellSprite->setPosition(CCPointZero);
//        
//        sprintf(mstring, "%d",rl->rmb);
//        //CCLog("%s",mstring);
//        //CCLog("%s",moneyDesc.c_str());
//        CCLabelTTF *rmbText=CCLabelTTF::create(mstring, "hycc.ttf", 20);
//        rmbText->setAnchorPoint(CCPointZero);
//        rmbText->setPosition(ccp(cellSprite->getContentSize().width/2-75,cellSprite->getContentSize().height/2-15));
//        rmbText->setColor(lColor);
//        cellSprite->addChild(rmbText);
//        
//        sprintf(ostring, "%d",rl->obtain);
//        //CCLog("%s",sObtain.c_str());
//        CCLabelTTF *obtainText=CCLabelTTF::create(ostring, "hycc.ttf", 20);
//        obtainText->setAnchorPoint(CCPointZero);
//        obtainText->setPosition(ccp(cellSprite->getContentSize().width/2+100,cellSprite->getContentSize().height/2+3));
//        obtainText->setColor(lColor);
//        cellSprite->addChild(obtainText);
//        
//        CCLabelTTF *presentText=CCLabelTTF::create(rl->present.c_str(), "hycc.ttf", 20);
//        //CCLog("%s",rl->present.c_str());
//        presentText->setAnchorPoint(CCPointZero);
//        presentText->setPosition(ccp(cellSprite->getContentSize().width/2+100,cellSprite->getContentSize().height/2-32));
//        presentText->setColor(lColor);
//        cellSprite->addChild(presentText);
//        
//        tableViewCell->addChild(cellSprite);
//    }
    return tableViewCell;
}

unsigned int GoldRecharge::numberOfCellsInTableView(CCTableView *table)
{
    return 15;
}








