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

class Test
{
	static int x;
public:
	Test() {x++; }
	static int getX() {return x;}
	Test(const Test& t1){
		x++;
		*this = t1;
	}
};

int Test::x = 0;

void f(Test&& t){
	return;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<Test::getX()<<" ";
    Test t[5];
    cout<<Test::getX()<<" ";
    Test t1;
    f(move(t1));
    cout<<Test::getX()<<" ";

    char input[5];
    cin.getline(input,sizeof(input));
    cout<<input<<endl;


    return 0;
}