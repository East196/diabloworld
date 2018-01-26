#coding:utf8
'''
Created on 2013-10-25
阵法信息
@author: lan (www.9miao.com)
'''

from app.game.gatenodeservice import remoteserviceHandle
import json
from app.game.appinterface import pet


@remoteserviceHandle
def GetCharacterMatrixInfo_2306(dynamicId,request_proto):
    '''获取角色阵法的信息
    '''
    argument = json.loads(request_proto)
    characterId = argument.get('characterId')
    response = pet.GetCharacterMatrixInfo(dynamicId, characterId)
    return json.dumps(response)
    
    
@remoteserviceHandle
def GetAllPetList_2300(dynamicId,request_proto):
    '''获取角色的所有宠物信息
    '''
    argument = json.loads(request_proto)
    characterId = argument.get('characterId')
    response = pet.GetAllPetListFormatForWeixin(dynamicId, characterId)
    return json.dumps(response)
    
    
@remoteserviceHandle
def SetCharacterMatrix_2307(dynamicId,request_proto):
    '''设置角色的阵法
    '''
    argument = json.loads(request_proto)
    characterId = argument.get('characterId')
    setting = argument.get('setting')
    response = pet.SettingMatrix(dynamicId, characterId, setting)
    return json.dumps(response)
    
