#include<bits/stdc++.h>

using namespace std;

int pr[1000][1000];

int main()
{
    int t,n,m,i,j,k,maxm;
    bool p,p2;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d%d",&n,&m);
        string s[n+1];
        for(i=0;i<n;i++)
            cin>>s[i];
        for(i=0;i<n;i++)
        {
            p2=0;
            for(j=0;j<m;j++)
            {
                if(i==0)
                {
                    if(s[i][j]=='W')
                        pr[i][j]=1;
                    else
                        pr[i][j]=0;
                }
                if(s[i][j]=='W')
                {
                    if(j==0||j==m-1)
                    {
                        p=1;
                        break;
                    }
                    else if((s[i][j-1]=='A')||(s[i][j+1]=='A')||(i<(n-1)&&s[i+1][j]=='A'))
                    {
                        p=1;
                        break;
                    }
                    if(i>0)
                        pr[i][j]=pr[i-1][j]+1;
                    if(!p2)
                    {
                        maxm=pr[i][j];
                        k=j;
                    }
                    else
                    {
                        if(maxm<pr[i][j])
                            maxm=pr[i][j];
                        if((j==m-1)||(j<(m-1)&&s[i][j+1]!='W'))
                        {
                            for(int f=k;f<=j;f++)
                                pr[i][f]=maxm;
                        }
                    }
                    p2=1;
                }
                else if(s[i][j]=='B')
                {
                    if(i<(n-1)&&s[i+1][j]!='B')
                    {
                        p=1;
                        break;
                    }
                    pr[i][j]=0;
                    p2=0;
                }
                else
                {
                    pr[i][j]=0;
                    p2=0;
                }
            }
            if(p==1)
                break;
        }
        if(p)
            cout<<"no\n";
        else
        {
            p2=0;
            for(i=0;i<n-1;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(s[i][j]=='A'&&pr[i+1][j]>1)
                    {
                        p2=1;
                        break;
                    }
                }
                if(p2)
                    break;
            }
            if(p2)
                cout<<"no\n";
            else
                cout<<"yes\n";
        }
    }
    return 0;
}
