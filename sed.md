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
s是substitute（替换）的缩写，可省略。引号可省略。

    sed 's/pattern/replace' file
    sed '/pattern/replace' file
    sed 's/pattern/replace/g' file
    sed '1,3s/pattern/replace/g' file
* g 替换改行所有匹配。不加g，则只替换第1个

*****
##选项
###e
组合多个替换命令。
```bash
sed -e 's/01/JAN/' -e 's/02/FEB/' -e 's/03/MAR/' -e 's/04/APR/' -e 's/05/MAY/' \
-e 's/06/JUN/' -e 's/07/JUL/' -e 's/08/AUG/' -e 's/09/SEP/' -e 's/10/OCT/' \
-e 's/11/NOV/' -e 's/12/DEC/'
```
###f
可以把替换命令都放到一个文件里，用**-f**来指定就可以了。
###i
将修改保存。无此选项，所有修改只会打印到屏幕而不会保存到文件。
###n
和p联用，打印符合条件的行。当然此时p打印不会重复

比如：

    sed -n '/0\.[0-9][0-9]$/p' filename
