#include <iostream>
#include <queue>

using namespace std;

struct node{
    double data;
    node* left=NULL;
    node* right=NULL;
};


void clear (node* n) {
        if (n==NULL) {
            return;
        }
        clear (n->left);
        clear (n->right);
        delete n;
    }
 
 
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
    

struct bst{
    node* root;    
    
    bst(): root(NULL){};//конструктор по умолчанию
    
    bst(int data){//конструктор
        root=new node;
        root->data=data;
    }
    
    bst (const bst& other){//конструктор копирования
        node* temp = new node;
        node* cur = other.root;
        queue <node*> A;
        A.push(cur);
        while (A.empty() == 0){
            temp = A.front();
            A.pop();
            push(temp->data, root);
            if (temp->left != NULL) A.push(temp->left);
            if (temp->right != NULL) A.push(temp->right);
        }
    }
    
    bst& operator=(const bst& tr){// оператор присваивания
        clear(root);
        node* temp = new node;
        node* cur = tr.root;
        queue <node*> A;
        A.push(cur);
        while (A.empty() == 0){
            temp = A.front();
            A.pop();
            push(temp->data, root);
            if (temp->left != NULL) A.push(temp->left);
            if (temp->right != NULL) A.push(temp->right);
        }
        return *this;
    }
        
        
    
    bool find_dfs(double r){ // поиск в глубину
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
        if(root!=NULL){
            A.push(root);
            node* temp;
            while (!A.empty()){
                temp = A.front();
                A.pop();
                if (temp -> data == t) return 1;
                if (temp -> left != NULL) A.push(temp -> left);
                if (temp -> right != NULL) A.push(temp -> right);
            }
            return 0;
        }
        else{return 0;}
    }
    
    ~bst(){//деструктор
        clear(root);
    }

    
}; 



 

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
  bst tree1(9), tree2;
  push(1, tree1.root);
  push(10, tree1.root);
  push(6, tree1.root);
  push(11, tree1.root);
  push(11, tree1.root);
  tree2=tree1;
  tree2.root->data=0;
  cout<<"pre order tree1: ";
  pre_order(tree1.root);
  cout<<endl<<"pre order tree2: ";
  pre_order(tree2.root);
  cout<<endl<<"in order tree1: ";
  in_order(tree1.root);
  cout<<endl<<"post order tree1: ";
  post_order(tree1.root);
  cout<<endl<<endl<<"find_dfs(1) tree1: "<<tree1.find_dfs(1);
  cout<<endl<<"find_dfs(2) tree1: "<<tree1.find_dfs(2);
  cout<<endl<<endl<<"find_bfs(1) tree1: "<<tree1.find_bfs(1);
  cout<<endl<<"find_bfs(2) tree1: "<<tree1.find_bfs(2);
  return 0;
}
