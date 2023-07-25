
#include <stdio.h>
#define V 5
#include <iostream>
#include <string>
using namespace std;

class stack{
    
    private:

        int top;
        int size;
        int *stack_array;

    public:

        // argumented constructor
        stack(){

            top = -1;
            size = V;
            stack_array = new int[size]; 

        }
        bool is_Empty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool is_Full(){
            if(top == size - 1){
                return true;
            }
            else{
                return false;
            }
        }
        void push(int val){
            if(is_Full()){
                cout << "You cannot insert more elements! Stack Full" << endl;
            }
            else{
                top++;
                stack_array[top] = val;
            }
        }
        int pop(){
            if(is_Empty()){
                cout << "You cannot pop more elements! Stack empty" << endl;
            }
            else{
                return stack_array[top--];
            }
            return 0;
        }

        void printStack(){
            cout << "\n---------- Stack ----------" << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << stack_array[i] << " ";
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
void DFS(int arr[][V], bool vis[V], int starting){
    
    stack s1;

    bool check = false;
    vis[starting] = true;
    cout << ">> " << starting << " " << endl;

    int i = starting; 

    while (true) {
        for(int k = 0; k < V; k++){
    
            if(vis[k] != true){
                check = false;
                break;
            }
        }

        for (int j = V - 1; j >= 0; j--) {
            if(arr[i][j] == 1 && i != j && vis[j] == false){
                
                s1.push(j);
                vis[j] = true;
                
            }
        }
        if(s1.is_Empty()){
            break;
        }

        i = s1.pop();
        cout << ">> " << i << " " << endl;   
    }
    
    
}

void dijkstra(int arr[][V], int starting){
    
    bool vis[V];
    int small[V];
    initilizeBool(vis);
    initilizeInt(small);

    int i = starting;

    int smallest = INT_MAX;
    int smallestIndex = 0; 
    
    int path = 0;
    int check = true;
    int right = true;

    while (true) {
        
        // checks visited nodes 
        for(int k = 0; k < V; k++){
            if(vis[k] != true){
                check = false;
                break;
            }
        }

        if(i == starting){
            // insert all the values at first
            for (int j = 0; j < V; j++){
                small[j] = arr[i][j];
            }
            vis[i] = true;
            
            // find the smallest value
            for (int j = 0; j < V; j++) {
                if(small[j] < smallest && small[j] != -1 && vis[j] != true){
                    smallest = small[j]; 
                    smallestIndex = j;
                }
            }
            // here found the smallest index and smallest value     
            /* ------------------------------------- */
            i = smallestIndex;
            path = smallest;
            smallest = INT_MAX;
        }        
        else{
            for (int j = 0; j < V; j++){
                
                if(vis[j] != true && i != j && arr[i][j] != -1){
                    
                    if(small[j] == -1){
                        small[j] = path + arr[i][j];
                    }
                    else if(path + arr[i][j] > small[j]){
                        continue;
                    }
                    else{
                        small[j] = path + arr[i][j];
                    }
                }
            }
            vis[i] = true;

            for (int j = 0; j < V; j++) {
                if(small[j] < smallest && small[j] != -1 && vis[j] != true){
                    smallest = small[j]; 
                    smallestIndex = j;
                }
            }   
            /* ------------------------------------- */
            i = smallestIndex;
            path = smallest;
            smallest = INT_MAX;
        }

        if(check == true){
            break;
        }
        check = true;
    }


    cout << "\n";
    print1D(small);
    cout << "\n";
    printBoolArray(vis);
    
}

int main() {

    int adjMatrix[V][V];
    bool boolArr[V];

    initilize(adjMatrix);
    initilizeBool(boolArr);
/*     weight(Matrix, 0,1,1);
    weight(Matrix, 0,3,1);
    weight(Matrix, 1,0,1);
    weight(Matrix, 1,2,1);
    weight(Matrix, 2,1,1);
    weight(Matrix, 2,3,1);
    weight(Matrix, 2,4,1);
    weight(Matrix, 3,0,1);
    weight(Matrix, 4,2,1); */


    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 0);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 3, 0);
    addEdge(adjMatrix, 4, 3);

/*     addWeight(adjMatrix, 0, 1, 4);
    addWeight(adjMatrix, 0, 3, 11);
    addWeight(adjMatrix, 1, 0, 6);
    addWeight(adjMatrix, 1, 2, 3);
    addWeight(adjMatrix, 2, 0, 5);
    addWeight(adjMatrix, 2, 1, 2);
    addWeight(adjMatrix, 2, 3, 10);
    addWeight(adjMatrix, 3, 1, 6);
 */    
    
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
    DFS(adjMatrix, boolArr, 1);
    //printBoolArray(boolArr);
    //dijkstra(adjMatrix, boolArr, 0);
    

    return 0;

}
