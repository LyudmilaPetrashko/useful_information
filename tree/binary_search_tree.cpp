#include <iostream>
#include <queue>

using namespace std;

struct node{
    double data;
    node* left=NULL;
    node* right=NULL;
};

struct bst{
    node* root=NULL;    
    
    bool find_dfs(double r){
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
    
    
    bool find_bfs(double t){ // поиск/обход в ширину
        queue <node*> A;
        A.push(root);
        node* temp;
        while (A.empty()!=1){
            temp = A.pop();
            if (temp -> data == t) return 1;
            if (temp -> left != NULL) A.push(temp -> left);
            if (temp -> right != NULL) A.push(temp -> right);
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
 

void pre_order(node* x1){ // префиксный обход
    
    cout<<x1->data<<"  ";
    
    if(x1->left!=NULL){
        pre_order(x1->left);
    }
        
    if(x1->right!=NULL){
        pre_order(x1->right);
    }
}
 
void in_order(node* x2){ // инфиксный обход
    if(x2->left!=NULL){
        in_order(x2->left);
    }
    cout<<x2->data<<"  ";
        
    if(x2->right!=NULL){
        in_order(x2->right);
    }
}

void post_order(node* x3){ // постфиксный обход
    if(x3->left!=NULL){
        post_order(x3->left);
    }
        
    if(x3->right!=NULL){
        post_order(x3->right);
    }
    
    cout<<x3->data<<"  ";
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
  pre_order(tree.root);
  cout<<endl;
  in_order(tree.root);
  cout<<endl;
  post_order(tree.root);
  cout<<endl<<"find_dfs 1: "<<tree.find_dfs(1);
  cout<<endl<<"find_dfs 2: "<<tree.find_dfs(2);
  cout<<endl<<endl<<"find_bfs 1: "<<tree.find_bfs(1);
  cout<<endl<<"find_bfs 2: "<<tree.find_bfs(2);
 
  return 0;
}
