crontab计划任务
============
##安装启动
CentOS下：

	yum install vixie-cron
	yum install crontabs
安装前者一般会同样安装上后者。 
  
	service crond start
要启动该服务才行。
##系统级crontab
用ls /etc/cron然后敲两下TAB，可以看到相关文件及目录。

    cron.d/     cron.daily/   cron.hourly/  cron.monthly/ crontab   cron.weekly/
###文件及目录解读
我们可以编辑crontab文件，来创建计划任务。 
而以daily，hourly，weekly，monthly后缀的目录下分别存放每天，每月，每周，每月执行的任务。  
其中存放的就是Shell脚本文件。权限755。  
而不规则周期的计划任务放在corn.d目录下面。可以看做是crontab文件的补充。
###crontab文件格式
该文件开头包含必要的环境变量，不再介绍。  
具体写法直接看源文件注释：
```
 .---------------- minute (0 - 59)
 |  .------------- hour (0 - 23)
 |  |  .---------- day of month (1 - 31)
 |  |  |  .------- month (1 - 12) OR jan,feb,mar,apr ...
 |  |  |  |  .---- day of week (0 - 6) (Sunday=0 or 7) OR sun,mon,tue,wed,thu,fri,sat
 |  |  |  |  |
 *  *  *  *  * user-name command to be executed
 ```
 一共七个字段，其含义一目了然。需要注意的是每个字段的写法。
 * `*`表示每一个。比如minute字段下的`*`表示每一分钟执行
 * `*/n`表示每隔n。比如hour字段下，`*/2`表示每隔两小时执行。0-10/2表示1,3,5,7,9
 * `1-5`这种格式表示一共连续的时间段
 * `1,3,5`这种格式是枚举几个不连续的时间段
 
 >注意：第三个字段‘天’和第五个字段‘星期几’是或的关系。所以不会冲突，符合两种情况都执行。  
该文件中如果出现%要进行转义，比如date +%w 在该文件内编写的时候要写成date +\%w   
把分钟设置成`*`要慎重

##crontab命令（用户级）
###命令选项
    crontab [-u user] file
    crontab [-u user] [-e|-l|-r]

|选项|描述|
|----|:----:|
|e|编辑计划任务|
|l|列出计划任务|
|r|删除计划任务|
|i|删除之前确认|
|u|指明所属用户|
|s|selinux context|
s选项不常用。
>实际上该命令编辑的是`/var/spool/cron/用户名`文件。  
所以你也可以直接编辑该文件。
守护进程crond每分钟会读取该文件一次。

###编写格式。
格式与前文中crontab文件的编写格式相仿，但是没有用户user-name字段。
因为该命令只能编写当前用户的计划任务。
##日志
在`/var/log/cron`下面可以看到全部日志。  
而`/var/spool/cron/`在下面也可以看到一定的日志。 