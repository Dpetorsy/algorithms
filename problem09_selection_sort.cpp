#include <iostream>
#include <chrono>

int main()
{
    int n, max, index;
    std::cout << "Print the lenght of the array: ";
    std::cin >> n;
    int array[n];

    //օգտագործողը մուտքագրում է մասիվի թվերը, օգտագործել'space' ստեղնը 'enter'֊ի փոխարեն
    std::cout << "Print numbers for array: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> array[i];
    }
    
    //սկսում ենք ժամանակի հաշվարկը
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    /*ալգորիթմի ռեալիզացիա, գտնում ենք մեկսիմումը ու տեղադրում մասիվի սկզբում, 
    հետո մնացած անդամներից գտնում ենք մակսիմումը ու տեղադրում երկրորդ տեղում, այդպես մինչև վերջի տարրը*/
    for(int i = 0; i < n - 1; ++i)
    {
        max = array[i];
        index = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(array[j] > max)
            {
                max = array[j];
                index = j;
            }
        }
        //տեղերով փոխում ենք մասիվի հաջորդ տարրը ու տվյալ մասի մակսիմում տարրը
        std::swap(array[i], array[index]);
    }
    
    //ավարտում ենք ժամանակի հաշվարկը
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //արտածում է արդյունքը
    std::cout << "Result: ";
    for(int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }    
    std::cout << std::endl;

    // ժամանակը` միկրովայրկյաններով
    std::cout << "Elapsed time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    return 0;
}
