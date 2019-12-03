#include <iostream>
#include <vector>
#include "locale.h"
#define n 10

using namespace std;

void quick(vector <int> v, int start, int finish){
	int s = start;
	int f = finish;
	int sr = v[(s + f) / 2];
	do{
		while (v[s] < sr)
			s++;
		while (v[f] > sr)
			f--;
		if (s <= f){
			int tmp = v[s];
			v[s] = v[f];
			v[f] = tmp;
			s++;
			f--;
		}
	} while (s < f);
	if (start < f)
		quick(v, start, f);
	if (s < finish)
		quick(v, s, finish);
}

void main() {
	setlocale(LC_CTYPE, "Russian");
	vector <int> v(n);
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
	cout << "отсортированный вектор имеет координаты" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}
