压缩解压
========
Linux系统中常见的压缩文件格式(后缀名)有gz、bz、zip、rar和Z。
>`*.Z`类型为compress软件压缩的格式，目前已经退出历史舞台，被gzip取代。

打包和压缩是两个概念。打包只是单纯将多个文件合并成一个文件。
比如常见的`*.tar`后缀的是打包文件而不是压缩文件。
>尽管如此，tar也提供了压缩功能的选项。在打包之后再进行一次压缩，比如`*.tar.gz`文件。

##gzip
gzip全称GNU zip。最简单的用法就是gzip直接跟文件名，用来压缩。
    gzip test.sh
这样会生成test.sh.gz的文件。但是原文件会消失。加上`-k`选项则会保留原文件

|选项|英文释义|描述|
|----|----|----
|d|decompress|解压
|r|recursive|压缩目录
另有`gunzip`可以用于解压.gz的文件，效果同gzip -d。注意：   
gzip -d foo 可以解压foo.gz文件
###zcat
zcat可以在不解压`*.gz`文件的情况下，打印压缩文件的内容到屏幕。
##bzip2
bzip2比gzip有更好的一个压缩比。但其使用方法，选项和参数都和gzip相同。

相应的bzip2有一个`bzcat`。
##tar
确切说，tar是打包工具而不是压缩工具，但是也提供了借助gzip或bzip2来压缩的选项。
tar命令的选项可以不加`-`，比如常用的`tar xvf *.tar.gz`

|常用选项|英文全称|描述|
|:------:|:----:|----
|c|create|创建文件|
|C|change DIR|指定解压路径|
|f|file|指定文件名，f后要紧跟文件名|
|j||利用bzip2来压缩|
|J||利用xz来压缩|
|p|permissions|保留原文件的权限和属性|
|v|verbose|显示正在压缩/解压的文件|
|x|extract|解压缩|
|z||利用gzip来压缩|
###c
在不压缩只打包的时候不加c会报错。
    tar cvf abc.tar abc/
###f
    tar -zcv -f abc.tar.gz abc/
>因为f后面要紧跟文件名，所以最好将-f选项单独写出来，而不是组合使用

##xz
xz是linux上最有效的压缩功能，现在被用来储存Linux内核文件。    
它压缩速度慢，但是提供更高的压缩率。    

|命令|描述|
|----|----|
|xz _*_|压缩当前目录下所有文件，缀以.xz，不打包|
|xz foo|压缩foo文件为foo.xz，如果成功，会删除foo文件|

|选项|全命令|描述|
|----|----|----|
|c|stdout|解压（非）压缩文件到标准输出|
|d|decompress|解压.xz文件，默认替换掉压缩文件|
|k|keep|解压之后不删除原文件|
##zip/unzip
###zip
    zip [-options] [-b path] [-t mmddyyyy] [-n suffixes] [zipfile list] [-xi list]
最简单用法,zip+压缩后的文件名+要压缩的文件。如：
    zip jdk-docs.zip jdk-doc/
###unzip
<kbd>unzip<kbd/> 直接跟文件名，就能解压文件到当前目录。
    unzip jdk-docs.zip

|常用选项|英文全称|描述
|:------:|:------:|----|
|d|directory|指定解压路径
|I||指定为UNIX的字符集
|n|never|从不覆盖已存在的文件
|o|overwite|覆盖文件，不产生任何提示
|O||指定为Dos，Windows或OS/2中的字符集
有些Windows下压缩的文件，在解压后中文会出现乱码，这是由于编码不一致造成的。
图形化的解压工具无法指定编码格式，此时必须要借助unzip命令。

    unzip -O cp936 xxx.zip
**cp936**为Windows的默认编码格式，也即GBK，据测试也可指定为gb2312编码。
>指定编码的时候，大小写不敏感

##rar
格式

    rar <命令选项> 压缩包名称 [要操作的文件]

|常用选项|英文全称|描述
|:------:|:------:|----|
|a|add|给压缩包内添加文件|
|d|delete|删除压缩包内某文件|
|e|extract|提取文件到当前目录，不创建新目录|
##unrar
注意，改命令选项不加-

