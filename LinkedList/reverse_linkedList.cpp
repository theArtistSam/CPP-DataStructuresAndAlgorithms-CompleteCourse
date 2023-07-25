#include <iostream>
#include <string>
using namespace std;

struct student{

    int id;
    float marks;
    student *next = NULL;
    
};

student *front = NULL;
student *back = NULL;

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

    cout << "\nEnter student ID" << endl;
    cin >> current -> id;
    
    cout << "Enter student Marks" << endl;
    cin >> current -> marks;

    if(isEmpty()){
        front = back = current;
    }
    else{
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
        front = back = current;
    }
    else{
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
        while(true){
            if(p -> next == back){
                delete back;
                back = p;
                back -> next = NULL;
                break;
            }
            p = p -> next;
        }
    }
}

void insert_after_specfic(int value){
    student *current = new student;

    cout << "\nEnter student ID" << endl;
    cin >> current -> id;
    
    cout << "Enter student Marks" << endl;
    cin >> current -> marks;

    student *p = front;
    student *p_2;

            
    while(true){    
        if(p -> id == back -> id){
            p -> next = current;
            current -> next = NULL;
            back = current;
            break;
        }
        else if(p -> id == value){
            cout << "Found__!" << endl;
            p_2 = p -> next;
            p -> next = current;
            current -> next = p_2;
            break;
        }
        p = p -> next;
    }
}
void insert_before_specfic(int value){
    student *current = new student;


    cout << "\nEnter student ID" << endl;
    cin >> current -> id;
    
    cout << "Enter student Marks" << endl;
    cin >> current -> marks;

    student *p = front;
    student *p_2 = front;
    student *p_3; // Holding Pointer
    student *k = back;
    

    if(isEmpty()){
        cout << "Empty!" << endl;
    } 
    else{
        while(true){
            while(p != k){
                p_2 = p;
                p = p -> next;
            }
            if(value == front -> id){
                current -> next = front;
                front = current;     
                break;
            }

            else if(k -> id == value){
                cout << "Reached" << endl;
                p_3 = p_2 -> next;
                p_2 -> next = current;
                current -> next = p_3;
                break;
            }
            // updating values
            k = p_2;
            p = front;
            
        }
    }    
}


void delete_after_specfic(int value){

    student *p = front;
    student *p_2 = front;
    student *p_3;

    if(isEmpty()){
        cout << "Already Empty!" << endl;
    }
    else{
        while(true){
            if(p -> id == value){
                if(p -> next == NULL){
                    cout << "Item don't exist" << endl;
                    break;
                }
                else{
                    p_2 = p -> next;
                    p_3 = p_2 -> next;
                    p -> next = p_3;
                    delete p_2;
                    break;
                }
                         
            }
            p = p -> next;
        }
    }
}

void delete_before_specfic(int value){

    student *p = front;
    student *p_2 = front;
    student *p_3; // Holding Pointer
    student *p_4 = front;
    student *p_5; // Holding Pointer
    student *k = back;
    

    if(isEmpty()){
        cout << "Empty!" << endl;
    } 
    else{
        while(true){
            while(p != k){
                p_2 = p;
                p = p -> next;
            }
            if(value == front -> id){
                cout << "No value exists" << endl; 
                break;
            }

            cout << "p_2 id: " << p_2 -> id << endl;
            // previous's previous
            if(front -> next == p_2 -> next){
                cout << "Front per aa giya sir ma!" << endl;
                p = front -> next;
                delete front;
                front = p;    
                break;
            }

            while(p_4 != p_2){
                cout << "checking" << endl;
                p_5 = p_4;
                p_4 = p_4 -> next;
            }

            cout << "p_5 id: " << p_5 -> id << endl;

            if(k -> id == value){
                cout << "Reached" << endl;
                p_3 = p_2 -> next;
                p_5 -> next = p_3;
                delete p_2;
                break;
            }
            // updating values
            k = p_2;
            p = front;
            p_4 = front;
            
        }
    }    
}

void delete_specfic(int value){
    student *p = front;
    student *k = back;
    student *p_2 = front;
    student *p_3;

    if(isEmpty()){
        cout << "Empty!" << endl;
    }
    else if(value == front -> id){
        p = front -> next;
        delete front;
        front = p;
    }
    else{
        while(true){
            while(p != k){
                p_2 = p;
                p = p -> next;
            }
            if (value == back -> id){
                back = p_2;
                p_2 -> next = NULL;
                delete k;
                break;
            }
            else if(k -> id == value){
                p_3 = k -> next;
                delete k;
                p_2 -> next = p_3;
                break;
            }
            // updating values
            k = p_2;
            p = front;
        }
    }   
}

void reverse(){

    // Initialize current, previous and next pointers
        student *current = front;
        student *prev = NULL;
        student *next = NULL;
        student *p = front;

        while (current != NULL) {
            // Store next
            next = current -> next;
            // Reverse current node's pointer
            current -> next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        back = p;
        front = prev;

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
            cout << "Student ID is: " << p -> id;
            cout << "\tStudent Marks are: " << p -> marks << endl;
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
        cout << "Press [13] to reverse" << endl;
        

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
        else if(choice == 13){
            reverse();
        }

    } while (true);
    return 0;
}

