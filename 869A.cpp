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

int x[MAX],y[MAX];
map<int,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x[i];
        my[x[i]]++;
    }
    for(i=0;i<n;i++)
    {
        cin>>y[i];
        my[y[i]]++;
    }
    int j,p=0,q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            q=x[i]^y[i];
            if(my[q])
                p++;
        }
    }
    if(p%2)
        cout<<"Koyomi";
    else
        cout<<"Karen";
    return 0;
}
