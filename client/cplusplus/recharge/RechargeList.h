//
//  RechargeList.h
//  tsDemo
//
//  Created by jie on 13-9-5.
//
//

#ifndef __tsDemo__RechargeList__
#define __tsDemo__RechargeList__

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//struct RechargeList
//{
//    int rid;
//    int rmb;
//    int obtain;
//    string present;
//}sr[15];
//string sMoney,sObtain;
//stringstream moneyDesc,obtainDesc;

class RechargeList
{
public:
    int rid;
    int rmb;
    int obtain;
    string present;
    static RechargeList *getInstance();
    ~RechargeList();
};


#endif /* defined(__tsDemo__RechargeList__) */
