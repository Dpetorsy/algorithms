#include <iostream>
#define ARRAY_MAX_SIZE 10
using std::cout;
using std::endl;

size_t  getArrSize();
void    getTreeNodes(unsigned tree[], const size_t size);
void    buildHeap(unsigned tree[], const size_t size);
void    minHeapify(unsigned tree[], const size_t size, const size_t root);
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
    
    buildHeap(tree, arrSize);
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

void buildHeap(unsigned tree[], const size_t size)
{
    size_t start = (size / 2) - 1;
    
    for (int i = start; i >= 0; --i)
        minHeapify(tree, size, i);
}

void minHeapify(unsigned tree[], const size_t size, const size_t root)
{
    size_t min = root;
    size_t left = (root * 2) + 1;
    size_t right = (root * 2) + 2;
    
    if (left < size && tree[left] < tree[min])
        min = left;
        
    if (right < size && tree[right] < tree[min])
        min = right;
        
    if (min != root)
    {
        std::swap(tree[root], tree[min]);
        minHeapify(tree, size, min);
    }
}

void printHeap(unsigned tree[], const size_t size)
{
    cout << "Min heap nodes:  ";
    for (size_t i = 0; i < size; ++i)
    {
        cout << tree[i] << "  ";
    }
    cout << endl;
}
