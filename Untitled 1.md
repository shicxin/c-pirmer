# 面向对象基础整理

[toc]


## 类

类与结构体是有区别的

类包含三个部分：

1.   前置声明：包含类的声明
2.   类-定义：`class head`、`class body` {`data`，成员函数}
3.   相关函数{部分成员函数的实现、全局函数}

### `lnline`(内联)函数

`lnline`函数可以更快的被执行，但是我们标记的内联函数只是给编辑器的建议，函数是不是`inline`由编辑器决定。

### 访问级别

`public`：公共的、公开的

>   `public`的内容一般为成员函数，为了方便阅读，大部分只做申明；

`private`：封装的，可以通过`public`访问，不能直接在环境中访问

>   类中需要表示的数据、部分成员函数，这里面的函数不能被直接访问，需要通过`public`的函数调用。

`publiced`：保护的

`friend`：友元

>   C++提供的可以通过其他方式访问一个类中被封装的成员，打破了C++的封装性，用的好有奇效。
>
>   **相同的`class`的各个`objects`互为`friends`**



## 基础符号

### `const`申明符

1.   表示数据是不会发生改变的，`const`的数据不允许被改变，`const`函数中不会改变数据；
2.   被`const`限制的类只可以调用`const`函数。

### `&`(引用)申明符

相当与指针

## C++的构造函数

### 普通构造

构造函数用于创建一个对象；

构造函数没有返回值，函数名与类名相同；

构造函数有其独有的写法：`类名(参数):Data1(赋值1), Data2(赋值2), ...{}`；

构造函数支持重载；

构造函数可以写在`private`中，是一种著名的设计模式（`Singleton`（单例、单体））；

### 拷贝构造

当一个类中有指针时，不适合直接使用1V1拷贝（浅拷贝）。此时要使用已有的同类进行构造时，我们需要使用深度拷贝；

拷贝构造函数可以实现对象的深拷贝，即为所构造对象的指针变量分配新的内存空间，并拷贝其值值新的空间。拷贝构造函数通常有以下三种情况会被调用：

-   通过使用另一个同类型的对象来初始化新创建的对象，例如 Complex c2(c1); 或 Complex c2 = c1;。
-   复制对象把它作为参数传递给函数，例如 void Func(A a);。
-   复制对象，并从函数返回这个对象，例如 A Func();。

```c++
class people
{
private:
    char* name;
    bool sex;//性别，false为女，true为男
    int age;//年龄
    double h, w;//更高，体重
public:
    people(const char* nm = 0);
    people(const people& x);
};
inline people::people(const char* nm = 0) : sex(0), h(0), w(0)  
{
    if(nm) {
        name = new char[1];
        name = '\0';
    }
    else {
        name = new char[sizeof(nm) + 1];
        strcpy(name, nm);
    }
}
inline people::people(const people& x)
: age(x.age), sex(x.sex), h(x.h), w(x.w)
{
    name = new char[sizeof(x.name) + 1];
    strcpy(name, x.name);
}
```

## 运算符重载

在C++中，运算符也是一个函数，当然也分为成员运算符与全局运算符，有些运算符因为使用习惯，必须重载为全局运算符；

### 拷贝赋值（重载 = ）

赋值拷贝也是一种深度拷贝，但是要先释放之前的内存；

有时运算符需要连用，于是我们要考虑重载运算符的返回类型；

### `<<`（输出流运算符）重载

由于`<<`运算符经常跟在`cout`后面，而不是作为成员运算符存在，所以我们把它重载为全局函数会更符合使用习惯

```c++
class people
{
private:
    char* name;
    bool sex;//性别，false为女，true为男
    int age;//年龄
    double h, w;//更高，体重
public:
    people& operator+=(const people& x);
    people& operator=(const people& x);
};
inline people& people::operator=(const people& x)
{
    delete(this->name);
    this->name = new char[sizeof(x.name + 1)];
    strcpy(this->name, x.name);
    this->age = x.age;
    this->sex = x.sex;
    this->age = x.age;
    this->h = x.h;
    this->w = x.w;
    return *this;
}
```

