
Today I can use git in Linux.
================
|![](http://git-scm.com/images/logo@2x.png)|Git命令还是很有必要学的，很强大的说。原来在Windows上面直接使用GUI 的GitHub，导致对于Git命令很不熟悉。在Linux下，使用命令行才是王道，感觉Git和Shell的命令无缝集成，毫无违和。
|-----|:--------|

2014/04/30
==========
深入理解了几个git命令，入门级命令。
---
###ssh
```bash
ssh -keygen -t rsa -C "your@email.com"
```
* -t  Type 指的是加密算法的类型，后面跟得是rsa
* -C  comment 注释，一般是使用你的邮箱地址

### git add or rm
        git add (filename)
        git rm (filename)

分别对应添加和删除文件.(filaname)为对应的文件名称。也可以使用

    git add .

添加全部修改或新增的文件
###commit
```bash
git commit -m "the first commit"
```
提交文件，后面的字符串就是commit的标题<br>
单引号，双引号都可以
###修改默认编辑器
linux中直接使用`git commit`会出现nano。nano写commit的提示信息很不方便。貌似一定要要保存个文件名什么的，用着也不如vim顺手。
设置

    git config --global core.editor vim

###git总结(来自网络)
>如果你在与Git的默认设置背道而驰，先问问为什么。　　
>将公共分支历史看做不可变的、原子性的、容易追溯的。将私有分支历史看做一次性的、可编辑的。
>推荐的工作流程是：
- 基于公共分支创建一个私有分支。
- 经常向这个私有分支commit代码。
- 一旦你的代码完善了，就清理掉私有分支的历史。
- 将干净的私有分支merge到公共分支中。

2014/05/01
=====
今天好多的第一次吧。其实学习本身就是一个个第一次的过程。今天主要是关于Git的学习了吧。
-----
###分支
|操作|详细命令|
|:----:|:-----:|
|新建分支|`git branch testing`|
|切换分支|`git checkout testing`|
|删除分支|`git branch -d testing`|
|查看分支|`git branch`|

###stash
我今天遇到的一个状况就是：我是在网站上新建的分支alpha，然后本地的代码又进行了改动，本来想把改动都push进alpha的。结果在本地是无法checkout的。因为本地还没有这个分支，这时候git stash就派上用场了。
- git stash
- git pull
- git checkout alpha
- git stash apply
- git push

2014/05/27
=========
在git中添加文件的命令很简单`git add .`，但对于删除文件，一直有误解。今天算是搞清楚了git移除文件的命令奥义
---------

    git rm 文件名
	
与`git add`不同。git add 并不会新建文件，只是把已经新建了的文件提交到本地仓库。但是git rm真的会删除文件。比如git rm a.c。如果a.c是已删除文件的话，那么就会提交到本地仓库，如果是未删除文件的话，就会给删除掉。
>注意！可以这样被删除的只能是已经add过的文件，未在本地仓库记录的文件是无法删除的，要删除还是使用`rm`吧。

2014/05/30
===========
分支的小盲点
------------
###提交新分支
今天为操作系统实验，新建了个文件夹。又新建了个os分支用于在本地编辑实验文件。然后学到了提交本地新建分支到服务器。<br>在本地新建分支很容易

    git branch 【分支名】
但是如何把分支提交到github呢？
开始我以为直接`git push`就行了，却发现不行。真正的做法是：

    git push origin 【分支名】

###新建并切换到新分支

    git checkout -b 【新分支名】
		
>原来误以为这个操作是`git branch -b 【新分支名】`，囧。。


2014/05/31
==========
把远端其他分支clone到本地
-----------------------
通常我们clone一个远端的仓库，只能克隆到它的`master`分支。然而如果有其他分支呢？比如github的`gh-pages`分支。
<br>我们可以这样：

    git branch gh-pages origin/gh-pages

很简单吧。以此类推，我们还能想出其他的解决方案。

    git branch gh-pages
    git checkout gh-pages origin/gh-pages
或者

    git checkout -b gh-pages origin/gh-pages
	
>注意，本地的那个分支并不一定要求和远端相联的分支名称相同。并且本地的分支并不一定要`推`到远端，远端分支也并不一定需要`拉`到本地。
	

2014/06/04
==========
删除已提交到本地仓库的文件
------
我在本地新建了一个文件a.c，并使用`git add a.c`添加到本地暂存区，我现在想撤销它。

    git rm --cache a.c

2014/06/06
==========
今天发了一个一直以来的误解吧：`git pull`和`git push`是针对所有分支进行的操作。也就是说即使我切换到一个次分支`alpha`，
如果这个分支和远端的分支已关联了的话，那么执行`git pull`会把`master`分支和`alpha`分支都更新到远端。
单独提交某个分支的方法，其实我前面的学习日志里已经写过了，汗颜。。。

    git push origin alpha
>`git pull`也是同样的道理。

2014/06/15
==========
##移动文件
原先我移动文件到另一个文件夹总是使用shell的命令。

    mv a.txt Book/
这样有个问题就是接下来我要做两次track操作

    git add .
    git rm a.txt
但是，其实有个更简洁的操作，就是git的移动操作

    git mv a.txt Book/
不仅移动了文件的位置，而且自动track了这个变动。
##git add新学习

    git add -u
可以自动track删除掉的文件

    git add -A
可以自动track删除掉和新增的文件

2014/06/22
==========
##git init
原先一直是clone项目的。但是也可以把本地项目变作git项目。只需要

    git init
##git remote
但是还有和远端建立连接

    git remote add origin https://code.csdn.net/guodongxiaren/test.git
比如这样。origin这个远端名可以随便取，也可以删除掉它。

    git remote rm origin
这样以后，如果pull的时候需要完整的路径。

    git pull origin master
不能只写`git pull`了。

2014/06/24
==========
今天学到了使fork来的库与原ower的库保持更新的方法。因为我fork了一个vim配置文件的库，
原持有者修复了一些bug，我需要把他的更新也同步到我的这个库里面。

>其实没有用到新的知识，都是已经掌握的。主要是学到了一个经验。

1. 增加一个远端
```
    git remote add ma6174 https://github.com/ma6174/vim.git
```    
远端名任意。

2. 开始更新
```    
    git fetch ma6174
```
3. 合并
```
    git merge ma6174/master
```
或者直接`git pull ma6174 master`

再`git push ncu master`
>其中ncu是添加的另一个远端

2014/07/04
==========
##git commit -a
commit的`a`选项，只能捕获修改和删除的文件。

2014/07/08
==========
##对于git add .的再理解
git add .只能添加当前目录及其子目录下新增或修改的文件，
不能添加兄弟目录下的文件。

2014/07/12
==========
##git add -A
这个命令一定要加路径才行。要添加该目录树下所有新文件

    git add -A :/

2014/07/23
==========
##克隆远端repository的时候，可以在后面加一个参数。如

    git clone git@github.com:abc/hello.git hehe
这样这个repo的所在的文件夹名称就变为了hehe，而不是默认的hello了。
##删除远端的分支

    git push origin --delete <分支名>
注意空格。即使是在子目录中也能添加整个目录树的文件。
2014/08/11
==========
设置默认追踪分支

    git branch --set-upstream-to=origin/<branch> master
这样就可以直接`git pull`了，而不用指定远端和分支。
