/*
题目：复数可以写成A+Bi的形式，其中A是实部，B是虚部。
从键盘输入两个复数，做加法或乘法并输出结果。*/ 

#include <stdio.h>
int main() {
	double a1, b1, a2, b2;
	double res1, res2;
	char c;//符号+*
	scanf("%lf %lf %lf %lf %c", &a1, &b1, &a2, &b2, &c);
	switch(c) {
		case '+':
			res1 = a1 + a2;
			res2 = b1 + b2;
			break;
		case '*':
			res1 = a1 * a2 - b1 * b2;
			res2 = a1 * b2 + b1 * a2;
			break;				
	} 
	printf("%.1lf %.1lf\n", res1, res2);
	return 0;
}
