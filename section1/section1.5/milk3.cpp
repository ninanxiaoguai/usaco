/*
ID: ninanxi2
PROG: milk3
LANG: C++11
*/


#include <stdio.h>
int A, B, C;
int CB[21][21]; // All states

void readFile() {
    FILE *f;
    f = fopen("milk3.in", "r");
    fscanf(f, "%d%d%d", &A, &B, &C);
    fclose(f);
}

void writeFile() {
    FILE *f; int i;
    f = fopen("milk3.out", "w");
    for(i = 0; i <= C; i++) {
        if(CB[i][C - i] == 1) {   //C = b + c
            if((i != C-B) && (i != 0)) fprintf(f, " "); //格式为 _i 所以第一个不能加# 分为两种情况 第一种: C > B 为 i != C-B
            fprintf(f, "%d", i);                        //                                      第二种  C < B 为 i != 0
        }
    }
    fprintf(f, "\n");
    fclose(f);
}

// do brute-force search, c/b: current state
void search(int c, int b) {
    int a;
    if(CB[c][b] == 1) return; // already searched
    CB[c][b] = 1;
    a = C-b-c; // calc amount in A      C = a+b+c
    // do all moves:
    // c->b
    if(B < c+b) search(c - (B - b), B);
    else search(0, c + b);
    // b->c
    if(C < c+b) search(C, b - (C - c));
    else search(c + b, 0);
    // c->a
    if(A < c+a) search(c - (A - a), b);
    else search(0, b);
    // a->c
    if(C < c+a) search(C, b);
    else search(c + a, b);
    // b->a
    if(A < b+a) search(c, b - (A - a));
    else search(c, 0);
    // a->b
    if(B < b+a) search(c, B);
    else search(c, b + a);
   }
   
int main () {
    readFile();
    search(C, 0);
    writeFile();
    return 0;
}