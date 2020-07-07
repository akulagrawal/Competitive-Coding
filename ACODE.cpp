#include<bits/stdc++.h>

using namespace std;

long long dp[5003];

int main()
{
    int p=0,n,i,a,b,c;
    while(!p)
    {
        string s;
        cin>>s;
        n=s.size();
        if(s[0]=='0'&&n==1)
            p=1;
        else
        {
            if(s[0]-'0')
                dp[0]=1;
            else
            {
                cout<<"0\n";
                continue;
            }
            if(n>1)
            {
                i=3;
                a=s[0]-'0';
                b=s[1]-'0';
                c=(10*a)+b;
                if(c==10||c==20)
                    dp[1]=1;
                else if(b==0)
                {
                    dp[n-1]=0;
                    i=n+1;
                }
                else if(c<=26&&c>0)
                    dp[1]=2;
                else
                    dp[1]=1;
                for(;i<=n;i++)
                {
                    a=s[i-2]-'0';
                    b=s[i-1]-'0';
                    c=(10*a)+b;
                    if(c==10||c==20)
                        dp[i-1]=dp[i-3];
                    else if(b==0)
                    {
                        dp[n-1]=0;
                        break;
                    }
                    else if(a==0)
                        dp[i-1]=dp[i-2];
                    else if(c<=26&&c>0)
                        dp[i-1]=dp[i-2]+dp[i-3];
                    else
                        dp[i-1]=dp[i-2];
                }
            }
            cout<<dp[n-1]<<"\n";
        }
    }
    return 0;
}
