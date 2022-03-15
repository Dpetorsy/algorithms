//ֆակտորիզացիայի մեթոդով gcd ստացվում է երկու տրված թվերի ընդհանուր պարզ բաժանարարների բազմապատկումով

#include <iostream>
#include <vector>
#include <cmath>

//վերածում է տրված թիվը պարզ բաժանարարների ու գրում վեկտորի մեջ
std::vector<int> factorize(int x) {
    std::vector<int> factors;

    for (int i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }
    
    //եթե x != 1, ապա թիվը պարզ է
    if (x != 1) {
        factors.push_back(x);
    }

    return factors;
}

int main()
{
    int gcd = 1;
    int a, b;
    std::vector<int> first_factorize;
    std::cout << "Print first number: ";
    std::cin >> a;
    std::cout << "Print second number: ";
    std::cin >> b;
    int reminderB = b;
    
    //վերածենք պարզ բաժանարարների միայն առաջին թիվը
    first_factorize = factorize(a);
    
    //ցիկլով անցնում է վեկտորի անդամների վրայով
    for(int i : first_factorize)
    {
        //եթե երկրորդ թիվը բաժանվեց վեկտորի թվի վրա, ապա այդ թիվը ավելացնենք "gcd" փոփոխականի մեջ
        if(reminderB % i == 0)
        {
            gcd *= i;
            //երկրորդ թիվը փոքրացնենք, բաժանելով վեկտորի թվի վրա
            reminderB /= i;
        }
    }
    
    //արտածենք արդյունքը
    std::cout << "GCD for numbers " << a << " and " << b << " is " << gcd << std::endl;
    
    return 0;
}
