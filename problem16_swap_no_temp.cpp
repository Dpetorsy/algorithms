#include <iostream>
 
// փոխում է տեղերով 2 փոփոխականներ
void swap(int& a, int& b)
{
    // a = a + b
    a = (a & b) + (a | b);
 
    // b = a - b
    b = a + (~b) + 1;
 
    // a = a - b
    a = a + (~b) + 1;
}
 
int main()
{
    int a = 5, b = 10;

    swap(a, b);
 
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;
 
    return 0;
}
