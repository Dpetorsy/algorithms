#include <iostream>
#define ARRAY_MAX_SIZE 10
using std::cout;
using std::endl;

size_t  getArrSize();
void    getTreeNodes(unsigned tree[], const size_t size);
void    maxHeapify(unsigned tree[], const size_t size);
void    printHeap(unsigned tree[], const size_t size);

int main()
{
    size_t arrSize = ARRAY_MAX_SIZE;
    arrSize = getArrSize();
    if (arrSize <= 1 || arrSize > 500)
    {
        std::cerr << "ERROR: Binary tree size must be in range [2, 500], try again." << endl;
        exit(1);
    }
    
    unsigned tree[arrSize];
    getTreeNodes(tree, arrSize);
    
    maxHeapify(tree, arrSize);
    printHeap(tree, arrSize);

    return 0;
}

size_t getArrSize()
{
    size_t size;
    cout << "Input binary tree size: ";
    std::cin >> size;
    cout << endl;
    return size;    
}

void getTreeNodes(unsigned tree[], const size_t size)
{
    cout << "Input binary tree nodes: ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> tree[i];
    }
    cout << endl;
}

void maxHeapify(unsigned tree[], const size_t size)
{
    size_t parent = 0;
    size_t j = 0;
    
    for (size_t i = 1; i < size; ++i)
    {
        parent = (i - 1) / 2;
        j = i;
            
        while (tree[j] > tree[parent])
        {
            std::swap(tree[j], tree[parent]);
            j = parent;
            parent = (parent - 1) / 2;
        }
    }
}

void printHeap(unsigned tree[], const size_t size)
{
    cout << "Max heap nodes:  ";
    for (size_t i = 0; i < size; ++i)
    {
        cout << tree[i] << "  ";
    }
    cout << endl;
}
