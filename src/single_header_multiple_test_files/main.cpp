#include "testee.hpp"

int main()
{
    int a = add(2, 3);

    return a == 5 ? 0 : 1;
}
