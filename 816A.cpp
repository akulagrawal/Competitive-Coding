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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int h1,h2,m1,m2,n,m,i,j;
    int v[20]={0,1,2,3,4,9,10,11,12,13,14,19,20,21,22};
    cin>>s;
    h1=(int)(s[0]-'0');
    h2=(int)(s[1]-'0');
    m1=(int)(s[3]-'0');
    m2=(int)(s[4]-'0');
    n=10*m1+m2;
    m=10*h2+h1;
    if(m>=n&&m<60)
        cout<<(m-n);
    else
    {
        j=0;
        while(1)
        {
            m=(10*h1+h2+j)%24;
            if(m==23)
            {
                cout<<60-n+(60*j);
                return 0;
            }
            for(i=0;i<15;i++)
            {
                if(m==v[i])
                {
                    m=10*((v[i]+1)%10)+((v[i]+1)/10);
                    cout<<60-n+m+(60*j);
                    return 0;
                }
            }
            j++;
        }
    }
    return 0;
}
