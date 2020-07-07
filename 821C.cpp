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

priority_queue< int, vector<int> > pq;
stack<int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p,i,k=1,ans=0;
    string s;
    cin>>n;
    for(i=0;i<(2*n);i++)
    {
        cin>>s;
        if(s[0]=='a')
        {
            cin>>p;
            my.push(p);
        }
        else
        {
            if(!my.empty())
            {
                if(my.top()==k)
                    my.pop();
                else
                {
                    while(!my.empty())
                    {
                        pq.push(my.top());
                        my.pop();
                    }
                    ans++;
                    pq.pop();
                }
                k++;
            }
            else
            {
                pq.pop();
                k++;
            }
        }
    }
    cout<<ans;
    return 0;
}
