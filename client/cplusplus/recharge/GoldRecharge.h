//
//  GoldRecharge.h
//  tsDemo
//
//  Created by jie on 13-8-27.
//
//

#ifndef __tsDemo__GoldRecharge__
#define __tsDemo__GoldRecharge__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "RechargeList.h"
#include "json.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;

class GoldRecharge:public CCLayer,public CCTableViewDelegate,public CCTableViewDataSource
{
public:
    virtual bool init();
    CREATE_FUNC(GoldRecharge);
    virtual void scrollViewDidScroll(CCScrollView *view);
    virtual void scrollViewDidZoom(CCScrollView *view);
    virtual void tableCellTouched(CCTableView *table,CCTableViewCell *cell);
    virtual CCSize cellSizeForTable(CCTableView *table);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
    
    string path;
    CCString *str;
    Json::Reader read;
    Json::Value root;
    Json::Value gold;
    RechargeList *rl;
    char ostring[20];
    char mstring[20];


private:
    ccColor3B lColor;
    CCTableView *tableView;
};

#endif /* defined(__tsDemo__GoldRecharge__) */
