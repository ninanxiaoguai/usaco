/*
ID: ninanxi2
PROG: barn1
LANG: C++11
*/


# include<cstdio>
# include<iostream>
# include<algorithm>
# include<cstring>
# include<functional>

using namespace std;

# define MAX 200

int a[MAX];//用来模拟整个牛棚
int b[MAX];//用来存放间隙的长度

int cmp ( int x, int y )
{
	return x > y;
}

int main(void)
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	int M, S, C;
	cin >> M >> S >> C;
	for ( int i = 0; i < C; i++ )
	{
		cin >> a[i];
	}
	sort(a, a + C); //默认从小到大进行排序
	int sum = a[C - 1] - a[0] + 1;
	for ( int j = 1; j < C; j++ )
	{
		b[j] = a[j] - a[j - 1] - 1;
	}

	sort(b + 1, b + C, greater<int>()); //默认从大到小进行排序
	for ( int i = 1; i < M; i++ )
	{
		sum -= b[i];
	}
	cout << sum << endl;

	return 0;

}