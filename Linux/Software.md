#软件
>注意！本文探讨的关于软件操作的命令属于`系统相关`的命令，仅适用于Debian系列衍生版。
- [x] Debian
- [x] Ubuntu
- [ ] Red Hat
- [ ] Cent OS 

##卸载软件
卸载命令有多条，但是不可获缺的一个操作是首先要知道该软件的包名
```bash
dpkg -l|grep wps
```
上述命令用于Debian系列Linux系统中。dpkg软件包管理机制中的 `-l` 参数能显示已安装软件的列表。接下来的`grep wps` 是查找和wps相关的软件包。<br>
屏幕上会可能显示出一个

    wps-office

然后我们执行卸载命令
```
sudo apt-get purge wps-office
或者
dpkg -p wps-office
```
-p参数等同于--purge
##aptitude
`aptitude`是个比apt-get更高级的包管理工具，它在解决依赖性问题上更胜一筹。不过它没有被预装，要自己安装。

    sudo apt-get aptitude
卸载命令形如：

    sudo aptitude wine1.6
会自动解决依赖问题。
##暴力卸载软件
如果温柔的卸载方式，不起作用的话，那么就来点暴力的，直接删除。

1. 安装文件如果在/目录中，那么一般位置，就是/usr/local。
2. 但是即使删除以后，在软件管理器中还会残留这个软件的图标，此时是无效链接了。
3. 删除残留文件，残留文件一般在/usr/share中有其文件夹，在/usr/share/applications中有其图标。

##查看文件最后修改时间

    stat 文件名  
##查看命令的所在位置

    which java
    which adb
可以显示java，adb的所在位置
