#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *lft;
    node *ryt;
};
node* input(node *p){
    node *temp=new node;
    int branch;

    cout<<"enter data : ";
    cin>>temp->data;
    cout<<"do you want to branch(enter 0 for no) ? : ";
    cin>>branch;
    if(branch){
    temp->lft=input(temp->lft);
    temp->ryt=input(temp->ryt);
    }
    else{
        temp->lft=NULL;
        temp->ryt=NULL;
    }
    return temp;
}
void top_bottom(node *point){

 cout<< " -> "<<point->data;
     if(point->lft!=NULL){
        top_bottom(point->lft);
    }

    if(point->ryt!=NULL){
        top_bottom(point->ryt);
    }
}
void bottom_top(node *point){
    if(point->lft!=NULL){
        bottom_top(point->lft);
    }

    if(point->ryt!=NULL){
        bottom_top(point->ryt);
    }

 cout<< " -> "<<point->data;
}
void left_right(node *point){
    if(point->lft!=NULL){
        left_right(point->lft);
    }

 cout<< " -> "<<point->data;
    if(point->ryt!=NULL){
        left_right(point->ryt);
    }
}
main(){
    node *root;
    root=input(root);

    cout<<"\n";
    top_bottom(root);
    cout<<"\n";
    bottom_top(root);
    cout<<"\n";
    left_right(root);
}
