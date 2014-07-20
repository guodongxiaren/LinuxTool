迭代器
======
用于指向顺序容器和关联容器中的元素，用法和指针类似
------
##分类
* 常量迭代器_const_iterator_和非常量迭代器（默认）之分
* 正向迭代器（默认）和反向迭代器_reverse_iterator_
* 双向迭代器和随机访问迭代器，视容器类型而定

##定义迭代器
```cpp
容器类名::iterator 变量名;
容器类名::const_iterator 变量名;

```
##访问指向元素
```
*迭代器变量名
```
##操作
 ++操作，但到了end位置时无法再自增。
###遍历
```cpp
vector<int>::iterator i;
for(i=v.begin();i!=v.end();i++)
    cout<<*i<<" ";

vector<int>::reverse_iterator r;
for(r=v.rbegin();r!=v.rend();r++)
    cout<<*r<<" ";
```
###双向迭代器支持的操作
若p和q都是双向迭代器，则支持：
- ++p,p++
- --p,p--
- \*p
- p = q
- p==q,p!=q

###随机访问迭代器支持的操作
- 双向迭代器支持的所有操作
- p+=i //将p向后移动i个元素
- p-=i //将p向后移动前移动i个元素
- p+i  //值为p后面第i个元素的迭代器
- p-i  //值为p前面第i个元素的迭代器
- p[i] //值为p后面第i个元素的引用
- p < q, p <= q, p > q, p >= q;
