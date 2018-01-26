#coding:utf8

import os
if os.name!='nt' and os.name!='posix':
    from gtwisted.core.internet import epollreactor
    epollreactor.install()

if __name__=="__main__":
    from gfirefly.master.master import Master
    master = Master()
    master.config('config.json','appmain.py')
    master.start()
    
    