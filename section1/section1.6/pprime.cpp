/*
ID: ninanxi2
PROG: pprime
LANG: C++11
*/

#include <iostream>  
#include <cstring>  
#include <cmath>  
  
using namespace std;  
  
int func(int n)//转换成回文数  
{//如n=12时，我们只需要回文数121，  
    int res=n/10;  
    while(n)  
    {  
        res=res*10+n%10;  
        n/=10;  
    }  
    return res;  
}  
int is_prime(int n)//判断素数   
{  
    if(n<=1){  
        return 0;}  
    if(n==2)  
        return 1;  
    int i;  
    int k=sqrt(n);  
    for(i=2;i<=k;i++)  
    {  
        if(n%i==0)  
        {  
            return 0;  
        }  
    }  
    return 1;  
}  
int main()  
{  
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    int a,b;  
    cin>>a>>b;  
    int i;  
    if(a<12){//处理偶数回文数11的情况，若a小于12，输出a在5-11之间满足条件的数    
        for(i=a;i<12;i++)  
        {  
            if(is_prime(i)==1)  
            {  
                cout<<i<<endl;  
            }  
        }  
    }  
    for(i=10;i<=10000;i++)  
    {  
        int x;  
        //先还原回文数另外一半  
        x=func(i); 
        if(x<a)
            continue;
        if(x>b)  
            break;  
        if(is_prime(x)==1){  
            cout<<x<<endl;  
        }  
    }  
    return 0;  
}  