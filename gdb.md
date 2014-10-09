gdb调试器学习记录
=================
|gdb是Linux/Unix系统上强大的调试器。但同时学习起来也让人十分头疼，没有了VS上直观的按键,取而代之的是大量的命令。为此，只有从点滴学起，慢慢积累|![](http://www.gnu.org/software/gdb/images/archer.jpg)
|:-------------------------------|----------------------

##一进一出
###启动gdb

直接使用<kbd>gdb 文件名</kbd>即可调试。此时，将进入gdb的shell。
```bash
gdb a.out
```
>>注意！要调试的文件不是源文件，而是加入了调试信息的可执行文件。

>>编译源文件时，使用`gcc -g`命令添加调试信息。

###退出gdb

<kbd>quit</kbd>简写为`q`,用以退出gdb调试。
>>gdb中的大部分命令会有简写形式

##开始
###file
如果你在gdb命令后没输入要调试的文件名，那么可以在进入了gdb终端后，使用<kbd>file</kbd>命令装载要调试的文件。
###start
在打开gdb调试后，需要在回车后键入<kbd>start</kbd>命令才开始调试。

重定向

    start <in.txt >out.txt

###run
<kbd>run</kbd>简写为`r`。可以中断当前执行的步骤,转而回到程序开始处重新开始调试。

重定向

    run <in.txt >out.txt

###list
<kbd>list</kbd>简写为`l`。用于显示源码。可以直接`list`来打印10行源码。也可以在`list`后面跟上行号。

    list 100
注意，将打印出95-104行的代码，中间那一行就是第100行。
##下一步
###next
<kbd>next</kbd>简写为`n`。执行下一步，`next`不会进入调用的函数内部，类似VS中的F10。

###step
<kbd>step</kbd>简写为`s`。执行下一步，但是`step`会进入调用的函数内部，类似VS中的F11。

<kbd>finish</kbd>命令用于跳出该函数内部，否则`s`命令恐怕就会进入`printf`内部。
###continue
<kbd>continue</kbd>简写为`c`,执行直到遇到断点才中断,类似VS里面F5

>在VS中:
>>F5直到遇到断点才中断
>>>F10单步执行，遇到子函数调用不进入
>>>>F11单步执行，遇到子函数调用会进入

##打印信息
###info
<kbd>info</kbd>简写为`i`，用以查看局部变量的值。写作：

    info locals
  
###print
<kbd>print</kbd>简写为`p`，用以查看单个变量的值。比如我们在执行了
```c
scanf("%d",n);
```
并且键入了n的值之后，可以使用

    print n

来查看此时n的值
###disp
<kbd>disp</kbd>命令可以在每步执行后都自动打印变量的值。

    disp i
要自动打印多个值，需要多条disp命令：

    disp a
    disp b
其打印效果可能如:

    3: b = 3
    2: a = 2
与之相对的一个命令就是<kbd>undisp</kbd>,用于取消自动打印的变量。

    undisp
可以取消所有自动打印的变量。

    undisp 3
可以取消自动打印变量`b`。
>之所以参数是`3`,请查看上面`disp`的打印结果。

##栈帧
在C语言中每一次函数调用都会开启一个新的栈帧。正是因为有不同的栈帧的存在，我们才可以在两个函数中定义出重名的变量。
###backtrace
<kbd>backtrace</kbd>，简写为`bt`。其打印结果可能如：

    #0  add (a=2, b=3) at test.c:5
    #1  0x0000000000400525 in main () at test.c:11
在main函数中调用了一个add函数，查看栈帧可以看到传入add函数的参数。上面的结果显示main函数在1号栈帧，add函数为0号栈帧。
###frame
<kbd>frame</kbd>简写为`f`，可以用来转移栈帧。

    frame 1
转移到main函数的栈帧中，只有这样我们才能查看main函数中的变量。

##断点
###break
<kbd>break</kbd>简写为`b`,用于加断点,类似VS里面F9

要在第71行加一断点

    break 71
用来查看断点,可简写为`i b`

    info break
打印结果如：
```
(gdb) i b
Num     Type           Disp Enb Address            What
2       breakpoint     keep y   0x0000000000401334 in main() at 2225.cpp:71
5       breakpoint     keep y   0x0000000000401345 in main() at 2225.cpp:72
```

    delete 2
删除第71行的断点
>delte后面跟的是断点的id，而不是行号

<kbd>continue</kbd>命令简写为`c`，执行程序，直到遇到断点才中断。
##set
<kbd>set</kbd>可以在调试过程中设置变量的值。  
特别值得一提的是，如果用gdb调试main的参数需要在一开始这么写：

    set args 参数...
然后再执行start语句开始调试。    
程序名（*argv[1]*）无需设置到set args里面
