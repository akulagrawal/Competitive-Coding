#include<iostream>
#include<algorithm>

using namespace std;

long s[100005];

int main()
{
    int t;
    cin>>t;

    for(int i = 1; i <= t; i++)
    {
    	int n, k;
    	cin >> n >> k;
    	int j;
    	for( j = 0; j < n; j++)
    		cin >> s[j];
    	sort( s, s + n);
    	j=n-k-1;
    	while( j >= 0 && s[j] == s[n-k])
    		j--;
    	cout << n-j-1 << endl;

    }


    return 0;
}