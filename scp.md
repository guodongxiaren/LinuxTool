scp
====
两个主机间的文件复制命令，不同于rsync，scp是全量复制。使用需谨慎。

## 格式
```
scp 本地文件 远程用户名@远程主机IP:远程路径
```
拷贝目录，要在scp后面加**-r**选项（不要把-r放到命令最后）。

举例：
```
scp /usr/lib/libxxx.so root@123.123.123.123:/usr/lib/\
scp -r /usr/lib root@123.123.123.123:/usr/
```
