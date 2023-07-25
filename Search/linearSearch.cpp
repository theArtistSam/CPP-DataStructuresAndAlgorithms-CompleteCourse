# define V 5
#include <iostream>
#include <string>
using namespace std;




void linearSearch(int arr[V], int value){

    for(int i = 0; i < V; i++){
        if (arr[i] == value) {
            cout << "Found! " << arr[i] << endl;
            break;
        }
        
    }
}
int main(){

    int array[V] = {2, 3, 4, 5, 6};
    linearSearch(array, 5);
    
    return 0;
}