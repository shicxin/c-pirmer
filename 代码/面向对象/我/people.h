#ifndef __PEOPLE__
#define __PEOPLE__
#include <iostream>
#include <cstring>

class people
{
private:
    char* name;
    bool sex;//性别，false为女，true为男
    int age;//年龄
    double h, w;//更高，体重
public:
    people(const char* nm = 0);//构造函数
    people(const people& x);//拷贝构造
    people& operator=(const people& x);//重载运算符、拷贝赋值

    char* get_name() const { return name;}
    // ~people();// 析构函数
};

inline people::people(const char* nm) : sex(0), h(0), w(0)  
{
    if(nm) {
        name = new char[1];
        name[0] = '\0';
    }
    else {
        name = new char[sizeof(nm) + 1];
        strcpy(name, nm);
        std::cout << nm;
    }
}

inline people::people(const people& x)
: age(x.age), sex(x.sex), h(x.h), w(x.w)
{
    name = new char[sizeof(x.name) + 1];
    strcpy(name, x.name);
}

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

std::ostream& operator<<(std::ostream& os, const people& x)
{
    return os << "名字是" << x.get_name() << ";";
}

#endif