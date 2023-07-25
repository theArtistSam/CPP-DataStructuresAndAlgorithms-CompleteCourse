// Your First C++ Program

#include <iostream>
using namespace std;

class queue{

    private:
        int front;
        int back;
        int size;
        int *array;

    public:
        
        queue(){
            size = 5;
            array = new int[size];    
            front = -1;
            back = -1;
        }
        

        bool isEmpty(){
            if(front == -1 && back == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            if(back == size - 1){
                return true;
            }
            else{
                return false;
            }
        } 
        void printLinearArray(){
            for (int i = 0; i < back + 1; i++) {
                cout << array[i] << "  ";
            }
        }

        void Front(){
            //cout << "Front is: " <<endl;
            cout << front;

        }

        void Back(){
            //cout << "Back is: " <<endl;
            cout << back;
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
        int enqueue_from_end(int number){
            if(isFull()){
                cout << "Queue is full! Try dequeing it";
            }
            else if(isEmpty()){
                front++;
                back++;
                array[back] = number;
                return number;
            }
            else{
                back++;
                array[back] = number;
                return number;
            }
            return 0;
        }
        
        void dequeue_from_start(){
            if(isEmpty()){
                cout << "Empty! You cannot dequeue any more elements" << endl;
            }
            else if(front == back){
                front = back = -1;
            }
            else{
                left_shift();
                back--;
            }
        }
        int enqueue_from_start(int value){
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
            else if (front == 0 && back != size - 1){
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
        void dequeue_from_end(){
            if(isEmpty()){
                cout << "You cannot delete more values"; 
            }
            else if(front == back){ 
                front = -1;
                back = -1;
            }
            else{
                back--;
            }
        }
};

int main() {
    queue s1;
    int choice, position, value;

    do
    {   
        cout << "\n----------------- DISPLAY ------------------\n" << endl;
        cout << "Select your option!\n\nPress [0] to Exit." <<endl;
        cout << "Press [1] to isEmpty." <<endl;
        cout << "Press [2] to isFull." <<endl;
        cout << "Press [3] to enqueue_from_end." <<endl;
        cout << "Press [4] to dequeue_from_end." <<endl;
        cout << "Press [5] to enqueue_from_start." <<endl;
        cout << "Press [6] to dequeue_from_start." <<endl;
        cout << "Press [7] to print array." <<endl;
        cout << "Press [8] to print Front." <<endl;
        cout << "Press [9] to print Back." <<endl;
        cout << endl;
        cin >> choice;

        if(choice == 1){
            if(s1.isEmpty()){
                cout<< "true" <<"\n";
            }
            else{
                cout<< "false" <<"\n";
            }
        }
        else if(choice == 2){
            if(s1.isFull()){
                cout<< "true" <<"\n";
            }
            else{
                cout<< "false" <<"\n";
            }
        }
        else if(choice == 3){
            cout << "\nEnter your value" <<endl;
            cin >> value;
            s1.enqueue_from_end(value);
        }
        else if(choice == 4){
            s1.dequeue_from_end();
        }
        else if(choice == 5){
            cout << "\nEnter your value" <<endl;
            cin >> value;
            s1.enqueue_from_start(value);
        }
        else if(choice == 6){
            s1.dequeue_from_start();
        }
        else if(choice == 7){
            s1.printLinearArray();   
        }
        else if(choice == 8){
            cout << "Front value is: "; 
            s1.Front();   
        }
        else if(choice == 9){
            cout << "Back value is: "; 
            s1.Back();   
        }        
        else if(choice == 0){
            break;
        }
    } while (true);
    return 0;
};