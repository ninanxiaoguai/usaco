/*
ID: ninanxi2
TASK: subset
LANG: C++
*/

#include <iostream>

#include <stdio.h>

using namespace std;

const int maxn=10000+10;
long long f[100000];
int n,s;
int main()
{	
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
    cin>>n;
    s=n*(n+1);
    if(s%4!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    s/=4;
    f[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=s;j>=i;j--)
            f[j]+=f[j-i];
    cout<<f[s]/2<<endl;
    return 0;
}
