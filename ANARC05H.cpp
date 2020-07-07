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

int a[30][30];

int func(int m,int sum,int n)
{
    int ans=0,p=0;
    for(int i=m;i<=n;i++)
    {
        if(a[m][i]>=sum)
        {
            if(!p)
            {
                ans++;
                p=1;
            }
            ans+=func(i+1,a[m][i],n);
        }
    }
    return ans;
}

int main()
{
    int i,j,k,sum,t=1;
    while(1)
    {
        string s;
        cin>>s;
        if(s[0]=='b')
            break;
        for(i=0;i<s.size();i++)
        {
            for(j=i;j<s.size();j++)
            {
                for(k=0;k<=j-i;k++)
                    a[i+1][j+1]+=s[i+k]-'0';
            }
        }
        sum=func(1,0,s.size());
        for(i=0;i<s.size();i++)
        {
            for(j=i;j<s.size();j++)
                a[i+1][j+1]=0;
        }
        cout<<t<<". "<<sum<<"\n";
        t++;
    }
    return 0;
}
