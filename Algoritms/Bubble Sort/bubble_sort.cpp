



/*    Bubble Sort is the simplest sorting algorithm.
 It works by repeatedly swapping the adjacent elements 

*/

#include <iostream>
#include <array>
#include <iterator>
using namespace std;

class BubbleSortAlg
{
public:
    int length;
    int *arr;
    BubbleSortAlg(int ar[], int len)

    {
        length = len;
        arr = ar;
    }
    

    void doSort()
    {

        for (int i = 0; i < length; i++)
        {

            for (int j = 0; j < length - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
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
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BubbleSortAlg bs = BubbleSortAlg(arr, n);
    cout << "Before sorting\n";
    bs.display();

    bs.doSort();
    cout << "\nAfter sorting\n";
    bs.display();
}