# diabloworld

## 整理方案
- 守 先跑起来
- 破 破译优化
- 离 走我路


## 搭建说明

### pymysql
替换所有的MySQLdb调用为pymysql
```
import pymysql
pymysql.install_as_MySQLdb()
```

### firefly
替换所有的firefly为gfirefly