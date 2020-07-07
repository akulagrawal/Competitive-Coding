#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[10];
    int n,ans=0;
    gets(s);
    n=strlen(s);
    if(n>1)
    {
        for(int i=1;i<n;i++)
            ans+=pow(2,i);
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='7')
            ans+=pow(2,n-1-i);
    }
    ans++;
    cout<<ans;
    return 0;
}
