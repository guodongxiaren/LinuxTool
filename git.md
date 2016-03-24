Today I can use git in Linux.
================
|![](http://git-scm.com/images/logo@2x.png)|抛弃GUI，在Linux下，使用命令行才是王道。
|-----|:--------|

2014/04/30
==========
深入理解了几个git命令，入门级命令。
---
###ssh
```bash
ssh-keygen -t rsa -C "your@email.com"
```
* -t  Type 指的是加密算法的类型，后面跟得是rsa
* -C  comment 注释，一般是使用你的邮箱地址

###config

    git config --global user.name "用户名"
    git config --global user.email "邮箱"
    git config --global core.quotepath false

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
##设置默认追踪分支

    git branch --set-upstream-to=origin/<branch> master
这样就可以直接`git pull`了，而不用指定远端和分支。
##git协议的误区
使用SSH协议可以避免每次`push`输入密码。前提是在账户里配置好SSH秘钥。
git@github.com开头的就是SSH协议。
使用Https协议则会导致每次都会输入用户名和密码。
2014/08/31
==========
    git config --global credential.helper store
https协议记住密码的命令。
2014/09/14
==========
##查询man手册
查看man手册的git命令时，比如查询git diff要使用man git-diff。
##git ls-files
可以显示在Git管理范围内的文件。
##git diff
比较差别。但是只能显示已经在Git范围内的文件，新建而未添加的文件不显示差别。  
*注意*，git diff显示的是“缓存区”(staging area)和工作区之间的差别。  
也就是说，当我把改动的文件add之后，缓存区与工作区就一致了，使用git diff就会没有反应。
####git diff HEAD
用以显示最新提交(commit)和当前工作区的差别。包括已更改但尚未add的改动。
####git diff --cached
用以显示最新提交和缓存区的差别。包括已add但尚未commit的改动。
2014/10/11
==========
##撤销暂存的文件
暂存，就是已经add但未commit的文件。   
    
    git reset HEAD
恢复所有add文件为未暂存的状态。
也可以使用上面语句加上单个文件名，来恢复单个文件。
##撤销commit的文件
先用git log查看每个版本的hash值  
使用下面语句恢复到特定版本
   
    git reset --hard hash值
hash值也可以用HEAD代替。    
HEAD^代表上一次commit前的版本。     
注意，这时已经暂存但未commit的文件，将消失。在上次版本之后出现的文件，也将消失。    
HEAD^^代表上上次commit前的版本，以此类推。
##删除所有未被跟踪的文件
    git clean -df

2014/10/24
=====
Git2.0版本，git add命令有了改动。使用如下命令进行设置：

    git add --all
这样，以后被rm，mv操作的文件，再使用了git add .之后也能提交到暂存区了。

2014/10/28
===========
补充上次commit

    git commit --amend
把文件添加到缓存区后，再执行上述命令。可以补充到上一次的commit。
2014/11/01
=========
一个错误的解决方案：  
今天在CentOS上，git push的时候遇到一个问题：

	error: The requested URL returned error: 403 Forbidden while accessing https://....
我的remote地址使用的https协议。百度到的解决方案是：  
把config文件中的url改为https://用户名@github.com/... 的形式。然后再push的时候就会直接提示输入密码。

2014/11/08
==========
设置本地分支默认跟踪的远程分支

    git branch --set-upstream-to=origin/django django
origin后面的django指的是远程分支，最后一个参数django是本地分支。

2014/11/17
==========
不再跟踪某一文件。

    git rm [-r] --cached .classpath
.classpath为文件名
2014/12/29
===========
##丢弃工作区改动
如果你的工作区发生了改动，还没暂存的话，
那么用`git status`查看，改动的文件会是红色的。此时如果执行`git pull`，
则会出现问题，提示你要暂存改动，如果你不想暂存，想用云端的文件覆盖掉本地的文件，
则需要丢弃工作区改动：

    git checkout 要丢弃改动的文件名
    git checkout ddl.sql
    
##把本地分支同步到remote
    git push -u origin test
上面命令将当前本地分支，推送到远端的test分支，并建立关联。
远端若无test分支，则会自动创建
2015/03/05
==========
源码编译git。遇到了一些问题，主要是依赖没安装完整（也能编译成功，但是缺少功能）。

要安装的依赖是：
- zlib
- openssl(--shared和-fPIC选项)
- libcurl（--with-ssl）
- expat
- ascilldoc

把这些源码下载下来编译好，就行了。  
要注意的是openssl要先于libcurl编译，因为libcurl在configure阶段需要开启`--with-ssl`选项来指明openssl的路径，否则就无法支持很好地https协议（git pull失败）。

另外openssl的configure阶段要使用`--shared -fPIC`选项使编译生成动态库（`.so`，默认是静态库`.a`），这样才能被libcurl调用。如果之前已经生成过静态库了，重新编译之前要`sudo make clean`一下。

2015/06/25
==========
修改终端中git中文的显示方式：

    git config --global core.quotepath false
这样就不会对`0x80`以上的字符进行quote。能正常显示中文。

2015/11/19
==========
修改默认push/pull规则。默认有两个规则：
- Matching： 推送当前所有分支到remote
- Simple： 只推送当前分支到remote

命令如下：
```
git config --global push.default matching
git config --global push.default simple
```
2016/02/25
===========
克隆指定分支的文件。
```
git clone -b 分支名 远端URL
```

2016/03/24
============
##孤儿分支，开启新历史  
如果你想抛弃所有的git历史纪录，你可以创建一个孤儿分支，它不继承自任何父分支。而是重新开启一段git历史记录。
它不会丢失之前的文件，你只需要重新把它们commit一次。例如：
```
git checkout --orpha gh-pages
```
上述命令创建了一个分支`gh-pages`。
>如果原始分支master是空的，那么gh-pages分支创建后，master分支将消失。如果master不空，那么不消失。

##删除远程分支
比如你想删除远程master分支。那么：
- 本地删除master分支：`git branch -D master`
- 在github上将其他分支（比如gh-pages）设置为默认分支
- 本地执行`git push -u origin :master`（冒号前空格）

注意执行顺序。