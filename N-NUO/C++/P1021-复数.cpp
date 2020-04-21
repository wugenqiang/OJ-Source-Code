/*
题目：复数可以写成A+Bi的形式，其中A是实部，B是虚部。
从键盘输入两个复数，做加法或乘法并输出结果。*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double a1, b1, a2, b2, ans_a, ans_b;
	string op;
	cin >> a1 >> b1 >> a2 >> b2 >> op;
	if (op == "+") {
		ans_a = a1 + a2;
		ans_b = b1 + b2;
	}
	else if (op == "*") {
		ans_a = a1 * a2 - b1 * b2;
		ans_b = a1 * b2 + a2 * b1;
	}
	printf("%.1f %.1f\n", ans_a, ans_b);
	return 0;
}
