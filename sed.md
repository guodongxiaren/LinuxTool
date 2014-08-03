sed
===
sed全称stream editor。其处理文本的理念为搜索替换。
---
##基本格式

    sed '/pattern/replace' filename
pattern是正则的模式串
replace代表要替换的内容
filename是要处理的文件名
##命令
###p
打印，但是会重复打印一行

    sed '/key/p' filename
在文件中搜索包含key的行，打印的时候会重复打印两遍
>若不指定关键字，比如`sed p filename`那么会打印所有行两遍。

###s
    sed 's/pattern/replace' file
    sed '/pattern/replace' file

*****
##选项
###n
和p联用，打印符合条件的行。当然此时p打印不会重复

比如：

    sed -n '/0\.[0-9][0-9]$/p' filename

