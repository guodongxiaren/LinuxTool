Makefile
========
#注释
以`#`开头
##基本格式
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
##clean
比如：
```
clean:
    rm *.o
    rm main
```
make命令执行时，并不会执行clean。以make clean的方式单独执行才可以。
##变量
```
objects = main.o getdata.o calc.o putdata.o
main:$(objects)
    gcc -o main $(objects)
```

###特殊变量
|变量|描述|
|----|----|
|**$@**|目标文件
|**$^**|所有依赖文件|
|**$<**|第一个依赖文件|
```
main:main.o getdata.o calc.o putdata.o
    gcc -o $@ $^
```
##通配符
支持Unix常用的三个通配符：`*`,`?`,`[]`
