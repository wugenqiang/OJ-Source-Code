/*
题目：删除最大最小数*/ 
#include<iostream>
using namespace std;
int main()
{
	int num[105];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int Max = 0, Min = n-1;
	for (int i = 0; i < n; i++) {
		if (num[i] > num[Max])
			Max = i;
		if (num[i] < num[Min])
			Min = i;
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (i != Max && i != Min) {
			if (flag)
				cout << " " << num[i];
			else
				cout << num[i];
			flag = true;
		}
	}
	cout << endl;
	return 0;
}
