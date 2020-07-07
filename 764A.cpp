#include<bits/stdc++.h>

using namespace std;

int main()
{
    long n,m,z,p=1;
    int i;
    cin>>n>>m>>z;
    for(i=1;i<=min(n,m);i++)
    {
        if(n%i==0&&m%i==0)
            p=(long)i;
    }
    cout<<z*p/(m*n);
    return 0;
}
