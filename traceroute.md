traceroute
==========
检查到达某一主机中间所经过的主机。默认为udp包。  
`traceroute www.baidu.com`
##-I
发送icmp报文。有时候，如果使用了路由器，会导致udp包的响应功能消失。从而显示星号。
此时可以使用-I选项（或-T，不过有时候-T不管用）
