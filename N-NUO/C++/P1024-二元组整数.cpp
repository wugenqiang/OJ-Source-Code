#include<iostream>
#include<cstdlib>
using namespace std;
int cmp(const void* c, const void* d)
{
	return (*(int*)c - *(int*)d);
}
int main()
{
	int n, x;
	cin >> n;
	int* a = new int[n];//存数 
	int* b = new int[n];//存不重复数 
	bool* c = new bool[n]; //给有重复的数添加标记 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[i] = false;
	}
	qsort(a, n, sizeof(a[0]), cmp);
	b[0] = a[0];
	int len = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != b[len])
			b[++len] = a[i];
		else
			c[len] = true; 
	}
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= len; j++) {
			if (i != j) {
				cout << "(" << b[i] << "," << b[j] << ")" << endl;
			}
			else if (c[i]) {
				cout << "(" << b[i] << "," << b[j] << ")" << endl;
			}
		}
	}
	return 0;
}
