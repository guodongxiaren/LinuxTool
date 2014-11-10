telnet服务端与客户端
====================
安装telnet服务
=============
##下载
CentOS：

    yum install telnet-server
Ubuntu:  
有三个可选安装包：
  * telnetd-ssl 
  * telnetd 
  * inetutils-telnetd 
 
选择一个安装：  
    
    apt-get install telnetd

##开启telnet服务
以上安装命令完成后，会自动在`/etc/xinetd.d/`目录下，生成一个文件**telnet**：  
内容如下：
```
# default: on
# description: The telnet server serves telnet sessions; it uses \
#	unencrypted username/password pairs for authentication.
service telnet
{
	disable	= no
	flags		= REUSE
	socket_type	= stream        
	wait		= no
	user		= root
	server		= /usr/sbin/in.telnetd
	log_on_failure	+= USERID
}
```
开启xinet服务，就等于开启了telnet服务：

    service xinetd start
