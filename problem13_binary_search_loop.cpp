#include <iostream>

// բինար որոնման ռեկուրսիվ ֆունկցիա
int bynary_search(int arr[], int start, int end, int number)
{
    int middle = (end + start) / 2;
    if(arr[middle] == number)
    {
        return middle;
    }
    else
    {
        if(number > arr[middle])
        {
            return bynary_search(arr, middle + 1, end, number);
        }
        else
        {
            return bynary_search(arr, start, middle - 1, number);
        }      
    }
}

int main()
{
    int n, number;
    std::cout << "Print array lenght: ";
    std::cin >> n;
    std::cout << "Print number: ";
    std::cin >> number;   

    // օգտագորժողը մուտքարում է մասիվի տարրերը
    int arr[n];
    std::cout << "Print array numbers: "; 
    for(int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    std::cout << std::endl;
    
    // արտածում է արդյունքը
    std::cout << "Index of number " << number << " is " << bynary_search(arr, 0, n - 1, number) << std::endl;

    return 0;
}
