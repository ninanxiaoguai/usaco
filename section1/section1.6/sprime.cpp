/*
ID: ninanxi2
PROG: sprime
LANG: C++11
*/

#include <iostream>  
#include <cstring>  
#include <cmath>  
  
using namespace std;  
  
#include <cstdio>  
#include <cmath>  
int n;  
inline bool check(int k)  
{  
    for (int i = 2; i <= sqrt(k); ++ i)  
        if (k % i == 0) return false;  
    return true;      
}  
  
void dfs(int k, int num)  
{  
    if (k == n)   
    {  
        printf("%d\n", num);  
        return;  
    }  
    for (int i = 0; i != 10; ++ i)  
        if (check(num * 10 + i))    
        	dfs(k + 1, num * 10 + i);     
}  
  
int main()  
{  
    freopen("sprime.in", "r", stdin);  
    freopen("sprime.out", "w", stdout);  
    scanf("%d", &n);  
    dfs(1, 2);  
    dfs(1, 3);  
    dfs(1, 5);  
    dfs(1, 7);  
    return 0;  
}  