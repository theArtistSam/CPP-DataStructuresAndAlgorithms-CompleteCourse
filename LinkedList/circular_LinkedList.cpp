#include <iostream>
#include <string>
using namespace std;

struct student{

    int id;
    float marks;
    student *next = NULL;
    
};

student *back = NULL;

void front_id(){
    cout << "ID at back is: " << back -> next -> id << endl;
}
void back_id(){
    cout << "ID at back is: " << back -> id << endl;
}
bool isEmpty(){
    if(back == NULL){
        return true;
    }
    else{
        return false;
    }
}

void insert_at_end(){

    student *current = new student;

    cout << "\nEnter student ID" << endl;
    cin >> current -> id;
    
    cout << "Enter student Marks" << endl;
    cin >> current -> marks;

    if(isEmpty()){
        back = current;
        back -> next = current;
    }
    else{
        current -> next = back -> next;
        back -> next = current;
        back = current;
    }
}

void insert_at_start(){

    student *current = new student;


    cout << "\nEnter student ID" << endl;
    cin >> current -> id;
    
    cout << "Enter student Marks" << endl;
    cin >> current -> marks;

    if(isEmpty()){
        back = current;
        back -> next = current;
    }
    else{
        current -> next = back -> next;
        back -> next = current;
    }
}
void delete_from_start(){

    student *p = back;

    if(isEmpty()){
        cout << "\nAlready empty! Can't delete more" << endl; 
    }
    else{
        cout << "--------------------------------------------" << endl;
        if(p -> next == p){
            back = NULL;
        }
        else{
            p = back -> next -> next;
            delete back -> next;
            back -> next = p;
        }
        
    }
}

void delete_from_end(){
    student *p = back;
    student *p2;

    if(isEmpty()){
        cout << "\nAlready empty! Can't delete more" << endl;
    }
    else{
        if(p -> next == p){
            back = NULL;
        }
        else{
            do
            {
                p2 = p;
                p = p -> next;

            } while (p != back);
            
            
            p2 -> next = p -> next;
            back = p2;
            delete p;

        }
        
    }
}

void insert_after_specfic(int value){
    student *current = new student;

    cout << "\nEnter student ID" << endl;
    cin >> current -> id;
    
    cout << "Enter student Marks" << endl;
    cin >> current -> marks;

    student *p = back;

    if(value == back -> id){
        current -> next = back -> next;
        back -> next = current;
        back = current;
    }
    else{
        do
        {
            p = p -> next;

        } while (p -> id != value);

        current -> next = p -> next;
        p -> next = current;
    }   
 
}
void insert_before_specfic(int value){
    student *current = new student;

    student *p = back;
    student *p_2;

    cout << "\nEnter student ID" << endl;
    cin >> current -> id;
    
    cout << "Enter student Marks" << endl;
    cin >> current -> marks;
    
    if(value == back -> next -> id){
        current -> next = back -> next;
        back -> next = current;
    }
    else{
        do
        {   
            p_2 = p;
            p = p -> next;

        } while (p -> id != value);
        
        current -> next = p_2 -> next;
        p_2 -> next = current;
    } 
    
}

void delete_after_specfic(int value){

    student *p = back;
    student *p2;

    if(isEmpty()){
        cout << "Already Empty!" << endl;
    }
    else if(value == back -> id){
        cout << "Last one! you cannot delete any more element!" << endl;
    }
    else{
        do
        {   
            p = p -> next;

        } while (p -> id != value);

        p2 = p -> next;
        p -> next = p2 -> next;
        delete p2;
    }
}

void delete_before_specfic(int value){

    student *p = back;
    student *p2;
    student *p3 = back -> next;


    if(isEmpty()){
        cout << "Empty!" << endl;
    }
    else if(value == back -> next -> id){
        cout << "First Element! you cannot delete any more element!" << endl;
    } 
    else{

        do
        {   p3 = p2;
            p2 = p;
            p = p -> next;

        } while (p -> id != value);

        cout << "p3 is: " << p3 -> id << endl;
        cout << "p2 is: " << p2 -> id << endl;
        cout << "p is: " << p -> id << endl;

        if(p2 -> next -> id == back -> next -> next -> id){
            p = back -> next -> next;
            delete back -> next;
            back -> next = p;
        }
        else{

            p3 -> next = p2 -> next;
            delete p2;
        }
        
    } 
}

void delete_specfic(int value){
    student *p = back;
    student *p2;


    if(isEmpty()){
        cout << "Empty!" << endl;
    }
    else if(value == back -> next -> id){
        p = back -> next -> next;
        delete back -> next;
        back -> next = p;
    }
    else{
        do
        {
            p2 = p;
            p = p -> next;

        } while (p -> id != value);
        
        if(value == back -> id){
            p2 -> next = p -> next;
            back = p2;
            delete p;
        }
        else{
            p2 -> next = p -> next;
            delete p;
        }

    }   
}

void display(){
    student *p = back;

    if(isEmpty()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        
        do
        {
            p = p -> next;
            cout << "Student ID is: " << p -> id;
            cout << "\tStudent Marks are: " << p -> marks << endl;
            
        }
        while (p != back);   
        
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

