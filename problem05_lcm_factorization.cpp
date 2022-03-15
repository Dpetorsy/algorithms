//Ալգորիթմի քայլերի հերթականությունը
//1. սկզբում գտնում ենք առաջին թվի պարզ բաժանարարները ու գրում վեկտորում
//2. երկրորդ թիվը հաջորդաբար բաժանում ենք վեկտորի թվերի վրա
//3. եթե բաժանվեց, ապա տրված թիվը ընդհանուր պարզ բաժ․ է 2 թվերի համար, ավելացնում ենք 'sum' փոփոխականի մեջ
//4. եթե բաժանվեց, փոքրացնում ենք երկրորդ թիվը այդ վեկտորի թվով
//5. եթե չբաժանվեց ավելացնում ենք 'reminderA' փոփոխականի մեջ, դրանք կլինեն միայն առաջին թվի համար պարզ բաժ․֊երը
//6․ վերջում երկրորդ թվի մնացորդը կլինի այն թվերի արտադրյալը, որոնք պարզ բաժ․ են միայն երկրորդ թվի համար
//7. բազմապատկելով sum, reminderA,reminderB փոփոխականները կստանանք տրված 2 թվերի LCM-ը

#include <iostream>
#include <vector>
#include <cmath>

//հաշվում է տրված թվի պարզ բաժ․֊երը և գրում վեկտորի մեջ
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
    int sum = 1; 
    int reminderA = 1;
    int lcm;
    int a, b;
    std::vector<int> first_factorize;
    std::cout << "Print first number: ";
    std::cin >> a;
    std::cout << "Print second number: ";
    std::cin >> b;
    int reminderB = b;
    
    //ստանանք առաջին թվի պարզ բաժ․֊երը
    first_factorize = factorize(a);
    
    //ցիկլով անցնենք վեկտորի թվերի վրայով
    for(int i : first_factorize)
    {
        if(reminderB % i == 0)
        {
            //եթե բաժանվեց ավելացնենք փոփոխականի մեջ
            sum *= i;
            //երկրորդ թիվը փոքրացնենք վեկտորի թվով
            reminderB = reminderB / i;
        }
        else
        {
            //ավելացնենք առաջին թվի մնացորդի մեջ           
            reminderA *= i;
        }
    }
    
    //հաշվենք և արտածենք LCM-ը
    lcm = sum * reminderB * reminderA;
    std::cout << "LCM for numbers " << a << " and " << b << " is " << lcm << std::endl;
    
    return 0;
}
