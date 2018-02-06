/*
ID: ninanxi2
PROG: holstein
LANG: C++11
*/
#include<fstream>  
using namespace std;  
int n;                  //保存维生素的种类数，n<30  
int v[30];              //每天需要的每种维生素数  
int m;                  //保存饲料种类数，m<20  
int s[20][30];          //每种饲料含有的维生素含量  
int mins=10000;         //保存最少的饲料种类数  
int now_num[30]={0};    //保存当前各种维生素的含量，共n个  
int now_a[20];          //保存当前满足条件的每种饲料种类，共mins个  
int res_a[20];          //保存满足条件的每种饲料种类，共mins个  
int i,j;  
int p;

void DFS(int k,int sum) //k:当前第 k种饲料，但还没有加入到sum中,sum:迄今已选择的饲料种类  
{  
    p++;
    if(k==m+1)          //遍历完每一种饲料后进入 if 语句
    {  
        for(i=1;i<=n;i++)  
        {  
            if(now_num[i]<v[i])  //不满足条件
                return;  
        }  
        if(sum<mins)  
        {  
            mins=sum;  
            for(i=1;i<=mins;i++)  
            {  
                res_a[i]=now_a[i];  
            }  
        }  
        return;  
    }  
    for(i=1;i<=n;i++)             //选择第 k 种饲料
        now_num[i]+=s[k][i];  
    now_a[sum+1]=k; 
    DFS(k+1,sum+1);  

    for(i=1;i<=n;i++)             //不选择第 k 种饲料
        now_num[i]-=s[k][i];  
    DFS(k+1,sum);  
}  

int main()  
{  
    ifstream fin ("holstein.in");  
    ofstream fout ("holstein.out");  
    fin>>n;  
    for(i=1;i<=n;i++)  
    {  
        fin>>v[i];  
    }  
    fin>>m;  
    for(i=1;i<=m;i++)  
    {  
        for(j=1;j<=n;j++)  
        {  
            fin>>s[i][j];  
        }  
    }  
    DFS(1,0);  
    fout<<mins;  
    for (i=1;i<=mins;i++)  
        fout<<" "<<res_a[i];  
    fout << p;
    fout<<endl;  

    return 0;  
}  
