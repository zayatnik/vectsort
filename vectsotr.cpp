#include <iostream>
#include <vector>
#include "locale.h"
#define n 10

using namespace std;

void quick(int *a, int start, int finish){
	int s = start;
	int f = finish;
	int sr = a[(s + f) / 2];
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
	cout << "введите координаты вектора" << endl;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << "исходный вектор имеет координаты" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	int start = 0;
	int finish = n - 1;
	quick(a, start, finish);
	cout << "отсортированный вектор имеет координаты" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}
