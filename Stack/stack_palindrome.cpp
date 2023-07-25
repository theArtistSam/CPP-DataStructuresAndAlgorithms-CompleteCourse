#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class stack{
    
private:

        int top;
        int size;
        string expression;
        char *stack_array;

    public:

        // argumented constructor
        stack(){

            top = -1;
            size = 0; 

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
        void push(char character){
            if(is_Full()){
                cout << "You cannot insert more elements! Stack Full" << endl;
            }
            else{
                top++;
                stack_array[top] = character;
            }
        }
        void pop(){
            if(is_Empty()){
                cout << "You cannot pop more elements! Stack empty" << endl;
            }
            else{
                top--;
            }
        }

        void palindrome_check(string expression){
            
            size = expression.length();
            stack_array = new char[size];
            // Reverse String
            string reverse = "";

            for(int i = 0; i < size; i++){
                // push-ing elements into the stack
                push(expression[i]);
                
            }
            
            for(int i = size; i > 0; i--){
                char x = stack_array[top];
                pop();
                reverse += x;
            }

            cout << reverse << endl;

            if(reverse == expression){
                cout << "Palindrome" << endl;
            }
            else{
                cout << "Not Palindrome" << endl;
            }
            top = -1;
        }
};

int main(){
    
    stack s1;
    int choice;
    string expression;
    
    do {
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        cout << "Select your option!\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to palindrome_check()." << endl;
        cout << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            cout << "Enter your any string based expression" <<endl;
            cin >> expression;
            s1.palindrome_check(expression);
        }
        
    } while (true);
    return 0;
};