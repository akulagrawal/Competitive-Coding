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
    string s1,s2;
    cin>>s1>>s2;
    int i,p1=0,p2=0,p3=0,k;
    double num=1,den=1;
    for(i=0;i<s1.size();i++)
    {
        if(s1[i]=='+')
            p1++;
        else
            p1--;
    }
    for(i=0;i<s2.size();i++)
    {
        if(s2[i]=='+')
            p2++;
        else if(s2[i]=='-')
            p2--;
        else
            p3++;
    }
    k=abs(p1-p2);
    if(p3<k)
        cout<<"0";
    else
    {
        k=(p3-k)/2;
        for(i=p3-k+1;i<=p3;i++)
            num*=(double)i;
        for(i=2;i<=k;i++)
            num/=(double)i;
        for(i=0;i<p3;i++)
            den*=2;
        cout<<setprecision(10)<<num/den;
    }
    return 0;
}
