/*
ID: ninanxi2
PROG: transform
LANG: C++11
*/
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn = 15;

int n;

struct Plat {
    string p[maxn];
};

Plat plat, finalPlat;

Plat rotate90(Plat a) {
    Plat np;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            np.p[j][n - 1 - i] = a.p[i][j];
        }
    }
    return np;
}

Plat reflect(Plat a) {
    Plat np;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            np.p[i][n - 1 - j] = a.p[i][j];
        }
    }
    return np;
}

bool cmp(Plat a, Plat b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a.p[i][j] != b.p[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    string tempt;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tempt;
        plat.p[i] = tempt;
    }
    for (int i = 0; i < n; i++) {
        cin >> tempt;
        finalPlat.p[i] = tempt;
    }
    int ans;
    if (cmp(finalPlat, rotate90(plat))) {
        ans = 1;
    } else if (cmp(finalPlat, rotate90(rotate90(plat)))) {
        ans = 2;
    } else if (cmp(finalPlat, rotate90(rotate90(rotate90(plat))))) {
        ans = 3;
    } else if (cmp(finalPlat, reflect(plat))) {
        ans = 4;
    } else if (cmp(finalPlat, rotate90(reflect(plat)))
            || cmp(finalPlat, rotate90(rotate90(reflect(plat))))
            || cmp(finalPlat, rotate90(rotate90(rotate90(plat))))) {
        ans = 5;
    } else if (cmp(finalPlat, plat)) {
        ans = 6;
    } else {
        ans = 7;
    }
    cout << ans << endl;



    return 0;
}