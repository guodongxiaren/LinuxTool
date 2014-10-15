fc
===
fix command
-----------
常用于修改错误的命令输入。
##l
fc -l查看最近的历史记录。显示结果如：

    1984	 ls
    1985	 cd GitHub/
    1986	 ls
    1987	 cd ShiYan/
    1988	 ls
    1989	 git status
    1990	 git commit -am'shiyan3'
    1991	 git status
    1992	 git push
    1993	 clsa
    1994	 cls
    1995	 cd ..
    1996	 cd Notes/
    1997	 cd .git/
    1998	 vi config 
    1999	 cd
左边的数字为事件编号
##s
s选项不加参数，则继续执行上一个命令。(另外bash支持csh的!!，可完成同样功能)    
s选项后面跟上事件编号，则执行该编号对应的命令。    
s选项可替换上一条命令的部分字符

    git stutas
    fc -s uta=atu

