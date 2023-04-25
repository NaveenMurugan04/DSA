/* ///Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. The count is stored in an auxiliary array and 
the sorting is done by mapping the count as an index of the auxiliary array. */


#include <iostream>
#include <array>
#include <iterator>
using namespace std;

class CountSort
{
public:
  int *arr;
  int length;

  CountSort(int ar[], int len)
  {
    arr = ar;
    length = len;
  }

  void doSort()
  {
    int count_arr[11] = {0};
    for (int i = 0; i < 6; i++)
    {

      count_arr[arr[i]]++;
    }
    for (int i = 1; i < 11; i++)
    {

      count_arr[i] += count_arr[i - 1];
    }

    for (int i = 0; i < 11; i++)
    {
      cout << count_arr[i] << "\t";
    }




    int op_arr[6] = {0};
    for (int i = 0; i < 6; i++)
    {

      op_arr[--count_arr[arr[i]]] = arr[i];
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

  int inp[6] =
      {4, 10, 3, 1, 0, 10};
  CountSort cs = CountSort(inp, 6);
  cout << "Before sorting\n";
  cs.display();
  cout << "\n";
  cs.doSort();
  cout << "\nAfter sorting\n";
  cs.display();
  return 0;
}