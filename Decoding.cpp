#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,i,p;
    char s[2003],t[2003];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    if(n%2==0)
        a=n/2;
    else
        a=(n+1)/2;
    t[a-1]=s[0];
    for(i=1;i<a;i++)
    {
        if(n%2==1)
        {
            t[a-1-i]=s[2*i-1];
            t[a-1+i]=s[2*i];
        }
        else
        {
            t[a-1+i]=s[2*i-1];
            t[a-1-i]=s[2*i];
        }
    }
    if(n%2==0)
        t[n-1]=s[n-1];
    for(i=0;i<n;i++)
        cout<<t[i];
    return 0;
}
