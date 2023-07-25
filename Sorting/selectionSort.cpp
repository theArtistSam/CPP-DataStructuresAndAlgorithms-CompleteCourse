# define V 6
#include <iostream>
#include <string>
using namespace std;



void printLinearArray(int arr[V]){
    for (int i = 0; i < V; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void selectionSort(int arr[V]){
    
    for(int i = 0; i < V; i++){
        int minIndex = i;
        for(int j = i + 1; j < V; j++){
            if (arr[j] < arr[minIndex]) {
                
                minIndex = j;
            
            }
        }
        // Swapping
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(){

    int array[V] = {23, 60, 8, 1, 0, 3};
    selectionSort(array);
    printLinearArray(array);
    return 0;

}