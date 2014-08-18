awk
===
##基本格式
|命令 	|描述
|------- 	|------
|awk '{ print $0 }' /etc/passwd 	|打印整行
|awk -F: '{ print $1 }' /etc/passwd 	|打印每行分号;分割的第一个字段
|awk -F: '{ print $1 $6 }' /etc/passwd 	|打印每行第1和6个字段

