vmstat
=====
`virtual memory statistics`**实时**输出系统中各种资源的使用情况
##基本格式
	vmstat [选项] [delay[count]]
##缺省输出
缺省情况下（无选项），vmstat的输出内容相当丰富，比如：
```
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 0  0      0 2469012 489604 1451368    0    0    36   131  996 1043 23  4 72  1  0
```
>vmstat功能丰富，实际上**vmstat**命令主要用于查看系统内存的使用情况。我可以使用**iostat**获得磁盘使用情况的更多信息，使用**mpstat**获得CPU使用情况的更多信息。

|procs|进程信息
|:--:|----
|r|（runnable）等待运行额进程数目，即**就绪状态**
|b|（blocked）处于不可中断睡眠状态的进程数目，即**阻塞状态**

|memory|内存信息（单位KB）
|:--:|----
|swpd|交换分区（虚拟内存）的使用数量
|free|空闲内存的数量
|buff|**buffer cache**的内存数量
|cache|**page cache**的内存数量
>buffer cache：从磁盘读入的数据可能被保存在**buffer cache**中，以便下一次快速访问。
>>page cache:待写入的数据首先被放到**page cache**中，然后由磁盘中断程序写入磁盘

|swap|交换分区的使用信息（单位KB/s）
|:--:|----
|si|（swap input）数据由磁盘交换至内存的速率
|so|（swap output）数据由内存交换至磁盘的速率

|io|块的使用信息（单位block/s）
|:--:|----
|bi|（block input）从块设备读入的速率
|bo|（block output）向块设备写入的速率

|sys|系统信息
|:--:|----
|in|每秒发生的中断次数
|cs|每秒发生的上下文切换（进程切换）次数

|cpu|CPU使用信息
|:--:|----
|us|系统所有进程在用户空间的时间占CPU总时间的比例
|sy|系统所有进程在内核空间的时间占CPU总是就的比例
|id|表示CPU处于空闲状态的时间占CPU总运行时间的比例
|wa|表示CPU等待I/O事件的的时间占CPU总运行时间的比例

##参数
- delay:采样间隔（单位s）
- count:采样次数|共输出count次统计信息

delay和count是参数，而非选项，实际使用的时候用数字代替。比如：
```
vmstat 5 3 
```
每个5秒输出一次结果，共输出3次
##常用选项
|选项|描述
|:--:|----
|-f|显示系统自启动以来执行的fork次数
|-s|显示内存相关的统计信息以及多种系统活动的数量
|-d|显示磁盘相关的统计信息 
|-p|需要参数，显示指定磁盘分区的统计信息
|-S|使用指定的单位来显示，如k、K，m，M

###-S
- k：1000
- K：1024
- m：1 000 000
- M：1 048 576

