gcc编译器学习记录
================
|![](http://gcc.gnu.org/img/gccegg-65.png)|gcc是Linux/Unix上非常强大的C语言编译器。并且如今也支持C++的编译。与VC不同，gcc是完全跨平台的。到目前为止很多工具都使用gcc作为其编译环境，比如`cocos2d-x`，android的`NDK`等等。 学习使用gcc编译器，就是学习它众多的编译参数。就是用连字符`-`连接的参数。
|:----------------:|:--------------------|

>因为它的参数并不全是单字符的，所以不能使用一个连字符后加多个参数的写法，
要每个参数前面都要加一个连字符

||gcc|g++|vc|
|---|:---:|:---:|:---:|
|main|√|x|x|
|void main|x|x|√|
|int main|√|√|√|
<br>
###直接开始
直接在gcc后面加上要编译的C语言源文件
    
    gcc hello.c
这种默认的情况下会生成一个名为`a.out`的可执行文件。
>注意，在Linux系统下，后缀名真的不是很重要的事，甚至没有后缀名都可以。这些都没有关系，比如你写一个shell的脚本，其实加不加后缀都是可以运行的。此时后缀的目的是为了便于用户管理和区分文件而已。By the way，如果你执行`./hello.c`，那么系统会把它也当做shell脚本来运行，根本不管什么后缀。

###-o
最常用的编译选项，用于指定要生成的可执行文件的名称。

    gcc -o hello hello.c
    
需要体会的一点是：gcc对于参数的位置无要求！比如也可以写作

    gcc hello.c -o hello

惟一要注意的就是`-o`后面一定要紧跟要生成的可执行文件名。
>编译出的可执行文件，在Windows下就是exe（executive）。但Linux下，后缀名无限制。一般不指定后缀就可以了。

###-g
用于给生成的可执行文件加上调试信息，只有这样才可使用[<kbd>gdb</kbd>](./gdb.md)调试。

    gcc -g -o hello hello.c

同样参数`-g`的也可写在hello.c后面。

###-c
终止链接器的运行，输出文件为汇编后的目标文件`*.o`

    gcc -c hello.c

生成文件为`hello.o`
###-O2
对源码进行优化，使编译出的程序，运行效率更高。注意是大写的英语字母`O`，不是阿拉伯数字`0`

    gcc -O2 hello.c -o hello
    
`O`是<kbd>Optimize</kbd>之意。同样还有`O1`，但是优化效果不如`O2`

##Link
    gcc -o temp temp.c -lm
**-lm**选项是链接math.h的库。常用的库会自动链接，无需指定。
>数学库的文件可能位*libm-2.1.2.so*去掉lib和后面的版本号就只剩下m了。

如果该库不在系统缺省路径下，还要使用**-L**选项指定。
    
    -L/home/jelly/mylib
系统缺省的库路径为：/lib、/usr/lib、/usr/local/lib。
###静态链接库
静态链接库是后缀名为.a的文件。它有多个后缀为你.o的目标文件组成。

使用`-c`参数可以使编译在链接前终止，所以生成的是源文件对应的目标文件。

    gcc -c addvec.c multvec.c
    ar rcs libvector.a addvec.o multvec.o
`ar`是archive档案的缩写。上面命令生成了.a的静态库文件，在链接时，要如下：

    gcc -c main2.c
    gcc -static -o p2 main2.o ./libvector.a
###动态链接库
后缀名为.so的是动态共享链接库文件，其中的s就是shared共享的意思，如下命令：

    gcc -shared -fPIC -o libvector.so addvec.c multvec.c
    gcc -o p2 main2.c ./libvector.so
完成了生成.so以及链接.so的操作。<kbd>-fPIC</kbd>指示生成与位置无关的代码。

##使用c99标准编译
默认的情况下，编译器是以c89的标准编译的。使用c99则：

    gcc -std=c99 hello.c

