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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int t,n,k,low,mid,high,i,maxm,ct;
    char ch;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>n>>k;
        cin>>s1;
        s2=s1;
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        for(i=0;i<n;i++)
        {
            if(i%2)
                s2[i]='1';
            else
                s2[i]='0';
        }
        high=n;
        low=0;
        while(low<high)
        {
            ct=1;
            maxm=0;
            mid=low+(high-low)/2;
            if(mid==1)
            {
                for(i=0;i<n;i++)
                    if(s1[i]==s2[i])
                        maxm++;
                maxm=min(maxm,n-maxm);
            }
            else
            {
                for(i=1;i<n;i++)
                {
                    if(s1[i]==s1[i-1])
                        ct++;
                    else
                    {
                        maxm+=ct/(mid+1);
                        ct=1;
                    }
                }
                maxm+=ct/(mid+1);
            }
            if(maxm<=k)
                high=mid;
            else
                low=mid+1;
        }
        mid=low+(high-low)/2;
        if(mid==0)
            cout<<"1\n";
        else
            cout<<mid<<"\n";
    }
    return 0;
}
