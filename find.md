find
====
常用查找文件的命令。  
以下选项都要以-开头
##基本格式
    find 路径 -选项 参数 ...
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


