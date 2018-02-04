/*
ID: ninanxi2
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include  <fstream>
#include <string>

using namespace std;

int main() {
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    char a[10],b[10];
    scanf("%s%s",a,b);
    int i = 0,num1 = 1,num2 = 1;
    int flag;
    while(a[i] != '\0'){
   		 num1 = num1*(a[i++]-'A'+1);
    } 
    i = 0;
    while(b[i] != '\0'){
   		 num2 = num2*(b[i++]-'A'+1);
    }     
    flag = num1 % 47 - num2 % 47;
    if(flag)
    	 cout <<"STAY"<<endl;
    else
    	 cout <<"GO"<<endl;
    return 0;
}