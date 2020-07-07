#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
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
    int r,l,i,k,p;
    string s;
    cin>>r;
    while(r--)
    {
        k=0;
        p=0;
        cin>>l;
        cin>>s;
        for(i=0;i<l;i++)
        {
            if(s[i]=='H')
            {
                if(!k)
                    k++;
                else
                {
                    p=1;
                    cout<<"Invalid\n";
                    break;
                }
            }
            else if(s[i]=='T')
            {
                if(k==1)
                    k--;
                else
                {
                    p=1;
                    cout<<"Invalid\n";
                    break;
                }
            }
        }
        if(k&&!p)
            cout<<"Invalid\n";
        else if(!k&&!p)
            cout<<"Valid\n";
    }
    return 0;
}
