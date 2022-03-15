#include <iostream>
#include <cmath>

//function checks the number for simplicity
bool prime_number(int a)
{
    float root = round(sqrt(a));
    int sum_of_numbers = 0;
    
    for(int i = 2; i <= (int)root; i++)
    {
        if((a % i) == 0)
        {
            sum_of_numbers++;
        }
    }
    
    if(sum_of_numbers > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a;
    std::cout << "print number: ";
    std::cin >> a;
    
    //check and print "prime" if number is prime
    if(prime_number(a))
    {
        std::cout << "number " << a << " is not prime" << std::endl;
    }
    else
    {
        std::cout << "number " << a << " is prime" << std::endl;
    }
    return 0;
}
