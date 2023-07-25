#include <iostream>
#include <string>
using namespace std;

struct circular{

    int number1;
    int number2;
    int number3;
    circular *next;
};


circular *back_List1 = NULL;
circular *back_List2 = NULL;
circular *back_ListMax = NULL;

void front_id(){
    cout << "ID at front is: " << back_List1 -> next -> number1 << endl;
}
void back_id(){
    cout << "ID at back is: " << back_List1 -> number1 << endl;
}

void front_id_2(){
    cout << "ID at front is: " << back_List2 -> next -> number2 << endl;
}
void back_id_2(){
    cout << "ID at back is: " << back_List2 -> number2 << endl;
}
int length(){

    circular *p = back_List1;
    int count = 0;
    do
    {
        p = p -> next;
        count++;

    } while (p != back_List1);
    
    return count;
} 
bool isEmpty_List1(){
    if(back_List1 == NULL){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty_List2(){
    if(back_List2 == NULL){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty_ListMax(){
    if(back_ListMax == NULL){
        return true;
    }
    else{
        return false;
    }
}
void insert_at_end_List1(){

    circular *current = new circular;

    cout << "\nEnter number" << endl;
    cin >> current -> number1;
    

    if(isEmpty_List1()){
        back_List1 = current;
        back_List1 -> next = current;
    }
    else{
        current -> next = back_List1 -> next;
        back_List1 -> next = current;
        back_List1 = current;
    }
}
void insert_at_end_List2(){

    circular *current = new circular;

    cout << "\nEnter number" << endl;
    cin >> current -> number2;
    
    if(isEmpty_List2()){
        back_List2 = current;
        back_List2 -> next = current;
    }
    else{
        current -> next = back_List2 -> next;
        back_List2 -> next = current;
        back_List2 = current;
    }
}
void insert_at_end_ListMax(circular *p){

    circular *current = p;

    current -> number3 = p -> number1;
    
    if(isEmpty_ListMax()){
        back_ListMax = current;
        back_ListMax -> next = current;
    }
    else{
        current -> next = back_ListMax -> next;
        back_ListMax -> next = current;
        back_ListMax = current;
    }
}
void display_List1(){
    circular *p = back_List1;

    if(isEmpty_List1()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        
        do
        {
            p = p -> next;
            cout << "Number is: " << p -> number1 << endl;
    
        }
        while (p != back_List1);   
        
    }
}
void display_List2(){
    circular *p = back_List2;

    if(isEmpty_List2()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        
        do
        {
            p = p -> next;
            cout << "Number is: " << p -> number2 << endl;
    
        }
        while (p != back_List2);   
        
    }
}
void display_MaxList(){
    circular *p = back_ListMax;

    if(isEmpty_ListMax()){
        cout << "No record!" << endl;
    }
    else{
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        
        do
        {
            p = p -> next;
            cout << "Number is: " << p -> number3 << endl;
        }
        while (p != back_ListMax);   
        
    }
}

void set_max_values(){
    
    // essentials for finding max in list one!
    circular *p1 = back_List1;
    circular *p2; // Previous Pointer
    circular *value_at_max_1 = NULL;
    circular *previous_at_max_1 = NULL;  
    int max_1 = 0; // Max value of circular list 1


    // essentials for finding max in list two!
    circular *p3 = back_List2;
    circular *p4; // Previous Pointer
    circular *value_at_max_2 = NULL;
    circular *previous_at_max_2 = NULL;  
    int max_2 = 0; // Max value of circular list 2

    do
    {   
          
        do
        {
            p2 = p1; // Pointing previous number
            p1 = p1 -> next;

            if(p1 -> number1 >= max_1){
                max_1 = p1 -> number1; 
                value_at_max_1 = p1;
                previous_at_max_1 = p2; 
            }        

        } while (p1 != back_List1);

        
        cout << "Max of List 1 is: " << max_1 << endl;
        
        circular *current = new circular();
        //current = value_at_max_1;
        current -> number3 = max_1;    
        
        if(isEmpty_ListMax()){
            back_ListMax = current;
            current -> next = back_ListMax;
        }
        else{
            current -> next = back_ListMax -> next;
            back_ListMax -> next = current;
            back_ListMax = current;
        }
        
        // Checks the Only element left in the list
        if(p1 -> next == p1){
            //cout << "Only number in the list is: " << p1 -> number1 << endl;
    
            back_List1 = NULL; 
            p1 = NULL;
        }
        // Checks the first element
        else if(value_at_max_1 -> number1 == back_List1 -> next -> number1){
            cout << "Reached First" << endl;
            back_List1 -> next = back_List1 -> next -> next; 
            
        }
        // Checks the last element
        else if(value_at_max_1 -> number1 == back_List1 -> number1){
            cout << "Reached last" << endl;
            previous_at_max_1 -> next = back_List1 -> next;
            back_List1 = previous_at_max_1;
            
        }
        // Checks the alternate element
        else{
            cout << "Reached alternate" << endl;
            previous_at_max_1 -> next = value_at_max_1 -> next;
            
        }

        max_1 = 0;

        do
        {
            p4 = p3; // Pointing previous number
            p3 = p3 -> next;

            if(p3 -> number2 >= max_2){
                max_2 = p3 -> number2; 
                value_at_max_2 = p3;
                previous_at_max_2 = p4; 
            }        

        } while (p3 != back_List2);

        
        cout << "Max of List 2 is: " << max_2 << endl;
        circular *current2 = new circular();
        
        current2 -> number3 = max_2;    

        current2 -> next = back_ListMax -> next;
        back_ListMax -> next = current2;
        back_ListMax = current2;
      
        // Checks the Only element left in the list
        if(p3 -> next == p3){
           // cout << "Only number in the list is: " << p3 -> number2 << endl;
          
            back_List2 = NULL; 
            p3 = NULL;
        }
        // Checks the first element
        else if(value_at_max_2 -> number2 == back_List2 -> next -> number2){
            cout << "Reached First" << endl;
            back_List2 -> next = back_List2 -> next -> next; 
            
        }
        // Checks the last element
        else if(value_at_max_2 -> number2 == back_List2 -> number2){
            cout << "Reached last" << endl;
            previous_at_max_2 -> next = back_List2 -> next;
            back_List2 = previous_at_max_2;
            
        }
        // Checks the alternate element
        else{
            cout << "Reached alternate" << endl;
            previous_at_max_2 -> next = value_at_max_2 -> next;
            
        }

        max_2 = 0;
    
    } while(p1 != NULL && p3 != NULL);
    

}

int main(){
    int choice, value;
    do
    {
        cout << "\n------------ SELECT YOUR OPTION! -----------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to insert_at_end List 1." << endl;
        cout << "Press [2] to insert_at_end List 2." << endl;
        cout << "Press [3] to set max values." << endl;
        cout << "Press [4] to display List 1" << endl;
        cout << "Press [5] to display List 2" << endl;
        cout << "Press [6] to display Maxed List" << endl;
        cout << "Press [11] to front id" << endl;
        cout << "Press [12] to back id" << endl;
        
        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            insert_at_end_List1();
        }
        else if(choice == 2){
            insert_at_end_List2();
        }
        else if(choice == 3){
            set_max_values();
        }
        else if(choice == 4){
            display_List1();
        }
        else if(choice == 5){
            display_List2();
        }
        else if(choice == 6){
            display_MaxList();
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

