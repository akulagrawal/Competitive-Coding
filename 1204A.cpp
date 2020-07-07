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
    cin>>s;
    if(s == "0")
    {
    	cout<<0;
    	return 0;
    }
    int n=s.size()-1;
    n = 1+(int)(n/2);
    int i=0;
    for(i=1;i<s.size();i++)
    	if(s[i] == '1')
    		break;
    if((i == s.size()) && (s.size()%2 == 1))
    	n--;
    cout<<n;


    return 0;
}