
/* Insertion  sort is the sorting mechanism where the sorted array is built having one item at a time. 
The array elements are compared with each other sequentially and then arranged simultaneously in some particular order ,
Every pass will ensure that elements are arranged in left side are lesser than curent element*/

#include <iostream>
#include <array>
#include <iterator>
using namespace std;

class InsertionSortAlg
{
public:
    int *arr;
    int length = 0;

    InsertionSortAlg(int ar[], int len)
    {
        arr = ar;
        length = len;
    }

    void doSort()
    {
        int insertionElement;

        for (int i = 1; i < length; i++)
        {
            int k = i;
            int j = i - 1;
            insertionElement = arr[i];

            while (j >= 0 && arr[j] > arr[k])
            {
                arr[k] = arr[j];
                arr[j] = insertionElement;
                k = j;
                j = j - 1;
            }
        }

        //return arr;
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << "\t";
        }
    }
};

int main()
{
    int n;
    int inputArray[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inputArray[i];
    }

    InsertionSortAlg ins = InsertionSortAlg(inputArray, n);
    cout << "Before sorting\n";
    ins.display();

    ins.doSort();
    cout << "\nAfter sorting\n";
    ins.display();

    return 0;
}