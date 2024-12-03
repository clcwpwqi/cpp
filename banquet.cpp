//祝我拿一等奖！！！ 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define endl '\n'
#define x first
#define y second
#define pb(i) push_back(i)

using namespace std;

const int N = 2e5 + 10;

int T;
int n;
int x[N], t[N];
int lp = 0x3f3f3f3f, rp;

int check(double pos, double l, double r)
{
	double r1 = 0;
	for (int i = 1; i <= n; i ++)
		r1 = max(r1, fabs(pos - x[i]) + t[i]);
	
	double ll = l, rr = r;
	
	ll = pos;
	double p2 = pos + 0.1;
	double r2 = 0;
	for (int i = 1; i <= n; i ++)
		r2 = max(r2, fabs(p2 - x[i]) + t[i]);
		
	ll = l, rr = pos;
	double p3 = pos - 0.1;
	double r3 = 0;
	for (int i = 1; i <= n; i ++)
		r3 = max(r3, fabs(p3 - x[i]) + t[i]);
		
	if (r2 > r1 && r3 > r1) return 2;
	else if (r2 < r3) return 1;
	else return 0;
}

int main()
{
//	freopen("banquet.in", "r", stdin);
//	freopen("banquet.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	//用scanf时，别忘了关！ 
	
	cin >> T;
	
	while (T --)
	{
		cin >> n;
		
		for (int i = 1; i <= n; i ++)
			cin >> x[i], lp = min(x[i], lp), rp = max(rp, x[i]);
			
		for (int i = 1; i <= n; i ++)	
			cin >> t[i];
			
		double l = lp, r = rp;
		while (abs(r - l) > 1e-6)
		{
			double mid = (l + r) * 1.0 / 2;
			int op = check(mid, l, r);
			
			if (op == 0) r = mid;
			else if (op == 1) l = mid;
			else
			{
				r = mid;
				break;
			}
		}
		
		if (fabs(r - int(r + 0.5)) < 1e-1) printf("%.0f\n", r);
		else printf("%.1lf\n", r);
	}
	
	return 0;
}
