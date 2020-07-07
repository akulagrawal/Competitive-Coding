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

int r[30];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,i,maxm=0;
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>r[i];
        maxm=max(maxm,r[i]);
    }
    if(maxm>=25)
        cout<<maxm-25;
    else
        cout<<"0";
    return 0;
}
