/*
ID: ninanxi2
PROG: palsquare
LANG: C++11
*/


#include <iostream>
using namespace std;
int base;
char c[50]={"0123456789ABCDEFGHIJ"};


bool fun(int a){
    int tem = 0,aa = a,b;
    for(;a != 0;){
        b = a % base;
        a = a/base; 
        tem = tem*base + b;
    }
    if(tem == aa)
        return 1;
    else
        return 0;
}
void shuchu2(int a){
    int b;
    for(;a != 0;){
        b = a % base;
        a = a/base; 
        cout << c[b];
    }
}

void shuchu1(int a){
    int tem = 0,b;
    for(;a != 0;){
        b = a % base;
        a = a/base; 
        tem = tem*base + b;
    }
    shuchu2(tem);
}

int main() {

    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);

    cin >> base;
    for (int i = 1;i <= 300;i++)
        if(fun(i*i)){
            shuchu1(i);
            cout <<" ";
            shuchu2(i*i);
            cout << endl;
        }

    return 0;
}