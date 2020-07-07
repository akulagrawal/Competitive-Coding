#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 200005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int main()
{
    string a,b;
    int ans,p=0;
    cin>>a>>b;
    if(a.size()!=b.size())
        ans=max(a.size(),b.size());
    else
    {
        ans=a.size();
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                p=1;
                break;
            }
        }
        if(!p)
            ans=-1;
    }
    cout<<ans;
    return 0;
}
