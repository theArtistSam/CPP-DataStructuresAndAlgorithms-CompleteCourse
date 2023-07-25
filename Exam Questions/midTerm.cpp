#include <iostream>
#include <string>
using namespace std;

struct student{

    int id;
    student *next = NULL;
    student *previous = NULL;

};

// list one
student *front = NULL;
student *back = NULL;

// list one
student *front2 = NULL;
student *back2 = NULL;

// prints front
void front_id(){
    cout << "ID at front is: " << front -> id << endl;
}

// prints back
void back_id(){
    cout << "ID at back is: " << back -> id << endl;
}

// check is linked list is empty
bool isEmpty(){
    if(front == NULL){
        return true;
    }
    else{
        return false;
    }
}

// insert at end
void insert_at_end(){

    student *current = new student;
    
    student *p = front;

    cout << "Enter student ID" << endl;
    cin >> current -> id;
        
    while (p != NULL)
    {
        p = p -> next;
    }
    if(front == NULL){
        front = back = current;
    }
    else{
        current -> previous = back;
        back -> next = current;
        back = current;
    }
    
}
void insert_at_end_2(){

    student *current = new student;

    cout << "Enter student ID" << endl;
    cin >> current -> id;
     
    if(front2 == NULL){
        front2 = back2 = current;
    }
    else{
        current -> previous = back2;
        back2 -> next = current;
        back2 = current;
    }
}

// prints all elements from start
void display(){
    student *p = front;

    if(isEmpty()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        while (p != NULL)
        {
            cout << "\nStudent ID is: " << p -> id;
            p = p -> next;

        }   
    }
}
// prints all elements from start
void display2(){
    student *p = front2;

    if(isEmpty()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        while (p != NULL)
        {
            cout << "\nStudent ID is: " << p -> id;
            p = p -> next;

        }   
    }
}

void splitEven2(){

    student *p = front;
    student *p2 = p -> next;

    while (p != NULL)
    {   
        if(p -> id % 2 == 0){

            while (p2 != NULL)
            {   
                if(p2 -> id % 2 == 0){
                    
                    p -> next = p2;
                    p2 -> previous = p;
                    break;

                }
                p2 = p2 -> next;
            }
            

        }
        p = p -> next;
    }
    


}
void splitEven(){

    student *p = front;
    student *p2 = p -> next;
    student *temp = front;
    int count = 0;

    // Calculating length
    while (p != NULL)
    {
        p = p -> next;
        count++;

    }
    
    cout << "Count is: " << count << endl;

    p = front; 

    for(int i = 1; i <= count; i++){
        // Even Check!
        if(i % 2 == 0){
            // Changing Front
            if(i == 2){

                // Moved to the second one
                p = p -> next;

                front = p;
                p -> previous = NULL;
                // temp
                temp = p -> next;
                p -> next = temp -> next;

                // Moved two steps ahead
                p = temp -> next;
                
            }
            // Last value Check
            else if(i == count){

                back = temp -> next;
                
                back -> previous = temp -> previous;
                back -> next = NULL;
                break;
            }
            // in between
            else{
                p -> previous = temp -> previous;
    
                // temp
                temp = p -> next;
                p -> next = p -> next -> next;            
                // Moved two steps ahead
                p = temp -> next;
            }

        }
        else{
            continue;
        }
    }
}

void splitOdd(){

    student *p = front;
    student *temp = front;
    int count = 0;

    // Calculating length
    while (p != NULL)
    {
        p = p -> next;
        count++;

    }
    
    cout << "Count is: " << count << endl;

    p = front; 

    for(int i = 1; i <= count; i++){
        // Even Check!
        if(i % 2 == 1){
            // Changing Front
            if(i == 1){

                front = p;
                p -> previous = NULL;
                // temp
                temp = p -> next;
                p -> next = temp -> next;

                // Moved two steps ahead
                p = temp -> next;
                
            }
            // Last value Check
            else if(i == count){

                back = temp -> next;
                
                back -> previous = temp -> previous;
                back -> next = NULL;
                break;
            }
            // in between
            else{
                p -> previous = temp -> previous;
    
                // temp
                temp = p -> next;
                p -> next = p -> next -> next;            
                // Moved two steps ahead
                p = temp -> next;
            }

        }
        else{
            continue;
        }
    }
};
// swaps two values from top to bottom
void swap(int value_1, int value_2){

    // First value essentials 
    student *p = front;

    // Second value essentials 
    student *p2 = front2;

    // temp value
    student *t1;
    
    do
    {   if(front -> id == value_1){
            continue;
        }
        else{
            p = p -> next;
        }

    } while (p -> id != value_1 && p != NULL);

    do
    {
        p2 = p2 -> next;

    } while (p2 -> id != value_2 && p2 != NULL);
    
    // assigning temp values
    // -------------- IN BETWEEN ONLY --------------- //
    t1 = p -> next;

    p2 -> next = p -> next;
    p -> previous -> next = p2;

    t1 = p2 -> next; 
    p2 -> previous -> next = p;
        
        
    
}
// main function that calls all other functions
int main(){
    int choice, value, value_2;
    do
    {
        cout << "\n--------- SELECT YOUR OPTION! ---------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to insert at end." << endl;
        cout << "Press [2] to insert at end 2." << endl;
        cout << "Press [3] to display() 1." << endl;
        cout << "Press [4] to display() 2." << endl;
        cout << "Press [5] to splitEven()." << endl;
        cout << "Press [6] to splitOdd()." << endl;
        cout << "Press [7] to swap()." << endl;
        cout << "Press [8] to splitEven 2()." << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            insert_at_end();
        }
        else if(choice == 2){
            insert_at_end_2();
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            display2();
        }
        else if(choice == 5){
            splitEven();
        }
        else if(choice == 6){
            splitOdd();
        }
        else if(choice == 7){
            cout << "Enter the first value!" << endl;
            cin >> value;

            cout << "Enter the second value!" << endl;
            cin >> value_2;
            swap(value, value_2);
        }
        else if(choice == 8){
            splitEven2();
        }

    } while (true);
    return 0;
}

