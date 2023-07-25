#include <iostream>
#include <string>
using namespace std;

// Checking Essentials
    int front = -1;
    int back  = -1;

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

struct student {
    
    int id;
    float marks;

};

student stu_Array[5];

void printArray(){
    cout << "-----------------------------\n";
    for (int i = front; i < back + 1; i++) {
        cout << "ID is: " << stu_Array[i].id << "\t";
        cout << "Marks are: " << stu_Array[i].marks << "  " << endl;
    }
}
void left_shift(){
    for(int i = front; i < back + 1; i++){
        stu_Array[i - 1] = stu_Array[i];
    }
}
void right_shift(){
    for(int i = back + 1; i > front; i--){
        stu_Array[i] = stu_Array[i - 1];
    }
}
int insert_at_end(int id, float marks){
    if(isEmpty()){
        front = 0;
        back = 0;
        stu_Array[back].id = id;
        stu_Array[back].marks = marks;
        return 1; 
    }
    else if(isFull()){
        cout << "You cannot insert more items! Full" << endl;
        return 0;
    }
    else if (back == 4){
        left_shift();
        stu_Array[back].id = id;
        stu_Array[back].marks = marks;
        front--;
        return 1;
    }
    else{
        back++;
        stu_Array[back].id = id;
        stu_Array[back].marks = marks;
        return 1;
    }
}
int insert_at_start(int id, float marks){
    if(isEmpty()){
        front = 0;
        back = 0;
        stu_Array[front].id = id;
        stu_Array[front].marks = marks;
        return 1; 
    }
    else if(isFull()){
        cout << "You cannot insert more items! Full" << endl;
        return 0;
    }
    else if (front == 0 && back != 4){
        right_shift();
        stu_Array[front].id = id;
        stu_Array[front].marks = marks;
        back++;
        return 1;
    }
    else{
        front--;
        stu_Array[front].id = id;
        stu_Array[front].marks = marks;
        return 1;
    }
}

int delete_from_start(){
    if(isEmpty()){
        cout << "You cannot delete more values";
        return 0; 
    }
    else if(front == back){
        int trash = stu_Array[front].id;
        trash = stu_Array[front].marks;
        stu_Array[front].id = 0;
        stu_Array[front].marks = 0;

        front = -1;
        back = -1;
        cout << "Number is: " << trash;
        return trash;
    }
    else{
        int trash = stu_Array[front].id;
        trash = stu_Array[front].marks;
        stu_Array[front].id = 0;
        stu_Array[front].marks = 0;
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
        int trash = stu_Array[front].id;
        trash = stu_Array[front].marks;
        stu_Array[front].id = 0;
        stu_Array[front].marks = 0; 
        front = -1;
        back = -1;
        cout << "Number is: " << trash;
        return trash;
    }
    else{
        int trash = stu_Array[back].id;
        trash = stu_Array[back].marks;
        //stu_Array[back] = 0;
        back--;
        cout << "Number is: " << trash;
        return trash;
    }
}

int insert_after_specfic(int index, int id, float marks){
    if(isFull()){
        cout << "You cannot insert! Array is Full" << endl;
        return 0;
    }
    else if(index = back){
        stu_Array[index + 1].id = id;
        stu_Array[index + 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        back = index + 1;
        return 1;
    }
    else if (front == 0 && back != 4){
        int front_catch = front;
        front = index;
        right_shift();
        stu_Array[index + 1].id = id;
        stu_Array[index + 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        back++;
        front = front_catch;
        return 1;
    }
    else if (front != 0 && back == 4){
        //int front_catch = front;
        int back_catch = back;
        back = index + 1;
        front--;
        left_shift();
        stu_Array[index + 1].id = id;
        stu_Array[index + 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        back = back_catch;
        return 1;
    }
    else{
        int front_check = front;
        front = index - 1;
        left_shift();
        stu_Array[index + 1].id = id;
        stu_Array[index + 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        front = front_check;
        front--;
        return 1;
    }
}
int insert_before_specfic(int index, int id, int marks){
    if(isFull()){
        cout << "You cannot insert! Array is Full" << endl;
        return 0;
    }
    else if(index == front){
        stu_Array[index - 1].id = id;
        stu_Array[index - 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        back = index - 1;
        return 1;
    } 
    else if(front == 0 && back != 4){
        int front_select = front;
        front = index - 1; 
        back++;
        right_shift();
        stu_Array[index - 1].id = id;
        stu_Array[index - 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        front = front_select;
        return 1;
    }
    else if(front != 0 && back == 4){
        int back_select = back;
        back = index; 
        left_shift();
        stu_Array[index - 1].id = id;
        stu_Array[index - 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        back = back_select;
        front--;
        return 1;
    }
    else{
        int front_check = front;
        int back_check = back;
        back = index;
        front = index - 1;
        left_shift();
        stu_Array[index - 1].id = id;
        stu_Array[index - 1].marks = marks;
        cout << "ID is: " << id << endl;
        cout << "Marks are: " << marks;
        front = front_check;
        front--;
        back = back_check;
        return 1;  
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

    student s1;

    // Essentials for ID and Marks
    int choice;
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
            cout << "Enter your ID" << endl;
            cin >> s1.id;
            cout << "Enter your Marks" << endl;
            cin >> s1.marks;

            insert_at_end(s1.id, s1.marks);
        }
        else if(choice == 4){
            cout << "Enter your ID" << endl;
            cin >> s1.id;
            cout << "Enter your Marks" << endl;
            cin >> s1.marks;
            insert_at_start(s1.id, s1.marks);
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
            cout << "Enter your index" <<endl;
            cin >> index;

            cout << "Enter your id" <<endl;
            cin >> s1.id;

            cout << "Enter your marks" <<endl;
            cin >> s1.marks;

            insert_after_specfic(index, s1.id, s1.marks);
        }
        else if(choice == 9){
            cout << "Enter your index" <<endl;
            cin >> index;

            cout << "Enter your id" <<endl;
            cin >> s1.id;

            cout << "Enter your marks" <<endl;
            cin >> s1.marks;

            insert_before_specfic(index, s1.id, s1.marks);
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
};


