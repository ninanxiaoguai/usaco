/*
ID: ninanxi2
PROG: combo
LANG: C++11
*/


#include <fstream>  
 #include <iostream>  
 #include <set>  
#include <vector>  
 using namespace std;  
  
  
 int main()  
 {  
    ifstream fin("combo.in");  
    ofstream fout("combo.out");  
  
    int N;  
    fin >> N;  
    std::vector<int> combo1(3);  
    std::vector<int> combo2(3);  
  
    fin >> combo1[0] >> combo1[1] >> combo1[2];  
    fin >> combo2[0] >> combo2[1] >> combo2[2];  
  
  
    set<std::vector<int>> combo_set;  
  
    for (int i = -2; i <= 2; ++i)  
    {  
        for (int j = -2; j <= 2; ++j)  
        {  
            for (int k = -2; k <= 2; ++k)  
            {  
                std::vector<int> v(3);  
                v[0] = (i+combo1[0]+N)%N;  
                v[1] = (j+combo1[1]+N)%N;  
                v[2] = (k+combo1[2]+N)%N;  
  
                std::vector<int> v1(3);  
                v1[0] = (i+combo2[0]+N)%N;  
                v1[1] = (j+combo2[1]+N)%N;  
                v1[2] = (k+combo2[2]+N)%N;  
  
                combo_set.insert(v);  
                combo_set.insert(v1);  
            }  
        }  
    }  
  
    fout << combo_set.size() << endl;  
  
    return 0;  
  
  
  
 }  
