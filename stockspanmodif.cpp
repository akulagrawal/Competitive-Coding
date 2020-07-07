#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    stack<int> s;
    s.push(0);

    int maxm=0,diff;
    for(i=1;i<n;i++)
    {
        while(!s.empty()&&a[i]>a[s.top()])
          s.pop();
        diff=(s.empty())?i+1:i-s.top();
        if(diff>maxm)
            maxm=diff;
        s.push(i);
    }
    cout<<maxm<<endl;
    return 0;
}
