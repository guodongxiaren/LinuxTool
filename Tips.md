各种Tip
=======
接下来介绍下在Linux系统装完之后，要掌握的基本概念，常用命令及操作
---------
##root
root是Linux下最高权限的用户，类似Windows下的管理员administer。
###切换到root

    su
然后输入密码即可切换到root用户
>注意
>>在Ubuntu系统刚被装上之后，有时候默认情况下root账户是被锁定的，即使你`su`，并且敲了正确密码，也会提示密码错误。
>>>此时键入`sudo passwd`然后根据提示再重新键入几次密码，root用户的权限就解锁了。该命令也可用于修改root密码。

###退出root
最快捷的方式就是按组合键 Ctrl+D

##Bash相关
###上下键
通过上下键可以翻阅历史命令。而无需重新键入相同命令。
###Tab键
在一个命令未输完的时候，按两下Tab键会出现命令补全提示。
###Alt+.
`Alt`和`.`组合键可快速调用上一个命令的参数。
不过如果上一个命令有多个参数，则只能调用最后一个参数。
###Ctrl相关
|组合键|描述|
|------|-----
|Ctrl+Z|发送susp信号，暂停当前程序，丢入后台运行
|Ctrl+C|发送intr信号终止当前程序
|Ctrl+D|发送EOF信号
|Ctrl+L|清屏
|Ctrl+H|erase信号，删除光标前一个字符
|Ctrl+W|werase信号，删除光标前一个单词
|Ctrl+U|kill信号，删除光标前该行所有内容
|Ctrl+X|在行首和行尾之间切换光标
|Ctrl+R|搜索历史命令
|Ctrl+S|发送stop信号，暂停屏幕输出
|Ctrl+Q|发送start信号，恢复屏幕输出
>所有的Ctrl键都可以通过键入^字符来代替。
>Ctrl+S只是暂停输出，但并不暂停程序运行

##^
###删除
使用^删除上一个命令多余部分。
```shell
cp fooo.c test.c
^o
#等于cp foo.c test.c
```
只会删除掉第一个匹配的字符
###替换
使用^old^new替换上一个命令
##!
!是用于快捷输入历史命令的
###!!
!!执行上一个命令  
```shell
apt-get install vsftpd
#提示没有权限
sudo !!
```
###!foo与!?foo
!foo执行以foo开头的命令  
!?foo执行包含foo的命令
###!n
使用!n执行第n个命令。
n可以是负数，即倒数第几个命令
###`!#`
单独的`!#`是引用当前行。  
!#:n 引用当前行的第n个参数。
###!:
引用上一个命令的参数。参数索引从0算起。
```shell
#引用上一个命令的第0个参数（实际上是引用命令）
!:0
#引用上一个命令的第2个参数
[root@localhost ~]#mv test Test
[root@localhost ~]#echo !:2
echo Test   ( 命令回显)
Test
#引用上一个命令的第1到3个参数
!:1-3
#引用上一个命令的第2个参数开始的所有参数
!:2*
#引用上一个命令的所有参数
!*
```
###!^和!$
```shell
#引用上一个命令的第一个参数
[root@localhost ~]# mv Test/ test/
[root@localhost ~]# echo !^
echo Test/
Test/
#引用上一个命令的最后一个参数
[root@localhost ~]# mv Test/ test/
[root@localhost ~]# echo !$
echo test/
test/
```
###:选取
需要配合历史命令,一起工作。比如`!$:r`
* :h,选取路径的开头，相当于dirname  
* :t,选取路径的结尾，相当于basename  
* :r,选取文件名，即不包含后缀  
* :e,选取文件的后缀名  
* :p,打印  
* :s,替换，比如`!:s/ti/it`。（更简便的写法：^ti/it）  
* :gs,全局替换，不加g的话，只替换第一个匹配  
* :u,变成大写。比如`!$:u`  
* :l,变成小写。比如`!$:l`  


##授人以渔
高手是善于寻找帮助的人
###man
如果你对某个命令的用法不熟悉，可以使用`man`命令来查看。如

    man ls
可以查看`ls`命令的用法。
###info
man是Unix系统的产物，而Linux也提供了自己的解决方案 <kbd>info</kbd>。
info中带星号的行，按回车可以跳进新的页面，按shift+u返回。
>原先info要优秀与man，但近代以来差异已经不大。info逐渐没落，极少更新。
建议使用man

###tldp.org
The Linux Document Project
一个Howto网站。
###doc 
查看 `/usr/share/doc/`
###百度谷歌
    内事不决问百度，外事不决问谷歌
如果找不到中文资料，那么要去谷歌找英文资料，谷歌比百度要强大丰富的多。
不过需要搜索英文。


