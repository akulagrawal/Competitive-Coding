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

map<string, string> my;
string a[MAX],b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        my[b[i]+';']=a[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>a[i]>>b[i];
        cout<<a[i]<<" "<<b[i]<<" #"<<my[b[i]]<<endl;
    }
    return 0;
}
