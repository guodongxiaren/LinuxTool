网络设置
========
##ifconfig
配置网络地址接口，显示MAC地址，用冒号`:`分割。
>Windows下是使用`ipconfig/all`显示MAC地址，用`-`分割。

##域名
域名分几个等级：根域（.）、顶级域（com，net，org...）、二级域（baidu，sina...）...主机（www）

在浏览器地址栏输入域名，比如`baidu.com`浏览器会自动的补全**www**，但如果你使用`baidu.com.`（.为根域），那么浏览器不会自动补全，你需要自己补全。
##hosts文件
古老的一个域名和ip地址映射文件，目前不鼓励使用，但是所有系统都保留该文件。
尽管保存位置不尽相同（ubuntu是/etc/hosts），但是功能都支持。系统一般是先查找hosts文件，然后查找DNS文件。
##虚拟网卡
    ifconfig eth0:1 192.168.2.3
`eth0:1`为虚拟网卡名，接着可以`:2`,`:3`...

##chkconfig
Ubuntu的启动机制Upstart是没有chkconfig的，只有包含SysV中init启动机制的系统才有chkconfig
###列出所有开机自启的服务
    chkconfig --list
###在自启动列表中添加/删除服务
    chkconfig --add NAME
    chkconfig --del NAME
NAME指的是服务的名称
##traceroute
检查到达某一主机中间所经过的主机。默认为udp包。  Windows上类似的命令叫做tracert
`traceroute www.baidu.com`
##-I
发送icmp报文。有时候，如果使用了路由器，会导致udp包的响应功能消失。从而显示星号。
此时可以使用-I选项（或-T，不过有时候-T不管用）