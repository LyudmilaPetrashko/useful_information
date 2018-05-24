#include <iostream>

using namespace std;

struct node{
    double data;
    node* left=NULL;
    node* right=NULL;
};

struct bst{
    node* root=NULL;    
    
    bool find(double r){
        node* cur=root;
        while(cur!=NULL){
            if(cur->data==r){return 1;}
            else{
            if(r>cur->data){
                cur=cur->right;
                }
            else{
                cur=cur->left;
            }
        }
        }
        return 0;
        }
    
    
}; 



 void push(double x, node* &y){
        if(y==NULL){
            y=new node();
            y->data=x;
            y->left=NULL;
            y->right=NULL;
        }
        else{
            if(x>=y->data){
                if(y->right!=NULL){
                    push(x,y->right);
                }
                else{
                    y->right=new node();
                    y->right->data=x;
                    y->right->right=y->right->left=NULL;
                }
            }
            else{
                if(y->left!=NULL){
                    push(x,y->left);
                }
                else{
                    y->left=new node();
                    y->left->data=x;
                    y->left->right=y->left->left=NULL;
                }
            }
        } 
 }
 
 
void print(node* x){
    if(x->left!=NULL){
        print(x->left);
    }
    cout<<x->data<<endl;
        
    if(x->right!=NULL){
        print(x->right);
    }
}



int main()
{
  bst tree;
  push(9, tree.root);
  push(1, tree.root);
  push(10, tree.root);
  push(6, tree.root);
  push(11, tree.root);
  push(11, tree.root);
  print(tree.root);
  cout<<endl<<"find 1: "<<tree.find(1);
  cout<<endl<<"find 2: "<<tree.find(2);
 
  return 0;
}
