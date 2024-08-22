#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) : data(data) {left=right=nullptr;};
    TreeNode(int data,TreeNode *left,TreeNode *right) : data(data), left(left), right(right) {};
};



//
inOrder(TreeNode *root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

bool search(TreeNode *root,int x){
    if(root == nullptr){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data>x){
        search(root->left,x);
    }
    else{
        search(root->right,x);

    }
}

void insertItr (TreeNode * &root,int x){
    if(root ==NULL){
        root= new TreeNode(x);
        return;
    }
    TreeNode *temp=root,*prev=nullptr;
    while(temp!=NULL){
        if(temp->data==x){
            return;
        }
        else if(x>temp->data){
            prev=temp;
            temp=temp->right;
        }
        else{
            prev=temp;
            temp=temp->left;
        }
    }
        if(x<prev->data){
            prev->left=new TreeNode(x);
        }
        else {
            prev->right=new TreeNode(x);
        }

}

TreeNode * insertRecursive(TreeNode *root,int x){
    
    if(root ==NULL){
        return new TreeNode(x);
    }
    
    if(x<root->data){
        root->left=insertRecursive(root->left,x);
    }
    else{
        root->right=insertRecursive(root->right,x);

    }
}

int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right = new TreeNode(70);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    insertItr(root,90);
    insertRecursive(root , 5);
    inOrder(root);
    cout<<endl;
    if(search(root,90)){
        cout<<"Found !"<<endl;
    }
    else{
        cout<<"Not Found !"<<endl;
    }

return 0;
}