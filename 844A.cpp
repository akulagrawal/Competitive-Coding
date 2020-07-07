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
    string s;
    int k,i,m=0;
    cin>>s;
    cin>>k;
    for(i=0;i<s[i];i++)
    {
        if(!my[s[i]])
        {
            my[s[i]]=1;
            m++;
        }
    }
    if(k>s.size())
        cout<<"impossible";
    else if(k>m)
        cout<<k-m;
    else
        cout<<"0";
    return 0;
}
