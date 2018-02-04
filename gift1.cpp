/*
ID: ninanxi2
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include  <fstream>
#include <string>
#include <cstring>

using namespace std;
struct gift
{
	string name;
	int money;
}g[15];

int main(){
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

	int nump;
	int a,b;
	string name;
	cin>>nump;
	for(int i = 1;i <= nump;i++){
		
		cin>>name;
		g[i].name = name;
		g[i].money = 0;
	}
	for(int i = 1;i <= nump;i++){
		string nam;
		cin>>nam;
		cin>>a>>b;
		int m,n;
		if(a==0&&b==0)
			continue;
		else if (a==0||b==0)
		{
			m = 0;
			n = 0;
		}
		else {
			m = a/b;
			n = m*b;
		}
		for(int j = 1;j <= nump;j++){
			if(g[j].name == nam){
				g[j].money =g[j].money - n;
				break;
			}
		}
		for(int k = 1;k <= b;k++ ){
			string abc;
			cin >> abc;
		
			for(int p = 1;p <= nump;p++){
				if(g[p].name == abc ){
					g[p].money =g[p].money + m;
					break;
				}
			}
		}
	}
	for(int i = 1;i <= nump;i++)
		cout <<g[i].name<<' '<<g[i].money<<endl;

	return 0;

}