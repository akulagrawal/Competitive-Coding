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

int g[102][102];
int p[MAX];
int dp[102][102];
int mark[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<n;j++){
    		g[i][j] = s[j] - '0';
    		if(g[i][j] == 1)
    			dp[i][j] = g[i][j];
    		else
    			dp[i][j] = MAX;
    	}
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
    	cin>>p[i];
    	p[i]--;
    }

    for (int k = 0; k < n; k++)  
    {  
        // Pick all vertices as source one by one  
        for (int i = 0; i < n; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (int j = 0; j < n; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dp[i][k] + dp[k][j] < dp[i][j])  
                    dp[i][j] = dp[i][k] + dp[k][j];  
            }  
        }  
    }
    for (int i = 0; i < n; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            dp[i][i]=0;
        }



    int ans=  0;
    int l=0;
    for(int i=1;i<m-1;i++){
    	//cout<<p[l]<<" "<<p[i]<<" "<<p[i+1]<<endl;
    	//cout<<dp[p[l]][p[i+1]]<<" "<<dp[p[l]][p[i]]<<" "<<dp[p[i]][p[i+1]]<<endl<<endl;
    	if(dp[p[l]][p[i+1]] == dp[p[l]][p[i]] + dp[p[i]][p[i+1]]) {
    		mark[i] = 1;
    		ans++;
    	}
    	else {
    		l=i;
    	}
    }
    cout<<m-ans<<endl;
    for(int i=0;i<m;i++){
    	if(mark[i]==0)
    		cout<<p[i]+1<<" ";
    }




    return 0;
}