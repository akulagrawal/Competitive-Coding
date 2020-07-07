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
    string t[5]={"Danil","Olya","Slava","Ann","Nikita"};
    int i,j,n,m,k,p=0;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        for(k=0;k<5;k++)
        {
            m=t[k].size();
            for(j=0;j<m;j++)
            {
                if(s[i+j]!=t[k][j])
                    break;
            }
            if(j==m)
                p++;
        }
    }
    if(p==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
