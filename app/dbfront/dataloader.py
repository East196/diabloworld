#coding:utf8
'''
Created on 2013-8-14

@author: lan (www.9miao.com)
'''
from gfirefly.dbentrust.madminanager import MAdminManager
from twisted.internet import reactor

import memmode
from app.share.mcharacter.McharacterManager import McharacterManager

reactor = reactor

def initData():
    """载入角色初始数据
    """
    McharacterManager().initData()
    
def registe_madmin():
    """注册数据库与memcached对应
    """
    MAdminManager().registe(memmode.tb_character_admin)
    MAdminManager().registe(memmode.tb_zhanyi_record_admin)
    MAdminManager().registe(memmode.tbitemadmin)
    MAdminManager().registe(memmode.tb_matrix_amin)
    MAdminManager().registe(memmode.tbpetadmin)
    
def CheckMemDB(delta):
    """同步内存数据到数据库
    """
    MAdminManager().checkAdmins()
    reactor.callLater(delta,CheckMemDB,delta)
    

    
    
    
    