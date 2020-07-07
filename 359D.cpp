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

int tree[MAX];

int a[MAX];

void build(int node, int start, int end1)
{
    if(start == end1)
    {
        // Leaf node will have a single element
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end1) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end1);
        // Internal node will have the sum of both of its children
        tree[node] = __gcd(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return __gcd(p1, p2);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    	cin>>a[i];
    build(1,0,n-1);
    int maxm=0;
    vector<int> v;
    int cnt=0;
    for(i=0;i<n;i++)
    {
    	int l=i+1;
    	int r=n-1;
    	int mid=(l+r)/2;
    	int j;
    	while(l<r)
    	{
    		mid=(l+r)/2;
    		int x=query(1,0,n-1,i,mid);
    		if(x==0)
    		{
    			r=mid-1;
    			continue;
    		}
    		for(j=0;j<n;j++)
    			if(x%a[j]==0)
    			{
    				l=mid+1;
    				break;
    			}
    		if(j==n)
    			r=mid;
    	}
    	mid=(l+r)/2;
    	int x=query(1,0,n-1,i,mid);
    	for(int j=0;j<n;j++)
    		if(x%a[j]==0)
    		{
    			mid++;
    			break;
    		}
    	if((mid-i-1)==maxm)
    	{
    		cnt++;
    		v.pb(i);
    	}
    	if((mid-i-1)>maxm)
    	{
    		cnt=1;
    		v.clear();
    		v.pb(i);
    		maxm=mid-i-1;
    	}
    }
    cout<<cnt<<" "<<maxm<<endl;
    for(i=0;i<v.size();i++)
    	cout<<v[i]+1<<" ";

    return 0;
}