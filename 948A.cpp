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

string s[5000];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c;
    int i,j;
    cin>>r>>c;
    for(i=0;i<r;i++)
        cin>>s[i];
    int p=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(s[i][j]=='.')
                s[i][j]='D';
            else if(s[i][j]=='W')
            {
                if((i>0)&&(s[i-1][j]=='S'))
                    p=1;
                if((j>0)&&(s[i][j-1]=='S'))
                    p=1;
                if((i<r)&&(s[i+1][j]=='S'))
                    p=1;
                if((j<c)&&(s[i][j+1]=='S'))
                    p=1;
            }
        }
    }
    if(p)
        cout<<"No";
    else
    {
        cout<<"Yes\n";
        for(i=0;i<r;i++)
            cout<<s[i]<<endl;
    }
    return 0;
}
