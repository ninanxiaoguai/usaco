/*
ID: ninanxi2
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
/* This solution simply changes the string s into ss, then for every starting
// symbol it checks if it can make a sequence simply by repeatedly checking 
// if a sequence can be found that is longer than the current maximum one.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory.h>

using namespace std;
int a[20];
string str[20];

int main() {
  freopen("gift1.in","r",stdin);
  freopen("gift1.out","w",stdout);
  map<string,int>id;
  memset(a,0,sizeof(a));
  int n;
  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>str[i];
    id[str[i]]=i;
  }
  for(int i = 0;i < n;i++){
    string s;
    int m,x;
    cin >> s >> x >> m;
    if(m) a[id[s]] -= x/m * m;
    for(int j = 0; j < m;j++){
      cin >> s;
      a[id[s]] += x/m;
    }
  }
  for (int i = 0;i < n;i++) cout << str[i]<<' '<<a[i]<<endl;
  
  return 0;
} 