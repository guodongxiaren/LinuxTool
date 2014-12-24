过滤器
========
多用于文本处理
- [x] 基本操作
* [cat](#cat)
* [tac](#tac)
* split
* [rev](#rev)
* head
* tail
* colrm
- [x] 比较
* cmp
* comm
* [diff](#diff)
* sdiff
- [x] 抽取
* [cut](#cut)
* paste
- [x] 格式化
* nl
* [wc](#wc)
* expand
* unexpand
* fold
* fmt
* pr
- [x] 其他
* look
* [uniq](#uniq)
* join
* [sort](#sort)
* tsort
* strings
* [tr](#tr)

>该目录的索引借鉴的《Unix&Linux大学教程》一书

##sort
排序

|常用选项|描述|
|:------:|----|
|u|去除重复行
|r|倒序
|f|忽略大小写
|n|基于数字排序
##uniq
`unique`是唯一的意思。就是去除掉文件中的重复行。  
但是只能去除相邻行中的重复行。  
也就是说，如果重复发生在不相邻的行，是不能被去掉的。所以uniq一般与sort联用。
>这大概就是KISS原则的体现吧。 

###-d
`uniq -d`去除重复行。  
同样要记得和sort联用。  
>一次，在一个Linux群里，一个群友的公司，生产的产品包装盒上的条码有重复，
他想找出重复条码。条形码文件有上万行，他公司电脑是Windows的，本来他想写一个python脚本来解决的，
后来实现起来也有点麻烦，我就帮他用uniq -d命令来实现了。开始我没有排序。
发现没有任何输出。后来我加上sort排序，再使用uniq，就找出了，有重复行的四条记录。

##cat
* 打印文本内容
* 进行多个文件的连接，并打印
* 通过重定向，将标准输入的回显写入文件中

>cat的由来，很多人认为是concatenate(连接)的缩写。  
其实不然，他是古老的单词catenate，意味着to join in a chain。
catena是chain的拉丁语单词。
----《Unix&Linux大学教程》

##tac
与cat相反，它会按行反序打印文本。
##rev
将字符反序。
##cut
##wc
统计文本内信息的数量

|常用选项|描述|
|:------:|----|
|l|只统计行数|
|w|只统计单词数|
|m|只统计*字符*数|
|c|只统计*字节*数|
|L|最大行的长度|
不管指定选项的顺序如何，其信息显示的顺序都是固定的，遵从上面从上到下的顺序。

若不加参数，则默认显示l，w，m三项。
##tr
##diff
##aspell
拼写检查，只能检查英文，故不常用
