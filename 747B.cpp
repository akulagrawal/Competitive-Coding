#include<bits/stdc++.h>

using namespace std;
map<char,int> my;

int main()
{
    int n,i,maxm,p,t;
    char s[260];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        my[s[i]]++;
    }
    maxm=max(my['A'],my['T']);
    maxm=max(my['G'],maxm);
    maxm=max(my['C'],maxm);
    p=n/4;
    if(n%4!=0||maxm>p)
        cout<<"===";
    else
    {
        i=0;
        t=0;
        for(;i<n;i++)
        {
            if(t==p-my['A'])
                break;
            if(s[i]=='?')
            {
                s[i]='A';
                t++;
            }
        }
        t=0;
        for(;i<n;i++)
        {
            if(t==p-my['T'])
                break;
            if(s[i]=='?')
            {
                s[i]='T';
                t++;
            }
        }
        t=0;
        for(;i<n;i++)
        {
            if(t==p-my['G'])
                break;
            if(s[i]=='?')
            {
                s[i]='G';
                t++;
            }
        }
        t=0;
        for(;i<n;i++)
        {
            if(t==p-my['C'])
                break;
            if(s[i]=='?')
            {
                s[i]='C';
                t++;
            }
        }
        for(i=0;i<n;i++)
            cout<<s[i];
    }
    return 0;
}
