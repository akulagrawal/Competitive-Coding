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
    int t=1,sum,ans;
    string s;
    while(1)
    {
        sum=0;
        ans=0;
        cin>>s;
        if(s[0]=='-')
            break;
        for(int i=0;i<s.size();i++)
        {
            if(!sum&&s[i]=='}')
            {
                ans++;
                sum++;
            }
            else if(s[i]=='}')
                sum--;
            else
                sum++;
        }
        ans+=sum/2;
        cout<<t<<". "<<ans<<endl;
        t++;
    }
    return 0;
}
