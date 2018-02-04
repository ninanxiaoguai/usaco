/*
ID: ninanxi2
PROG: milk
LANG: C++11
*/


#include <stdio.h>
#include <stdlib.h> // qsort
#include <string.h>
#include <iostream>

using namespace std;


#define MAXFARMER 5000

typedef struct Farmer Farmer;
struct Farmer {
	int p;	/* price per gallon */
	int a;	/* amount to sell */
};

int farmcmp(const void *va, const void *vb)
{
	return ((Farmer*)va)->p - ((Farmer*)vb)->p;
}

int nfarmer;
Farmer farmer[MAXFARMER];

int main()
{
	int i, n, a, p;

	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);

	cin >> n >> nfarmer; 

	for(i=0; i<nfarmer; i++)
		cin >> farmer[i].p >> farmer[i].a; 

	qsort(farmer, nfarmer, sizeof(farmer[0]), farmcmp);

	p = 0;
	for(i=0; i<nfarmer && n > 0; i++) {
		/* take as much as possible from farmer[i], up to amount n */
		a = farmer[i].a;
		if(a > n)
			a = n;
		p += a*farmer[i].p;
		n -= a;
	}

	cout << p << endl;
	return 0;
}