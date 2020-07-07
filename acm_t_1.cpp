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

int c[200];
map<int,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        my.clear();
        for(i=0;i<n;i++)
        {
            cin>>c[i];
            my[c[i]]++;
        }
        for(i=1;i<=100;i++)
        {
            if(my[i]==1)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
