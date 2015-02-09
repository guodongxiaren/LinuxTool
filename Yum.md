RedHat系列软件包管理器Yum
======
功能同Ubuntu的APT。命令格式为yum+选项 [参数]
##安装
    yum install 软件名

支持*。
##列出已安装或可用软件包
    yum list
##查看yum软件源
    yum repolist all

软件源即repository server（仓库服务器）。在`/etc/yum.repos.d/`下面
##搜索软件、命令所在的软件包
    yum search 名称
##生成缓存
    yum clean
    yum makecache
每次修改了yum源之后可以调用，这两个命令生成新的缓存
