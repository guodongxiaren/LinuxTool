系统管理
========
##df
df命令 报告磁盘上文件系统的挂载情况。
>>df为disk和filesystem之意

输出结果比如：

    文件系统       1K-blocks    已用     可用  已用% 挂载点
    /dev/sda8       38826448 6610444 30220692   18% /
    none                   4       0        4    0% /sys/fs/cgroup
    udev             4042472       4  4042468    1% /dev
    tmpfs             817248    1164   816084    1% /run
    none                5120       0     5120    0% /run/lock
    none             4086228     152  4086076    1% /run/shm
    none              102400      52   102348    1% /run/user
    /dev/sda7         274407   93785   161934   37% /boot
    /dev/sda9       78689200 4145188 70523788    6% /home

##dumpe2fs
显示 ext2/ext3/ext4 文件系统的信息

###dumpe2fs /dev/sda8

