#include<iostream>

using namespace std;

class String
{
public:
    String(const char* cstr = 0);
    String(const String& str);
    string& operator =(const String& str);
    ~String();
    char* get_c_str() const {return m_data;}

private:
    char* m_data;
};

inline String::String(const char* cstr = 0)
{
    if(cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else 
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String()
{
    delete[] m_data;
}

int main()
{
    String s1();
    String s2("Hello");

    String* p = new String("hello");
    cout << s1.get_c_str()
    return 0;
}