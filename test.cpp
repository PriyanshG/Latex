#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)

ll n=0;

ll A[10];
void heap(int i)
{
	ll l=2*i;
	ll r=2*i+1;
	ll lar;
	if(l<=n && A[l]>A[i])
		lar=l;
	else 
		lar=i;
	if(r<=n && A[r]>A[lar])
		lar=r;
	if(lar!=i)
	{
		ll t=A[lar];
		A[lar]=A[i];
		A[i]=t;
		heap(lar);
	}
}

void del()
{
	
	if(n==0)
		cout<<"Can't";
	else{
		cout<<A[1]<<"is deleted \n";
		A[1]=A[n];
		n--;
		heap(1);
	}
}
void ins()
{
	cout<<"Enter value ";
	ll x;
	cin>>x;
	n=n+1;
	A[n]=x;

	ll i=n;
	while(i>1 && A[i/2]<A[i])
	{	ll t=A[i/2];
		A[i/2]=A[i];
		A[i]=t;
		i=i/2;
	}
}
		


	
int main()
{
	
	ll ch;
	do{
		cout<<"Enter 1.To push \n\t2.To pop \n\t3. To top() \n\t4.Exit ";
		cin>>ch;

		switch(ch){
			case 1: ins();
			 break;
			case 2: del();
			 break;
			case 3: cout<<A[1];
		}
	}while(ch!=4);
}

