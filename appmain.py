#coding:utf8

import os
if os.name!='nt' and os.name!='posix':
    from gtwisted.core.internet import epollreactor
    epollreactor.install()

import json,sys
from gfirefly.server.server import FFServer

if __name__=="__main__":
    args = sys.argv
#     args = ['python','admin','config.json']#单独启动一个服务
    servername = None
    config = None
    if len(args)>2:
        servername = args[1];
        config = json.load(open(args[2],'r'))
    else:
        raise ValueError
    dbconf = config.get('db')
    memconf = config.get('memcached')
    sersconf = config.get('servers',{})
    masterconf = config.get('master',{})
    serconfig = sersconf.get(servername)
    ser = FFServer()
    ser.config(serconfig, dbconfig=dbconf, memconfig=memconf,masterconf=masterconf)
    ser.start()
    
    