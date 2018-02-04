/*
ID: ninanxi2
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
/* This solution simply changes the string s into ss, then for every starting
// symbol it checks if it can make a sequence simply by repeatedly checking 
// if a sequence can be found that is longer than the current maximum one.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <memory.h>
#include <utility>
    using namespace std;

    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int main(){
        int n;
        fin >> n;
        int min_s = 999999, max_e = 0;
        pair<int, int> time;
        vector<pair<int, int> > times;
        for(int i = 0; i < n; i++){
            int s, e;
            fin >> s >> e;
            time = make_pair(s, e);
            times.push_back(time);
            if(s < min_s)   min_s = s;
            if(e > max_e)   max_e = e;
        }
        int work = 0, max_work = 0, free = 0, max_free = 0;
        vector<pair<int, int> >::iterator it;
        for(int i = min_s; i <= max_e; i++){
            for(it = times.begin(); it != times.end(); it++){
                if(it->first <= i && it->second > i){
                    work++;
                    if(max_free < free){
                        max_free = free;
                    }
                    free = 0;
                    break;
                }
            }
            if(it ==  times.end()){
                free++;
                if(work > max_work){
                    max_work = work;
                }
                work = 0;
            }
        }

        fout << max_work << " " << max_free << endl;

        return 0;
    }