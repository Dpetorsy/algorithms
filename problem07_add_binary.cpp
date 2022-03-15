#include <iostream>

int main()
{
    int n;
    std::cout << "Print the lenght of the arrays: ";
    std::cin >> n;
    int array1[n], array2[n];
    int result[n+1];
    int karg = 0;
    int gumar;

    //mutqagrum e arajin masivi tarrer@, ogtagorcel 'space' stexn@ 'enter' stexni poxaren
    std::cout << "Print numbers for first array: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> array1[i];
    }

    //mutqagrum e erkrord masivi tarrer@, ogtagorcel 'space' stexn@ 'enter' stexni poxaren
    std::cout << "Print numbers for second array: ";
    for(int i = 0; i < n; ++i)
    {
        std::cin >> array2[i];
    }

    //algoritmi realizacian, cikl@ sksum enq verjic u stugum amen masivi tarri u kargi gumar@
    for(int i = n - 1; i >= 0; --i)
    {
        //gumarum enq masivi i tarrer@ ev naxord tveri gumarumic stacvac karg@(1 kam 0)
        gumar = array1[i] + array2[i] + karg;

        //ete gumar@ 0 e, apa karg@ mnum e 0, isk result massivum grum enq 0 tiv@
        if(gumar == 0)
        {
            result[i + 1] = 0;
            karg = 0;
        }
        ////ete gumar@ 1 e, apa karg@ mnum e 0, isk result massivum grum enq 1 tiv@
        else if(gumar == 1)
        {
            result[i + 1] = 1;
            karg = 0;
        }
        ////ete gumar@ 2 e, apa karg@ darnum e 1, isk result massivum grum enq 0 tiv@
        else if(gumar == 2)
        {
            result[i + 1] = 0;
            karg = 1;
        }
        //ete gumar@ 3 e, apa karg@ darnum e 1, isk result massivum grum enq 1 tiv@
        else if(gumar == 3)
        {
            result[i + 1] = 1;
            karg = 1;
        }
    }
    //verjum result masivi araji tarri tex@ grum enq 1, qani vor mer tvac erkuakan tver@ sksvum en 1 ov
    result[0] = 1;

    //artacum e ardyunq@
    std::cout << "Result: ";
    for(int i = 0; i <= n; ++i)
    {
        std::cout << result[i] << "";
    }
    std::cout << std::endl;

    return 0;
}
