#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

ll x1[MAX],x2[MAX],y[MAX],y2[MAX];
int a[4],b[4];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    	cin>>x1[i]>>y[i]>>x2[i]>>y2[i];
    a[0]=y[0];
    a[1]=y2[0];
    a[2]=x1[0];
    a[3]=x2[0];
    for(i=0;i<n;i++)
    {
    	if(y[i]>a[0])
    	{
    		a[0]=y[i];
    		b[0]=i;
    	}
    	if(y2[i]<a[1])
    	{
    		a[1]=y2[i];
    		b[1]=i;
    	}
    	if(x1[i]>a[2])
    	{
    		a[2]=x1[i];
    		b[2]=i;
    	}
    	if(x2[i]<a[3])
    	{
    		a[3]=x2[i];
    		b[3]=i;
    	}
    }
    
    int j;
    for(i=0;i<4;i++)
    {
    	ll a1,a2,b1,b2;
    	int p=0;
    	for(j=0;j<n;j++)
    	{
    		if(p==0&&(j!=b[i]))
    		{
    			p=1;
    			a1=x1[j];
    			a2=x2[j];
    			b1=y[j];
    			b2=y2[j];
    		}
    		else if(j!=b[i])
    		{
    			if(x1[j]>a1)
    				a1=x1[j];
    			if(y[j]>b1)
    				b1=y[j];
    			if(x2[j]<a2)
    				a2=x2[j];
    			if(y2[j]<b2)
    				b2=y2[j];
    		}
    		//cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
    		//cout<<endl;
    	}
    	//cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
    	if(a1<=a2&&b1<=b2)
    	{
    		cout<<a1<<" "<<b1;
    		return 0;
    	}
    }
    cout<<"NO";


    return 0;
}