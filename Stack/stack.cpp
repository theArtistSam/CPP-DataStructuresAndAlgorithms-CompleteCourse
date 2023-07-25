#include <iostream>
#include <string>
using namespace std;

class stack{
    

    private:
        int size;
        int array[5];
        int top;

    public:

        // Constructor
        stack(){
            size = 5;
            top = -1;
        }
        
        bool is_Empty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool is_Full(){
            if(top == size - 1){
                return true;
            }
            else{
                return false;
            }
        }

        void push(int num){
            if(is_Full()){
                cout << "You cannot insert more elements! Stack Full" << endl;
            }
            else{
                top++; // top = top + 1
                array[top] = num;
            }
        }

        void pop(){
            if(is_Empty()){
                cout << "You cannot pop more elements! Stack empty" << endl;
            }
            else{
                top--; // top = top - 1;
            }
        }
        
        void display(){
            cout << "\n--- STACK ---\n" << endl;
            for (int i = 0; i < top + 1; i++) {
                cout << array[i] << "  ";
            }
            cout << endl;
        }
};

int main(){
    
    stack s1; // Created an object of stack
    int choice, value;
    
    do {
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        cout << "Select your option!\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to isEmpty." << endl;
        cout << "Press [2] to isFull." << endl;
        cout << "Press [3] to push()" << endl;
        cout << "Press [4] to pop()" << endl;
        cout << "Press [5] to display()." << endl;
        cout << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            if(s1.is_Empty()){
                cout << "Empty!" << endl;
            }
            else{
                cout<< "Not Empty!" <<"\n";
            }
        }
        else if(choice == 2){
            if(s1.is_Full()){
                cout<< "Full" <<"\n";
            }
            else{
                cout<< "Not Full" <<"\n";
            }
        }
        else if(choice == 3){
            cout << "Enter your value" <<endl;
            cin >> value;
            s1.push(value);
        }
        else if(choice == 4){
            s1.pop();
        }
        else if(choice == 5){
           s1.display();
        }
        
    } while (true);
    return 0;
};