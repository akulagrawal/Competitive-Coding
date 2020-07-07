#include<bits/stdc++.h>

using namespace std;

long long a[200005];

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(n%2)
        {
            if(i%2==0)
                cout<<a[n-i-1];
            else
                cout<<a[i];
        }
        else
        {
            if(i<(n/2))
            {
                if(i%2==0)
                    cout<<a[n-i-1];
                else
                    cout<<a[i];
            }
            else
            {
                if(i%2)
                    cout<<a[n-i-1];
                else
                    cout<<a[i];
            }
        }
        cout<<" ";
    }
    return 0;
}
