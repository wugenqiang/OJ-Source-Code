/*
��Ŀ����������д��A+Bi����ʽ������A��ʵ����B���鲿��
�Ӽ��������������������ӷ���˷�����������*/
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
