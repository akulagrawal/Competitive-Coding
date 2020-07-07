#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,k,p=0,t=0;
    map<int,bool> my;
    cin>>n>>m;
    while(m--)
    {
        p=0;
        cin>>k;
        while(k--)
        {
            cin>>a;
            if(!my[a])
                my[a]=1;
            if(my[a]&&my[-1*a])
                p=1;
        }
        if(!p)
            t=1;
        my.clear();
    }
    if(t==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
