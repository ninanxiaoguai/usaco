/*
ID: ninanxi2
PROG: hamming
LANG: C++11
*/
#include<iostream>  
#include<cstdio>  
  
using namespace std;  
  
int N,B,D;  
int num[256+10];  //
  
int cout_num(int a){//计算B位数与0的距离，即B位数中1的个数  
    int i,cnt=0;  
  
    for (i=0;i<B;i++)  
    {  cnt=cnt+(a&1);  
       a=a>>1;  
    }  
    return cnt;  
  
}  
int isok(int x,int c,int d){  
    int i,temp;  
    for (i=0;i<c;i++)  
    {  
        temp=x^num[i];//异或结果，不相同的位 为 1 
        if (cout_num(temp)<d)  
          return 0;  
    }  
    return 1;  
}  
  
  
int main()  
{  
  
    freopen("hamming.in","r",stdin);  
    freopen("hamming.out","w",stdout);  
  
    scout << N << B << D;  
      
     num[0]=0; //0是必然会出现的。  
    int vis=0;  
    int i,j;  
    for (i=1;i<=256;i++)  
    {  
        if(isok (i,vis+1,D))   
            num[++vis]=i;  
  
    }  
    i=0;  
    for(i=0;i<N;i++){  
        cout << num[i];  
        if ((i+1)%10==0 || i==N-1)   
            cout<<endl;  
        else if (i<N-1)  
            cout << " ";
              
    }  
    return 0;  
}  
