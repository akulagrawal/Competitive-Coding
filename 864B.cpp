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

map<char,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,p=0,q=0;
    string s;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        p=0;
        my.clear();
        for(;i<n;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                break;
            if(!my[s[i]])
            {
                my[s[i]]++;
                p++;
            }
        }
        q=max(q,p);
    }
    cout<<q;
    return 0;
}