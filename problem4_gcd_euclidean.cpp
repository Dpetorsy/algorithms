#include <iostream>

//հաշվում է 2 տրված թվերի gcd-ն
int gcd(int a, int b)
{
    while((a != 0) && (b != 0))
    {
        if(a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    return a + b;
}

int main()
{
    int a, b;
    std::cout << "Print first number: ";
    std::cin >> a;
    std::cout << "Print second number: ";
    std::cin >> b;
    
    //արտածում է արդյունքը
    std::cout << "GCD for numbers " << a << " and " << b << " is " << gcd(a, b) << std::endl;
    
    return 0;
}
