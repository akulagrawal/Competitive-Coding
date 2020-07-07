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

int minm[5003][5003],maxm[5003][5003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int ans=0;
    int n=s.size();
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(j>i)
            {
                maxm[i][j]=maxm[i][j-1];
                minm[i][j]=minm[i][j-1];
            }
            if(s[j]=='(')
            {
                maxm[i][j]++;
                minm[i][j]++;
            }
            else if(s[j]==')')
            {
                if(!maxm[i][j])
                    break;
                else if(!minm[i][j])
                {
                    maxm[i][j]--;
                    minm[i][j]++;
                }
                else
                {
                    maxm[i][j]--;
                    minm[i][j]--;
                }
            }
            else
            {
                maxm[i][j]++;
                if(minm[i][j])
                    minm[i][j]--;
                else
                    minm[i][j]++;
            }
            if(!minm[i][j])
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
