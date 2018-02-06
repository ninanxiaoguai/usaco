/*
ID: ninanxi2
PROG: sort3
LANG: C++11
*/
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
int input[1000],order[1000];
int state[4][4];//state[i][j]表示排序后在1区里的j的数量（1区为排序后数组中全为1的区域）
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> input[i];
    memcpy(order,input,sizeof(order));
    memset(state,0,sizeof(state));
    sort(order,order+N);
    int counter=0;
    for(int i=0;i<N;i++)
    {
        state[order[i]][input[i]]++;
    }
    int exchange1_3=min(state[1][3],state[3][1]);//1区里的3和3区里的1交换，代价为1区里三的个数和3区里1的个数取最小值
    int exchange1_2=min(state[1][2],state[2][1]);//同上1和2换
    int exchange2_3=min(state[2][3],state[3][2]);//同上2和3换
    counter=state[1][2]+state[1][3]-exchange1_2-exchange1_3;//1 2 3,互换一个圈的数量
    counter*=2;//代价为圈数的2倍
    counter+=exchange1_2+exchange1_3+exchange2_3;//加上代价为1的操作数
    cout<<counter<<endl;
    return 0;
}
