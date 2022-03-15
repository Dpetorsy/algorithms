#include <iostream>

int main()
{
    int n = 1;
    std::cout << "Print array lenght: ";
    // օգտագործողը մուտքագրում է մասիվի չափը
    std::cin >> n;
    int arr[n];

    // օգտագործողը մուտքագրում է մասիվի տարրերը
    std::cout << "Print array numbers: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // ալգորիթմի ռեալիզացիա
    int k = n;
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 1; j < k; ++j)
        {
            if(arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }           
        }
        --k;    
    }

    // արտածենք սորտավորված մասիվը
    std::cout << "Sorted array numbers: ";
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
