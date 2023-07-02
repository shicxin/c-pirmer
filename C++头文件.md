# namespace（TODO）

C++ 标准程序库涵盖范围相当大，提供了大量功能，正因为这样，标准库中class名称和函数名与第三方提供的class和函数名冲突的可能性变大。为避免该冲突的发生，在标准化时特别引入了“名字空间的定义”，即namespace。将所有标准程序库中的东西都放在了namespace std中。

但是这么做同时有引来了一个新的问题。很多C++ 程序代码依赖那些已经存在很多年的C++ “准”标准程序库（C++迟迟未标准化才导致这些情况的发生），例如iosteam.h,complex.h等等。

# 用法区别

为了解决这个新出现的问题，标准化委员会决定设计一些新的头文件名，给那些穿上std外衣的组件所使用。把C++ 头文件的.h去掉，于是就有前面出现的iostream，同样C的头文件也做了相同的处理，同时在前面加上了一个字母c，以表示是C的头文件（感觉上有种种族歧视的感觉）。

|                 | 非标准            | 标准             |
| :-------------- | :---------------- | :--------------- |
| C输入输出标准库 | #include<stdio.h> | #include<cstdio> |

同时标准化委员会声明就有的C++头文件将不再列于被支持的名单之中了，而旧有的C头文件为了满足“对C的兼容性”这个古老契约，仍然将继续存活下去。

当代码中用<iostream.h>时，这时头文件是C语言格式的，尚未出现namespace，输出可直接引用。

```cobol
cout<<x;
//<iostream.h>继承C语言的标准库文件，未引入名字空间定义，所以可直接使用。
```

当代码中引入<iostream>时，为标准输入输出流，包含在std命名空间内，输出需要引用std命名空间。

```cobol
std::cout<<x;
```

如果还是按原来的方法就会有错。

使用<iostream>时，引入std::有以下方法：

1.  使用using编译指令引用整个命名空间。

```cobol
using namespace std;    //all names available
cout << x ;
```

这个using编译指令使std这个命名空间中的所有名称都可用，这是一种懒惰的做法，在大型项目中有潜在问题。所以更好的做法是按需引用.

2.  只列出所需的名称。

```cobol
using std :: cout;  //make cout available
cout << x ;
```

3. 基本引用

```cobol
std::cout << x;
```

## iostream 的使用

主要有3种方法，没有最优，只有最合适

方法1，适用于使用函数个数少，函数使用次数少的情况

```cobol
//example1.cpp
#include <iostream>
      
int main(void)
{
　　std::cout<<"Hello World"<<std::endl; //方法1
　　return 0;
}
```

方法2，适用于使用函数个数少，函数使用次数较多 的情况

```cobol
//example2.cpp
#include <iostream>
      
using std::cout;　　　　　　　　　　　　　　//方法2
using std::endl;　　　　　　　　　　　　　　//方法2

int main()
{
　　cout<<"Hello World"<<endl;
　　return 0;
}
```

方法3，适用于使用函数个数和函数次数较多 的情况

```cobol
//example3.cpp
#include <iostream>
      
using namespace std;　　　　　　　　　　　　//方法3

int main()
{
　　cout<<"Hello World"<<endl;
　　return 0;
}
```

## 建议

最好使用标准头文件。

iostream是现在C++ 中规定的标准，目的在于使C++ 代码用于移植和混合嵌入时不受扩展名.h的限制，避免因为.h而造成的额外的处理和修改。

iostream包含的基本功能和对应的旧头文件相同，但头文件的内容在名字空间std中（在标准化的过程中，库中有些部分的细节被修改了，所以旧头文件和新头文件中的实体不一定完全对应）。

一般情况下应该用这个头文件，而iostream.h则是老式的，以后有可能被淘汰