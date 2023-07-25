#include <iostream>
#include <string>
using namespace std;

struct student{

    int id;
    float marks;
    student *next = NULL;
    student *previous = NULL;

};

student *front = NULL;
student *back = NULL;

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

    cout << "Enter student ID" << endl;
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
            cout << "Student ID is: " << p -> id;
            cout << "\tStudent Marks are: " << p -> marks << endl;
            p = p -> next;

        }   
    }
}

// prints in reverse (iteration)
void display_reverse(){

    student *k = back;
    student *p = front;
    student *p_2;

    if(p == k){
        cout << "Student ID is: " << p -> id;
        cout << "\tStudent Marks are: " << p -> marks << endl;
    }
    else{
        while(true){
            while(p != k){
                p_2 = p;
                p = p -> next;
            }
            cout << "Student ID is: " << p -> id;
            cout << "\tStudent Marks are: " << p -> marks << endl;
            k = p_2;
            p = front;
            if(k == front){
                cout << "Student ID is: " << p -> id;
                cout << "\tStudent Marks are: " << p -> marks << endl;
                break;
            }
        }
    }
    
}

// prints frist and last and so on
void front_and_back_display(){
    student *k = back;
    student *p = front;
    student *p_2;
    student *p_3 = front;

    cout << "\n----------------- DISPLAY ------------------\n" << endl;
    while(true){
        while(p != k){
            p_2 = p;
            p = p -> next;
        }
        cout << "Student ID is: " << p_3 -> id;
        cout << "\tStudent Marks are: " << p_3 -> marks << endl;
        
        p_3 = p_3 -> next;
        cout << "Student ID is: " << k -> id;
        cout << "\tStudent Marks are: " << k -> marks << endl;
        
        // odd check
        if(p_3 -> next == k){
            cout << "Student ID is: " << p_3 -> id;
            cout << "\tStudent Marks are: " << p_3 -> marks << endl;
            break;
        }
        k = p_2;
        p = front;

        // even check
        if(p_3 -> next == k){
            cout << "Student ID is: " << p_3 -> id;
            cout << "\tStudent Marks are: " << p_3 -> marks << endl;
            cout << "Student ID is: " << k -> id;
            cout << "\tStudent Marks are: " << k -> marks << endl;
            break;
        }
    }
}

// swaps two values from top to bottom
void swap(int value_1, int value_2){

    // First value essentials 
    student *p = front;
    student *p_previous = front;
    int countFirst = 0;

    // Second value essentials 
    student *p2 = front;
    student *p2_previous = front;

    // temp values
    student *t1;
    student *t2;
    int countSecond = 0;


    
    if(value_1 == value_2){
        cout << "Same values! Try adding different values" << endl;
    }
    else{
        do
        {   if(front -> id == value_1){
                continue;
            }
            else{
                p_previous = p;
                p = p -> next;
            }

        } while (p -> id != value_1 && p != NULL);

        // checking if it is working or not!
        cout << "Previous id is: " << p_previous -> id << endl;
        cout << "P id is: " << p -> id << endl;

        do
        {
            p2_previous = p2;
            p2 = p2 -> next;

        } while (p2 -> id != value_2 && p2 != NULL);

        // checking if it is working or not!
        cout << "Previous id of p2 is: " << p2_previous -> id << endl;
        cout << "P2 id is: " << p2 -> id << endl;
        
        
        // assigning temp values
        t1 = p_previous -> next;
        t2 = p2 -> next;

        // changing valeus
        if(front -> id == value_1 && back -> id == value_2){
            cout << "Front and Last Connection" << endl;

            p2 -> next = p -> next;
            front = p2_previous -> next;
            p2_previous -> next = p_previous;
            p_previous -> next = NULL;
            back = p_previous;
        }
        else if(front -> id == value_1){

            if(p -> next == p2_previous -> next){
                cout << "Front Checked! *Alternate* " << endl;
                p2 -> next = p;
                p -> next = t2;
                front = p2;

            }
            else{
                cout << "Front Checked! No Alternate " << endl;
                p2 -> next = p -> next;
                p2_previous -> next = p;
                p -> next = t2; 
                front = p2;
            }
            
        }
        else if(back -> id == value_2){

            if(p -> next == p2_previous -> next){
                cout << "Back Checked! *Alternate* " << endl;
                p_previous -> next = p -> next;
                p2 -> next = p;
                p -> next = NULL;
                back = p;

            }
            else{
                cout << "Back Checked! No Alternate " << endl;
                p_previous -> next = p2_previous -> next;
                p2 -> next = p -> next;
                p2_previous -> next = p;
                p -> next = NULL;
                back = p;
            }
            
        }
        else if(p -> next == p2_previous -> next){

            cout << "Alternate values" << endl;
            p2 -> next = p_previous -> next;
            p_previous -> next = p2_previous -> next;
            
            p2_previous -> next = t2;          
        
        }
        else{
            p2 -> next = p -> next;
            p_previous -> next = p2_previous -> next;

            t1 -> next = t2;
            p2_previous -> next = t1;
        }
    }
}

