#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int s[105];
pii a[MAX],b[MAX],c[MAX],d[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k,t,s1,s2,start,end1,mid,sum=0,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&s[i]);
    t=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=j;k<n;k++)
            {
                a[t].f=s[i]*(s[j]+s[k]);
                if(!s[i])
                    a[t].s=0;
                else if(s[j]==s[k])
                    a[t].s=1;
                else
                    a[t].s=2;
                t++;
            }
        }
    }
    s1=t;
    t=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=j;k<n;k++)
            {
                b[t].f=s[i]+(s[j]*s[k]);
                if(s[j]==s[k])
                    b[t].s=1;
                else
                    b[t].s=2;
                t++;
            }
        }
    }
    s2=t;
    sort(a,a+s1);
    sort(b,b+s2);
    c[0]=a[0];
    j=0;
    k=0;
    for(i=1;i<s1;i++)
    {
        if(a[i].f==a[j].f)
            c[k].s+=a[i].s;
        else
        {
            j=i;
            k++;
            c[k]=a[i];
        }
    }
    s1=k+1;
    d[0]=b[0];
    j=0;
    k=0;
    for(i=1;i<s2;i++)
    {
        if(b[i].f==b[j].f)
            d[k].s+=b[i].s;
        else
        {
            j=i;
            k++;
            d[k]=b[i];
        }
    }
    s2=k+1;
    j=0;
    t=INT_MIN;
    for(i=0;i<s1;i++)
    {
        /*start=0;
        end1=s2-1;
        while(start<end1)
        {
            mid=start+(end1-start)/2;
            if(b[mid].f<a[i].f)
                start=mid+1;
            else
                end1=mid;
        }
        mid=start+(end1-start)/2;
        if(b[mid].f==a[i].f)
            sum+=(b[mid].s*a[i].s);*/
        if(c[i].f==t)
        {
            sum+=x;
            continue;
        }
        x=0;
        while(j<s2&&d[j].f<c[i].f)
            j++;
        while(j<s2&&d[j].f==c[i].f)
        {
            x+=(d[j].s*c[i].s);
            t=d[j].f;
            j++;
        }
        sum+=x;
    }
    printf("%d",sum);
    return 0;
}
