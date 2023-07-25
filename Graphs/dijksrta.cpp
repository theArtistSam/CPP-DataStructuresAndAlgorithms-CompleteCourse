
#include <stdio.h>
#define V 4
#include <iostream>
#include <string>
using namespace std;


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

void initilizeInt(int arr[V]) {
    
    for (int i = 0; i < V; i++) {
        arr[i] = 0;
    }
    
}
// Add edges
void addEdge(int arr[][V], int i, int j) {
    
    arr[i][j] = 1;
    arr[j][i] = 1;

}

// Add edges
void addWeight(int arr[][V], int i, int j, int num) {
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if(arr[i][j] == 0 && i != j){
                arr[i][j] = -1;
            }
        }
    }
    arr[i][j] = num;
    arr[j][i] = num;

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
}

void printBoolArray(bool arr[V]) {
    int i;
    for (i = 0; i < V; i++) {
        printf("%3d", arr[i]);

    }
}
void print1D(int arr[V]) {
    int i;
    for (i = 0; i < V; i++) {
        printf("%3d", arr[i]);

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
    bool check = true;

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

    cout << "\nDIJKSTRA\n";
    print1D(small);
    cout << "\nVISITED\n";
    printBoolArray(vis);
    
}

int main() {

    int adjMatrix[V][V];

    initilize(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);

    addWeight(adjMatrix, 0, 1, 4);
    addWeight(adjMatrix, 0, 3, 5);
    addWeight(adjMatrix, 0, 4, 6);
    addWeight(adjMatrix, 1, 2, 3);
    addWeight(adjMatrix, 1, 3, 2);
    
    printAdjMatrix(adjMatrix);

    dijkstra(adjMatrix, 0);
    

    return 0;

}
