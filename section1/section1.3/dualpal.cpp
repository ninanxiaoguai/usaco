/*
ID: ninanxi2
PROG: dualpal
LANG: C++11
*/


#include <iostream>
using namespace std;


int main() {

    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);

    int s,n;
    cin >> n >> s;
    int num = 0,sum_num = 0,tem ,np = 0;
	for( s= s+1;;s++){
		for(int base = 2;base <= 10;base++){
			int p = s;
			for(;s != 0; ){
				tem = s % base;
				s = s / base;
				np = np*base + tem;
			}
			
			s = p;
			if(np == p )
				num ++;
			np = 0;
			if(num >= 2){
				sum_num ++;
				cout << p <<endl;
				break;
			}
			
		}
		if(sum_num >= n)
		break;
		num = 0;
	}

    return 0;
}