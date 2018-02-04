/*
ID: ninanxi2
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include  <fstream>
#include <string>

using namespace std;
int daysofmonth[13][2] = {{0, 0},{31, 31},{28, 29},{31, 31},{30, 30},{31, 31},{30, 30},{31, 31},{31, 31},{30, 30},{31, 31},{30, 30},{31, 31}};  
  
bool isYear(int x){  
    return ((x % 400 == 0) || (x % 4 == 0 && x % 100 != 0));  
}  

int main(){
	//freopen("friday.in","r",stdin);
	//freopen("friday.out","w",stdout);
	int n,days,d[8];
	cin>>n; 
	days = 0;  
    for(int i = 1; i <= 7; i++)  
        d[i] = 0;    
    for(int i = 0; i < n; i++){  
        int t = isYear(1900 + i);  
        cout<<"i: "<<i<<endl;
        for(int j = 1; j <= 12; j++){  
            d[(days + 12) % 7 + 1]++;  
            days += daysofmonth[j][t];    
        }  
    }  
    cout<<d[6]<<" "<<d[7]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<" "<<d[4]<<" "<<d[5]<<endl;  
	return 0;

}