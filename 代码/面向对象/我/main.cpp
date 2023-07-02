#include"people.h"

int main()
{
    people p1("Alice");
    people* p2 = new people("Bob");
    std::cout << p1 << " " << p2;
    return 0;
}