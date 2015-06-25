Visual模式
==========
Visual模式又分为三种visual模式
----------
|plain visual|block visual|linewise visual
|:----------:|:----------:|:----------:|
##plain visual（普通）
Normal模式下，键入`v`进入`plain visual`模式
##block visual（块选）
`Ctrl-v`进入`block visual`模式，该模式可以竖着选中一列或几列；
所有的操作也将作用于所有选中列。

|按键|描述|
|----|:----|
|A|追加，更新到所有行|
|c|剪切单个字符并进入插入模式|
|C|剪切整行并进入插入模式|
|d|剪切列|
|D|剪切选中行|
|I|插入|
|r|替换单个字符|
|R|替换选中行，与其他命令不同，不更新到所有行，而是替换成一行|

##linewise visual(行选)
Normal模式下，键入`V`(shift-v)进入`linewise visual`模式。  
Normal模式下，键入`]+d`可进入该模式，并选中光标所在行到尾行间所有行。

所有的操作都是以行为单位的，只关系光标所在行，而不关心光标所在位置。

其余用法同`plain visual`模式。
