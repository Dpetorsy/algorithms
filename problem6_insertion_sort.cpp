#include <iostream>

int main()
{
    int n, a;
    std::cout << "Print array lenght: ";

    //օգտագործողը մուտքագրում է մասիվի չափը
    std::cin >> n;
    int array[n];

    //օգտագործողը մուտքագրում է մասիվի տարրերը, օգտագործել "space" ստեղնը "enter"֊ի փոխարեն
    std::cout << "Print array numbers: ";
    for(int i = 0; i < n; ++i)
    {
	    std::cin >> a;
	    array[i] = a;
    }

    //ալգորիթմի ռեալիզացիան
    for(int i = 1; i < n; ++i)
    {
        for(int j = i; j > 0 && array[j-1] > array[j]; --j) 
        {
            //տեղերով փոխում է մասիվի 2 տարրեր
            std::swap(array[j - 1], array[j]);
	    }
    }

    //արտածում է սորտավորված մասիվը
    std::cout << "Sorted array numbers: ";
    for(int i = 0; i < n; ++i)
    {
	    std::cout << array[i] << " ";
	    if(i == (n - 1)) std::cout << std::endl;
    }

    return 0;
}
