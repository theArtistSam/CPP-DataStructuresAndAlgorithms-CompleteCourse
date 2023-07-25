#define V 7
#include <iostream>
#include <string>

using namespace std;

void printLinearArray(int arr[V])
{
    for (int i = 0; i < V; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void insertionSort(int arr[V])
{

    /* for (int i = 0; i < 4; i++)
    {
        int minIndex = i;
        int j = i + 1;
        while (arr[j] < arr[minIndex])
        {

            // swap
            int temp = arr[minIndex];
            arr[minIndex] = arr[j];
            arr[j] = temp;

            j--;
            minIndex--;
        }
    } */

    int i, key, j;
    for (i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int array[V] = {7, 1, 9, 0, 3, 6, 2};
    insertionSort(array);
    printLinearArray(array);
    return 0;
}
