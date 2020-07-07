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

vector<int> va,vb;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    ll m=a,n=b;
    while(m)
    {
        va.pb(m%10);
        m/=10;
    }
    while(n)
    {
        vb.pb(n%10);
        n/=10;
    }
    m=va.size();
    n=vb.size();
    if(n>m)
    {
        vb.clear();
        n=m;
        for(int i=0;i<m;i++)
            vb.pb(9);
    }
    int i;
    int j=n-1;
    int t=0;
    while(j>=0)
    {
        int p=-1;
        for(i=j;i>=0;i--)
            if(((va[i]<=vb[j])||t==1)&&va[i]>p)
            {
                p=va[i];
                swap(va[j],va[i]);
            }
        if(va[j]<vb[j])
            t=1;
        else if(t==0&&va[j]>vb[j])
            break;
        j--;
    }
    if(j>=0)
    {
    while(j<n)
    {
        int p=-1;
        for(i=0;i<=j;i++)
        {
            if((va[i]<vb[j])&&va[i]>p)
            {
                p=va[i];
                swap(va[i],va[j]);
            }
        }
        if(p>-1)
        {
            j--;
            while(j>=0)
            {
                int s=-1;
                for(i=j;i>=0;i--)
                    if(va[i]>s)
                    {
                        s=va[i];
                        swap(va[j],va[i]);
                    }
                j--;
            }
            break;
        }
        j++;
    }
    }
    ll c=0;
    for(i=n-1;i>=0;i--)
        c=c*10+(ll)va[i];
    cout<<c;
    return 0;
}
