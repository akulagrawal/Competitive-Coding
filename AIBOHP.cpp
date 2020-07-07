#include<bits/stdc++.h>

using namespace std;

string s;
int a[6105][6105];

int min_len(int start,int last)
{
    if(last-start==1)
    {
        if(s[start]!=s[last])
            return a[start][last]=1;
        else
            return a[start][last]=0;
    }
    else if(last==start)
        return a[start][last]=0;
    else if(a[start][last]!=-1)
        return a[start][last];
    else if(s[start]==s[last])
        return a[start][last]=min_len(start+1,last-1);
    else
        return a[start][last]=min(min_len(start+1,last),min_len(start,last-1))+1;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.size()-1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                a[i][j]=-1;
        }
        cout<<min_len(0,n)<<endl;
    }
    return 0;
}
