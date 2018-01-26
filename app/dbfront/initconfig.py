#coding:utf8
'''
Created on 2013-8-14

@author: lan (www.9miao.com)
'''
from dataloader import registe_madmin,CheckMemDB,MAdminManager,initData
from gfirefly.server.globalobject import GlobalObject

def doWhenStop():
    """服务器关闭前的处理
    """
    print "##############################"
    print "##########checkAdmins#############"
    print "##############################"
    MAdminManager().checkAdmins()
    
GlobalObject().stophandler = doWhenStop
    

def loadModule():
#     mclient.flush_all()
    registe_madmin()
    initData()
    CheckMemDB(1800)
    
    
    