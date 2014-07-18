queue
=====
#queue
#priority_queue
=====
优先队列
-----
优先队列默认是数值越大，优先级越高，也就是降序排列。
##重载优先级

    priority_queue<int,vector<int>,greater<int> > q;
升序排列。
>注意最后的`> >`之间必须有空格。

##类模板
_std::priority_queue_
```cpp
template <class T, class Container = vector<T>,
  class Compare = less<typename Container::value_type> > class priority_queue;
```
##成员 
|成员名|描述|
|:----------:|--------------|
|_value_type_|第一个参数T|
|_container_type_|第二个参数Container|
|_sieze_type_|通常和_size_t相同|

##成员函数
|函数名|返回值|
|:----:|:----:|
|(constructor)||
|empty|bool|
|pop|void|
|push|void|
|size|_size_type_|
|top|_const value_type&_|
>优先队列没有front成员函数，取而代之是top函数。queue有front成员函数。

