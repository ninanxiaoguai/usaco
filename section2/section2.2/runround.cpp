/*
ID: ninanxi2
PROG: runround
LANG: C++11
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <memory.h>
using namespace std;
bool isarroud(int x)
{
	int A[20];
	int Size = 0;
	bool vis[10];
	memset(vis, false, sizeof(vis));
	for (Size = 0; x > 0; Size++)
	{
		A[Size + 1] = x % 10;
		if (A[Size + 1] == 0)  //不为零
			return false;
		if (vis[A[Size + 1]])  //没有重复
			return false;
		vis[A[Size + 1]] = true;
		x /= 10;
	}
	int tag = 0, i;
	//因为A数组中存储方向的关系，i表示的是从左往右数第几位数，但第i位数字在数组中的A[Size]位置

	for (i = 0; !(tag & 1 << i); i = (i + A[Size - i]) % Size) //  << 优先级高于 &
		tag |= 1 << i;

	if (tag == (1 << Size) - 1 && i == 0)
		return true;
	return false;
}
int main()
{
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	int N;
	cin >> N;
	while (N++)
	{
		if (isarroud(N))
			break;
	}
	cout << N << endl;
	return 0;
}
