#include <iostream>

#include "testee.hpp"

int main()
{
    int a = add(3, 2);
    int m = mul(3, 2);
    int s = sub(3, 2);

    if (a != 5)
        return 1;

    if (m != 6)
        return 1;

    if (s != 1)
        return 1;

    std::cout << "Everything seems to be working.\n";
}
