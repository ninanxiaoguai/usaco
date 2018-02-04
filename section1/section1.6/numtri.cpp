/*
ID: ninanxi2
PROG: numtri
LANG: C++11
*/


#include <iostream>
#include <string>

using namespace std;

int main() {
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int str[100][100];
    int n,sum = 0,j = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int k = 0;k <= i; k++)
			cin >> str[i][k];
	}
	for(int i = 0 ; i < n ; i++){
		if(i == 0)	sum = sum + str[i][j] ;
		else if (str[i][j] <= str[i][j+1]){
			sum = sum + str[i][j+1] ;
			cout << str[i][j+1] << " ";
			j = j + 1;
			
		}
		else{
			sum = sum + str[i][j];
			cout << str[i][j] << " ";
		}
	}
	cout << sum << endl;
	return 0;
}
