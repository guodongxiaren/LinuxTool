samba服务器
===========
基于SMB协议，最初不可路由（只能用于局域网），近年来可以用于互联网，但很少这样用。
>我称之为`桑巴`。

smb.conf文件
------------
ubuntu/red hat下都是在`/etc/samba/smb.conf`。
其他发行版位置可能不同，但都叫做`smb.conf`。
###注释
注释分两种。
`#`开始的行，是samba的描述。`;`开始的行是有效设置行，只是当前不启用，用`;`注释掉。
###设置段
|设置段|描述|
|------|------|
|[global]|设置全局环境变量选项|
|[homes]|设置用户宿主目录共享|
|[printers]|设置打印机共享|
|[sharefiles]|设置文件共享|

####global
* **workgroup** 指定工作组或域
* **server string** 描述
* **security** 指定安全模式
  * **share** 无权限验证
  * **user** 缺省，推荐，由Linux Samba服务器验证
  * **server** 较少使用。第三方主机验证
  * **domain** 较少使用。第三方主机验证（第三方必须是Windows的域控制器）
* **hosts allow** 限定主机访问
* **log file** 指定日志文件存放位置
* **max log size** 指定日志文件大小

hosts allow 只需指定网段，不需要主机名。

    hosts allow = 127. 192.168.12. 192.168.13.

smbclient
---------
    smbclient //192.168.1.107/share -U jelly
上面IP是局域网内的Windows主机的地址。share是该主机上的共享文件夹。jelly是该主机上的用户。    
命令成功后，将出现一个smb命令提示符的界面。可以用help查看支持的命令。
在这里没我们可以进行创建文件等等操作，所有所做都作用在share文件夹中。

smbpasswd
---------
|选项|描述|
|-----|----|
|a|添加用户到smbpasswd文件
|x|删除用户
