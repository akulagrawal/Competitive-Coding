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

ll a[MAX];
map<ll,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,p,q,cnt,i;
    cin>>t;
    while(t--)
    {
        my.clear();
        cin>>n;
        p=q=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0||a[i]==1)
                p++;
            if(a[i]==-1)
                q++;
            my[a[i]]++;
        }
        if(n>(p+q+1))
            cout<<"no\n";
        else if(q)
        {
            for(i=0;i<n;i++)
            {
                if(a[i]!=-1&&!my[-1*a[i]])
                {
                    cout<<"no\n";
                    break;
                }
            }
            if(i<n)
                continue;
            if(q>1&&!my[1])
                cout<<"no\n";
            else
                cout<<"yes\n";
        }
        else
            cout<<"yes\n";
    }
    return 0;
}
