make命令介绍
=====
##选项
###-i，--ignore-error
忽略编译过程中的所有错误。不建议使用。
###-k，--keep-going
如果某命令出错，则终止该命令，但是编译过程继续向下执行。
###-n，--just-print
只打印命令，不执行命令
###-s，--slient
全面禁止显示命令

##其他知识
###传递参数
比如`make prefix=/usr/local`，prefix并非是make的选项，这样做的目的是传递了一个参数（变量）`prefix`给了makefile使用。
