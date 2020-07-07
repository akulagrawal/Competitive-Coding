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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t,n,i,p,q;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.size();
        p=0;
        q=0;
        i=0;
        while(1)
        {
            q=0;
            if(i>=n)
                break;
            while(s[i]=='='&&i<n)
                i++;
            if(i>=n)
                break;
            while(s[i]=='<'&&i<n)
            {
                q++;
                i++;
                while(s[i]=='='&&i<n)
                    i++;
            }
            p=max(p,q);
            q=0;
            if(i>=n)
                break;
            while(s[i]=='>'&&i<n)
            {
                q++;
                i++;
                while(s[i]=='='&&i<n)
                    i++;
            }
            p=max(p,q);
        }
        cout<<p+1<<endl;
    }
    return 0;
}
