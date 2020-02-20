/*program to delete a node from the linked list as per the position given by the user
but to make sure to not delete nodes which contain armstrong number in there data section.
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};

/*Function definitions for linked list operations*/
node* in(node*,node*);
void del(node*,node*,int);
void display(node*);

node* dif(node*);
int arm(node*);

int main()
{
/*Pointers to first and last node*/
node *head=NULL, *tail=NULL ,*temp;
int cmd,n;

    /*Displaying choices for performing linked list operations*/
    while(1)
    {
        cout<<"\nEnter \n1 to insert node\n2 to 2 to delete node in node\n3 to display\n4 to exit\ncommand: \t"<<endl;
        cin>>cmd;
        switch(cmd)
        {
        case 1:
            {//logic to get data of node
                temp = new node();
                cout<<"\nenter data : ";
                cin>>temp->data;
                temp->next=NULL;
                //logic for first node
                if(head==NULL){
                    head=tail=temp;
                }
                else{//logic for next nodes
                tail=in(tail,temp);
                }
                break;
            }
        case 2:
            {
                //logic to input in front of rest
                cout<<"\nenter the position of element you want to delete: ";
                cin>>n;
              if(n==0){
            head=dif(head);
            }
            else{
                del(head,tail,n);
            }
                break;
            }
        case 3:
            display(head);
            break;

        case 4:
            exit(1);
        default:
            continue;
    }


}

}
//logic to input next nodes
node* in(node *tail,node *temp){
    tail->next=temp;
    tail=temp;
    return tail;
}
//logic to display
void display(node *head){
node *temp=head;
cout<<"list:"<<endl;
    while(temp!=NULL)
    {
    cout<<temp->data<<endl;
    temp=temp->next;
    }



}
//logic to delete in the front
node * dif(node* head){
    int i=arm(head);
if(!i){
    cout<<"Can not delete Armstrong number"<<endl;}
else{node* temp=head;
head=head->next;
}

return head;
}
//logic to delete in the middle
void del(node* head,node* tail,int  i){


        i=i-1;
        node *temp=head;
        while(i!=0){
            temp=temp->next;
            i--;
        }
        if(!arm(temp->next) && temp->next!=NULL){
        temp->next=temp->next->next;
        cout<<"element deleterd"<<endl;
        }
            else{
            if(temp->next==NULL){
                cout<<"value entered exceeded list size"<<endl;
            }
            else{
            cout<<"can not delete armstrong number"<<endl;
        }
    }
}
//logic for finding armstrong number or not
int arm(node *p){
int v,d,n,i,s=0;
v=d=p->data;
while(d>0){
        d=d/10;
        i++;
}
d=v;
while(d>0){
    n=d%10;
    d=d/10;
    n=pow(n,i);
s=s*10+n;
}
if(s==v)
{
    return(1);
}
else{
    return(0);
}

}
