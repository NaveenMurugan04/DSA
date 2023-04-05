

/* Shell sort is a sorting algorithm that first sorts the elements far; apart from each other and
 successively reduces the interval between the elements to be sorted */


#include <iostream>
#include <array>
#include <iterator>
using namespace std;

class ShellSort
{
public:
  int *arr;
  int length;

  ShellSort(int inpArray[], int len)
  {
    arr = inpArray;
    length = len;
  }

  void doSort()
  {
    int mid = length / 2;
    while (mid != 0)
    {

      for (int i = 0; i < length; i++)
      {
        if (mid + i < length && arr[i] > arr[mid + i])

        {
          int temp = arr[i];
          arr[i] = arr[mid + i];
          arr[mid + i] = temp;

          while (
              mid - i >= 0 && arr[mid - i] > arr[i] && i >= mid)
          {
            int t = arr[i];
            arr[i] = arr[mid - i];
            arr[mid - i] = t;
          }
        }
      }
      mid = mid / 2;
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
      {4, -10, 3, 1, 0, 10};
  ShellSort ss = ShellSort(inp, 6);
  cout << "Before sorting\n";
  ss.display();
  cout << "\n";
  ss.doSort();
  cout << "\nAfter sorting\n";
  ss.display();
  return 0;
}