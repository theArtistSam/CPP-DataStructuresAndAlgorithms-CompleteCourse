#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class stack{
    
    private:

        int top;
        int size;   
        char *stack_array;

    public:

        // default constructor
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

        int prec(char ch){
            if (ch == '(' || ch == ')')
            {
                return 0;
            }
            else if (ch == '{' || ch == '}')
            {
                return 1;
            }
            else if (ch == '[' || ch == ']')
            {
                return 2;
            }
            return 0;
        }
        void balanced_check(string expression){

            size = expression.length();
            stack_array = new char[size];

            // Boolean for checking
            bool check = true;
            for(int i = 0; i < size; i++){
                if(expression[0] == ')' || expression[0] == '}' || expression[0] == ']'){
                    check = false;
                    break;
                }
                else if(is_Empty()){
                    push(expression[i]);
                }
                else if(expression[i] == ')' && stack_array[top] == '('){
                    pop();
                }
                else if(expression[i] == '}' && stack_array[top] == '{'){
                    pop();
                }
                else if(expression[i] == ']' && stack_array[top] == '['){
                    pop();
                }
                else if(expression[i] == ')' && stack_array[top] != '('){
                    check = false;
                    break;
                }
                else if(expression[i] == '}' && stack_array[top] != '{'){
                    check = false;
                    break;
                }
                else if(expression[i] == ']' && stack_array[top] != '['){
                    check = false;
                    break;
                }
                else if (prec(stack_array[top]) >= prec(expression[i] )){
                    push(expression[i]);
                }
            }

            if(check == true && top == -1){
                cout << "Your expression is balanced" << endl;
            }
            else{
                cout << "Your expression is un-balanced" << endl;
            }

            top = -1;

        }

};

int main(){
    int choice;
    string new_expression;

    stack s1;
    
    do {
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        cout << "Select your option!\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to balanced_check()." << endl;
        cout << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            cout << "Enter new expression" << endl;
            cin >> new_expression;
            s1.balanced_check(new_expression);
        }
        
    } while (true);
    return 0;
};