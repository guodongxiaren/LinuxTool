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

##zip/unzip
###zip
    zip [-options] [-b path] [-t mmddyyyy] [-n suffixes] [zipfile list] [-xi list]
最简单用法,zip+压缩后的文件名+要压缩的文件。如：
    zip jdk-docs.zip jdk-doc/
###unzip
<kbd>unzip<kbd>直接跟文件名，就能解压文件到当前目录。
    unzip jdk-docs.zip

|常用选项|英文全称|描述
|:------:|:------:|----|
|d|directory|指定解压路径
|n|never|从不覆盖已存在的文件
|o|overwite|覆盖文件，不产生任何提示

