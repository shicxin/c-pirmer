#include <iostream>
using namespace std;

class date
{
public:
    date():a(0), b(0){}
    date(int x):a(x), b(0){}
    date(int x, int y):a(x), b(y){}

    int sha() const {return a;}
    int shb() const {return b;}
    date& add(const date* ths)
    {
        // cout << "this is " << this << endl;
        this->a += ths->a;
        this->b += ths->b;
        return *this;
    }
    date& operator+=(const date& b);
    date& operator+(const date& b);
    void putprint()const;
private:
    int a;
    int b;
};
inline date& __doapl(date* ths, const date& b)
{
    ths->add(&b);
    return *ths;
}
inline date& date::operator += (const date& b)
{
    // cout << "&b = " << &b << endl;
    return __doapl(this, b);
}
inline date operator + (const date& a, const date& b)
{
    return date(a.sha() + b.sha(),
                a.shb() + a.shb());
}
ostream& operator << (ostream& os, const date& x)
{
    return os << '(' << x.sha() << ", " << x.shb() << ')';
}
inline void date::putprint() const
{
    cout << "a = " << this->sha() << " " 
         << "b = " << this->shb() << endl; 
}
int main()
{
    date a(1), b(1, 2);
    a.putprint();
    b.putprint();
    b+=a+=b;
    a.putprint();
    b.putprint();
    return 0;
}