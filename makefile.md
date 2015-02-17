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
.PHONY clean
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
###:=
给变量增加值的使用使用**:=**操作符。  
比如：
```
$(OBJ):= main
```
请注意，如果:=后面也是以变量的形式给出的，那么后面这个变量一定要在前面已定义。

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
在变量的$()之中使用
###filter
举例：

    $(filter %.o,$(files))
表示在变量files中进行过滤，仅保留模式为%.o的内容。
