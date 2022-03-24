#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

void getMaxSize(size_t& size);
void fillRandom(int* const arr, size_t size);
int  maxSubArr(int* const startEndInd, const int* const arr, size_t size);
void print(const int* const arr, size_t start, size_t end);

int main()
{
    size_t maxSize = 10;
    getMaxSize(maxSize);
    
    if (maxSize <= 0)
    {
        cout << "Array size error, try again." << endl;
        exit(1);
    }

    int arr[maxSize];
    fillRandom(arr, maxSize);
    
    cout << "Random array: ";
    print(arr, 0, maxSize - 1);
    cout << endl;
    
    int startEndInd[2];
    int maxValue = 0;
    maxValue = maxSubArr(startEndInd, arr, maxSize);
    
    cout << "Subarray maximum value: " << maxValue << endl;
    cout << "Max subarray start index: " << startEndInd[0] << endl;
    cout << "Max subarray end index: " << startEndInd[1] << endl;
    cout << "Max subarray elements: ";
    print(arr, startEndInd[0], startEndInd[1]);

    return 0;
}

void getMaxSize(size_t& size)
{
    cout << "Input array size: ";
    std::cin >> size;
}

void fillRandom(int* const arr, size_t size)
{
    srand(time(0));
    
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = random() % 10;
        if (random() % 10 > 6)
            arr[i] = -arr[i];
    }
}

int maxSubArr(int* const startEndInd, const int* const arr, size_t size)
{
    int currentMaxValue = -2147483648;
    int currentValue = 0;
    
    for (size_t i = 0; i < size; ++i)
    {
        currentValue = 0;
        for (size_t j = i; j < size; ++j)
        {
            currentValue += arr[j];
            if (currentValue >= currentMaxValue)
            {
                currentMaxValue = currentValue;
                startEndInd[0] = i;
                startEndInd[1] = j;
            }
        }
    }
    return currentMaxValue;
}

void print(const int* const arr, size_t start, size_t end)
{
    for (size_t i = start; i <= end; ++i)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
