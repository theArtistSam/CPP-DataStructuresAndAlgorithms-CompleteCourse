#include <iostream>
#include <string>
using namespace std;

class heap{
    
    private:
        int size;
        int array[10];
        int front;
        int back;

    public:

        // Default Constructor
        heap(){
            size = 10;
            front = -1;
            back = -1;
        }
        
        bool is_Empty(){
            if(back == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool is_Full(){
            if(back == size - 1){
                return true;
            }
            else{
                return false;
            }
        }

        void insert(int num){
            if(is_Full()){
                cout << "You cannot insert more elements! Stack Full" << endl;
            }
            else if (is_Empty()){
                front = back = 0;
                array[back] = num;
            }
            else{
                array[++back] = num;
                int index = back;

                int parent = (back - 1) / 2;

                while (array[index] > 0 && array[index] < array[parent])
                {   
                    // Swap
                    int temp = array[parent];
                    array[parent] = array[index];
                    array[index] = temp;

                    // changing value back again!
                    index = parent;
                    parent = (index - 1) / 2;
                }
            }
        }

        void deleteVal(){
            if(is_Empty()){
                cout << "You cannot pop more elements! Stack empty" << endl;
            }
            else{
                int largest = array[back];
                back--;

                int start = 0;
                array[start] = largest;

                // parent of the starting index
                // once the value gets changed!
                int parent = (start - 1) / 2; 
                int left = 2 * start + 1;
                int right = 2 * start + 2;
                
                if(is_Empty()){
                    cout << "Deleted!" << endl;
                }
                // While Condition!                
                while (left < back && right < back)
                {       
                    if(array[left] < array[right]){
                        cout << "issue L" << endl;                 

                        if(array[left] < array[parent]){
                            // Swap
                            int temp = array[left];
                            array[left] = array[start];
                            array[start] = temp;

                            start = left;
                            left = 2 * start + 1;
                            right = 2 * start + 2;
                            parent = (start - 1) / 2;
                        }
                        else{
                            break;
                        }   
                    }
                    else if(array[right] < array[left]){
                        cout << "issue R" << endl;       

                        if(array[right] < array[parent]){
                            // Swap
                            int temp = array[right];
                            array[right] = array[start];
                            array[start] = temp;
                            
                            start = right;
                            left = 2 * start + 1;
                            right = 2 * start + 2;
                            parent = (start - 1) / 2;

                        }
                        else{
                            break;
                        }      
                    }
                }   
            }            
        }

        void display(){
            cout << "\n------ TREE ------\n" << endl;
            for (int i = 0; i < back + 1; i++) {
                cout << array[i] << "  ";
            }
            cout << endl;
        }
};

int main(){
    
    heap h1;
    int choice, value;
    
    do {
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        cout << "Select your option!\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to isEmpty." << endl;
        cout << "Press [2] to isFull." << endl;
        cout << "Press [3] to insert()" << endl;
        cout << "Press [4] to delete()" << endl;
        cout << "Press [5] to display()." << endl;
        cout << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            if(h1.is_Empty()){
                cout << "Empty!" << endl;
            }
            else{
                cout<< "Not Empty!" <<"\n";
            }
        }
        else if(choice == 2){
            if(h1.is_Full()){
                cout<< "Full" <<"\n";
            }
            else{
                cout<< "Not Full" <<"\n";
            }
        }
        else if(choice == 3){
            cout << "Enter your value" <<endl;
            cin >> value;
            h1.insert(value);
        }
        else if(choice == 4){
            h1.deleteVal();
        }
        else if(choice == 5){
           h1.display();
        }
        
    } while (true);
    return 0;
};