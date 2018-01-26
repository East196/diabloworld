# diabloworld

## 整理方案
- 守 先跑起来
- 破 破译优化
- 离 走我路


## 搭建说明

### pymysql
替换所有的MySQLdb调用为pymysql
替换所有的cusorclass=为空格

### gfirefly
替换所有的firefly为gfirefly
pip install pyzmq

替换所有from gevent-zmq为空格

### gtwisted
框架内部已经换成gtwisted了
外部还有少量的twisted修改的时候慢慢换吧