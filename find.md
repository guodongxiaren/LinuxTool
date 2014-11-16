find
====
常用查找文件的命令。  
以下选项都要以-开头
##基本格式
    find 路径 -选项 参数 ...
##选项
|名称|描述|
|----|-----
|name|按名称查找
|iname|同上，但不区分大小写
|type|文件类型
|perm|权限，其参数为数字
|user|查找属于特定用户
|group|查找属于特定组
|size|查找特定大小
|empty|查找空文件
|amin [-+]n|n分钟前访问
|anewer file|file文件之后访问
|atime [-+]n|n天前访问
|cmin [-+]n|n分钟之前状态改变
|cnewer file|在file之后状态改变
|ctime [-+]n|n天之前状态改变
|mmin [-+]n|n分钟之前修改
|mtime [-+]n|n天之前修改
|newer file|在file文件之后修改

##name/iname
比如： 

    find / -name pattern
    find / -iname pattern
/为路径。pattern代指文件名，可以使用模式，但是要放进引号中，模式才能生效。  
同样只支持glob的模式，即`*、？、[]`三个通配符。    
iname忽略大小写。
##type
    find / -name pattern -type f

搜索指定类型的文件。f表示常规文件。`dbcpl`仍旧表示其他五种文件类型。


