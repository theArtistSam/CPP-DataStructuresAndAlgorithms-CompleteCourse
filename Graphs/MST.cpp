
#include <stdio.h>
#define V 9
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

void mst(int arr[][V], int starting){
    
    bool vis[V];
    int small[V];
    initilizeBool(vis);
    initilizeInt(small);

    int i = starting;

    int smallest = INT_MAX;
    int smallestIndex = 0; 
    
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
            smallest = INT_MAX;
        }        
        else{
            for (int j = 0; j < V; j++){
                
                if(vis[j] != true && i != j && arr[i][j] != -1){
                    
                    if(small[j] == -1){
                        small[j] = arr[i][j];
                    }
                    else if(arr[i][j] > small[j]){
                        continue;
                    }
                    else{
                        small[j] = arr[i][j];
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
            smallest = INT_MAX;
        }

        if(check == true){
            break;
        }
        check = true;
    }


    cout << "\nMST\n";
    print1D(small);
    cout << "\nVISITED\n";
    printBoolArray(vis);
    
}

int main() {

    int adjMatrix[V][V];

    initilize(adjMatrix);
    /* addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3); */

    addWeight(adjMatrix, 0, 1, 4);
    addWeight(adjMatrix, 0, 7, 8);
    
    addWeight(adjMatrix, 1, 0, 4);
    addWeight(adjMatrix, 1, 2, 8);
    addWeight(adjMatrix, 1, 7, 11);
    
    addWeight(adjMatrix, 2, 1, 8);
    addWeight(adjMatrix, 2, 3, 7);
    addWeight(adjMatrix, 2, 5, 4);
    addWeight(adjMatrix, 2, 8, 2);
    
    addWeight(adjMatrix, 3, 2, 7);
    addWeight(adjMatrix, 3, 4, 9);
    addWeight(adjMatrix, 3, 5, 14);
    
    addWeight(adjMatrix, 4, 3, 9);
    addWeight(adjMatrix, 4, 5, 10);
    
    addWeight(adjMatrix, 5, 2, 4);
    addWeight(adjMatrix, 5, 3, 14);
    addWeight(adjMatrix, 5, 4, 10);
    addWeight(adjMatrix, 5, 6, 2);
    
    addWeight(adjMatrix, 6, 5, 2);
    addWeight(adjMatrix, 6, 7, 1);
    addWeight(adjMatrix, 6, 8, 6);
    
    addWeight(adjMatrix, 7, 0, 8);
    addWeight(adjMatrix, 7, 1, 11);
    addWeight(adjMatrix, 7, 6, 1);
    
    addWeight(adjMatrix, 8, 2, 2);
    addWeight(adjMatrix, 8, 6, 6);
    addWeight(adjMatrix, 8, 7, 7);
    
    printAdjMatrix(adjMatrix);

    mst(adjMatrix, 0);
    

    return 0;

}
