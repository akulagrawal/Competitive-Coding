// C++ program to compute Totient function for
// all numbers smaller than or equal to n.
#include<bits/stdc++.h>
using namespace std;

long long phi[1000006];

void computeTotient(int n)
{
	for (int i=1; i<=n; i++)
		phi[i] = i; // indicates not evaluated yet
					// and initializes for product
					// formula.

	// Compute other Phi values
	for (int p=2; p<=n; p++)
	{
		// If phi[p] is not computed already,
		// then number p is prime
		if (phi[p] == p)
		{
			// Phi of a prime number p is
			// always equal to p-1.
			phi[p] = p-1;

			// Update phi values of all
			// multiples of p
			for (int i = 2*p; i<=n; i += p)
			{
			// Add contribution of p to its
			// multiple i by multiplying with
			// (1 - 1/p)
			phi[i] = (phi[i]/p) * (p-1);
			}
		}
	}
}

// Driver program to test above function
int main()
{
	int n,t;
	computeTotient(1000000);
	scanf("%d",&t);
	while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",phi[n]);
    }
	return 0;
}
