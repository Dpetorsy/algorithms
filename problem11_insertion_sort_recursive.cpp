#include <iostream>

// արտածում է սորտավորված մասիվը
void print_array(int arr[], int size)
{
    std::cout << "Sorted array numbers: ";
    for(int i = 0; i < size; ++i)
    {
	    std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertion_sort(int arr[], int size, int index)
{
    if(index < size)
    {
        // ալգորիթմի ռեալիզացիան
        for(int j = index; j > 0 && arr[j-1] > arr[j]; --j) 
        {
            //տեղերով փոխում է մասիվի 2 տարրեր
            std::swap(arr[j - 1], arr[j]);
        }
        ++index;
        insertion_sort(arr, size, index);
    }
    else
    {
        // եթե հասել է վերջին, կանչում է արտածման ֆունկցիան
        print_array(arr, size);
    }     
}

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

    insertion_sort(arr, n, 1);
    
    return 0;
}
