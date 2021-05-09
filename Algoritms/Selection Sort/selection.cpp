




/*Slection Sort finds small element in each iteration and places in respective
position.  */
#include <iostream>
#include <array>
#include <iterator>
using namespace std;

class SelectionSort
{
public:
  int length;
  int *arr;
  SelectionSort(int ar[], int len)

  {
    length = len;
    arr = ar;
  }

  void doSort()
  {

    for (int i = 0; i < length; i++)
    {

      int j = i;

      int subArrayIndex = 0;
      int subArray[length - i];
      while (j < length)
      {

        subArray[subArrayIndex] = arr[j];

        subArrayIndex++;
        j++;
      }
      int smallestElementIndex = getSmallestElementIndex(subArray, length - i) + i;
      if (smallestElementIndex < length)
      {
        int temp = arr[i];
        arr[i] = arr[smallestElementIndex];
        arr[smallestElementIndex] = temp;
      }
    }
  }

  int getSmallestElementIndex(int arr[], int ln)
  {
    int smallest = arr[0];
    int index = 0;

    for (int i = 0; i < ln; i++)
    {

      if (arr[i] < smallest)
      {

        index = i;
        smallest = arr[i];
      }
    }

    return index;
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
  int arr[] = {2, 3, 4, -1, -10, 7, 8, 9, 45, -20};

  SelectionSort ss = SelectionSort(arr, sizeof arr / sizeof arr[0]);
  cout << "Before sorting\n";
  ss.display();
  cout << "\n";
  ss.doSort();
  cout << "\nAfter sorting\n";
  ss.display();
  return 0;
}
