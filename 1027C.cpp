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

int a[MAX];
int b[10004];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    int n;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	int i;
    	for(i=0;i<n;i++)
    	{
    		cin>>a[i];
    		b[a[i]]++;
    	}
    	int p=1;
    	int l1,l2;
    	int r1,r2;
    	double prod,minprod=(double)MAX;
    	if(n<10000)
    	{
    		sort(a,a+n);
    		for(i=n-1;i>=0;i--)
    		{
    			int k=1;
    			int j=i-1;
    			while((a[j]==a[i])&&j>=0)
    			{
    				j--;
    				k++;
    			}
    			if(k>3)
    			{
    				r1=a[i];
    				r2=a[i];
    				break;
    			}
    			if(k>1)
    			{
    				if(p)
    				{
    					l1=a[i];
    					p=0;
    				}
    				else
    				{
    					l2=a[i];
    					prod=(double)l1/(double)l2+(double)l2/(double)l1;
    					if(prod<minprod)
    					{
    						minprod=prod;
    						r1=l1;
    						r2=l2;
    					}
    					l1=a[i];
    				}
    			}
    			i=j+1;
    		}
    	}
    	else{
    	for(i=10000;i>=1;i--)
    	{
    		if(b[i]>3)
    		{
    			l1=i;
    			l2=i;
    			r1=i;
    			r2=i;
    			b[i]=0;
    			for(;i>=1;i--)
    				b[i]=0;
    			break;
    		}
    		if(b[i]>1)
    		{
    			if(p)
    			{
    				l1=i;
    				p=0;
    			}
    			else
    			{
    				l2=i;
    				prod=(double)l1/(double)l2+(double)l2/(double)l1;
    				if(prod<minprod)
    				{
    					minprod=prod;
    					r1=l1;
    					r2=l2;
    				}
    				l1=i;
    			}
    		}
    		b[i]=0;
    	}
    	}
    	cout<<r1<<" "<<r1<<" "<<r2<<" "<<r2<<endl;
    }

    return 0;
}