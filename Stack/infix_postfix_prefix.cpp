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
        
        int prec(char c) {
            if(c == '^')
                return 3;
            else if(c == '/' || c =='*')
                return 2;
            else if(c == '+' || c == '-')
                return 1;
            else
                return -1;
        }
        string infix_to_postfix(string expression){
            
            size = expression.length();
            stack_array = new char[size];
            
            // final expression string
            string string_evaluation = "";

            for(int i = 0; i < size + 1; i++){
                if(expression[0] == ')' || expression[0] == '}' || expression[0] == ']'){
                    cout << "Your expression is wrong! Try adding the right one!" << endl;
                    break;
                }
                else if((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= '0' && expression[i] <= '9')){
                    string_evaluation += expression[i];
                }
                else if(is_Empty() && (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' || expression[i] == '(' || expression[i] == '{' || expression[i] == '[')){
                    push(expression[i]);
                }
                else if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
                    push(expression[i]);

                }
                else if(prec(expression[i]) > prec(stack_array[top])){
                    push(expression[i]);
                }
                else if(expression[i] == ')'){
                    for(int j = top; j >= 0; j--){
                        if(stack_array[j] == '('){
                            pop();
                            break;
                        }
                        string_evaluation += stack_array[j];
                        pop();
                    }  
                }
                // inserting greater priority operator
                else if(prec(expression[i]) <= prec(stack_array[top]) && (expression[i] != '(' || expression[i] != '{' || expression[i] != '[' || expression[i] != ')' || expression[i] != '}'|| expression[i] != ']')){
                    // loop going backwards till it finds an expression of greater priority! 
                    while (!is_Empty() && (prec(stack_array[top]) >= prec(expression[i])))
                    {
                        string_evaluation += stack_array[top];
                        pop();
                    }
                    push(expression[i]);
                }
                
            }
            while(is_Empty()){
                string_evaluation += stack_array[top];
                pop();
            }
            cout << "Converted expression is: " << string_evaluation << endl;
            top = -1;
            return string_evaluation;
            
        }

        void postfixEvaluation(string expression){
            // sum numbers
            int num1 = 0;
            int num2 = 0;

            // Size allocation
            size = expression.length();
            stack_array = new char[size];

            string new_expression = infix_to_postfix(expression);

            for(int i = 0; i < new_expression.length() + 1; i++){
                if(new_expression[i] >= '0' && new_expression[i] <= '9'){
                    push((int) new_expression[i] - 48);
                }
                else if(new_expression[i] == '+'){
                    
                    num1 = (int) (stack_array[top--]);
                    num2 = (int) (stack_array[top--]);
                    if(num2 + num1 != 0){
                        push((num2 + num1));
                    }
                    else{
                        cout << endl;
                    }
                    
                }
                else if(new_expression[i] == '-'){
                    
                    num1 = (int) (stack_array[top--]);
                    num2 = (int) (stack_array[top--]);
                    if(num2 - num1 != 0){
                        push((num2 - num1));
                    }
                    else{
                        cout << endl;
                    }
                    
                }
                else if(new_expression[i] == '*'){
                    
                    num1 = (int) (stack_array[top--]);
                    num2 = (int) (stack_array[top--]);
                    if(num2 * num1 != 0){
                        push((num2 * num1));
                    }
                    else{
                        cout << endl;
                    }
                    
                }
                else if(new_expression[i] == '/'){

                    num1 = (int) (stack_array[top--]);
                    num2 = (int) (stack_array[top--]);
                    if(num2 / num1 > 0){
                        push((num2 / num1));
                    }
                    else{
                        cout << endl;
                    }               
                }
                else if(new_expression[i] == '^'){

                    num1 = (int) (stack_array[top--]);
                    num2 = (int) (stack_array[top--]);
                    if(num2 ^ num1 != 0){
                        push((num2 ^ num1));
                    }
                    else{
                        cout << endl;
                    }               
                }

            }
            if(!is_Empty()){
                int final_answer = (int) stack_array[top];
                cout << "\nEvaluated Answer is: " << final_answer;
            }
            else{
                cout << "ZERO!" << endl;
            }   
        }
};

int main(){
    
    stack s1;
    int choice;
    string expression;
    
    do {
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        cout << "Select your option!\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to convert expression()." << endl;
        cout << "Press [2] to evaluate expression()." << endl;
        cout << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            cout << "Enter an infix expression for conversion" <<endl;
            cin >> expression;
            s1.infix_to_postfix(expression);
        }
        else if(choice == 2){
            cout << "Enter an infix expression for evaluation" <<endl;
            cin >> expression;
            s1.postfixEvaluation(expression);
        }
        
    } while (true);
    return 0;
};