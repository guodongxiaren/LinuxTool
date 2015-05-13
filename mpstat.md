mpstat
======
multi-processor statistics。实时监测多处理器上每个CPU的使用情况。
>Linux系统上安装的时候，需要安装的软件包是sysstat。

##命令格式

    mpstat 选项 参数
##选项
###I
`  -I { SUM | CPU | SCPU | ALL }`
报告中断的信息。 
|参数|说明
|----|---
|SUM|报告每个CPU每秒收到的中断总数
|CPU|报告每个CPU每秒收到的每种中断的次数
|SCPU|报告每个CPU每秒收到的每种软中断的次数
|ALL|展示上面的所有信息

###P
` -P { cpu [,...] | ON | ALL }`
指定要检测的CPU号（0～n-1）。ALL表示检测所有CPU。ON表示只监测在线（在工作）的CPU。
###u
报告CPU的状态，其输出信息见下面的命令输出。
###A
等价于`-u -I ALL -P ALL`
##其他参数
###interval
指定采样间隔。
###count
指定采样次数
比如`mpstat 5 2`
##命令输出
```
时间戳 CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
```

