#include <iostream>
#include <string>
using namespace std;

struct stack{

    char data;
    stack *next = NULL;
    
};

stack *top = NULL;

bool isEmpty(){
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
}

void push(){

    stack *current = new stack();

    cout << "\nEnter student ID" << endl;
    cin >> current -> data;
    
    if(isEmpty()){
        top = current;
    }
    else{
        current -> next = top; // top++;
        top = current;
    }
}

char pop(){
    if(isEmpty()){
        cout << "\nAlready empty! Can't delete more" << endl;
    }
    else{
        int topElement = top -> data;
        top = top -> next;
        return topElement;
    }
    return 0;   
}

void display(){

    stack *p = top;

    if(isEmpty()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        while (p != NULL)
        {
            cout << "Student ID is: " << p -> data << endl;
            p = p -> next;
        }   
    }
}

void palindromeCheck(){
    
    string forward;
    string backward;

    // inserting in forward direction
    while(!isEmpty()){
        forward += pop();
    }

    // inserting in backward direction
    for (int i = forward.length() - 1; i >= 0; i--)
    {
        backward += forward[i];
    }
    
    // comparing them together!
    if (forward != backward)
    {
        cout << "Not Palindrome" << endl;
    }
    else{
        cout << "Palindrome" << endl;
    }
    
}

int main(){
    int choice, value;
    do
    {
        cout << "\n------------ SELECT YOUR OPTION! -----------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to push()." << endl;
        cout << "Press [2] to pop()." << endl;
        cout << "Press [3] to display()." << endl;
        cout << "Press [4] to checkPalindrome()." << endl;

        cin >> choice;
        
        if(choice == 1){
            push();
        }
        else if(choice == 2){
            pop();
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            palindromeCheck();
        }
    
    } while (choice != 0);
    return 0;
}

