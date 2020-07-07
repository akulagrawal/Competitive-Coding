#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k,x,t,ans,start,last,mid;
    cin>>n>>m>>k;
    m-=n;
    x=min(k,n-k+1);
    if(x>sqrt(m))
    {
        x=sqrt(m);
        ans=x+1;
    }
    else
    {
        ans=x+1;
        m-=(x*x);
        t=n-(2*x)+1;
        t=(t*(t+1)/2)+t*((2*x)-1);
        if(m>=t)
        {
            m-=t;
            ans+=(n-(2*x)+1);
            ans+=m/n;
        }
        else
        {
            start=0;
            last=n-(2*x)+1;
            while(start<last)
            {
                mid=(start+last)/2;
                t=(mid*(mid+1)/2)+(mid*((2*x)-1));
                if(t<m)
                    start=mid+1;
                else
                    last=mid;
            }
            t=(start*(start+1)/2)+(start*((2*x)-1));
            if(t>m)
                start-=1;
            ans+=start;
        }
    }
    cout<<ans;
    return 0;
}
