
#include <stdio.h>
#define V 5
#include <iostream>
#include <string>
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
            array = new int[V];    
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

        int enqueue(int number){
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
        int dequeue(){
            if(isEmpty()){
                cout << "Empty! You cannot dequeue any more elements" << endl;
                return -1;
            }
            else if(front == back){
                int a = array[front];
                front = back = -1;
                return a;
            }
            else{
                int a = array[front];
                left_shift();
                back--;
                return a;
            }
        }
};

// Initialize the matrix to zero
void initilize(int arr[][V]) {
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
    }
    
}

void initilizeBool(bool arr[V]) {
    
    for (int i = 0; i < V; i++) {
        arr[i] = false;
    }
    
}

// Add edges
void addEdge(int arr[][V], int i, int j) {
    
    arr[i][j] = 1;

}
void addWeight(int arr[][V], int i, int j, int num) {

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if(arr[i][j] == 0 && i != j){
                arr[i][j] = -1;
            }
        }
    }    
    arr[i][j] = num;

}


// Print the matrix
void printAdjMatrix(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {

        for (j = 0; j < V; j++) {
            printf("%3d", arr[i][j]);
        }
        cout << "\n";
    }
    cout << "-----------------" << endl;
}

void printBoolArray(bool arr[V]) {
    int i;
    cout << "-----------------\n";
    for (i = 0; i < V; i++) {
        printf("%3d", arr[i]);

    }
}
void initilizeInt(int arr[V]) {
    
    for (int i = 0; i < V; i++) {
        arr[i] = 0;
    }
    
}
void print1D(int arr[V]) {
    int i;
    for (i = 0; i < V; i++) {
        printf("%3d", arr[i]);

    }
}
void BFS(int arr[][V], bool vis[V], int starting){
    
    queue q1;

    bool check = true;
    vis[starting] = true;
    cout << ">> " << starting << " " << endl;

    int i = starting;  
    
    while (true) {
        
        // would keep an eye on visited nodes
        for(int k = 0; k < V; k++){
    
            if(vis[k] != true){
                check = false;
                break;
            }
        }

        for (int j = 0; j < V; j++) {
            if(arr[i][j] == 1 && i != j && vis[j] == false){

                q1.enqueue(j);
                vis[j] = true;
            
            }
            
        }
        if(q1.isEmpty()){
            break;
        }
        
        i = q1.dequeue();
        cout << ">> " << i << " " << endl;
        check = true;
    }
    

}


int main() {

    int adjMatrix[V][V];
    bool boolArr[V];

    initilize(adjMatrix);
    initilizeBool(boolArr);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 0);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 0);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 3, 0);
    addEdge(adjMatrix, 4, 2);
    

    /* addWeight(adjMatrix, 0, 1, 4);
    addWeight(adjMatrix, 0, 3, 11);
    addWeight(adjMatrix, 1, 0, 6);
    addWeight(adjMatrix, 1, 2, 3);
    addWeight(adjMatrix, 2, 0, 5);
    addWeight(adjMatrix, 2, 1, 2);
    addWeight(adjMatrix, 2, 3, 10);
    addWeight(adjMatrix, 3, 1, 6); */
    
    
    /* addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 3, 2);
    addEdge(adjMatrix, 1, 3); */
    
    printAdjMatrix(adjMatrix);
    //dijkstra(adjMatrix, 3);
    BFS(adjMatrix, boolArr, 1);
    //printBoolArray(boolArr);
    //dijkstra(adjMatrix, boolArr, 0);
    

    return 0;

}
