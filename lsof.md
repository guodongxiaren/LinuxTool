lsof
====
list open file 列出打开的文件描述符
##输出信息
```
COMMAND    PID  TID    USER   FD      TYPE             DEVICE  SIZE/OFF       NODE NAME
systemd      1         root  cwd       DIR              253,1      4096        128 /
systemd      1         root  rtd       DIR              253,1      4096        128 /
systemd      1         root  txt       REG              253,1   1214408    8702666 /usr/lib/systemd/systemd
```
|字段|说明|
COMMAND|进程的名称
PID|进程标识符
USER|进程所有者
FD|文件描述符 
TYPE|文件类型，如DIR、REG等
DEVICE|指定磁盘的名称（如主设备号，次设备号）
SIZE|文件的大小
NODE|索引节点（文件在磁盘上的标识）
NAME|打开文件的确切名称

###FD字段
- cwd:当前工作目录
- txt:文件的程序代码（代码段）
- mem:直接映射到内存中的文件（比如动态库）
- rtd:表示用户根目录
- 数字（fd值）+字母（含义如下）
  - u:可读可写
  - r:可读
  - w:可写
  - W:写锁
  
##常用选项
|选项|描述
|:---:|----
|-a|两个参数都满足时才显示结果
|-c `string`|显示COMMAND字段包含string的进程打开的文件
|-u `username`|显示指定用户进程打开的文件
|-p `pid`|显示指定进程打开的文件
|-n|同netstat的`-n`
|-t|仅显示PID（打开了fd的进程）

###-i
显示**socket**文件描述符(建议以root身份使用)：

    lsof -i [46] [protocol] [@hostname|ipaddr] [:service|port]

|参数|说明
|-----|----
|[46]|4表示IPv4协议；6表示IPv6协议
|[protocol]|表示运输层协议：tcp、udp
|[@hostname|ipaddr]|指定主机名或IP地址
|[:service|port]|指定服务名或端口号

比如查看22端口（ssh）有没有被监听：
```
lsof -i 4 :22
lsof -i6 :22
```
>sshd，会打开IPv4和IPv6两个套接字
