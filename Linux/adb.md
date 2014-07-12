android调试工具adb
=====
adb是跨平台的，各种平台都有。因为Linux上缺乏GUI的android手机管理工具，所以adb的使用变得尤为重要
-----
##查看设备

    adb devices
该命令可以查看连接到PC上的android手机。
##重启设备

    adb reboot
    
##安装与卸载软件
###安装apk

    adb install abc.apk
在开启了usb调试的android手机连接以后，可以用此命令将PC上的abc.apk发送到手机端并安装。
###重修安装apk

    adb install -r abc.apk
    
###卸载软件
卸载软件，需要知道软件的`包名`,比如：

    adb uninstall com.sina.weibo
