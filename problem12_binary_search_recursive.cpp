#include <iostream>

// բինար որոնման ֆունկցիա ցիկլով
int bynary_search(int arr[], int start, int end, int number)
{
    int middle;
    do
    {
        middle = (end + start) / 2;
        if(arr[middle] < number)
        {
            start = middle + 1;
        }
        if(arr[middle] > number)
        {
            end = middle - 1;
        }
    } while(arr[middle] != number);

    return middle;
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
