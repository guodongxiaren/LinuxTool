grep学习笔记
============
原型为ex编辑器中`g/RE/p`：global、Regular Expression、print
------------
##基本格式

    grep word filename filename
在多个文件中查找word。例如：

    grep echo hello.sh hi.sh
##退出状态
|$?|描述|
|:----:|-----|
|0|查找模式成功|
|1|找不到模式|
|2|找不到要搜索的文件|
##常用选项
###-q
`quiet`，不打印搜索结果到标准输出。
###-v
**-v**，`--invert-match`意为反转匹配，即打印不匹配的行。比如：

    grep -v '#' hello.cpp
将打印不以`#`开头的行。


