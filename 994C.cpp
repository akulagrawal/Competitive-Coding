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

/* A utility function to calculate area of 
   triangle formed by (x1, y1), (x2, y2) and
  (x3, y3) */
float area(int x1, int y1, int x2, int y2,
                            int x3, int y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + 
                x3 * (y1 - y2)) / 2.0);
}
 
/* A function to check whether point P(x, y) 
   lies inside the rectangle formed by A(x1, y1), 
   B(x2, y2), C(x3, y3) and D(x4, y4) */
bool check(int x1, int y1, int x2, int y2, int x3, 
             int y3, int x4, int y4, int x, int y)
{
    /* Calculate area of rectangle ABCD */
    float A = area(x1, y1, x2, y2, x3, y3) + 
              area(x1, y1, x4, y4, x3, y3);
 
    /* Calculate area of triangle PAB */
    float A1 = area(x, y, x1, y1, x2, y2);
 
    /* Calculate area of triangle PBC */
    float A2 = area(x, y, x2, y2, x3, y3);
 
    /* Calculate area of triangle PCD */
    float A3 = area(x, y, x3, y3, x4, y4);
 
    /* Calculate area of triangle PAD */
    float A4 = area(x, y, x1, y1, x4, y4);
 
    /* Check if sum of A1, A2, A3 and A4 
       is same as A */
    return (A == A1 + A2 + A3 + A4);
}

struct Point
{
    int x;
    int y;
};
 
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

int x[10],y[10];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i;
    for(i=0;i<8;i++)
    	cin>>x[i];
    for(i=0;i<8;i++)
    	cin>>y[i];
    for(i=0;i<4;i++)
    {
	    if(check(y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], x[2*i], x[2*i+1]))
	    {
	    	cout<<"YES";
	    	return 0;
	    }
	    if(check(x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], y[2*i], y[2*i+1]))
	    {
	    	cout<<"YES";
	    	return 0;
	    }
    }
    for(i=0;i<4;i++)
    {
    	for(int j=0;j<4;j++)
    	{
    		Point p1,p2,q1,q2;
    		p1.x=x[2*i];
    		p1.y=x[2*i+1];
    		p2.x=x[(2*i+2)%8];
    		p2.y=x[(2*i+3)%8];
    		q1.x=y[2*j];
    		q1.y=y[2*j+1];
    		q2.x=y[(2*j+2)%8];
    		q2.y=y[(2*j+3)%8];
    		if(doIntersect(p1, p2, q1, q2))
    		{
    			cout<<"YES";
    			return 0;
    		}
    	}
    }
    cout<<"NO";


    return 0;
}