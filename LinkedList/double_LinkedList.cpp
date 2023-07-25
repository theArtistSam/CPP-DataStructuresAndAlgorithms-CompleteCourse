#include <iostream>
#include <string>
using namespace std;


struct student{

    int id;
    float gpa;
    student *next = NULL;
    student *previous = NULL;
    
};

student *front = NULL;
student *back = NULL;

// Student Methods
void front_id(){
    cout << "ID at front is: " << front -> id << endl;
}
void back_id(){
    cout << "ID at back is: " << back -> id << endl;
}
bool isEmpty(){
    if(front == NULL){
        return true;
    }
    else{
        return false;
    }
}

void insert_at_end(){

    student *current = new student;

    cout << "\nEnter ID" << endl;
    cin >> current -> id;
    
    cout << "Enter GPA" << endl;
    cin >> current -> gpa;`

    if(isEmpty()){
        front = back = current;
    }
    else{
        current -> previous = back;
        back -> next = current;
        back = current;
    }
}
void insert_at_start(){

    student *current = new student;


    cout << "\nEnter ID" << endl;
    cin >> current -> id;
    
    cout << "Enter GPA" << endl;
    cin >> current -> gpa;

    if(isEmpty()){
        front = back = current;
    }
    else{
        front -> previous = current;
        current -> next = front;
        front = current; 
    }
}
void delete_from_start(){

    student *p = new student;

    if(isEmpty()){
        cout << "\nAlready empty! Can't delete more" << endl; 
    }
    else{
        cout << "--------------------------------------------" << endl;
        p -> previous = NULL;
        p = front -> next;
        delete front;
        front = p;
    }
}

void delete_from_end(){
    student *p = front;

    if(isEmpty()){
        cout << "\nAlready empty! Can't delete more" << endl;
    }
    else{
        p = back -> previous;
        delete back;
        p -> next = NULL;
        back = p;
    }
}

void insert_after_specfic(int value){
    student *current = new student;

    cout << "\nEnter ID" << endl;
    cin >> current -> id;
    
    cout << "Enter GPA" << endl;
    cin >> current -> gpa;

    student *p = front;

    if(isEmpty()){
        front = back = current;
    }
    else{
        while (p -> id != value && p != NULL){

            p = p -> next;
    
        }
        if(value == back -> id){
            current -> next = NULL;
            current -> previous = p;
            p -> next = current;
            back = current;    
        }
        else{
            current -> next = p -> next;
            current -> previous = p;
            p -> next -> previous = current;
            p -> next = current;
        }
        
    }
    
}

void insert_before_specfic(int value){
    student *current = new student;

    cout << "\nEnter ID" << endl;
    cin >> current -> id;
    
    cout << "Enter GPA" << endl;
    cin >> current -> gpa;

    student *p = front;
    
    if(isEmpty()){
        cout << "Empty!" << endl;
    }
    else if(front -> id == value){
        current -> previous = NULL;
        current -> next = p;
        p -> previous = current;
        front = current;
    } 
    else{
        while(p -> id != value && p != NULL){
            p = p -> next;
        }

        current -> next = p; 
        current -> previous = p -> previous -> next;
        p -> previous -> next = current;
        p -> previous = current;
    }    
}

void delete_after_specfic(int value){

    student *p = front;
    student *p_2;

    if(isEmpty()){
        cout << "Already Empty!" << endl;
    }
    else{

        while (p -> id != value && p != NULL){
            p = p -> next;     
        }
        if (value == back -> id){
            cout << "Last Element! No such elements exist" << endl;
        }
        else{
            p_2 = p -> next;
            p -> next = p_2 -> next;
            p_2 -> next -> previous = p;
            delete p_2;
        }
    }
}

void delete_before_specfic(int value){

    student *p = front;
    student *p2;

    if(isEmpty()){
        cout << "Empty!" << endl;
    }
    else if(value == front -> id){
        cout << "First! You cannot delete no existing element" << endl;
    } 
    else{
        while(p -> id != value && p != NULL){
            
            p = p -> next;
        
        }
        p2 = p -> previous;
        p -> previous = p2 -> previous;
        p2 -> previous -> next = p2 -> next;
        delete p2;
    }    
}

void delete_specfic(int value){
    student *p = front;

    if(isEmpty()){
        cout << "Empty!" << endl;
    }
    else if(value == front -> id){
        p = front -> next;
        p -> previous = NULL;
        delete front;
        front = p;
    }
    else if(value == back -> id){
        p = back -> previous;
        p -> next = NULL;
        delete back;
        back = p;
    }
    else{
        while(p -> id != value && p != NULL){
            p = p -> next;
        }
        p -> next -> previous = p -> previous;
        p -> previous -> next = p -> next;
        delete p;
    }   
}

void display(){
    student *p = front;

    if(isEmpty()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        while (p != NULL)
        {
            cout << "ID is: " << p -> id;
            cout << "\tGPA is: " << p -> gpa << endl;
            p = p -> next;

        }   
    }
}

int main(){
    int choice, value;
    do
    {
        cout << "\n------------ SELECT YOUR OPTION! -----------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to insert_at_end." << endl;
        cout << "Press [2] to insert_at_start." << endl;
        cout << "Press [3] to delete_from_start." << endl;
        cout << "Press [4] to delete_from_end." << endl;
        cout << "Press [5] to insert_after_specfic." << endl;
        cout << "Press [6] to insert_before_specfic." << endl;
        cout << "Press [7] to delete_after_specfic." << endl;
        cout << "Press [8] to delete_before_specfic." << endl;
        cout << "Press [9] to delete_specfic." << endl;
        cout << "Press [10] to display" << endl;
        cout << "Press [11] to front id" << endl;
        cout << "Press [12] to back id" << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            insert_at_end();
        }
        else if(choice == 2){
            insert_at_start();
        }
        else if(choice == 3){
            delete_from_start();
        }
        else if(choice == 4){
            delete_from_end();
        }
        else if(choice == 5){
            cout << "\nEnter old student ID" << endl;
            cin >> value;
            insert_after_specfic(value);
        }
        else if(choice == 6){
            cout << "\nEnter old student ID" << endl;
            cin >> value;
            insert_before_specfic(value);
        }
        else if(choice == 7){
            cout << "\nEnter old student ID" << endl;
            cin >> value;
            delete_after_specfic(value);
        }
        else if(choice == 8){
            cout << "\nEnter old student ID" << endl;
            cin >> value;
            delete_before_specfic(value);
        }
        else if(choice == 9){
            cout << "\nEnter old student ID" << endl;
            cin >> value;
            delete_specfic(value);
        }
        else if(choice == 10){
            display();
        }
        else if(choice == 11){
            front_id();
        }
        else if(choice == 12){
            back_id();
        }

    } while (true);
    return 0;
}
