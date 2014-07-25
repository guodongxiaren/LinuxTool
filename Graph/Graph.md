图的表示及存储
==============
##图的表示
- 关联矩阵(编程不常用)
- 邻接矩阵(bool矩阵)
- 邻接表

##邻接表
邻接表的数据结构分为三个部分
```cpp
//边结构
struct EdgeNode
{
    int to;    //终点
    int w;
    EdgeNode *next;//指向下一条边的指针
};
//点结构
struct VNode  
{
    int from;  //起点
    EdgeNode *first;//指向下一条边的指针邻接表头指针
};
//整个图的邻接表
Vnode Adjlist[maxn];
```
###链式前向星
链式前向星是邻接表的静态实现。
```cpp
int head[n];   //head[i]=j,表示以i为起点的第一条边在Edges数组中的位置是j
struct EdgeNode
{
    int to;    //该边指向的终点
    int w;     //权重
    int next;  //同起点的下一条边
};
EdgeNode Edges[m];
```

>链式前向星并非专业术语。是网友的说法，但是在中国也比较流行。

###vector实现的邻接表
vector实现的邻接表实际上上链接前向星的另一种表达。但是它所占用的内存会少于普通的链式前向星。
