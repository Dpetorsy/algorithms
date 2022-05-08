#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

void    fillRandom(int arr[], const size_t size);
void    print(int arr[], const size_t size);
int     bogomax(int arr[], const size_t size);
int     findMax(int arr[], const size_t size);

int main()
{
    const size_t size = 10;
    int arr[size];
    fillRandom(arr, size);
    
    cout << "Your random array: ";
    print(arr, size);

    int max = bogomax(arr, size);
    cout << "Yes, first element of an array is maximum!\nMax = " << max << endl;
}

void fillRandom(int arr[], const size_t size)
{
    srand(time(0));
    
    for (size_t i = 0; i < size; ++i)
        arr[i] = 1 + (rand() % (size * 10));
}

void print(int arr[], const size_t size)
{
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int bogomax(int arr[], const size_t size)
{
    static int max = findMax(arr, size);
    
    if (arr[0] == max)
        return arr[0];
    else
    {
        cout << "Element " << arr[0] << " is not a maximum, swap it with random element..." << endl;
        size_t randomIndex = 1 + (rand() % (size - 1));
        std::swap(arr[0], arr[randomIndex]);
        cout << "Current array: ";
        print(arr, size);
        bogomax(arr, size);
    }
    return arr[0];
}

int findMax(int arr[], const size_t size)
{
    int max = arr[0];
    
    for (size_t i = 0; i < size; ++i)
        if (max < arr[i])
            max = arr[i];
            
    return max;
}
