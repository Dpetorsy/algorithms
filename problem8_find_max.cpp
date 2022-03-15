#include <iostream>
#include <chrono>

int main()
{
    int n, max;
    std::cout << "Print the lenght of the array: ";
    std::cin >> n;
    int array[n];

    //օգտագործողը մուտքագրում է մասիվի տարրերը
    std::cout << "Print numbers for array: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> array[i];
    }
    
    //սկսենք ժամանակի չափումը
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for(int i = 0; i < n; ++i)
    {
        //եթե մասիվի առաջին թիվն է, ապա 'max' ին վերագրում է այդ թիվը
        if(i == 0)
        {
            max = array[i];
        }
        //հակառակ դեպքում համեմատում է մասիվի թիվը max-ի հետ
        else if(array[i] > max)
        {
            max = array[i];
        }
    }

    //ավարտում ենք ժամանակի չափումը
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //արտածում ենք max-ը
    std::cout << "Maximum in array is " << max << std::endl;

    //ժամանակը միկրովայրկյաններով
    std::cout << "Elapsed time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    return 0;
}
