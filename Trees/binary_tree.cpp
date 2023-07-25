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
int main(){
    int choice, value;
    

    //         create new nodes and do the job!       //

    bt *p = new bt();
    root = p;
    p ->id = 4;

    // 2nd one
    bt *q = new bt();
    root -> left = q;
    q ->id = 10;
    
    do
    {
        
        cout << "\n------------ SELECT YOUR OPTION! -----------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to Traverse Inorder." << endl;
        cout << "Press [2] to Traverse Preorder." << endl;
        cout << "Press [3] to Traverse Postorder." << endl;
        
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

    } while (choice != 0);
    return 0;
}
