ipcrm
======
删除System V的三种IPC对象（消息队列、信号量、共享内存）
##基本用法
有两种用法：
```
ipcrm {msg|sem|shm} id ...
ipcrm [选项]
```
##选项
|选项|描述|
|----|-----
|-Q|删除消息队列，以key为参数
|-q|删除消息队列，以id为参数
|-S|删除信号量，以key为参数
|-s|删除信号量，以id为参数
|-M|删除共享内存，以key为参数
|-m|删除共享内存，以id为参数

##相关命令
|命令|描述
|----|-----
|[ipcmk](ipcmk.md)|创建(make)IPC对象
|[ipcs](ipcs.md)|显示(show)IPC对象的信息
