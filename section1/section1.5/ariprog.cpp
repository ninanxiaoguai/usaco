/*
ID: ninanxi2
PROG: ariprog
LANG: C++11
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

bool flag[130000];  //判断一个数是否符合p^2 + q^2
int  d[33000];      //符合条件的数值都存在这个数组中
struct ANS{
    int start, diff;
}ans[30000];        //用于保存最后的答案

int k;
void cal_s(int m){    
    memset(flag, 0, sizeof(flag));

    for(int i = 0; i <= m; ++i){
        for(int j = i; j <= m; ++j)
            flag[i * i + j * j] = 1;
    }

    k = 0;
    for(int i = 0; i < 130000; ++i){
        if(flag[i])
            d[k++] = i;
    }
}

int comp(ANS a, ANS b){
    if( a.diff != b.diff )
        return a.diff < b.diff;
    else
        return a.start < b.start;
}

void PrintAns(int w){
    sort(ans, ans + w, comp);
    for(int i = 0; i < w; ++i)
        fout << ans[i].start << ' ' << ans[i].diff << endl;
}

int main(){
    int n, m;
    int diff;
    fin >> n >> m;
    cal_s(m);    //计算所有满足p^2 + q^2的数
    int w = 0;
    for(int i = 0; i < k; ++i){
        for(int j = i + 1; j < k; ++j){
            diff = d[j] - d[i];
            int tmp = n - 2;   //数列已经有d[i]和d[j]
            int atmp = d[j];
            while(tmp){
                atmp += diff;
                if( atmp > m * m * 2 || !flag[atmp] )  //前面的判断没有会越界
                    break;
                --tmp;
            }
            if(!tmp){   //如果满足条件就保存数列
                ans[w].start = d[i];
                ans[w].diff = diff;
                ++w;
            }
        }
    }
    if(!w)
        fout << "NONE" << endl;
    else
        PrintAns(w);   //按要求排序并且输出
    fin.close();
    fout.close();
    return 0;

}