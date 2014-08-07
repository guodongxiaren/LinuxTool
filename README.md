README
======
本目录中介绍Linux常用的工具，还有常用操作及其命令
------
目录

|名称|描述|
|:-------------:|-----|
|[adb](./adb.md)|跨平台安卓手机管理调试工具|
|[bc](./bc.md)|支持浮点运算及其他功能的高级计算器|
|[gcc](./gcc.md)|GNU/Linux下C语言编译器|
|[gdb](./gdb.md)|GNU/Linux下C语言调试器|
|[grep](./grep.md)|常用支持正则表达式的搜索工具|
|[MySQL](mysql.md)|强大的开源跨平台数据库|
|[Vim](./vim.md)|Unix/Linux下强大的编辑器|
|[文本](./Text.md)|文本处理相关工具和命令介绍|
|[软件](./Software.md.md)|Ubuntu下软件相关的命令介绍|
|[文件](./File.md)|Ubuntu下文件操作的命令介绍|
|[系统](./System.md)|Linux系统，磁盘管理相关介绍|
|[压缩](./Compress.md)|压缩，解压及打包的工具命令介绍|


Get Started
=========
接下来介绍下在Linux系统装完之后，要掌握的基本概念，常用命令及操作
---------
##root
root是Linux下最高权限的用户，类似Windows下的管理员administer。
###切换到root

    su
然后输入密码即可切换到root用户
>注意
>>在Linux系统刚被装上之后，有时候默认情况下root账户是被锁定的，即使你`su`，并且敲了正确密码，也会提示密码错误。
>>>此时键入`sudo passwd`然后根据提示再重新键入几次密码，root用户的权限就解锁了。该命令也可用于修改root密码。

###退出root
最快捷的方式就是按组合键 Ctrl+D

##Tips
###上下键
通过上下键可以翻阅历史命令。而无需重新键入相同命令。
###Tab键
在一个命令未输完的时候，按两下Tab键会出现命令补全提示。

比如按下`w`再按两次Tab，出现
```
w                     which                 wpa_action
wait                  while                 wpa_cli
wall                  whiptail/             wpa_passphrase
watch                 who                   wpa_supplicant/
wc                    whoami                wpp
webapp-container/     whoopsie/             w.procps
webbrowser-app/       whoopsie-preferences/ wps
weblint               wipefs                wps_error_check.sh
wftopfa               wish                  wrestool
wget/                 wish8.6               write
whatis                wodim/                
whereis               word-list-compress   
```
##授人以渔
###常看man手册
如果你对某个命令的用法不熟悉，可以使用`man`命令来查看。如

    man ls
可以查看`ls`命令的用法。
###Linux下的info
man是Unix系统的产物，而Linux也提供了自己的解决方案 <kbd>info</kbd>。

info与man功能相同，但是提供的手册却更为人性化，更具友好性。
