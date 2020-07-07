#include<bits/stdc++.h>

using namespace std;

int fn(int m,int n,int x)
{
    int table[n + 1][x + 1];
    memset(table, 0, sizeof(table));
    for (int j = 1; j <= m && j <= x; j++)
        table[1][j] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= m && k < j; k++)
                table[i][j] += table[i-1][j-k];
    return table[n][x];
}

double ans[20];

int main()
{
    //freopen ("fighting_the_zombie.txt","r",stdin);
    //freopen ("AKUL6.txt","w",stdout);
    int t,cas=0,z;
    cin>>t;
    for(z=1;z<=t;z++)
    {
       int h,n,i,j,n1,x,y,d,k,k1,h1;
       cin>>h>>n;
       string s[n];
       for(i=0;i<n;i++)
           cin>>s[i];
       for(i=0;i<n;i++)
       {
           x=0;
           y=0;
           d=0;
           n1=s[i].size();
           for(j=0;j<n1;j++)
               if(s[i][j]=='d')
                   break;
           k=j;
           for(j=0;j<k;j++)
               x=x*10+(int)(s[i][j]-'0');
           for(j=k+1;j<n1;j++)
               if(s[i][j]=='+'||s[i][j]=='-')
                   break;
           k1=j;
           for(j=k+1;j<k1;j++)
               y=y*10+(int)(s[i][j]-'0');
           for(j=k1+1;j<n1;j++)
               d=d*10+(int)(s[i][j]-'0');
           if(k1<n1)
           {
               if(s[i][k1]=='+')
                   h1=h-d;
               else
                   h1=h+d;
           }
           else
               h1=h;
           for(int f=h1;f<=(x*y);f++)
           {
               if(f==h1)
                   ans[i]=(double)fn(y,x,h1);
               else
                   ans[i]+=(double)fn(y,x,f);
           }
           for(int f=0;f<x;f++)
               ans[i]/=(double)y;
       }
       sort(ans,ans+n);
       cout<<"Case #"<<z<<": "<<ans[n-1]<<endl;
    }
    return 0;
}
