# define V 10
#include <iostream>
#include <string>
using namespace std;



void printLinearArray(int arr[V]){
    for (int i = 0; i < V; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void bubbleSort(int arr[V]){

    int count = 0;
    for(int i = 1; i < V; i++){
        for(int j = 0; j < V - i; j++){
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        
        }
    }
    cout << "Total number of swaps are: " << count << endl;   
}
int main(){

    int array[V] = {18, 34, 21, 12, 15, 8, 10, 4, 37, 2};
    bubbleSort(array);
    printLinearArray(array);
    return 0;
}