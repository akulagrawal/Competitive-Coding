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
    cout<<s1[0];
    for(int i=1;i<s1.size();i++)
    {
        if(s1[i]>=s2[0])
            break;
        cout<<s1[i];
    }
    cout<<s2[0];
    return 0;
}
