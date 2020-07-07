#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *newnode(int n)
{
    node *temp=new node;
    temp->data=n;
    temp->next=NULL;
    return temp;
}

node *rev(int k,node *head)
{
    node *prev=NULL,*next=NULL,*cur=head;
    int cnt=0;
    while(cur!=NULL&&cnt<k)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        cnt++;
    }
   // head=prev;
    cout<<head->data<<endl;
    if(next!=NULL)
    head->next=rev(k,next);
    return prev;
}

int main()
{
    node *fron = newnode(1);
    fron->next=newnode(2);
    fron->next->next=newnode(3);
    fron->next->next->next=newnode(4);
    fron->next->next->next->next=newnode(5);
    fron->next->next->next->next->next=newnode(6);
    fron->next->next->next->next->next->next=newnode(7);

    int k=3;
    node *cur=fron;
    while(cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
     fron= rev(k,fron);
    cur=fron;
    cout<<endl;
     while(cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    cout<<endl;
    return 0;
}
