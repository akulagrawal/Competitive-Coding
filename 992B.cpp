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

ll gcd(ll a,ll b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}

ll max(ll a, ll b)
{
	if(a>=b)
		return a;
	return b;
}

ll min(ll a, ll b)
{
	if(a<=b)
		return a;
	return b;
}

vector<pair<ll,int> > prime;

void factorize(long long n)
{
    int count = 0;
 
    // count the number of times 2 divides 
    while (!(n % 2)) {
        n >>= 1; // equivalent to n=n/2;
        count++;
    }
 
    // if 2 divides it
    if (count)
        prime.pb(mp(2,count));
 
    // check for all the possible numbers that can 
    // divide it
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            prime.pb(mp(i,count));
    }
 
    // if n at the end is a prime number.
    if (n > 2)
        prime.pb(mp(n,1));
}

ll k,l,r,x,y;
ll prod;
ll ans;

void solve(ll u, int n)
{
	//cout<<u<<" "<<n<<endl;
	ll p=1;
	if(n==k)
	{
		if(l<=u&&u<=r&&(gcd(u,prod/u)==x))
			ans++;
		return;
	}
	for(int i=0;i<prime[n].s;i++)
	{
		solve(u*p,n+1);
		p*=prime[n].f;
	}
	solve(u*p,n+1);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>l>>r>>x>>y;
    ll p=x*y;
    prod=p;
    factorize(p);
    int i;
    k=prime.size();
    solve(1,0);
    cout<<ans;


    return 0;
}