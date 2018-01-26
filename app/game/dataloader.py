#coding:utf8
'''
Created on 2013-8-14

@author: lan (www.9miao.com)
'''
from gfirefly.dbentrust.madminanager import MAdminManager

import memmode
from app.share.dbopear import dbItems, dbMonster, dbExperience, dbSkill, \
    dbProfession, dbZhanyi, dbDropout, dbShieldWord, dbCharacterPet


def load_config_data():
    """从数据库中读取配置信息
    """
    dbItems.getAll_ItemTemplate()
    dbItems.getAllsetInfo()
    dbMonster.getAllMonsterInfo()
    dbExperience.getExperience_Config()
    dbSkill.getAllSkill()
    dbSkill.getBuffAddition()
    dbSkill.getBuffOffsetInfo()
    dbSkill.getAllBuffInfo()
    dbProfession.getProfession_Config()
    dbZhanyi.getAllZhangJieInfo()
    dbZhanyi.getAllZhanYiInfo()
    dbDropout.getAll()
    dbShieldWord.getAll_ShieldWord()
    dbCharacterPet.getAllPetGrowthConfig()
    dbCharacterPet.getAllPetTemplate()
    dbCharacterPet.getPetExp()
    dbCharacterPet.getPetTrainConfig()

    
def registe_madmin():
    """注册数据库与memcached对应
    """
    MAdminManager().registe(memmode.tb_character_admin)
    MAdminManager().registe(memmode.tb_zhanyi_record_admin)
    MAdminManager().registe(memmode.tbitemadmin)
    MAdminManager().registe(memmode.tb_matrix_amin)
    
    
    
    
    