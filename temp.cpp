#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

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

int tree[MAX];
int a[MAX];
int bit[MAX];

void build(int node, int start, int end1) {
	if(start == end1)
	{
		tree[node] = a[start];
	}
	else
	{
		int mid = start+(end1-start)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end1);
		tree[node] = tree[2*node] + tree[2*node + 1];
	}
}

void update(int node, int start, int end1, int idx, int val) {
	if(start == end1){
		tree[node] += val;
		a[start] += val;
	}
	int mid = start+(end1-start)/2;
	if(idx <= mid)
		update(2*node, start, mid, idx, val);
	else
		update(2*node+1, mid+1, end1, idx, val);
	tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int start, int end1, int l, int r) {
	if((r < start) || (l > end1))
		return 0;
	if((l <= start) && (r >= end1))
		return tree[node];
	int mid = start+(end1-start)/2;
	int x1 = 0, x2 = 0;
	x1 = query(2*node, start, mid, l, r);
	x2 = query(2*node+1, mid+1, end1, l, r);
	return x1 + x2;
}

void update(int x, int val){
	while(x <= MAX){
		bit[x] += val;
		x += x&-x;
	}
}

int query(int x){
	int sum = 0;
	while(x > 0){
		sum += bit[x];
		x -= x&-x;
	}
	return sum;
}

bool compare(int a, int b) {
	return a > b;
}

struct cmp{
	bool operator()(int a, int b){
		return a>b;
	}
};

int gcd(int a, int b) {
	if(a==0)
		return b;
	return gcd(b%a, a);
}

int power(int x, int y){
	int p=x;
	int sum=1;
	while(y){
		if(y%2)
			sum*=p;
		p*=p;
		y/=2;
	}
	return sum;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;

    for(int i=0;i<10;i++){
    	pq.push(i);
    	a[i] = i;
    }
    while(!pq.empty()){
    	cout<<pq.top()<<" ";
    	pq.pop();
    }
    cout<<endl;
    sort(a, a+10, compare);
    for(int i=0;i<10;i++) {
    	cout<<a[i]<<" ";
    }
    cout<<endl;

    build(1, 0, 9);
    for(int i=1;i<16;i++)
    	cout<<tree[i]<<" ";
    cout<<endl;
    cout<<query(1, 0, 9, 2, 4)<<endl;
    cout<<gcd(10, 6)<<endl;
    cout<<power(2, 5)<<endl;

    for(int i=1;i<10;i++) {
    	update(i, 10-i);
    }
    cout<<query(10);

    char input[5];
    cin.getline(input,sizeof(input));
    cout<<input<<endl;

    return 0;
}