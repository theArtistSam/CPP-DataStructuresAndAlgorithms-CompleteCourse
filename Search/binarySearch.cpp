# define V 5
#include <iostream>
#include <string>
using namespace std;

void binarySearch(int arr[V], int value){
    int start = 0;
    int end = V - 1;
    int mid = (start + end) / 2;
    int check = true;
    
    while(start <= end && check == true){
        if (value == arr[mid]) {
            cout << "Found! " << arr[mid] << endl;
            check = false;
        }
        else if (value > arr[mid]){
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else{
            end = mid - 1;
            mid = (start + end) / 2;
    
        }
    }
}
int main(){

    int array[V] = {2, 3, 4, 5, 6};
    binarySearch(array, 2);
    
    return 0;
}