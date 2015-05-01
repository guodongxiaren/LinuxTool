Makefile
========
##注释
以`#`开头
###基本格式
```
目标:条件集合（依赖关系）...
    命令1
    命令2
```
命令前面必须有一个Tab，而不是空白符。
举例：
```
main:main.o getdata.o calc.o putdata.o
    gcc -o main main.o getdata.o calc.o putdata.o
```
最终生成的目标文件一定要在第一行被定义。

##伪目标
定义了目标，但却不会实际生成（比如clean）。它只是一个**标号**，它的命令也不会被make隐式调用，只能显式地调用
（比如make clean）。
###.PHONY
因为伪目标可能和真实目标重名，这时用**.PHONY**关键字来指定伪目标，这时无论是否有重名的真目标，该名称都视作伪目标处理。
即只能显式调用。
用法如：
```
.PHONY:clean
clean:
    rm *.o
    rm main
```

##变量

```
objects = main.o getdata.o calc.o putdata.o
main:$(objects)
    gcc -o main $(objects)
```
###各种=
|符号|描述
|----|----
|=|基本赋值
|:=|覆盖之前的值
|?=|如果没有被赋值就赋予等于号后面的值
|+=|给变量添加等于号后面的值

>:= 类似与C语言中简单的宏替换。比如 a:=$(b) 后面是一个变量的话，
那么当b值变化的时候，a的值不会发生变化。 = 则不然。

```
请注意，如果:=后面也是以变量的形式给出的，那么后面这个变量一定要在前面已定义。
```
###特殊变量
|变量|描述|
|----|----|
|**$@**|目标文件
|**$^**|所有依赖文件|
|**$<**|第一个依赖文件|
|**$?**|依赖文件列表中被改变过的文件
|VPATH|文件搜索路径
前4个称为自动化变量
```
main:main.o getdata.o calc.o putdata.o
    gcc -o $@ $^
```
##通配符
支持Unix常用的三个通配符：`*`,`?`,`[]`
##关键字
###vpath 
在目录中所有指定文件。  
`vpath <模式> <目录>`  
比如：
```
vpath %.h lib
vpath %.h lib2
```
可以连续使用该关键字

##命令 
支持所有系统命令（/bin/sh）。
###;
如果要使上一条命令的执行结果作用于下一条命令，请在一行写出这两个命令并用分号;间隔。  
比如：
```
exec:
    cd bin/;rm *
```
###@
Make在执行的命令的时候，首先会显示出来要执行的命令，如果给命令加上**@**前缀可使命令不显示。  
比如：
```
a : a.c
    @echo hello
    gcc $< -o $@
```
此时终端打印：
```
hello
gcc a.c -o a
```
如果不加@，则打印
```
echo hello
hello
gcc a.c -o a
```
###- 
在命令前面加上前缀**-**，表示忽略命令的出错，继续执行。

##函数
函数调用方式形如变量的引用。格式为：

	$(函数名 参数列表)
	${函数名 参数列表}
参数的个数，我下面用**元**来表示，多个参数用逗号(*,*)间隔，而非空格。一个参数实际上可以由多个空格间隔的变量组成。
###filter
二元函数，举例：

    $(filter %.o,$(files))
表示在变量files中进行过滤，仅保留模式为%.o的内容。
###filter-out
反过滤函数，与filter相反。
###dir
一元函数，举例：  

	$(dir $@)
提取文件名中的路径名并返回,如果目录有多层则也提取出多层。如果不包含目录，则返回值为`./`（当前目录）
###notdir
与`dir`函数相反，提取出不包含路径名的文件名。
###addprefix
二元函数，给指定变量的值增加前缀。举例：

	$(addprefix src/,foo bar)
返回值是`src/foo src/bar`
###wildcard
一元函数，wildcard是通配符的意思，这里的通配符是指星号--*--而非百分号**%**。举例：

	src=$(wildcard *.c ./lib/*.c)
将当前目录以及lib目录中所有后缀的c的文件名赋值给src
###patsubst
三元函数，函数名是`pattern substitue`（模式替换）的意思。格式：

	$(patsubst 模式1,模式2,变量)
将变量（或常量字符串）中符合模式1的字符串替换成模式2的形式。模式即包含%的模式。
###sort
一元函数，给字符串单词按字典升序排序。举例：

	$(sort foo bar lose)
返回`bar foo lose`。主要sort函数会去掉相同的词。
###word
二元函数，取字符串中第几个单词。举例：

	$(word 3,bar foo lose)
返回`lose`
###strip
一元函数，去除字符串首尾空格。
###foreach
三元函数，类似其他语言中的foreach循环。格式如：

	$(foreach 迭代子,迭代对象,循环体操作)
举例：
```
	//以下代码节选自“蘑菇街”IM服务器项目
	$(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
```
可以理解成java的类似语句
```java
	for(d:SRCDIRS){
		wildcard(addprefix(d,SRCEXTS));
	}
```