// checks if linked list is palindrome on the basis of ID 
void palindrome_check(){

student *k = back;
student *p = front;
student *p_2;
student *p_3 = front;

bool check = true;

    while(true){
        while(p != k){
            p_2 = p;
            p = p -> next;
        }

        if((p_3 -> id != k -> id)){
            check = false;
            break;
        }
        
        // k getting updated
        k = p_2;
        p = front;

        // p_3 getting updated
        p_3 = p_3 -> next;

        if(p_3 -> next == NULL){
            break;
        }

    }

    if(check == true){
        cout << "Palindrome" << endl; 
    }
    else{
        cout << "Not Palindrome" << endl;
    }

}
// checks the total number of elements with in a linked list (Didn't use it yet!)
int total_elements_list(){
    student *p = front; 

    int count = 0;
    while (p != NULL) {
        p = p -> next;
        count++;
    }
    return count;
}

// prints from start using recurrsion
void print_forward_recurrsion(student *x){
    
    if(x != NULL){
        cout << "Student ID is: " << x -> id;
        cout << "\tStudent marks is: " << x -> marks << endl;
        print_forward_recurrsion(x -> next);
    }
    else{
        
        x = NULL;
    }
}

// prints in reverse using recursion
void print_backward_recurrsion(student *x){
    if(x -> next != NULL){
        print_backward_recurrsion(x -> next);
        cout << "Student ID is: " << x -> id;
        cout << "\tStudent marks is: " << x -> marks << endl;
    }
    else{
        cout << "Student ID is: " << x -> id;
        cout << "\tStudent marks is: " << x -> marks << endl;
        x = NULL;
    }
}

// ID based swap
void swapID(int value1, int value2){

    // pointers to locate nodes
    student *p = front;
    student *p2 = front;

    while (p -> id != value1 && p != NULL)
    {
        p = p -> next;
    }

    while (p2 -> id != value2 && p2 != NULL)
    {
        p2 = p2 -> next;
    }

    // swaping and displaying
    int temp = p -> id;
    p -> id = p2 -> id;
    p2 -> id = temp;

    display();     

}
// main function that calls all other functions
int main(){
    int choice, value, value_2;
    do
    {
        cout << "\n--------- SELECT YOUR OPTION! ---------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to insert at end." << endl;
        cout << "Press [2] to display reverse order." << endl;
        cout << "Press [3] to front and back display." << endl;
        cout << "Press [4] to check palindrome." << endl;
        cout << "Press [5] to print front recurrsion." << endl;
        cout << "Press [6] to print backward recurrsion." << endl;
        cout << "Press [7] to Swap two values." << endl;
        cout << "Press [8] to Swap ID of two values." << endl;
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
            display_reverse();
        }
        else if(choice == 3){
            front_and_back_display();
        }
        else if(choice == 4){
            palindrome_check();
        }
        else if(choice == 5){
            student *p = front;
            print_forward_recurrsion(p);
        }
        else if(choice == 6){
            student *p = front;
            print_backward_recurrsion(p);
        }
        else if(choice == 7){
            cout << "Enter the first value!" << endl;
            cin >> value;

            cout << "Enter the second value!" << endl;
            cin >> value_2;

            swap(value, value_2);
        }
        else if(choice == 8){
            cout << "Enter the first value!" << endl;
            cin >> value;

            cout << "Enter the second value!" << endl;
            cin >> value_2;

            swapID(value, value_2);
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

