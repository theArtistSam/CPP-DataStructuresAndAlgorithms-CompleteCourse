#include <iostream>
#include <string>
using namespace std;

int front = -1;
int back = -1;
int size = 5;
int array[5];

bool isEmpty(){
    if(front == -1 && back == -1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(front == 0 && back == 4){
        return true;
    }
    else{
        return false;
    }
}
void printArray(){
    for (int i = front; i < back + 1; i++) {
        cout << array[i] << "  ";
    }
}
void left_shift(){
    for(int i = front; i < back + 1; i++){
        array[i - 1] = array[i];
    }
}
void right_shift(){
    for(int i = back + 1; i > front; i--){
        array[i] = array[i - 1];
    }
}
int insert_at_end(int value){
    if(isEmpty()){
        front = 0;
        back = 0;
        array[back] = value;
        return value; 
    }
    else if(isFull()){
        cout << "You cannot insert more items! Full" << endl;
        return 0;
    }
    else if (back == 4){
        left_shift();
        array[back] = value;
        front--;
        return value;
    }
    else{
        back++;
        array[back] = value;
        return value;
    }
}
int insert_at_start(int value){
    if(isEmpty()){
        front = 0;
        back = 0;
        array[front] = value;
        return value; 
    }
    else if(isFull()){
        cout << "You cannot insert more items! Full" << endl;
        return 0;
    }
    else if (front == 0 && back != 4){
        right_shift();
        array[front] = value;
        back++;
        return value;
    }
    else{
        front--;
        array[front] = value;
        return value;
    }
}

int delete_from_start(){
    if(isEmpty()){
        cout << "You cannot delete more values";
        return 0; 
    }
    else if(front == back){
        int trash = array[front]; 
        front = -1;
        back = -1;
        cout << "Number is: " << trash;
        return trash;
    }
    else{
        int trash = array[front];
        front++;
        cout << "Number is: " << trash;
        return trash;
    }
}

int delete_from_end(){
    if(isEmpty()){
        cout << "You cannot delete more values";
        return 0; 
    }
    else if(front == back){
        int trash = array[front];
        array[front] = 0; 
        front = -1;
        back = -1;
        cout << "Number is: " << trash;
        return trash;
    }
    else{
        int trash = array[back];
        array[back] = 0;
        back--;
        cout << "Number is: " << trash;
        return trash;
    }
}

int insert_after_specfic(int index, int value){
    if(isFull()){
        cout << "You cannot insert! Array is Full" << endl;
        return 0;
    }
    else if(index = back){
        array[index + 1] = value;
        cout << "Number is: " << value;
        back = index + 1;
        return value;
    }
    else if (front == 0 && back != 4){
        int front_catch = front;
        front = index ;
        right_shift();
        back++;
        array[index + 1] = value;
        cout << "Number is: " << value;
        front = front_catch;
        return value;
    }
    else if (front != 0 && back == 4){
        //int front_catch = front;
        int back_catch = back;
        back = index + 1;
        front--;
        left_shift();
        array[index + 1] = value;
        cout << "Number is: " << value;
        back = back_catch;
        return value;
    }
    else{
        int front_check = front;
        front = index - 1;
        front--;
        left_shift();
        array[index + 1] = value;
        cout << "Number is: " << value;
        front = front_check;
        return value;
    }
}
int insert_before_specfic(int index, int value){
    if(isFull()){
        cout << "You cannot insert! Array is Full" << endl;
        return 0;
    }
    else if(index == front){
        array[index - 1] = value;
        cout << "Number is: " << value;
        back = index - 1;
        return value;
    } 
    else if(front == 0 && back != 4){
        int front_select = front;
        front = index - 1; 
        back++;
        right_shift();
        array[index - 1] = value;
        cout << "Number is: " << value;
        front = front_select;
        return value;
    }
    else if(front != 0 && back == 4){
        int back_select = back;
        back = index; 
        left_shift();
        array[index - 1] = value;
        cout << "Number is: " << value;
        back = back_select;
        front--;
        return value;
    }
    else{
        int front_check = front;
        int back_check = back;
        back = index;
        front = index - 1;
        left_shift();
        array[index - 1] = value;
        cout << "Number is: " << value;
        front = front_check;
        front--;
        back = back_check;
        return value;  
    }
}
void delete_after_specfic(int index){
    if(isEmpty()){
        cout << "Empty! You cannot delete any item";
    }
    else if(index == back){
        cout << "The next element doesn't exist!";
    }
    else{
        int front_select = front;
        front = index + 2;
        left_shift();
        front = front_select;
        back--;
    }
}
void delete_before_specfic(int index){
    if(isEmpty()){
        cout << "Empty! You cannot delete any item";
    }
    else if(index == front){
        cout << "The previous element doesn't exist!";
    }
    else{
        int front_select = front;
        front = index;
        left_shift();
        front = front_select;
        back--;
    }
}
void delete_specfic(int index){
    if(isEmpty()){
        cout << "Empty! You cannot delete any item";
    }
    else{
        int front_choice = front;
        front = index + 1;
        left_shift();
        front = front_choice;
        back--;
    }
}


int main(){
    int choice;
    int value;
    int index;
    do
    {
        cout << "\nSelect your option!\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to isEmpty." << endl;
        cout << "Press [2] to isFull." << endl;
        cout << "Press [3] to insert_at_end." << endl;
        cout << "Press [4] to insert_at_start" << endl;
        cout << "Press [5] to display." << endl;
        cout << "Press [6] to delete from start." << endl;
        cout << "Press [7] to delete from end" << endl;
        cout << "Press [8] to insert_after_specfic" << endl;
        cout << "Press [9] to insert_before_specfic" << endl;
        cout << "Press [10] to delete_after_specfic" << endl;
        cout << "Press [11] to delete_before_specfic" << endl;
        cout << "Press [12] to delete_specfic" << endl;
        cout << "Press [13] to print Front" << endl;
        cout << "Press [14] to print Back" << endl;

        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            if(isEmpty()){
                cout << "Empty!" << endl;
            }
            else{
                cout<< "Not Empty!" <<"\n";
            }
        }
        else if(choice == 2){
            if(isFull()){
                cout<< "Full" <<"\n";
            }
            else{
                cout<< "Not Full" <<"\n";
            }
        }
        else if(choice == 3){
            cout << "Enter your value" <<endl;
            cin >> value;
            insert_at_end(value);
        }
        else if(choice == 4){
            cout << "Enter your value" <<endl;
            cin >> value;
            insert_at_start(value);
        }
        else if(choice == 5){
           printArray();
        }
        else if(choice == 6){
            delete_from_start();
        }
        else if(choice == 7){
            delete_from_end();
        }
        else if(choice == 8){
            cout << "Enter your index" << endl;
            cin >> index;

            cout << "Enter your value" << endl;
            cin >> value;

            insert_after_specfic(index, value);
        }
        else if(choice == 9){
            cout << "Enter your index" << endl;
            cin >> index;

            cout << "Enter your value" << endl;
            cin >> value;

            insert_before_specfic(index, value);
        }
        else if(choice == 10){
            cout << "Enter your index!" << endl;
            cin >> index;
            delete_after_specfic(index);
        }
        else if(choice == 11){
            cout << "Enter your index!" << endl;
            cin >> index;
            delete_before_specfic(index);
        }
        else if(choice == 12){
            cout << "Enter your index!" << endl;
            cin >> index;
            delete_specfic(index);
        }
        else if(choice == 13){
            cout << "Front is: " << front;
        }
        else if(choice == 14){
            cout <<  "Back is: " << back;
        }

    } while (true);
    return 0;
}