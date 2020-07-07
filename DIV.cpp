#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000
#define pb push_back

int prime1[10]={2,3,5,7,11,13,17,19};
int t[10]={250000,707,26,8,3,2,2,2};
vector<int> prime2;
vector<int> ans;
bool p[(MAX/4)+6];

ll fast_pow(int a,int n)
{
    ll result = 1;
    int power = n;
    ll value = (ll)a;
    while(power>0)
    {
        if(value>MAX)
        {
            result=MAX+1;
            break;
        }
        if(power&1)
        {
        	result = result*value;
        	if(result>MAX)
        		break;
        }
        value = value*value;
        power /= 2;
    }
    return result;
}

void psieve()
{
    int i;
    for(i=2;i<=sqrt(MAX/4);i++)
    {
        if(!p[i])
        {
            for(int j=2*i;j<=MAX/4;j+=i)
                p[j]=1;
            prime2.pb(i);
        }
    }
    for(i=sqrt(MAX/4)+1;i<=MAX/4;i++)
        if(!p[i])
            prime2.pb(i);
}

void sieve()
{
    ll a,b,temp;
    int x,y,i,j;
    for(i=0;i<prime2.size();i++)
    {
        for(j=i+1;j<prime2.size();j++)
        {
            temp=(ll)prime2[i]*(ll)prime2[j]*min(prime2[i],prime2[j]);
            if(temp>MAX)
                break;
            for(x=0;x<8;x++)
            {
                if(prime2[i]>t[x])
                    break;
                a=(ll)fast_pow(prime2[i],prime1[x]-1);
                if(a>MAX)
                    break;
                for(y=x+1;y<8;y++)
                {
                    if(prime2[j]>t[y])
                        break;
                    b=fast_pow(prime2[j],prime1[y]-1);
                    if(b>MAX)
                        break;
                    temp=a*b;
                    if(temp>MAX)
                        break;
                    ans.pb(temp);
                }
                if(y==x+1&&y<7)
                    break;
            }

            for(x=0;x<8;x++)
            {
                if(prime2[j]>t[x])
                    break;
                a=(ll)fast_pow(prime2[j],prime1[x]-1);
                if(a>MAX)
                    break;
                for(y=x+1;y<8;y++)
                {
                    if(prime2[i]>t[y])
                        break;
                    b=fast_pow(prime2[i],prime1[y]-1);
                    if(b>MAX)
                        break;
                    temp=a*b;
                    if(temp>MAX)
                        break;
                    ans.pb(temp);
                }
                if(y==x+1&&y<7)
                    break;
            }
        }
    }
}

int main()
{
    psieve();
    sieve();
    ll a;
    int j;
    for(int i=0;i<prime2.size();i++)
    {
        a=(ll)prime2[i];
        for(j=2;j<15;j++)
        {
            a*=(ll)prime2[i];
            if(a>MAX)
                break;
            if(j==5||j==9||j==13||j==14)
                ans.pb(a);
        }
        if(j<=5)
            break;
    }
    sort(ans.begin(),ans.end());
    for(int i=8;i<ans.size();i+=9)
        cout<<ans[i]<<"\n";
    return 0;
}
