#include <iostream>
using namespace std;

class circularQueue{

    private:
        int front;
        int back;
        int size;
        int *array;

    public:
        circularQueue(){

            size = 5;
            array = new int[size];    
            front = -1;
            back = -1;
            
        }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if((back + 1) % size == front){
            return true;
        }
        else{
            return false;
        }
    }

    int enQueue(int number){
        if(isFull()){
            cout << "You cannot insert more values! Queue overflow" << endl;
            return 0;
        }
        else if(isEmpty()){
            front = back = 0;
            array[back] = number;
            return number;
        }
        else{
            back = (back + 1) % size;
            array[back] = number;
        }
        return 0;
    }
    int deQueue(){
        if(isEmpty()){
            cout << "Queue is empty! You cannot remove any number" << endl;
        }
        else if(front == back){
            front = back = -1;
        }
        else{
            front = (front + 1) % size;
        }
        return 0;
    }

    void printLinearArray(){
        if(back > front){
            for (int i = front; i < back + 1; i++) {
                cout << array[i] << "  ";
            }
        }
        else{
            for (int i = front; i < size - 1; i++) {
                cout << array[i] << "  ";
            }
            for (int i = 0; i < back + 1; i++) {
                cout << array[i] << "  ";
            }
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
};

int main() {
    circularQueue s1;
    int choice, position, value;

    do
    {
        cout << "\nSelect your option!\n\nPress [0] to Exit." <<endl;
        cout << "Press [1] to isEmpty." <<endl;
        cout << "Press [2] to isFull." <<endl;
        cout << "Press [3] to enQueue." <<endl;
        cout << "Press [4] to deQueue." <<endl;
        cout << "Press [5] to print array." <<endl;
        cout << "Press [6] to print Front." <<endl;
        cout << "Press [7] to print Back." <<endl;

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
            cout << "Enter your value" <<endl;
            cin >> value;
            s1.enQueue(value);
        }
        else if(choice == 4){
            s1.deQueue();
        }
        else if(choice == 5){
            s1.printLinearArray();   
        }
        else if(choice == 6){
            cout << "Front value is: "; 
            s1.Front();   
        }
        else if(choice == 7){
            cout << "Back value is: "; 
            s1.Back();   
        }        
        else if(choice == 0){
            break;
        }
    } while (true);
    return 0;
};