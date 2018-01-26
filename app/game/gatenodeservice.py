#coding:utf8
'''
Created on 2013-8-14

@author: lan (www.9miao.com)
'''
from gfirefly.server.globalobject import GlobalObject
from gfirefly.utils.services import CommandService


remoteservice = CommandService("gateremote")
GlobalObject().remote['gate']._reference.addService(remoteservice)


def remoteserviceHandle(target):
    """
    """
    remoteservice.mapTarget(target)


