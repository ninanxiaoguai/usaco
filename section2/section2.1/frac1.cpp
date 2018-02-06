/*
ID: ninanxi2
PROG: frac1
LANG: C++11
*/
                                 // 法雷数列 : a/b < (a+c)/(b+d) < c/d
#include <iostream>
#include<cstdio>
using namespace std;
long n;
void dfs(long x1, long y1, long x2, long y2) {
	if (y1 + y2 <= n) {
		dfs(x1, y1, x1 + x2, y1 + y2);
		cout << x1 + x2 << "/" << y1 + y2 << endl;
		dfs(x1 + x2, y1 + y2, x2, y2);
	}
}
int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	cin >> n;;
	cout << "0/1" << endl;
	dfs(0, 1, 1, 1);
	cout << "1/1" << endl;
	return 0;
}
