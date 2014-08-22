Makefile
========
##基本格式
```
目标:条件集合...
    命令1
    命令2
```
命令前面必须有一个Tab，而不是空白符。
举例：
```
main:main.o getdata.o calc.o putdata.o
    gcc -o main main.o getdata.o calc.o putdata.o
```
##clean
比如：
```
clean:
    rm *.o
    rm main
```
make命令执行时，并不会执行clean。以make clean的方式单独执行才可以。
