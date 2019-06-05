#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)
ll c=0;

struct node{
    ll val;
    node * next;
    node * prev;
}*head=NULL;
void insert(ll y,ll x)
{

    node *temp=new node;
    temp->val=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
	if(y==0)
	    head=temp,c++;
	else
	    cout<"dimag to sahi hai ";
    }
    else
    {
	if(y==0)
	{
	    c++;
	    node *temp1=head;
	    temp1->prev=temp;
	    head=temp;
	    head->next=temp1;
	    return ;
	}
	ll co=0;
	ll f=0;
	node * temp1=head;
	while(temp1!=NULL)
	{
	    co++;
	    if(y==co){
		f=1;
		break;
	    }
	    temp1=temp1->next;
	}
	if(f)
	{
	    c++;
	    temp->next=temp1->next;
	    if(temp1->next!=NULL)
	    temp1->next->prev=temp;
	    temp1->next=temp;
	    temp->prev=temp1;
	}
	else
	     cout<<"Dimag to sahi hai "<<endl;
    }
}
	    

		
void func()
{
	node * temp1,*temp2;
	temp1=head;
	ll x;
	cout<<"Enter x ";
	cin>>x;
	while(temp1!=NULL)
	{
	    temp2=head;
	    while(temp2!=NULL)
	    {
		if(temp1->val*temp2->val==x)
		    cout<<"("<<temp1->val<<","<<temp2->val<<")\n";
		   temp2=temp2->next;
	    }

		   temp1=temp1->next;
	}
}


void disp()
{
    node *temp=head;
    cout<<"\n Doubly linked list have element\n";
    while(temp!=NULL)
    {
	cout<<temp->val<<" ";
	temp=temp->next;
    }
    cout<<endl;
}



int main()
{

    ll ch,x,y;
    do{
	cout<<"\nEnter \n\t1.To enter at the front.\n\t2.To add after a given node\n\t3.Add a node at the last.\n\t4.Add a node before a given node\n\t5.To operation \n\t6.Exit. ";
	cin>>ch;
	switch(ch){
	    case 1:
	     cout<<"Enter value of the node";
	     cin>>x;
	     insert(0,x);
	     break;
	    case 2:
	     cout<<"Enter value of the node and position of node after which it is going to store ";
	     cin>>x>>y;
	     insert(y,x);
	     break;
	    case 3:
	     cout<<"Enter value of the node";
	     cin>>x;
	     insert(c,x);
	     break;
	    case 4:
	     cout<<"Enter value of the node and position of node before which it is going to stoe ";
	     cin>>x>>y;
	     insert(y-1,x);
	     break;
	    case 5: func();
	}
	if(c && ch!=5)
	disp();
    }while(ch!=6);
}
