#include <iostream>
#include <vector>
#include "locale.h"
#include <cstdlib>
#include <ctime>
#define n 1000

using namespace std;
void quick(int *a, int start, int finish){
	int s = start;
	int f = finish;
	//int sr = a[(s + f) / 2];
	//int sr = a[s];
	int sr = a[s+rand() % f-s+1];
	do{
		while (a[s] < sr)
			s++;
		while (a[f] > sr)
			f--;
		if (s <= f){
			int tmp = a[s];
			a[s] = a[f];
			a[f] = tmp;
			s++;
			f--;
		}
	} while (s < f);
	if (start < f)
		quick(a, start, f);
	if (s < finish)
		quick(a, s, finish);
}

void main() {
	setlocale(LC_CTYPE, "Russian");
	vector <int> v(n);
	int *a = &v[0];
	for (int i = 0; i < n; i++) {
		v[i] = rand() % 100;
	}
	cout << "исходный вектор имеет координаты" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	int start = 0;
	//v[0] = 0;
	//v[(n - 1) / 2] = 0;
	int finish = n - 1;
	int tstart = clock();
	quick(a, start, finish);
	int tfinish = clock();
	int t = (tfinish - tstart);
	cout << "отсортированный вектор имеет координаты" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl << "время сортировки составило " << t << endl;
}
