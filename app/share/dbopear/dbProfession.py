#coding:utf8
'''
Created on 2013-8-14

@author: lan (www.9miao.com)
'''
from gfirefly.dbentrust.dbpool import dbpool
import pymysql

from pymysql.cursors import DictCursor


tb_Profession_Config = {}


def getProfession_Config():
    '''获取职业配置表信息'''
    global tb_Profession_Config
    sql = "select * from tb_profession"
    conn = dbpool.connection()
    cursor = conn.cursor(DictCursor)
    cursor.execute(sql)
    result = cursor.fetchall()
    cursor.close()
    conn.close()
    for _item in result:
        tb_Profession_Config[_item['preId']] = _item


