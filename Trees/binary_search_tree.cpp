#include <iostream>
#include <string>
using namespace std;

struct bt{

    int id;
    bt *right = NULL;
    bt *left = NULL;
    
};

bt *root = NULL;

bool isEmpty(){
    if(root == NULL){
        return true;
    }
    else{
        return false;
    }
}

void traversePreOrder(bt *p){

    if(p != NULL){
        cout << "ID is: " << p -> id << endl;
        traversePreOrder(p -> left);
        traversePreOrder(p -> right);
    }

}
void traverseInOrder(bt *p){

    if(p != NULL){
        traversePreOrder(p -> left);
        cout << "ID is: " << p -> id << endl;
        traversePreOrder(p -> right);
    }

}
void traversePostOrder(bt *p){

    if(p != NULL){
        
        traversePreOrder(p -> left);
        traversePreOrder(p -> right);
        cout << "ID is: " << p -> id << endl;
    
    }
}

void insert(int value){

    bt *current = new bt();
    current -> id = value;
    
    // previous pointer
    bt *p = root; 
    bt *p_previous;

    if(isEmpty()){
        root = current;
    }
    else{
        while(p != NULL){
            p_previous = p;
            if(value >= p -> id){
                p = p -> right;
            }
            else{
                p = p -> left;
            }
        }   

        if(value >= p_previous -> id){
            p_previous -> right = current;
        }
        else{
            p_previous -> left = current;
        }
    }
}

int height(bt *node){

    if (node == NULL)
        return -1;
    else {

        /* compute the depth of each subtree */
        int left = height(node -> left);
        int right = height(node -> right);
        
        /* use the larger one */
        if (left > right){
             
            return(left + 1);
        }
        else{
            return(right + 1);
        }
    }
}
void delete_Node(int value){
    bt *p = root;
    bt *p2; // Previous Node!

    // Reaching at the value! Searching
    while (p -> id != value && p != NULL)
    {
        p2 = p;

        if(value >= p -> id){
            p = p -> right;
        }
        else{
            p = p -> left;
        }
    }

    // -------------------------------------------- //
    // Leaf Node Check
    if(p -> right == NULL && p -> left == NULL){
        cout << "Leaf Check!" << endl;
        if(p2 -> left == p){
            p2 -> left = NULL;
            delete p;
        }
        else{
            p2 -> right = NULL;
            delete p;
        }   
    }
    // Single Root Check
    else if(p -> right == NULL || p -> left == NULL){
        cout << "Single Check!" << endl;
        if (p2 -> left == p)
        {
            if(p -> right == NULL){
                p2 -> left = p -> left;
                delete p;
            }
            else{
                p2 -> left = p -> right;
                delete p;
            }
        }
        else{
            if(p -> left == NULL){
                p2 -> right = p -> right;
                delete p;
            }
            else{
                p2 -> right = p -> left;
                delete p;
            }
        }
    }
    // Double Root Check
    else{
        cout << "Double Check!" << endl;

        // Independant condition
        if(p -> id == root -> id && (p -> right -> right == NULL && p -> right -> left == NULL)){
            cout << "Root with empty sides!";
            root -> id = p -> right -> id;
            delete root -> right;
            root -> right = NULL;

        }
        else{
            bt *k = p -> right;
            bt *k2 = k;
            
            if(k -> left == NULL){
                p -> id = k -> id;
                p -> right = k -> right;
                delete k;
            }
            else{
                while (k -> left != NULL)
                {
                    k2 = k;
                    k = k -> left;
                }
                
                if(k -> right == NULL){
                    p -> id = k -> id;
                    p -> right = NULL;
                    delete k;
                }
                else{
                    cout << "Else;";
                    
                    p -> id = k -> id;
                    k2 -> left = k -> right;
                    delete k;
                }
            }
        }
    } 
}

int leafCount(bt *p){
    if(p == NULL){
        return 0;
    }
    if(p -> left == NULL && p -> right == NULL){
        return 1;
    }
    else{
        return leafCount(p -> left) + leafCount(p -> right);
    
    }
}

void searchIteration(int value){

    bt *p = root;

    if(isEmpty()){
        cout << "No Element exists" << endl;
    }
    else{
        while(p -> id != value && p != NULL){

            if(value >= p -> id){
                p = p -> right;
            }
            else{
                p = p -> left;
            }
        }   

        cout << "Searched key is: " << p -> id << endl;
    }
}
void searchRecurrsion(int value, bt *p){

    if(isEmpty()){
        cout << "No Element exists" << endl;
    }
    else if (p -> id == value){
        cout << "Found!" << endl;
    }
    else if(p -> id >= value){
        searchRecurrsion(value, p -> right);
    }
    else{
        searchRecurrsion(value, p -> left);
    }

    cout << "Search ID is: " << p -> id << endl;
}
int main(){
    int choice, value;
    
    do
    {
        
        cout << "\n------------ SELECT YOUR OPTION! -----------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to Traverse Inorder." << endl;
        cout << "Press [2] to Traverse Preorder." << endl;
        cout << "Press [3] to Traverse Postorder." << endl;
        cout << "Press [4] to Insert New Node." << endl;
        cout << "Press [5] to Delete a Node." << endl;
        cout << "Press [6] to Search Iteration." << endl;
        cout << "Press [7] to Search Recurrsion." << endl;
        cout << "Press [8] to Height of binary tree." << endl;
        
        cin >> choice;
        
        if(choice == 1){
            traverseInOrder(root);
        }
        else if(choice == 2){
            traversePreOrder(root);
        }
        else if(choice == 3){
            traversePostOrder(root);
        }
        else if(choice == 4){
            cout << "Enter an ID to insert: " << endl;
            cin >> value;
            insert(value);
        }
        else if(choice == 5){
            cout << "Enter an ID to delete: " << endl;
            cin >> value;
            delete_Node(value);
        }
        else if(choice == 6){
            cout << "Enter an ID to search: " << endl;
            cin >> value;
            searchIteration(value);
        }
        else if(choice == 7){
            
            cout << "Enter an ID to search: " << endl;
            cin >> value;

            bt *p = root;
            searchRecurrsion(value, p);
        }
        else if(choice == 8){

            cout << "Height is: " << height(root);
        }
        else if(choice == 9){
            cout << "count is: " << leafCount(root); 
        }

    } while (choice != 0);
    return 0;
}
