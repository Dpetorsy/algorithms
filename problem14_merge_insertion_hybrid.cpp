#include <iostream>

// իրար է միացնում L և M մասիվները
void merge(int arr[], int l, int m, int r) 
{
    // ստանանք L և M մասիվների չափերը
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], M[n2];

    // ստանանք L և M մասիվները մեր տված մասիվից
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[m + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    // մինչև որ չհասնենք մասիվներից մեկի վերջին, համեմատում ենք իրար հետ L և M մասիվների տարրերը
    // որը փոքր է գրում ենք arr մասիվի մեջ
    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // երբ հասանք L կամ M մասիվներից մեկի վերջին
    // arr մասիվի վերջից տեղադրում ենք ոչ դատարկ մասիվի մեջ մնացած տարրերը
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// բաժանում ենք մասիվը 2 փոքր մասիվների, սորտավորում ենք և միացնում իրար
void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        // m֊ը մասիվի բաժանման կետն է
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// սորտավորում է մասիվը 
void insertion(int array[], int size)
{
    for(int i = 1; i < size; ++i)
    {
        for(int j = i; j > 0 && array[j-1] > array[j]; --j) 
        {
            //տեղերով փոխում է մասիվի 2 տարրեր
            std::swap(array[j - 1], array[j]);
	    }
    }
}

// տպում է սորտավորված մասիվը
void printArray(int arr[], int size) 
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    int n,k;

     //օգտագործողը մուտքագրում է 'k' թիվը
    std::cout << "Enter k positive number: ";
    std::cin >> k;
    
    //օգտագործողը մուտքագրում է մասիվի չափը
    std::cout << "Print lenght of an array: ";
    std::cin >> n;
    int arr[n];

    // օգտագործողը մուտքագրում է մասիվի տարրերը
    std::cout << "Print array numbers: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // կախված k և n թվերից, կանչում է համապատասխան սորտավորման ֆունկցիաները
    if(n < k)
    {
        insertion(arr, n);
    }
    else
    {
        mergeSort(arr, 0, n - 1);
    }

    //արտածում ենք արդյունքը
    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
